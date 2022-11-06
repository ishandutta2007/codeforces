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
		int a[4], b[4];
		for (int i = 0; i < 4; i++)
		{
			cin >> a[i];
			b[i] = a[i];
		}

		sort(b, b + 4);
		int c, d;
		for (int i = 0; i < 4; i++)
		{
			if (a[i] == b[3]) c = i / 2;
			if (a[i] == b[2]) d = i / 2;
		}

		if (c == d) cout << "NO\n";
		else cout << "YES\n";
	}
}