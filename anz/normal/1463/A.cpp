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
	while(t--)
	{
		int a, b, c; cin >> a >> b >> c;

		bool ans = true;
		if ((a + b + c) % 9) ans = false;
		else
		{
			if (min(a, (min(b, c))) < (a + b + c) / 9) ans = false;
		}

		if (ans) cout << "YES\n";
		else cout << "NO\n";
	}
}