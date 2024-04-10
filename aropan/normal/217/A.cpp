#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>

template <typename T> T sqr(T x) { return x * x; }
template <typename T> T abs(T x) { return x < 0? -x : x; }

using namespace std;

const int MAXN = 107;

int x[MAXN], y[MAXN];
int f[MAXN], n;

void dfs(int ind)
{
	f[ind] = true;
	for (int i = 0; i < n; i++)
		if (!f[i] && (x[ind] == x[i] || y[ind] == y[i]))
			dfs(i);
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
		freopen("out", "w", stdout);
	#endif
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d %d", &x[i], &y[i]);

	int ans = 0;
	for (int i = 0; i < n; i++)
		if (!f[i])
		{
			ans += 1;
			dfs(i);
		}
	printf("%d\n", ans - 1);
	return 0;
}