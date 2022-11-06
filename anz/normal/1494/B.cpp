#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		int n, u, r, d, l;
		cin >> n >> u >> r >> d >> l;

		bool ans = false;

		for (int k = 0; k < 16; k++)
		{
			int ul = 0;
			int ur = 0;
			int dl = 0;
			int dr = 0;

			if (k & 1) ul = 1;
			if (k & 2) ur = 1;
			if (k & 4) dl = 1;
			if (k & 8) dr = 1;

			if (0 <= u - ul - ur && u - ul - ur <= n - 2
				&& 0 <= d - dl - dr && d - dl - dr <= n - 2
				&& 0 <= l - ul - dl && l - ul - dl <= n - 2
				&& 0 <= r - ur - dr && r - ur - dr <= n - 2) ans = true;
		}

		if (ans) cout << "YES\n";
		else cout << "NO\n";
	}
}