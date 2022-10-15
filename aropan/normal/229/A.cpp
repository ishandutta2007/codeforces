#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

template <typename T> T sqr(T x) { return x * x; }
template <typename T> T abs(T x) { return x < 0? -x : x; }


const int INF = (int)1e+9;
const int MAXN = 100007;

char s[MAXN];
int n, m;
int f[MAXN], g[MAXN];

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
		freopen("out", "w", stdout);
	#endif
	int n, m;
	scanf("%d %d\n", &n, &m);
	for (int i = 0; i < n; i++)
	{
		gets(s);
		for (int j = 0; j < m; j++)
			g[j] = INF;
			
		int x;
		
		x = INF;
		for (int j = 0; j < m + m; j++, x++)
		{
			if (s[j % m] == '1') x = 0;
			g[j % m] = min(g[j % m], x);
		}

		x = INF;
		for (int j = m + m - 1; j >= 0; j--, x++)
		{
			if (s[j % m] == '1') x = 0;
			g[j % m] = min(g[j % m], x);
		}
		
		if (x > INF)
		{
			puts("-1");
			return 0;
		}
		
		
		for (int i = 0; i < m; i++)
			f[i] += g[i];
	}
	printf("%d\n", *min_element(f, f + m));
	return 0;
}