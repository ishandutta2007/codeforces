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
		ll n; cin >> n;
		if (n % 3 == 0) cout << n / 3 << ' ' << n / 3 << '\n';
		else if (n % 3 == 1) cout << n / 3 + 1 << ' ' << n / 3 << '\n';
		else cout << n / 3 << ' ' << n / 3 + 1 << '\n';
	}
}