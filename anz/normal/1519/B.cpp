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
		ll n, m, k; cin >> n >> m >> k;

		ll res = (n - 1) + (m - 1) * n;
		if (k == res) cout << "YES\n";
		else cout << "NO\n";
	}
}