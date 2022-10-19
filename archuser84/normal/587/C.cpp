#include <iostream>
#include <string.h>
#include <math.h>
#include <memory.h>
#include <map>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#define FAST ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define Loop(x, a, b) for(int x = a; x < b; ++x)
#define LoopR(x, a, b) for(int x = b - 1; x >= a; --x)
#define ll long long
#define Mod1 1000000007
#define Mod2 998244353
using namespace std;

const int inf = 1e9 + 10;
const int N = 100000;
const int logN = 18;
const int MAX = 10;

int n, m;
vector<int> A[N];
int lca[N][logN];
int lcaLive[N][logN][MAX] = {};
int Live[N][MAX] = {};
int living[N] = {};
int d[N];

void merge(int* merd, int a[MAX], int b[MAX])
{
	int p1 = 0;
	int p2 = 0;
	int cnt = 0;
	while (cnt < MAX)
	{
		if(a[p1] == b[p2])
		{
			merd[cnt] = a[p1];
			p1++; p2++;
			cnt++;
		}
		else if (a[p1] < b[p2])
		{
			merd[cnt] = a[p1];
			p1++;
			cnt++;
		}
		else
		{
			merd[cnt] = b[p2];
			p2++;
			cnt++;
		}
	}
}

void dfs(int u, int p, int h)
{
	d[u] = h;
	lca[u][0] = p;
	Loop(i, 1, logN)
		lca[u][i] = lca[lca[u][i - 1]][i - 1];
	merge(lcaLive[u][0], Live[u], Live[p]);
	Loop(i, 1, logN)
		merge(lcaLive[u][i], lcaLive[u][i - 1], lcaLive[lca[u][i - 1]][i - 1]);
	for (auto v : A[u])
	{
		if (v != p)
			dfs(v, u, h + 1);
	}
}

int LCA(int u, int v)
{
	int a = u, b = v;
	if (d[a] > d[b])
		swap(a, b);
	int dif = d[b] - d[a];
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

void getLive(int* live, int u, int up)
{
	int a = u;
	int dif = up;
	Loop(i, 0, MAX)
		live[i] = inf;
	for (int i = 0; dif > 0; i++)
	{
		if (dif & 1)
		{
			int h[MAX]; Loop(i, 0, MAX)h[i] = live[i];
			merge(live, h, lcaLive[a][i]);
			a = lca[a][i];
		}
		dif >>= 1;
	}
}

int main()
{
	int q;
	cin >> n >> m >> q;
	Loop(i, 0, n - 1)
	{
		int u, v;
		cin >> u >> v;
		u--; v--;
		A[u].push_back(v);
		A[v].push_back(u);
	}
	Loop(i, 0, n)
		Loop(j, 0, MAX)
			Live[i][j] = inf;
	Loop(i, 0, m)
	{
		int c;
		cin >> c; c--;
		if(living[c] < MAX)
			Live[c][living[c]++] = i;
	}
	dfs(0, 0, 0);
	while (q--)
	{
		int u, v, a;
		cin >> u >> v >> a;
		u--; v--;
		int x1[MAX], x2[MAX], ans[MAX];
		if (u == v)
		{
			Loop(i, 0, MAX)
				ans[i] = Live[u][i];
		}
		else
		{
			int anc = LCA(u, v);
			getLive(x1, u, d[u] - d[anc]);
			getLive(x2, v, d[v] - d[anc]);
			merge(ans, x1, x2);
		}
		int k = 0;
		LoopR(i,0,a)
			if (ans[i] != inf)
			{
				k = i + 1;
				break;
			}
		cout << k << ' ';
		Loop(i, 0, k)
			cout << ans[i] + 1 << ' ';
		cout << '\n';
	}
}