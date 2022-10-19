#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define Loop(x, a, b) for(int x = a; x < b; ++x)
#define LoopR(x, a, b) for(int x = b - 1; x >= a; --x)
#define YN(flag) (flag? "YES\n": "NO\n")
#define ll long long
#define Mod1 1000000007
#define Mod2 998244353
#define Bit(x,k) ((x >> k) & 1)
using namespace std;

const int N = 100000;

int n, m;
vector<int> A[N];
int p[N];

int par[N];
int cnt;

int find(int k)
{
	if (par[k] == -1)
		return k;
	par[k] = find(par[k]);
	return par[k];
}
void dsu(int u,int v)
{
	u = find(u);
	v = find(v);
	if (u == v)
		return;
	par[v] = u;
	cnt--;
}

void Solve1()
{
	memset(par, -1, 4 * n);
	cnt = n;
	Loop(i, 0, n)
	{
		int p = 0;
		Loop(j, 0, n)
		{
			if (p < A[i].size() && A[i][p] == j)
				p++;
			else
				dsu(i, j);
		}
	}
	cout << cnt - 1;
}

bool vis[N] = {};
int dfs(int u,int c)
{
	if (vis[u])
		return 0;
	int q = c;
	c++;
	vis[u] = true;
	int p = 0;
	Loop(i, 0, n)
	{
		if (p < A[u].size() && A[u][p] == i)
			p++;
		else
		{
			c += dfs(i, c);
			if (c > 22)
				break;
		}
	}
	return c - q;
}

void Solve2()
{
	Loop(i, 0, n)
	{
		p[i] = i;
	}
	sort(p, p + n, [](auto a, auto b)
		{
			return A[a].size() > A[b].size();
		});
	cnt = 1;
	Loop(i, 0, 23)
		if (!vis[p[i]] && dfs(p[i], 0) <= 22)
			cnt++;
	cout << cnt - 1;
}

int main()
{
	FAST;
	cin >> n >> m;
	Loop(i, 0, m)
	{
		int u, v;
		cin >> u >> v;
		u--; v--;
		A[u].push_back(v);
		A[v].push_back(u);
	}
	Loop(i, 0, n)
	{
		sort(A[i].begin(), A[i].end());
	}
	if (n <= 5000)
		Solve1();
	else
		Solve2();
}