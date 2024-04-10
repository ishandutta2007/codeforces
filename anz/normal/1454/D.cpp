#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

ll n;
map <ll, ll> mp;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		mp.clear();
		cin >> n;

		ll tn = n;
		for (ll i = 2; i * i <= n; i++)
		{
			while (tn % i == 0)
			{
				mp[i]++;
				tn /= i;
			}
		}

		if (tn != 1) mp[tn]++;

		ll d = -1, cnt = 0;
		for (auto it : mp)
		{
			if (it.second > cnt)
			{
				d = it.first;
				cnt = it.second;
			}
		}

		tn = n;

		cout << cnt << '\n';
		for (int i = 0; i < cnt - 1; i++)
		{
			cout << d << ' ';
			tn /= d;
		}

		cout << tn << '\n';
	}
}