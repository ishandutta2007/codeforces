#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

const ll INF = 2e9;

int n[3];
vector <ll> w[3];

ll calc(ll r, ll g, ll b)
{
	return (r - g) * (r - g) + (g - b) * (g - b) + (b - r) * (b - r);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		for (int k = 0; k < 3; k++) w[k].clear();
		for (int k = 0; k < 3; k++) cin >> n[k];
		for (int k = 0; k < 3; k++)
		{
			for (int i = 0; i < n[k]; i++)
			{
				ll x; cin >> x;
				w[k].push_back(x);
			}

			sort(w[k].begin(), w[k].end());
		}

		ll ans = numeric_limits<ll>::max();
		for (int k = 0; k < 3; k++)
		{
			vector <ll>& r = w[k];
			vector <ll>& g = w[(k + 1) % 3];
			vector <ll>& b = w[(k + 2) % 3];

			for (int i = 0; i < n[k]; i++)
			{
				ll cr = r[i];
				
				ll cg[2] = { INF, INF };
				auto it = lower_bound(g.begin(), g.end(), cr);
				if (it == g.end())
					cg[0] = g.back();
				else
				{
					cg[0] = *it;
					if (it != g.begin()) cg[1] = *prev(it);
				}

				ll cb[2] = { INF, INF };
				it = lower_bound(b.begin(), b.end(), cr);
				if (it == b.end())
					cb[0] = b.back();
				else
				{
					cb[0] = *it;
					if (it != b.begin()) cb[1] = *prev(it);
				}

				for (int u = 0; u < 2; u++) for (int v = 0; v < 2; v++)
				{
					ll res = calc(cr, cg[u], cb[v]);
					ans = min(ans, res);
				}
			}
		}

		cout << ans << '\n';
	}
}