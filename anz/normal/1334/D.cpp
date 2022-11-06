#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int ans_2[4] = { 0,1,2,1 };
vector <ll> vec;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		ll n, l, r; cin >> n >> l >> r;
		if (n == 2)
		{
			for (int i = l; i <= r; i++) cout << ans_2[i] << ' ';
			cout << '\n';
			continue;
		}

		vec.clear();		
		ll tmp = 0;
		for (ll k = n - 1; k > 0; k--)
		{
			tmp += k * 2;
			vec.push_back(tmp);
		}
		vec.push_back(tmp + 1);

		for (ll i = l; i <= r; i++)
		{
			int idx = lower_bound(vec.begin(), vec.end(), i) - vec.begin();
			if (idx != vec.size() - 1)
			{
				ll ci = i - 1;
				if (idx) ci -= vec[idx - 1];

				if (ci % 2 == 0) cout << idx + 1 << ' ';
				else cout << ci / 2 + idx + 2 << ' ';
			}
			else cout << "1 ";
		}
		cout << '\n';
	}
}