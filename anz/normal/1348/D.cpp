#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		ll n; cin >> n;

		ll tmp = 1;
		ll sum = 1;
		multiset <ll> res;

		res.insert(tmp);
		while (true)
		{
			tmp *= 2;
			if (sum + tmp > n) break;
			sum += tmp;
			res.insert(tmp);
		}

		ll rm = n - sum;
		if (rm) res.insert(rm);

		ll prev = -1;
		vector <ll> ans;

		for (ll it : res)
		{
			if (prev == -1)
			{
				prev = it;
				continue;
			}
			ans.push_back(it - prev);
			prev = it;
		}

		cout << ans.size() << '\n';
		for (auto it : ans) cout << it << ' ';
		cout << '\n';
	}
}