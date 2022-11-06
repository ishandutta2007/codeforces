#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

const ll MOD = 1e9 + 7;

ll n, k;
vector <int> graph[101];

ll cnt[101][101];

void DFS(int v, int p)
{
	cnt[v][0] = 1;
	for (int nv : graph[v])
	{
		if (nv == p) continue;
		DFS(nv, v);

		for (int i = 0; i < 100; i++)
			cnt[v][i + 1] += cnt[nv][i];
	}
}

ll DFS2(int v, int p)
{
	ll res = 0;

	for (int i = 0; i < 100; i++)
	{
		ll cur[101] = { 1, };
		for (int nv : graph[v])
		{
			ll nxt[101];
			memcpy(nxt, cur, sizeof cur);

			for (int j = 1; j < 100; j++)
			{
				nxt[j] += cur[j - 1] * cnt[nv][i] % MOD;
				nxt[j] %= MOD;
			}

			memcpy(cur, nxt, sizeof cur);
		}

		res += cur[k];
		res %= MOD;
	}

	for (int nv : graph[v])
	{
		if (nv == p) continue;
		for (int i = 0; i < 100; i++)
		{
			cnt[v][i + 1] -= cnt[nv][i];
		}
		for (int i = 0; i < 100; i++)
		{
			cnt[nv][i + 1] += cnt[v][i];
		}

		res += DFS2(nv, v);
		res %= MOD;

		for (int i = 0; i < 100; i++)
		{
			cnt[nv][i + 1] -= cnt[v][i];
		}
		for (int i = 0; i < 100; i++)
		{
			cnt[v][i + 1] += cnt[nv][i];
		}
	}

	return res;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int T; cin >> T;
	while (T--)
	{
		cin >> n >> k;
		for (int i = 1; i <= n; i++) graph[i].clear();
		memset(cnt, 0, sizeof cnt);

		for (int i = 0; i < n - 1; i++)
		{
			int u, v; cin >> u >> v;
			graph[u].push_back(v);
			graph[v].push_back(u);
		}

		if (k == 2)
		{
			cout << n * (n - 1) / 2 % MOD << '\n';
			continue;
		}


		DFS(1, 0);
		ll ans = DFS2(1, 0);

		cout << ans << '\n';
	}
}