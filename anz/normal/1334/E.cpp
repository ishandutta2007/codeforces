#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

const ll MOD = 998244353;

ll d, q;
vector <ll> prm;
ll dp_pow[1000];

ll mpow(ll a, ll n)
{
	if (dp_pow[a] != -1) return dp_pow[a];

	if (n == 0) return 1;
	ll res = mpow(a, n / 2);
	res = res * res % MOD;
	if (n % 2) res = res * a % MOD;
	return dp_pow[a] = res;
}

map <ll, ll> mp;
ll dist(ll n)
{
	if (mp.count(n)) return mp[n];
	ll tn = n;

	ll all_cnt = 0;
	vector <ll> v;
	for (ll p : prm)
	{
		ll cnt = 0;
		while (n % p == 0)
		{
			n /= p;
			cnt++;
		}

		all_cnt += cnt;
		if (cnt) v.push_back(cnt);
	}

	ll res = 1;
	for (ll i = 1; i <= all_cnt; i++)
	{
		res *= i;
		res %= MOD;
	}

	for (ll cnt : v)
	{
		for (ll i = 1; i <= cnt; i++)
		{
			res *= mpow(i, MOD - 2);
			res %= MOD;
		}
	}

	return mp[tn] = res;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	memset(dp_pow, -1, sizeof dp_pow);
	cin >> d >> q;
	ll cd = d;
	for (ll i = 2; i * i <= d; i++)
	{
		ll cnt = 0;
		while (cd % i == 0)
		{
			cd /= i;
			cnt++;
		}

		if (cnt) prm.push_back(i);
	}

	if (cd != 1) prm.push_back(cd);

	while (q--)
	{
		ll u, v; cin >> u >> v;
		if (u == v)
		{
			cout << "1\n";
			continue;
		}

		ll g = gcd(u, v);

		ll ans = (dist(u / g) * dist(v / g)) % MOD;
		cout << ans << '\n';
	}
}