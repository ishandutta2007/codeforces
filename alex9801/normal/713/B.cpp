#include <stdio.h>
#include <string.h>
#include <algorithm>

int a, b, c, ds;

bool chk(int l, int d, int r, int u)
{
	int aa = a-l, bb = b-d, cc = c-r, dd = ds-u, t;
	if(l<=r&&d<=u&&aa<=cc&&bb<=dd)
	{
		printf("? %d %d %d %d\n", l, d, r, u);
		fflush(stdout);
		scanf("%d", &t);
		if(t != 1)
			return 0;
		printf("? %d %d %d %d\n", aa, bb, cc, dd);
		fflush(stdout);
		scanf("%d", &t);
		if(t != 1)
			return 0;
		printf("! %d %d %d %d %d %d %d %d\n", l, d, r, u, aa, bb, cc, dd);
		fflush(stdout);
		return 1;
	}
	return 0;
}

int main()
{
	int n, s, g, x, r1, r2, l1, l2, u1, u2, d1, d2, t, i, j;
	scanf("%d", &n);

	s = 1;
	g = n;
	while(s<g)
	{
		x = (s+g)/2;
		printf("? 1 1 %d %d\n", x, n);
		fflush(stdout);
		scanf("%d", &t);
		if(t)
			g = x;
		else
			s = x+1;
	}
	r1 = s;

	s = 1;
	g = n;
	while(s<g)
	{
		x = (s+g)/2;
		printf("? 1 1 %d %d\n", x, n);
		fflush(stdout);
		scanf("%d", &t);
		if(t==2)
			g = x;
		else
			s = x+1;
	}
	r2 = s;

	s = 1;
	g = n;
	while(s<g)
	{
		x = (s+g+1)/2;
		printf("? %d 1 %d %d\n", x, n, n);
		fflush(stdout);
		scanf("%d", &t);
		if(t==2)
			s = x;
		else
			g = x-1;
	}
	l1 = s;

	s = 1;
	g = n;
	while(s<g)
	{
		x = (s+g+1)/2;
		printf("? %d 1 %d %d\n", x, n, n);
		fflush(stdout);
		scanf("%d", &t);
		if(t)
			s = x;
		else
			g = x-1;
	}
	l2 = s;



	s = 1;
	g = n;
	while(s<g)
	{
		x = (s+g)/2;
		printf("? 1 1 %d %d\n", n, x);
		fflush(stdout);
		scanf("%d", &t);
		if(t)
			g = x;
		else
			s = x+1;
	}
	u1 = s;

	s = 1;
	g = n;
	while(s<g)
	{
		x = (s+g)/2;
		printf("? 1 1 %d %d\n", n, x);
		fflush(stdout);
		scanf("%d", &t);
		if(t==2)
			g = x;
		else
			s = x+1;
	}
	u2 = s;

	s = 1;
	g = n;
	while(s<g)
	{
		x = (s+g+1)/2;
		printf("? 1 %d %d %d\n", x, n, n);
		fflush(stdout);
		scanf("%d", &t);
		if(t==2)
			s = x;
		else
			g = x-1;
	}
	d1 = s;

	s = 1;
	g = n;
	while(s<g)
	{
		x = (s+g+1)/2;
		printf("? 1 %d %d %d\n", x, n, n);
		fflush(stdout);
		scanf("%d", &t);
		if(t)
			s = x;
		else
			g = x-1;
	}
	d2 = s;

	a = l1+l2;
	b = d1+d2;
	c = r1+r2;
	ds = u1+u2;


	if(chk(l1, d1, r1, u1))
		return 0;
	if(chk(l1, d1, r1, u2))
		return 0;
	if(chk(l1, d1, r2, u1))
		return 0;
	if(chk(l1, d1, r2, u2))
		return 0;
	if(chk(l1, d2, r1, u1))
		return 0;
	if(chk(l1, d2, r1, u2))
		return 0;
	if(chk(l1, d2, r2, u1))
		return 0;
	if(chk(l1, d2, r2, u2))
		return 0;

	if(chk(l2, d1, r1, u1))
		return 0;
	if(chk(l2, d1, r1, u2))
		return 0;
	if(chk(l2, d1, r2, u1))
		return 0;
	if(chk(l2, d1, r2, u2))
		return 0;
	if(chk(l2, d2, r1, u1))
		return 0;
	if(chk(l2, d2, r1, u2))
		return 0;
	if(chk(l2, d2, r2, u1))
		return 0;
	if(chk(l2, d2, r2, u2))
		return 0;

	return 0;
}