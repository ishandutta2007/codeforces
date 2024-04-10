#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

const int N = 300001;

int q;
ll a[N], c[N];

int lv[N];
ll spt[20][N];

int main()
{
	ios::sync_with_stdio(0);
	//cin.tie(0), cout.tie(0);

	cin >> q >> a[0] >> c[0];
	for (int v = 1; v <= q; v++)
	{
		int t; cin >> t;
		if (t == 1)
		{
			int p; cin >> p >> a[v] >> c[v];
			lv[v] = lv[p] + 1;
			spt[0][v] = p;
			for (int k = 1; k < 20; k++) spt[k][v] = spt[k - 1][spt[k - 1][v]];
		}
		else
		{
			ll v, w; cin >> v >> w;
			ll gold = 0, cost = 0;

			ll pv = v;
			for (int k = 19; k >= 0; k--)
			{
				if (a[spt[k][pv]] > 0) pv = spt[k][pv];
			}

			int pl = lv[pv];
			int cl = lv[v];

			while (w)
			{
				ll res = min(w, a[pv]);
				gold += res, cost += res * c[pv];

				a[pv] -= res, w -= res;

				if (pv != v)
				{
					++pl;
					pv = v;
					int d = cl - pl;
					for (int k = 19; k >= 0; k--)
					{
						if (d & (1 << k)) pv = spt[k][pv];
					}
				}
				else break;
			}

			cout << gold << ' ' << cost << endl;
		}
	}
}