#include <cassert>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
#include <ctime>

using namespace std;

template <typename T> T sqr(T x) { return x * x; }
template <typename T> T gcd(T a, T b) { return b == 0? a : gcd(b, a % b); }
template <typename T> T abs(T x) { return x < 0? -x : x; }

const int MAXK = 31;

int f[MAXK];
int g[MAXK];
int ans;
int n, m;

int main()
{
	#ifdef MJUDGE
		assert(freopen("in", "r", stdin));
		assert(freopen("out", "w", stdout));
	#endif
	
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		int x;
		scanf("%d", &x);
		for (int j = 0; j < MAXK; j++)
			if ((1 << j) & x)
				f[j] += 1;
	}
	for (int i = 0; i < m; i++)
	{
		int x;
		scanf("%d", &x);
		if (x >= MAXK)
			continue;
		g[x] += 1;
	}
	
	ans = 0;
	for (int i = 0; i < MAXK; i++)
	{
		long long x = f[i] * (long long)(1 << i);
		for (int j = 0; j <= i; j++)
		{
			long long v = min(x, (long long)g[j]);
			ans += v;
			g[j] -= v;
			x = (x - v) / 2;
		}
	}
	printf("%d\n", ans);
	fprintf(stderr, "Time execute: %.3lfs\n", clock() / (double)CLOCKS_PER_SEC);
	return 0;
}