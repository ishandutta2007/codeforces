#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n;
map <ll, ll> mp;
vector <pll> vec;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		mp.clear();
		vec.clear();

		cin >> n;
		for (int i = 0; i < n; i++)
		{
			int a; cin >> a;
			mp[a]++;
		}

		for (auto it : mp)
			vec.push_back({ it.second, it.first });

		sort(vec.rbegin(), vec.rend());

		ll ans = 1e9;
		for (int i = 0; i < vec.size(); i++)
		{
			ll cnt = vec[i].first;
			ll cur = (i + 1) * cnt;

			ans = min(ans, n - cur);
		}

		cout << ans << '\n';
	}
}