#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define Loop(x, a, b) for(int x = a; x < b; ++x)
#define LoopR(x, a, b) for(int x = b - 1; x >= a; --x)
#define YN(flag) (flag? "YES": "NO")
#define all(x) x.begin(),x.end()
#define ll long long
#define pii pair<int,int>
#define Mod1 1000000007
#define Mod2 998244353
#define Bit(x,k) ((x >> k) & 1)
using namespace std;

const int N = 200010;
vector<int> A[N];
ll a[N];
bool b[N];
bool c[N];
ll wn[N] = {};
int n;
int wc = 0;

ll dfs1(int u, int p, ll miin)
{
	a[u] = min(a[u], miin);
	miin = a[u];
	wn[u] += c[u] - b[u];
	for (int v : A[u])
		if (v != p)
			wn[u] += dfs1(v, u, miin);
	return wn[u];
}

ll dfs2(int u, int p)
{
	ll ans = 0;
	for (int v : A[u])
		if (v != p)
			ans += a[u] * abs(wn[v]);
	if (b[u] != c[u])
		ans += a[u];
	ans -= a[u] * abs(wn[u]);
	for (int v : A[u])
		if (v != p)
			ans += dfs2(v,u);
	return ans;
}

int main()
{
	FAST;
	cin >> n;
	Loop(i, 0, n)
	{
		cin >> a[i] >> b[i] >> c[i];
		wc += c[i] - b[i];
	}
	Loop(i, 0, n - 1)
	{
		int u, v;
		cin >> u >> v;
		u--; v--;
		A[u].push_back(v);
		A[v].push_back(u);
	}
	if (wc)
	{
		cout << "-1\n";
		return 0;
	}
	dfs1(0, -1, (1LL << 60));
	cout << dfs2(0, -1) << '\n';
}