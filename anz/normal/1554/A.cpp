#include <bits/stdc++.h>
#include <random>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int T; cin >> T;
	while (T--)
	{
		int n; cin >> n;

		ll ans = 0;
		ll l; cin >> l;
		for (int i = 1; i < n; i++)
		{
			ll r; cin >> r;
			ans = max(ans, l * r);
			l = r;
		}
		cout << ans << '\n';
	}
}