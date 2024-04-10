#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <list>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cassert>
#include <ctime>
#include <cctype>
#include <cstring>
#include <bitset>
#include <algorithm>

using namespace std;

#define ll long long
#define ull unsigned long long
#define ld long double
#define fst first
#define snd second
#define pb push_back
#define mp make_pair
#define y0 _y0
#define y1 _y1

template < typename T > T abs(T x)
{
	return x > 0 ? x : -x;
}

const int maxn = 200005;

vector < int > g[maxn];
vector < int > askQ[maxn];
vector < pair < int, int > > addQ[maxn];
int ans[maxn];

int tree1[maxn], tree2[maxn];

int sum(int r, int *tree)
{
	int res = 0;
	while (r >= 0)
	{
		res += tree[r];
		r = (r & (r + 1)) - 1;
	}
	return res;
}

void modify(int i, int val, int *tree)
{
	while (i < maxn)
	{
		tree[i] += val;
		i = i | (i + 1);
	}
}

void dfs(int v, int p, int *addTree, int *subTree)
{
	for (int i = 0; i < addQ[v].size(); i++)
	{
		int val = addQ[v][i].fst;
		int t = addQ[v][i].snd;
		modify(t, val, addTree);
		//modify(t, val, subTree);
	}
	
	for (int i = 0; i < askQ[v].size(); i++)
	{
		int t = askQ[v][i];
		int res = sum(t, addTree) - sum(t, subTree);
		ans[t] += res;
	}
	
	for (int i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i];
		
		if (to == p)
			continue;
			
		dfs(to, v, subTree, addTree);
	}
	
	for (int i = 0; i < addQ[v].size(); i++)
	{
		int val = addQ[v][i].fst;
		int t = addQ[v][i].snd;
		modify(t, -val, addTree);
		//modify(t, -val, subTree);
	}
}

vector < int > ask;
int a[maxn];

int main()
{
	//freopen("a.in", "r", stdin);
	int n, m;
	scanf("%d %d", &n, &m);
	
	for (int i = 1; i <= n; i++)
		scanf("%d", a + i);
	
	for (int i = 0; i < n-1; i++)
	{
		int u, v;
		scanf("%d %d", &u, &v);
		g[u].pb(v);
		g[v].pb(u);
	}
	
	for (int i = 0; i < m; i++)
	{
		int type;
		scanf("%d", &type);
		if (type == 1)
		{
			int x, val;
			scanf("%d %d", &x, &val);
			addQ[x].pb(mp(val, i));
		}
		else
		{
			int x;
			scanf("%d", &x);
			ask.pb(i);
			askQ[x].pb(i);
			ans[i] += a[x];
		}
	}
	
	dfs(1, -1, tree1, tree2);
	
	for (int i = 0; i < ask.size(); i++)
	{
		printf("%d\n", ans[ask[i]]);
	}
	
	return 0;
}