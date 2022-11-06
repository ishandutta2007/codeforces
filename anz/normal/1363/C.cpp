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
		int n, x; cin >> n >> x;
		int cnt = 0;
		for (int i = 0; i < n - 1; i++)
		{
			int u, v; cin >> u >> v;
			if (u == x || v == x) cnt++;
		}

		if (cnt <= 1)
		{
			cout << "Ayush\n";
			continue;
		}

		if (n % 2) cout << "Ashish\n";
		else cout << "Ayush\n";
	}
}