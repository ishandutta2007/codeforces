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
		ll n, k; cin >> n >> k;
		ll a = (n / k) + (n % k ? 1 : 0);

		cout << (k * a - n) / n + ((k * a - n) % n ? 1 : 0) + 1 << '\n';
	}
}