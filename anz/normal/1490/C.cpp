#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

set <ll> v;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	for (ll i = 1; i * i * i <= 1e12; i++) v.insert(i * i * i);

	int t; cin >> t;
	while (t--)
	{
		ll x; cin >> x;

		bool flag = false;
		for (auto it : v)
		{
			if (it > x) break;
			if (v.find(x - it) != v.end())
			{
				flag = true;
				break;
			}
		}

		if (flag) cout << "YES\n";
		else cout << "NO\n";
	}
}