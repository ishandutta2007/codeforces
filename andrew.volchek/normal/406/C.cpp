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

template < typename T > T abs(T x)
{
    return x > 0 ? x : -x;
}

const int maxn = 100005;

int deg[maxn];
int inv[maxn];

vector < pair < int, int > > g[maxn];
vector < pair < int, int > > edges;

int used[maxn];

int dfs(int v)
{
	used[v] = 1;
	int res = deg[v] & 1;
	
	for (int i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i].fst;
		int ee = g[v][i].snd;
		
		if (used[to])
			continue;
			
		int curr = dfs(to);
		if (curr)
			inv[ee] = 1;
		res += curr;
	}
	
	return res & 1;
}

vector < int > ans[maxn];

int main(int argc, char *argv[])
{
    //freopen("a.in", "r", stdin);
	int n, m;
	scanf("%d %d", &n, &m);
	
	for (int i = 0; i < m; i++)
	{
		int u, v;
		scanf("%d %d", &u, &v);
		deg[u]++;
		g[u].pb(mp(v, edges.size()));
		g[v].pb(mp(u, edges.size()));
		edges.pb(mp(u, v));
	}
	
	if (m & 1)
	{
		puts("No solution");
		return 0;
	}
	
	dfs(1);
	
	for (int i = 0; i < m; i++)
	{
		if (inv[i])
		{
			ans[edges[i].snd].pb(edges[i].fst);
		}
		else
		{
			ans[edges[i].fst].pb(edges[i].snd);
		}
	}
	
	for (int i = 1; i <= n; i++)
	{
		assert(ans[i].size() % 2 == 0);
		for (int j = 0; j < ans[i].size(); j += 2)
		{
			printf("%d %d %d\n", ans[i][j], i, ans[i][j + 1]);
		}
	}
	
	return 0;
}