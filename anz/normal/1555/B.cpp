#include <bits/stdc++.h>
#include <random>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

const ll INF = 1e18;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int T; cin >> T;
	while (T--)
	{
		ll W, H;
		ll x1, y1, x2, y2;
		ll w, h;

		cin >> W >> H;
		cin >> x1 >> y1 >> x2 >> y2;
		cin >> w >> h;

		ll ans = INF;

		if (x2 - x1 + w <= W)
		{
			ans = min(ans, max(0ll, w - x1));
			ans = min(ans, max(0ll, w - (W - x2)));
		}
		
		if (y2 - y1 + h <= H)
		{
			ans = min(ans, max(0ll, h - y1));
			ans = min(ans, max(0ll, h - (H - y2)));
		}
		
		if (ans == INF) ans = -1;
		cout << ans << '\n';
	}
}