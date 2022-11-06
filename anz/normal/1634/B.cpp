#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

ll n, x, y;
ll a[100001];

int main()
{
	int t; cin >> t;
	while (t--)
	{
		cin >> n >> x >> y;
		for (int i = 0; i < n; i++) cin >> a[i];

		ll c = 0;
		for (int i = 0; i < n; i++) c ^= (a[i] & 1ll);

		if ((x & 1ll ^ c) == (y & 1ll)) cout << "Alice\n";
		else cout << "Bob\n";
	}
}