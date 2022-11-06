#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n;
ll t[100001];
ll x[100001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int T; cin >> T;
	while (T--)
	{
		cin >> n;

		for (int i = 0; i < n; i++) cin >> t[i] >> x[i];
		t[n] = 1e18;

		ll cx = 0;

		ll last = 0;
		int ans = 0;

		int a = 0, b = 0;

		for (int i = 0; i < n; i++)
		{
			if (last <= t[i])
			{
				last = t[i];

				if (cx < x[i])
				{
					a = 1;
					b = cx - t[i];
					last += x[i] - cx;
				}
				else if (cx > x[i])
				{
					a = -1;
					b = cx + t[i];
					last += cx - x[i];
				}
				else
				{
					a = 0;
					b = cx;
				}

				cx = x[i];
				if (t[i + 1] >= last) ans++;
			}
			else
			{
				ll l = a * t[i] + b;
				ll r = a * min(last, t[i + 1]) + b;

				if (l > r) swap(l, r);
				if (l <= x[i] && x[i] <= r) ans++;
			}
		}

		//cout << "ANS:";
		cout << ans << '\n';
	}
}