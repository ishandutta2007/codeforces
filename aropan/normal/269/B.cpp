#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

template <typename T> T sqr(T x) { return x * x; }
template <typename T> T abs(T x) { return x < 0? -x : x; }


const int MAXN = 5005;

int f[MAXN];

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
		freopen("out", "w", stdout);
	#endif
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		int x;
		double p;
		scanf("%d %lf", &x, &p);

		for (int j = 1; j <= m; j++)
			if (j != x)
				++f[j];
		for (int j = 2; j <= m; j++)
			f[j] = min(f[j], f[j - 1]);
	}

	printf("%d\n", f[m]);
	return 0;
}