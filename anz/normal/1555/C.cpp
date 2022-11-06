#include <bits/stdc++.h>
#include <random>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int m;
int a[2][100001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int T; cin >> T;
	while (T--)
	{
		cin >> m;
		for (int i = 0; i < 2; i++) for (int j = 1; j <= m; j++)
		{
			cin >> a[i][j];
			a[i][j] += a[i][j - 1];
		}

		if (m == 1)
		{
			cout << "0\n";
			continue;
		}

		ll ans = 1e18;;
		for (int i = 1; i <= m; i++)
		{
			ll lval = a[0][m] - a[0][i];
			ll rval = a[1][i - 1];

			ans = min(ans, max(lval, rval));
		}

		cout << ans << '\n';
	}
}