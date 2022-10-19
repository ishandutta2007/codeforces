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

const int N = 100000;
const int logN = 18;
int n;
vector<int> A[N];
int lca[N][logN];
int dep[N];

void dfs(int u, int p, int d)
{
	lca[u][0] = p;
	Loop(i, 1, logN)
		lca[u][i] = lca[lca[u][i - 1]][i - 1];
	dep[u] = d;
	for (int v : A[u])
	{
		if (v != p)
			dfs(v, u, d + 1);
	}
}

int path(int u, int v);

int main()
{
	cin >> n;
	Loop(i, 0, n - 1)
	{
		int u, v;
		cin >> u >> v;
		u--; v--;
		A[u].push_back(v);
		A[v].push_back(u);
	}
	dfs(0, 0, 0);
	int q;
	cin >> q;
	while (q--)
	{
		int x, y, a, b, k;
		cin >> x >> y >> a >> b >> k;
		x--; y--; a--; b--;
		int ans = path(a, b);
		int ans2 = path(a, x) + 1 + path(y, b);
		int ans3 = path(a, y) + 1 + path(x, b);
		if ((ans <= k && ans % 2 == k % 2) || (ans2 <= k && ans2 % 2 == k % 2) || (ans3 <= k && ans3 % 2 == k % 2))
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}

int path(int u, int v)
{
	int a = u, b = v;
	if (dep[a] > dep[b])
		swap(a, b);
	int ans = dep[b] - dep[a];
	int dif = dep[b] - dep[a];
	for (int i = 0; dif > 0; i++)
	{
		if (dif & 1)
			b = lca[b][i];
		dif >>= 1;
	}
	if (a == b)
		return ans;

	LoopR(i, 0, logN)
	{
		if (lca[a][i] != lca[b][i])
		{
			a = lca[a][i];
			b = lca[b][i];
			ans += 1 << (i + 1);
		}
	}
	return ans + 2;
}