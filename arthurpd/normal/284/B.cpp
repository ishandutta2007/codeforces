#include <stdio.h>

int
main(void)
{
int tmp;
register int numa = 0, n = 0, numin = 0, i;
scanf("%d", &tmp);
n = tmp;
for(i = 0; i < n; i++)
	{
	char c;
	scanf(" %c", &c);
	if(c == 'A')
		numa++;
	if(c == 'I')
		numin++;
	}
if(numin > 1)
	printf("0\n");
else if(numin == 1)
	printf("1\n");
else
	printf("%d\n", numa);
return 0;
}