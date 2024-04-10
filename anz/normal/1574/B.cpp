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

	int T; cin >> T;
	while (T--)
	{
		int a[3], m;
		cin >> a[0] >> a[1] >> a[2] >> m;
		sort(a, a + 3);
		int mn = max(0, a[2] - a[0] - a[1] - 1);
		int mx = max(0, a[0] - 1) + max(0, a[1] - 1) + max(0, a[2] - 1);

		if (mn <= m && m <= mx) cout << "YES\n";
		else cout << "NO\n";
	}
}