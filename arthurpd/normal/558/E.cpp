//http://codeforces.com/contest/558/problem/E

#include <stdio.h>
#include <string.h>

#define left(i) ((i) << 1)
#define right(i) (((i) << 1) + 1)

char s[112345];
int val[26][412345];
int lazy[26][412345];

int prop(int num, int id, int l, int r)
{
	if(lazy[num][id] >= 0)
	{
		val[num][id] = (r-l+1)*lazy[num][id];
		if(l != r)
			lazy[num][left(id)] = lazy[num][right(id)] = lazy[num][id];
		lazy[num][id] = -1;
	}
}

void update(int num, int id, int l, int r, int a, int b, int x)
{
	prop(num, id, l, r);
	if(a == l && b == r)
		lazy[num][id] = x;
	else
	{
		int mid = (l+r)/2;
		if(b <= mid)
			update(num, left(id), l, mid, a, b, x);
		else if(a > mid)
			update(num, right(id), mid+1, r, a, b, x);
		else
			update(num, left(id), l, mid, a, mid, x), update(num, right(id), mid+1, r, mid+1, b, x);
		prop(num, left(id), l, mid), prop(num, right(id), mid+1, r);
		val[num][id] = val[num][left(id)] + val[num][right(id)];
	}
}

int get(int num, int id, int l, int r, int a, int b)
{
	prop(num, id, l, r);
	if(a == l && b == r)
		return val[num][id];
	else
	{
		int mid = (l+r)/2;
		if(b <= mid)
			return get(num, left(id), l, mid, a, b);
		else if(a > mid)
			return get(num, right(id), mid+1, r, a, b);
		else
			return get(num, left(id), l, mid, a, mid) + get(num, right(id), mid+1, r, mid+1, b);
	}
}

int
main(void)
{
	memset(lazy, 0xff, sizeof(lazy));
	int n, q, a, b, c;
	scanf("%d %d", &n, &q);
	scanf(" %s", s);
	for(int i = 0; i < n; i++)
		update(s[i] - 'a', 1, 0, n-1, i, i, 1);
	while(q--)
	{
		scanf("%d %d %d", &a, &b, &c); a--, b--;
		int delta = 0;
		for(int i = 0; i < 26; i++)
		{
			int x = get(i, 1, 0, n-1, a, b);
			update(i, 1, 0, n-1, a, b, 0);
			if(c == 1 && x > 0)
				update(i, 1, 0, n-1, a + delta, a + delta + x - 1, 1);
			else if(x > 0)
				update(i, 1, 0, n-1, b - delta - x + 1, b - delta, 1);
			delta += x;
		}
	}
	for(int i = 0; i < n; i++)
		for(int j = 0; j < 26; j++)
			if(get(j, 1, 0, n-1, i, i))
				printf("%c", 'a' + j);
	printf("\n");
}