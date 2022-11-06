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
		ll x, n; cin >> x >> n;

		//cout << "ANS: ";
		ll d = 1; if (x % 2) d = -1;

		ll r = 0;
		if (n % 4 == 0) r = 0;
		else if (n % 4 == 1) r = -n;
		else if (n % 4 == 2) r = 1;
		else r = n + 1;

		cout << x + r * d << '\n';
	}
}