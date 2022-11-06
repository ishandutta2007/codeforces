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
		if (n == 1)
		{
			cout << "-1\n";
			continue;
		}

		if ((n - 1) % 3 == 0)
		{
			cout << "4";
			for (int i = 0; i < n - 2; i++) cout << "2";
			cout << "3\n";
		}
		else
		{
			for (int i = 0; i < n - 1; i++) cout << "2";
			cout << "3\n";
		}
	}
}