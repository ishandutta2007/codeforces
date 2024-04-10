#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int dist[1001];

int n, k;
int b[1001];
int c[1001];

int dp[1001][12001];
int solve(int idx, int k)
{
	if (idx >= n) return 0;

	int& ret = dp[idx][k];
	if (ret != -1) return ret;

	ret = solve(idx + 1, k);
	if (k >= dist[b[idx]])
	{
		int res = solve(idx + 1, k - dist[b[idx]]) + c[idx];
		ret = max(ret, res);
	}

	return ret;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	memset(dist, -1, sizeof dist);
	dist[1] = 0;
	queue <int> q; q.push(1);

	while (!q.empty())
	{
		int v = q.front(); q.pop();
		for (int x = 1; x <= v; x++)
		{
			int nv = v + v / x;
			if (nv > 1000) continue;
			if (dist[nv] != -1) continue;
			dist[nv] = dist[v] + 1;
			q.push(nv);
		}
	}

	int T; cin >> T;
	while (T--)
	{
		cin >> n >> k;
		for (int i = 0; i < n; i++) cin >> b[i];
		for (int i = 0; i < n; i++) cin >> c[i];

		memset(dp, -1, sizeof dp);
		k = min(k, 12000);
		cout << solve(0, k) << '\n';
	}
}