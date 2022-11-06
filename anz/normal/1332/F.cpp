#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

const int MOD = 998244353;
int n;
vector <int> graph[300001];

ll dp[300001][3];
void solve(int v, int p)
{
	dp[v][0] = dp[v][1] = dp[v][2] = 1;
	for (auto nv : graph[v])
	{
		if (nv == p) continue;
		solve(nv, v);

		ll res = 0;
		res = dp[nv][0] * 2 % MOD;
		res += dp[nv][1] * 2 % MOD; res %= MOD;
		res += MOD - dp[nv][2]; res %= MOD;

		dp[v][0] *= res; dp[v][0] %= MOD;

		res = dp[nv][0] * 2 % MOD;
		res += dp[nv][1]; res %= MOD;
		res += MOD - dp[nv][2]; res %= MOD;

		dp[v][1] *= res; dp[v][1] %= MOD;

		res = dp[nv][0];
		res += dp[nv][1]; res %= MOD;
		res += MOD - dp[nv][2]; res %= MOD;

		dp[v][2] *= res; dp[v][2] %= MOD;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n;
	for (int i = 0; i < n - 1; i++)
	{
		int u, v; cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	solve(1, 0);

	cout << (dp[1][0] + dp[1][1] + MOD - dp[1][2] - 1) % MOD;
}