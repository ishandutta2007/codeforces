#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

const int MAXN = 100007;
const int INF = 2e+9;

struct robot
{
	int c, f;
	robot(int c = 0, int f = 0, int l = 0) : c(c), f(f) { }	
};

robot a[MAXN];
int n, d, S;
int res, ans;

bool opr_sort(const robot &a, const robot &b)
{
	return	a.c > b.c || (a.c == b.c && a.f > b.f);
}

bool opr_sort_sec(const robot &a, const robot &b)
{
	return a.f < b.f;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
		freopen("out", "w", stdout);
	#endif
	scanf("%d %d %d", &n, &d, &S);
	for (int i = 0; i < n; i++)
	{
		int l;
		scanf("%d %d %d", &a[i].c, &a[i].f, &l);
		if (l < d)
			a[i].f = INF;
	}
	
	sort(a, a + n, opr_sort);
	for (int i = 0; i <= n; i++)
	{
		if (i == n || a[i].c == 0)
		{
			sort(a, a + i, opr_sort_sec);
			break;
		}
	}
	
	res = 0;
	ans = S;
	if (a[0].f <= S && a[0].c)
	{
		int s = S - a[0].f;
		int c = a[0].c;
		res = 1;
		int I = 1;
		while (I < n && c)
		{
			c -= 1;
			c += a[I].c;
			res++;
			I++;
		}
		
		for (int i = 1, j = I, k = n - 1; j <= k; )
		{
			if (i < I && a[i].f < a[k].f)
			{
				if (a[i].f > s) break;
				s -= a[i].f;
				i++;
				j++;
				res++;
			}
			else
			{
				if (a[k].f > s) break;
				s -= a[k].f;
				k--;
				res++;
			}
		}
		ans = s;
	}
	
	sort(a, a + n, opr_sort_sec);
	int s = S;
	int x = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i].f <= s)
		{
			s -= a[i].f;
			x++;
		}
	}
	
	if (make_pair(res, ans) < make_pair(x, s))
	{
		res = x;
		ans = s;
	}
	
	printf("%d %d\n", res, S - ans);	
	return 0;
}