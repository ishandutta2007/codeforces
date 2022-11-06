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
		int a = 0, b = 0;
		while (n--)
		{
			int x; cin >> x;
			if (x == 1) a++;
			else b++;
		}

		bool ans = false;
		if (b % 2 == 0)
		{
			if (a % 2 == 0) ans = true;
		}
		else
		{
			if (a >= 2 && a % 2 == 0) ans = true;
		}

		if (ans) cout << "YES\n";
		else cout << "NO\n";
 	}
}