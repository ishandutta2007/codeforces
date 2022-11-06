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
		int odd = 0;
		int one = 0;

		for (int i = 0; i < 4; i++)
		{
			int a; cin >> a;
			if (a % 2) odd++;
			if (i < 3 && a) one++;
		}

		if (odd <= 1) cout << "Yes\n";
		else if (odd != 2 && one == 3) cout << "Yes\n";
		else cout << "No\n";
	}
}