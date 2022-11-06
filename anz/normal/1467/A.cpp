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
		int n; cin >> n;
		if (n == 1) cout << "9\n";
		else if (n == 2) cout << "98\n";
		else
		{
			cout << "989";
			for (int i = 0; i < n - 3; i++)
				cout << i % 10;

			cout << '\n';
		}
	}
}