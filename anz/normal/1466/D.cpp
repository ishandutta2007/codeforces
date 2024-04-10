#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<ll>> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
const ll N = 200002;
vector<ll> g[N];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	ll t; cin >> t;
	while (t--)
	{
		ll n; cin >> n;
		vector<ll> a(n + 1);
		for (ll i = 1; i <= n; i++)
		{
			cin >> a[i];
			g[i].clear();
		}
		for (ll i = 0; i < n - 1; i++)
		{
			ll u, v; cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}

		ll ans = 0;

		multiset <pll> st;
		for (ll i = 1; i <= n; i++)
		{
			if (g[i].size() - 1 > 0)
				st.insert({ -a[i], g[i].size() - 1 });
			ans += a[i];
		}

		cout << ans << " ";

		for (ll i = 0; i < n - 2; i++)
		{
			auto it = st.begin();
			ll val = -it->first;
			ll idx = it->second;
			st.erase(it);

			ans += val; idx--;
			if (idx > 0)
				st.insert({ -val, idx });

			cout << ans << " ";
		}

		cout << "\n";
	}
}