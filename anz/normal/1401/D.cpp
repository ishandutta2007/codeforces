#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

const ll MOD = 1e9 + 7;

int n, m;
vector <ll> vec;

vector <int> graph[100001];
ll child[100001];
vector <ll> p;

void DFS(int v, int p)
{
	for (int nv : graph[v])
	{
		if (nv == p) continue;
		DFS(nv, v);

		ll c1 = child[nv] + 1;
		ll c2 = n - c1;
		vec.push_back(c1 * c2);

		child[v] += c1;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			child[i] = 0;
			graph[i].clear();
		}
		p.clear();
		vec.clear();

		for (int i = 0; i < n - 1; i++)
		{
			int u, v; cin >> u >> v;
			graph[u].push_back(v);
			graph[v].push_back(u);
		}

		cin >> m;
		for (int i = 0; i < m; i++)
		{
			ll x; cin >> x;
			p.push_back(x);
		}

		DFS(1, 0);

		sort(vec.rbegin(), vec.rend());
		sort(p.rbegin(), p.rend());

		ll ans = 0;
		int ptr = 0;

		for (int i = 0; i < vec.size(); i++)
		{
			int rm = n - 1 - i;
			ll res = vec[i] % MOD;
			do 
			{
				if (ptr >= p.size()) break;
				res *= p[ptr++];
				res %= MOD;
			} while ((int)p.size() - ptr >= rm);

			ans += res;
			ans %= MOD;
		}

		cout << ans << '\n';
	}
}