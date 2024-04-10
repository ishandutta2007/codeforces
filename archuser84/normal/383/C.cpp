#define _USE_MATH_DEFINES
#define FAST ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#include <bits/stdc++.h>
#define Loop(x, l, r) for(int x = l; x < r; ++x)
#define LoopR(x, l, r) for(int x = r-1; x >= l; --x)
#define all(x) x.begin(), x.end()
#define Kill(x) return cout << x << '\n', 0
#define YN(flag) (flag? "YES": "NO")
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
//#pragma GCC optimize ("O3")
using namespace std;

const int N = 200010;

bool par[N];
int init[N];
vector<int> A[N];
int st[N];
int en[N];

void dfs(int u, int p, int& k, bool c)
{
	par[u] = c;
	st[u] = k++;
	for (int v : A[u])
		if (v != p)
			dfs(v, u, k, !c);
	en[u] = k;
}

int FTree[N + 1] = {};

// k is 0-indexed
void addF(int k, int v)
{
	int i = k + 1;
	while (i > 0)
	{
		FTree[i] += v;
		i -= i & (-i);
	}
}
// k is 0-indexed
int getF(int k, int n)
{
	int ans = 0;
	int i = k + 1;
	while (i <= n)
	{
		ans += FTree[i];
		i += i & (-i);
	}
	return ans;
}

int main()
{
	FAST;
	int n, t;
	cin >> n >> t;
	Loop(i, 0, n)
	{
		cin >> init[i];
	}
	Loop(i, 0, n - 1)
	{
		int u, v;
		cin >> u >> v;
		u--; v--;
		A[u].push_back(v);
		A[v].push_back(u);
	}
	int k = 0;
	dfs(0, -1, k, 0);
	while (t--)
	{
		int ty, x;
		cin >> ty >> x; x--;
		if (ty == 1)
		{
			int val;
			cin >> val;
			addF(en[x] - 1, val * ((!par[x]) * 2 - 1));
			addF(st[x] - 1, -val * ((!par[x]) * 2 - 1));
		}
		else
		{
			cout << getF(st[x], n) * ((!par[x]) * 2 - 1) + init[x] << '\n';
		}
	}
}