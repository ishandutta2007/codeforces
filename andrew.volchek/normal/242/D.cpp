#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <string>

using namespace std;

#define pb push_back
#define mp make_pair
#define ll long long
#define fst first
#define snd second

int n, m;
const int maxn = 100005;

vector < int > g[maxn];
int bad[maxn];
int sum[maxn];
int state[maxn];

void dfs(int v)
{
	state[v] = 1;
	sum[v]++;
	
	for (int i = 0; i < g[v].size(); i++)
		sum[g[v][i]]++;
		
	for (int i = 0; i < g[v].size(); i++)
		if (sum[g[v][i]] == bad[g[v][i]])
			dfs(g[v][i]);
}

int main(int argc, char **argv)
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		g[a].pb(b);
		g[b].pb(a);
	}
	
	for (int i = 1; i <= n; i++)
		scanf("%d", bad + i);
	
	for (int i = 1; i <= n; i++)
		if (sum[i] == bad[i])
			dfs(i);
	
	vector < int > ans;
	for (int i = 1; i <= n; i++)
		if (state[i])
			ans.pb(i);
	
	printf("%d\n", ans.size());
	for (int i = 0; i < ans.size(); i++)
	{
		if (i)
			printf(" ");
		printf("%d", ans[i]);
	}
	
	return 0;
}