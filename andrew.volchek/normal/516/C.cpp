#include <iostream>
#include <cstdio>
#include <string>
#include <string.h>
#include <queue>
#include <math.h>
#include <cmath>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <bitset>
#include <ctype.h>
#include <cassert>
#include <stack>
#include <fstream>
#include <unordered_map>
#include <ctime>

using namespace std;

#define snd second
#define fst first
#define mp make_pair
#define ll long long
#define ull unsigned long long
#define ld long double
#define pb push_back
#define left _left
#define right _right

const ld pi = 3.14159265359;

template < typename T > T abs(T x)
{
    return x > 0 ? x : -x;
}

template < typename T > T sqr(T x)
{
	return x * x;
}

struct data
{
	ll p, m, ans;
	data()
	{
		ans = p = m = -1e18;
	}
	
	data operator + (const data &x)
	{
		data res;
		res.ans = max(max(ans, x.ans), m + x.p);
		res.p = max(p, x.p);
		res.m = max(m, x.m);
		return res;
	}
};

const int maxn = 200005;

data t[maxn * 4];

ll d[maxn], h[maxn];

void build(int v, int l, int r)
{
	if (l == r)
	{
		t[v].m = 2LL * h[l] - d[l];
		t[v].p = 2LL * h[l] + d[l];
		return;
	}
	
	int c = (l + r) >> 1;
	
	build(2 * v, l, c);
	build(2 * v + 1, c + 1, r);
	
	t[v] = t[2 * v] + t[2 * v + 1];
}

data get(int v, int l, int r, int i, int j)
{
	if (i <= l && r <= j)
		return t[v];
		
	data res;
	int c = (l + r) >> 1;
	
	if (i <= c)
		res = res + get(2 * v, l, c, i, j);
	if (c < j)
		res = res + get(2 * v + 1, c + 1, r, i, j);
		
	return res;
}

int main()
{
	//srand(time(NULL));
	//gen();
	//freopen("a.in", "r", stdin);
	
	int n, m;
	scanf("%d %d", &n, &m);
	
	for (int i = 0; i < n; i++)
	{
		int x;
		scanf("%d", &x);
		d[1 + i] = d[1 + n + i] = x;
	}
	
	for (int i = 0; i < n; i++)
	{
		int x;
		scanf("%d", &x);
		h[i] = h[n + i] = x;
	}
	
	for (int i = 1; i < 2 * n; i++)
	{
		d[i] += d[i - 1];
	}
	
	build(1, 0, 2 * n - 1);
	
	
	for (int i = 0; i < m; i++)
	{
		int u, v;
		scanf("%d %d", &u, &v);
		u--;
		v--;
		
		if (u <= v)
		{
			auto res = get(1, 0, 2 * n - 1, v + 1, n + u - 1);
			printf("%lld\n", res.ans);
		}
		else
		{
			auto res = get(1, 0, 2 * n - 1, v + 1, u - 1);
			printf("%lld\n", res.ans);
		}
		
	}
	
	
	return 0;
}