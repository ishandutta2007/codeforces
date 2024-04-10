#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n;
vector <int> graph[200001];
ll ans[200001];

map <int, ll> mp;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int T; cin >> T;
	while (T--)
	{
		mp.clear();

		cin >> n;
		for (int i = 1; i <= n; i++) graph[i].clear();

		int root = -1;
		for (int i = 1; i <= n; i++)
		{
			int a; cin >> a;
			if (i == a) root = i;
			else graph[a].push_back(i);
		}

		bool flag = false;

		ll last = 0;
		mp[root] = 0;

		for (int i = 0; i < n; i++)
		{
			int v; cin >> v;
			if (mp.find(v) == mp.end())
			{
				flag = true;
				continue;
			}

			ll val = mp[v];
			mp.erase(v);

			ll res = 0;
			if (i > 0) res = max(1ll, last + 1 - val);

			ans[v] = res;
			last = val + res;

			for (int nv : graph[v])
			{
				mp.insert({ nv, val + res });
			}
		}

		if (flag)
		{
			cout << "-1\n";
			continue;
		}

		for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
		cout << '\n';
	}
}