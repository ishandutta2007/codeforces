#include <stdio.h>
#include <string.h>
#include <algorithm>

char a[100001];
int c[100];

int main()
{
	int r, i;
	scanf("%s", a);

	for(i = 0; a[i]; i++)
	{
		if(a[i] == 'B')
			c[0] += 2;
		if(a[i] == 'u')
			c[1] += 1;
		if(a[i] == 'l')
			c[2] += 2;
		if(a[i] == 'b')
			c[3] += 2;
		if(a[i] == 'a')
			c[4] += 1;
		if(a[i] == 's')
			c[5] += 2;
		if(a[i] == 'r')
			c[6] += 2;
	}

	r = c[0];

	for(i = 1; i<=6; i++)
	{
		r = std::min(r, c[i]);
	}

	printf("%d", r/2);

	return 0;
}