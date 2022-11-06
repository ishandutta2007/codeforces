#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;
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
		if (n < 31) cout << "NO\n";
		else
		{
			cout << "YES\n";

			if (n - 30 == 6)
			{
				cout << "5 6 10 15\n";
			}
			else if (n - 30 == 10)
			{
				cout << "6 9 10 15\n";
			}
			else if (n - 30 == 14)
			{
				cout << "6 7 10 21\n";
			}
			else
			{
				cout << "6 10 14 " << n - 30 << '\n';
			}
		}
	}
}