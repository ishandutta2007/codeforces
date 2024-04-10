#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n;
string s;
int d[1000001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		cin >> n >> s;
		for (int i = 0; i < n; i++) d[i] = 0;

		ll l = 0, r = 0;
		ll lcnt = 0, rcnt = 0;
		ll x = 0;
		for (int i = 0; i < n; i++)
		{
			if (s[i] == '.') continue;
			rcnt++;
			r += i - x;
			d[i - x]++;
			x++;
		}

		ll cnt = rcnt;
		ll ans = r;
		for (int i = 1; i + cnt <= n; i++)
		{
			rcnt -= d[i - 1];
			lcnt += d[i - 1];

			r -= rcnt;
			l += lcnt;

			ans = min(ans, l + r);
		}

		cout << ans << '\n';
	}
}