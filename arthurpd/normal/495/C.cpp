#include <stdio.h>
#include <string.h>

char s[112345];
int a[112345];

int
main(void)
{
	scanf("%s", s);
	
	int n = strlen(s);
	int k = 0, l = 0;
	
	for(int i = 0; i < n; i++)
		if(s[i] == '(')
			k++;
		else if(s[i] == ')')
			k--, a[i] = 1;
		else
			k--, a[i] = 1;
	
	if(k < 0)
	{
		printf("-1\n");
		return 0;
	}

	for(int i = n-1; i >= 0; i--)
		if(s[i] == '#')
		{
			a[i] += k;
			k = 0;
			break;
		}
	if(k != 0)
	{
		printf("-1\n");
		return 0;
	}
	int placed = 0, need = 0;
	for(int i = 0; i < n; i++)
	{
		if(s[i] == '(')
			need++;
		placed += a[i];
		if(need < placed)
		{
			printf("-1\n");
			return 0;
		}
	}
	for(int i = 0; i < n; i++)
		if(s[i] == '#')
			printf("%d\n", a[i]);
}