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
		if (n >= k && (n - k + 1) % 2 == 1)
		{
			cout << "YES\n";
			for (int i = 0; i < k - 1; i++) cout << "1 ";
			cout << n - k + 1;
			cout << '\n';
			continue;
		}
		if (n >= 2 * k && (n - 2 * k + 2) % 2 == 0)
		{
			cout << "YES\n";
			for (int i = 0; i < k - 1; i++) cout << "2 ";
			cout << n - 2 * k + 2;
			cout << "\n";
			continue;
		}
		cout << "NO\n";
	}
}