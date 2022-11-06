#include <stdio.h>
#include <string.h>
#include <algorithm>

char arr[100000];

int main()
{
	int p, r, t, k, i;
	char c;
	scanf("%s", arr);
	r = 0;
	t = 0;
	k = 1;
	for(i = 0; arr[i]; i++)
	{
		c = arr[i];
		if(c == '+')
		{
			r += t*k;
			t = 0;
			k = 1;
		}
		else if(c == '-')
		{
			r += t*k;
			t = 0;
			k = -1;
		}
		else
		{
			t = 10*t + (c - '0');
		}
	}
	r += t*k;

	if(r>=100)
	{
		t = r/100;
		for(i = 0; i<48; i++)
			printf("+");
		for(i = 0; i<t; i++)
			printf("+");
		printf(".");
		printf(">");
	}

	if(r>=10)
	{
		t = r%100/10;
		for(i = 0; i<48; i++)
			printf("+");
		for(i = 0; i<t; i++)
			printf("+");
		printf(".");
		printf(">");
	}

	if(r>=0)
	{
		t = r%10;
		for(i = 0; i<48; i++)
			printf("+");
		for(i = 0; i<t; i++)
			printf("+");
		printf(".");
	}
	return 0;
}