#include <stdio.h>
#include <string.h>
#include <algorithm>

//00 01 10 11

int main()
{
	bool u;
	int a, b, c, d, p, q, i, j;
	long long s, t;
	scanf("%d%d%d%d", &a, &b, &c, &d);

	if(a==0 && d==0)
	{
		if(b==0 && c==0)
		{
			printf("0");
			return 0;
		}
		if(b==1 && c==0)
		{
			printf("01");
			return 0;
		}
		if(b==0 && c==1)
		{
			printf("10");
			return 0;
		}
		printf("Impossible");
		return 0;
	}

	u = 0;
	for(i = 0; ; i++)
	{
		t = 1LL*i*(i-1)/2;
		if(t >= a)
		{
			if(t==a)
			{
				p = i;
				u = 1;
			}
			break;
		}
	}
	if(u==0)
	{
		printf("Impossible");
		return 0;
	}

	u = 0;
	for(i = 0; ; i++)
	{
		t = 1LL*i*(i-1)/2;
		if(t >= d)
		{
			if(t==d)
			{
				q = i;
				u = 1;
			}
			break;
		}
	}
	if(u==0)
	{
		printf("Impossible");
		return 0;
	}

	if(p==0 && b+c>0)
		p = 1;
	if(q==0 && b+c>0)
		q = 1;

	if(b+c != 1LL*p*q)
	{
		printf("Impossible");
		return 0;
	}

	if(p==0)
	{
		for(i = 0; i<q; i++)
			printf("1");
		return 0;
	}

	if(q==0)
	{
		for(i = 0; i<p; i++)
			printf("0");
		return 0;
	}

	t = 0;
	for(i = 0; i<q; i++)
	{
		if(t+p>=c)
		{
			s = c-t;
			for(j = 0; j<i; j++)
				printf("1");
			for(j = 0; j<p-s; j++)
				printf("0");
			printf("1");
			for(j = 0; j<s; j++)
				printf("0");
			for(j = 0; j<q-(i+1); j++)
				printf("1");
			return 0;
		}
		t += p;
	}
	return 0;
}