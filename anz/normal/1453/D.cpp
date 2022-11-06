#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

vector <ll> vec;
vector <int> ans;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	ll sum = 0;

	for (ll i = 1; sum <= 1e18; i++)
	{
		sum += 1ll << i;
		vec.push_back(sum);
	}

	int t; cin >> t;
	while (t--)
	{
		ll k; cin >> k;
		if (k % 2)
		{
			cout << "-1\n";
			continue;
		}

		ans.clear();

		for (int i = vec.size() - 1; i >= 0; i--)
		{
			while (k >= vec[i])
			{
				k -= vec[i];
				ans.push_back(1);
				for (int j = 0; j < i; j++) ans.push_back(0);
			}
		}

		cout << ans.size() << '\n';
		for (int x : ans) cout << x << ' ';
		cout << '\n';
	}
}