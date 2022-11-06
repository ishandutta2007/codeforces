#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

const ll MOD = 998244353;

int n, k;
vector <int> graph[5001];
ll dp[5001][5001];
// dp[v][len] : v , v   len  
int h[5001];
ll tmp[5001];

void DFS(int v, int p)
{
	dp[v][0] = 1;
	h[v] = 1;

	ll ans = 0;

	for (int nv : graph[v])
	{
		if (nv == p) continue;
		
		DFS(nv, v);
		memset(tmp, 0, sizeof tmp);

		for (int i = 0; i <= h[v]; i++) for (int j = 0; j <= h[nv]; j++)
		{
			if (i + j + 1 <= k)
			{
				tmp[max(i, j + 1)] += dp[v][i] * dp[nv][j] % MOD;
				tmp[max(i, j + 1)] %= MOD;
			}

			if (i <= k && j <= k)
			{
				tmp[i] += dp[v][i] * dp[nv][j] % MOD;
				tmp[i] %= MOD;
			}
		}

		h[v] = max(h[v], h[nv] + 1);
		memcpy(dp[v], tmp, sizeof tmp);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> k;
	for (int i = 0; i < n - 1; i++)
	{
		int u, v; cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	DFS(1, 0);

	ll ans = 0;
	for (int i = 0; i <= k; i++)
	{
		ans += dp[1][i];
		ans %= MOD;
	}

	cout << ans;
}