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
		if (n / 2 % 2)
		{
			cout << "NO\n";
			continue;
		}

		cout << "YES\n";
		for (int i = 0; i < n / 2; i++) cout << i * 2 + 2 << ' ';
		for (int i = 0; i < n / 4; i++) cout << i * 2 + 1 << ' ';
		for (int i = n / 4; i < n / 2; i++) cout << i * 2 + 3 << ' ';
		cout << '\n';
	}
}