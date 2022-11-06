#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

const ll MOD = 1e9 + 7;
const ll INF = 987654321987654321;

ll mpow(ll n, ll a)
{
	if (a == 0) return 1;
	ll res = mpow(n, a / 2);
	res = res * res % MOD;
	if (a % 2) res = res * n % MOD;
	return res;
}

ll n, p;
ll k[1000001];

map <ll, ll> dif;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		dif.clear();

		cin >> n >> p;
		for (int i = 0; i < n; i++)
		{
			cin >> k[i];
		}

		if (p == 1)
		{
			cout << n % 2 << '\n';
			continue;
		}

		sort(k, k + n);

		vector <ll> add;
		for (int i = n - 1; i >= 0; i--)
		{
			if (dif.empty())
			{
				dif[k[i]] = 1;
				continue;
			}

			auto it = dif.lower_bound(k[i]);

			if (it->first != k[i])
			{
				ll tmp = 1;

				bool flag = false;
				for (int j = it->first - 1; j >= k[i]; j--)
				{
					tmp *= p;
					if (tmp > n)
					{
						flag = true;
						break;
					}
				}

				if (flag)
				{
					dif[k[i]] = INF;
					
					ll res = (mpow(p, it->first) - mpow(p, k[i]) + MOD) % MOD;
					add.push_back(res);
				}
				else
				{
					dif[k[i]] = tmp - 1;
				}
			}

			if (it->second != INF)
			{
				if (--it->second == 0)
				{
					dif.erase(it);
				}
			}
			else
			{
				add.push_back(MOD - mpow(p, it->first));
			}
		}

		ll ans = 0;
		for (auto it : dif)
		{
			if (it.second == INF) continue;
			ans += mpow(p, it.first) * it.second % MOD;
			ans %= MOD;
		}

		for (ll x : add)
		{
			ans += x;
			ans %= MOD;
		}

		cout << ans << '\n';
	}
}