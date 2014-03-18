/*
** client_main.c for  in /home/bauwen_j/rendu/my_git/minitalk/client
** 
** Made by bauwen_j
** Login   <bauwen_j@epitech.eu>
** 
** Started on  Mon Mar 17 16:43:57 2014 bauwen_j
** Last update Mon Mar 17 16:43:57 2014 bauwen_j
*/

#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include "my.h"

void	start_client(char *spid, char *text)
{
  pid_t	pid;
  int	i;
  int	j;
  int	*oct;

  pid = my_getnbr(spid);
  i = 0;
  while (text[i] != 0)
    {
      if ((oct = get_dec_to_bin(text[i])) == NULL)
	return ;
      j = 0;
      while (j < 8)
	{
	  if (oct[j] == 0)
	    kill(pid, SIGUSR1);
	  else
	    kill(pid, SIGUSR2);
	      usleep(1);
	  j++;
	}
      i++;
    }
}

int	main(int ac, char **argv)
{
  if (ac != 3)
    my_putstr("error : this program need two arguments\n");
  else
    start_client(argv[1], argv[2]);
  return (0);
}
