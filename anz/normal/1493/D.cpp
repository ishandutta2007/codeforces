#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll MOD = 1e9 + 7;

ll n, q;
string s;

vector <ll> prime;
int ett[200001];

map <ll, ll> mp[18000];
set <pll> st[18000];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	for (int i = 2; i <= 200000; i++)
	{
		if (ett[i] == 0)
		{
			for (int j = i + i; j <= 200000; j += i) ett[j] = 1;
			prime.push_back(i);
		}
	}

	cin >> n >> q;

	for (int i = 1; i <= n; i++)
	{
		ll a; cin >> a;
		for (int j = 0; j < prime.size() && prime[j] * prime[j] <= a; j++)
		{
			if (a % prime[j] == 0)
			{
				ll cnt = 0;
				while (a % prime[j] == 0)
				{
					a /= prime[j];
					cnt++;
				}

				st[j].insert({ cnt, i });
				mp[j][i] = cnt;
			}
		}

		if (a > 1)
		{
			int idx = lower_bound(prime.begin(), prime.end(), a) - prime.begin();
			st[idx].insert({ 1, i });
			mp[idx][i] = 1;
		}
	}

	ll ans = 1;
	for (int i = 0; i < prime.size(); i++)
	{
		if (st[i].size() < n) continue;
		ll cnt = st[i].begin()->first;

		for (int j = 0; j < cnt; j++)
		{
			ans *= prime[i];
			ans %= MOD;
		}
	}

	while (q--)
	{
		ll i, x; cin >> i >> x;
		for (int j = 0; j < prime.size() && prime[j] * prime[j] <= x; j++)
		{
			if (x % prime[j] == 0)
			{
				ll cnt = 0;
				while (x % prime[j] == 0)
				{
					x /= prime[j];
					cnt++;
				}

				ll last = 0;
				if (st[j].size() >= n) last = st[j].begin()->first;

				ll& ccnt = mp[j][i];
				st[j].erase({ ccnt, i });
				ccnt += cnt;
				st[j].insert({ ccnt, i });

				ll now = 0;
				if (st[j].size() >= n) now = st[j].begin()->first;

				for (ll k = last; k < now; k++)
				{
					ans *= prime[j];
					ans %= MOD;
				}
			}
		}

		if (x > 1)
		{
			int idx = lower_bound(prime.begin(), prime.end(), x) - prime.begin();

			ll last = 0;
			if (st[idx].size() >= n) last = st[idx].begin()->first;

			ll& ccnt = mp[idx][i];
			st[idx].erase({ ccnt, i });
			ccnt += 1;
			st[idx].insert({ ccnt, i });

			ll now = 0;
			if (st[idx].size() >= n) now = st[idx].begin()->first;

			for (ll k = last; k < now; k++)
			{
				ans *= prime[idx];
				ans %= MOD;
			}
		}

		cout << ans << '\n';
		if (ans < 0)
		{
			int stop_here = 0;
		}
	}
}