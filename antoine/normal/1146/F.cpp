#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

const int MxN = (int) 2e5 + 9;
const int mod = 998244353;
vector<int> adj[MxN + 9];

array<ll, 3> dfs(const int u) {
	if (adj[u].empty())
		return {0, 0, 1};

	array<ll, 3> res;
	res.fill(0);

	vector<array<ll, 3>> v;
	const int k = (int) adj[u].size();
	for (const int x : adj[u])
		v.push_back(dfs(x));

	res[0] = 1;
	for (const array<ll, 3> &a : v)
		(res[0] *= a[0] + a[2]) %= mod;

	{
		static ll L[MxN + 9], R[MxN + 9];
		for (int i = 0; i < k; ++i)
			L[i] = (i == 0 ? 1 : L[i - 1]) * (v[i][0] + v[i][2]) % mod;
		for (int i = k - 1; i >= 0; --i)
			R[i] = (i == k - 1 ? 1 : R[i + 1]) * (v[i][0] + v[i][2]) % mod;

		for (int i = 0; i < k; ++i) {
			res[1] += (i == 0 ? 1 : L[i - 1]) * (v[i][1] + v[i][2]) % mod * (i == k - 1 ? 1 : R[i + 1]) % mod;
		}
		res[1] %= mod;
	}

	{
		static ll dp[MxN + 9][3];
		for (int i = k; i >= 0; --i)
			for (int j = 0; j <= 2; ++j) {
				ll &res = dp[i][j];
				if (i == k)
					res = j == 0;
				else
					res = (v[i][0] + v[i][2]) * dp[i + 1][j] + (v[i][1] + v[i][2]) * dp[i + 1][max(0, j - 1)];
				res %= mod;
			}
		res[2] = dp[0][2];
	}
	return res;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	int n;
	cin >> n;
	for (int i = 2; i <= n; ++i) {
		int p;
		cin >> p;
		adj[p].push_back(i);
	}

	array<ll, 3> res = dfs(1);
	ll ans = res[0] + res[2];
	cout << (ans % mod + mod) % mod;
	return 0;
}