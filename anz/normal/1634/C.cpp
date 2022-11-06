#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n, k;

int main()
{
	int t; cin >> t;
	while (t--)
	{
		cin >> n >> k;
		if (k > 1 && n % 2)
		{
			cout << "NO\n";
			continue;
		}

		cout << "YES\n";
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < k; j++)
				cout << j * n + i + 1 << ' ';
			cout << '\n';
		}
	}
}