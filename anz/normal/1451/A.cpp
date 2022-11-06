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
		ll n; cin >> n;
		if (n == 1) cout << "0\n";
		else if (n == 2) cout << "1\n";
		else if (n == 3) cout << "2\n";
		else if (n % 2 == 0) cout << "2\n";
		else cout << "3\n";
	}
}