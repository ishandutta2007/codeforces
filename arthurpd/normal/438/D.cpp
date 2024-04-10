#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;

#define left(i) ((i)<<1)
#define right(i) (((i)<<1)+1)

long long maior[412345];
long long sum[412345];
int a[112345];

long long add(long long x, long long y)
{
	return x+y;
}

long long comp(long long x, long long y)
{
	if(a[x] > a[y])
		return x;
	return y;
}

void change(long long val[], long long join(long long, long long), int id, int l, int r, int pos, int x)
{
	if(l == r)
		val[id] = x;
	else
	{
		int mid = (l+r)/2;
		if(pos <= mid)
			change(val, join, left(id), l, mid, pos, x);
		else
			change(val, join, right(id), mid+1, r, pos, x);
		val[id] = join(val[left(id)], val[right(id)]);
	}
}

long long get(long long val[], long long join(long long, long long), int id, int l, int r, int a, int b)
{
	if(l == a && r == b)
		return val[id];
	else
	{
		int mid = (l+r)/2;
		if(b <= mid)
			return get(val, join, left(id), l, mid, a, b);
		else if(a > mid)
			return get(val, join, right(id), mid+1, r, a, b);
		else
			return join(get(val, join, left(id), l, mid, a, mid), get(val, join, right(id), mid+1, r, mid+1, b));
	}
}

int
main(void)
{
	int n, q, type, l, r, x;
	scanf("%d %d", &n, &q);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		change(sum, add, 1, 1, n, i, a[i]);
		change(maior, comp, 1, 1, n, i, i);
	}
	while(q--)
	{
		scanf("%d", &type);
		if(type == 1)
		{
			scanf("%d %d", &l, &r);
			cout << get(sum, add, 1, 1, n, l, r)<< '\n';
		}
		else if(type == 2)
		{
			scanf("%d %d %d", &l, &r, &x);
			int pos;
			while(a[pos = get(maior, comp, 1, 1, n, l, r)] >= x)
			{
				a[pos] %= x;
				change(sum, add, 1, 1, n, pos, a[pos]);
				change(maior, comp, 1, 1, n, pos, pos);
			}
		}
		else
		{
			scanf("%d %d", &l, &x);
			a[l] = x;
			change(sum, add, 1, 1, n, l, a[l]);
			change(maior, comp, 1, 1, n, l, l);
		}
	}
	return 0;
}