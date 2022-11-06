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
		ll p, a, b, c; cin >> p >> a >> b >> c;
		a = (a - p % a) % a;
		b = (b - p % b) % b;
		c = (c - p % c) % c;

		cout << min(a, min(b, c)) << '\n';
	}
}