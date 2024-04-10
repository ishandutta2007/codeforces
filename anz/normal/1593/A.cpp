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
		ll a, b, c; cin >> a >> b >> c;
		cout << max(0ll, max(b, c) - a + 1) << ' '
			<< max(0ll, max(a, c) - b + 1) << ' '
			<< max(0ll, max(a, b) - c + 1) << '\n';
	}
}