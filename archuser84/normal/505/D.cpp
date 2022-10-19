#include <iostream>
#include <string>
#include <math.h>
#include <memory.h>
#include <map>
#include <algorithm>
#include <vector>
#define FAST ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define Loop(x, a, b) for(int x = a; x < b; ++x)
#define LoopR(x, a, b) for(int x = b - 1; x >= a; --x)
#define ll long long
#define Mod1 1000000007
#define Mod2 998244353
using namespace std;

int ANS = 0;

int n, m;
vector<int> G[100000], T[100000];
vector<int> back[100000];
int lis[100000];
int liss = 0;
bool vis[100000];
bool vis3[100000] = { 0 };
int dfs3(int u)
{
	vis3[u] = true;
	int ans = 1;
	for (int v : back[u])
		if (!vis3[v])
			ans += dfs3(v);
	return ans;
}
void dfs(int u)
{
	vis[u] = true;
	for (int v : G[u])
		if (!vis[v])
			dfs(v);
	lis[liss++] = u;
}
void dfs2(int u)
{
	vis[u] = true;
	for (int v : T[u])
		if (!vis[v])
		{
			if (!vis3[v])
				ANS += dfs3(v);
			dfs2(v);
		}
}

int main()
{
	cin >> n >> m;
	Loop(i, 0, m)
	{
		int u, v;
		cin >> u >> v;
		u--; v--;
		G[u].push_back(v);
		T[v].push_back(u);
		back[u].push_back(v);
		back[v].push_back(u);
	}
	memset(vis, 0, n);
	Loop(u, 0, n)
	{
		if (!vis[u])
			dfs(u);
	}
	memset(vis, 0, n);
	while(liss > 0)
	{
		int u = lis[--liss];
		if (!vis[u])
			dfs2(u);
	}
	Loop(u, 0, n)
	{
		if (!vis3[u])
			ANS += dfs3(u) - 1;
	}
	cout << ANS << '\n';
}