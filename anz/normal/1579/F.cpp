#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

ll n, d;
int a[1000001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int T; cin >> T;
	while (T--)
	{
		cin >> n >> d;
		for (int i = 0; i < n; i++) cin >> a[i];
		int g = gcd(n, d);

		bool isValid = true;
		int ans = 0;

		for (ll k = 0; k < g; k++)
		{
			vector <int> v;
			for (ll i = 0; i < n / g; i++)
				if (a[(k + i * d) % n] == 0) v.push_back(i);

			if (!v.size()) isValid = false;
			else
			{
				v.push_back(v.front() + n / g);
				for (int i = 0; i + 1 < v.size(); i++)
					ans = max(ans, v[i + 1] - v[i] - 1);
			}
		}

		//cout << "ANS: ";
		if (!isValid) cout << "-1\n";
		else cout << ans << '\n';
	}
}