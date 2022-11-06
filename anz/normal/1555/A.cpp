#include <bits/stdc++.h>
#include <random>
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
		if (n < 6)
		{
			cout << "15\n";
			continue;
		}

		cout << (n + 1) / 2 * 5 << '\n';
	}
}