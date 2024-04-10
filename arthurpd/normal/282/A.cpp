#include <stdio.h>

int
main(void)
{
int n, i, x = 0;
scanf("%d", &n);
for(i = 0; i < n; i++)
{
char s[10];
scanf(" %s", s);
if(s[0] == '+' || s[2] == '+')
x++;
else
x--;
}
printf("%d\n", x);
return 0;
}