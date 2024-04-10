#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector < pair <int, int> > a, v;

const int MAXN = 100007;
const int MAXM = MAXN * 2;

int last[MAXN];
int next[MAXM], dest[MAXM];
int f[MAXN];
int n;

void dfs(int x, int p = 0)
{
	for (int i = last[x]; i; i = next[i])
	{
		int y = dest[i];
		if (y == p)
			continue;
		a.push_back(make_pair(x, y));
		if (f[x])
			v.push_back(make_pair(f[x], a.size()));
		f[x] = f[y] = a.size();
		dfs(y, x);
	}
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
		freopen("out", "w", stdout);
	#endif
	scanf("%d", &n);
	for (int i = 1; i < n; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		dest[i] = y;
		next[i] = last[x];
		last[x] = i;

		dest[i + n] = x;
		next[i + n] = last[y];
		last[y] = i + n;
	}
	
	dfs(1);
	
	printf("%d\n", (int)a.size());
	for (int i = 0; i < (int)a.size(); i++)
		printf("2 %d %d\n", a[i].first, a[i].second);
	for (int i = 0; i < (int)v.size(); i++)
		printf("%d %d\n", v[i].first, v[i].second);
	return 0;
}