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

const int N = 200000;
const int logN = 18;

vector<int> A[N];
int h[N];
int lca[N][logN];

void dfs(int u, int p, int d)
{
	h[u] = d;
	lca[u][0] = p;
	Loop(i, 1, logN)
		lca[u][i] = lca[lca[u][i - 1]][i - 1];
	for (int v : A[u])
	{
		if (v != p)
			dfs(v, u, d + 1);
	}
}

int LCA(int a, int b)
{
	if (h[a] > h[b])
		swap(a, b);
	int dif = h[b] - h[a];
	for (int i = 0; dif > 0; i++)
	{
		if (dif & 1)
			b = lca[b][i];
		dif >>= 1;
	}
	if (a == b)
		return a;
	LoopR(i, 0, logN)
	{
		if (lca[a][i] != lca[b][i])
		{
			a = lca[a][i];
			b = lca[b][i];
		}
	}
	return lca[a][0];
}

int main()
{
	FAST;
	int n, m;
	cin >> n >> m;
	Loop(i, 0, n - 1)
	{
		int u, v;
		cin >> u >> v;
		u--; v--;
		A[u].push_back(v);
		A[v].push_back(u);
	}
	dfs(0, 0, 0);
	int q[N];
	while (m--)
	{
		int k;
		cin >> k;
		int maax = 0;
		Loop(i, 0, k)
		{
			cin >> q[i]; q[i]--;
			if (h[q[i]] > h[q[maax]])
				maax = i;
		} maax = q[maax];
		bool ans = true;
		Loop(i, 0, k)
		{
			if (q[i] == maax)
				continue;
			if (LCA(lca[q[i]][0], maax) != lca[q[i]][0])
			{
				ans = false;
				break;
			}
		}
		cout << YN(ans);
	}
}