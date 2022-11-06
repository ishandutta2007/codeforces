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
		int x, y; cin >> x >> y;
		if (x > y) swap(x, y);
		int ans = x * 2;
		if (y > x) ans += (y - x - 1) * 2 + 1;
		cout << ans << '\n';
	}
}