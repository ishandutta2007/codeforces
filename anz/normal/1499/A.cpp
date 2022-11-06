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
		int n, k1, k2; cin >> n >> k1 >> k2;
		int w, b; cin >> w >> b;

		bool ans = true;
		if (k1 + k2 < w * 2) ans = false;
		if (n + n - k1 - k2 < b * 2) ans = false;

		if (ans) cout << "Yes\n";
		else cout << "No\n";
	}
}