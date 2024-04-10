#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

const ll MOD = 1e9 + 7;

int n, m;
string board[2001];

ll pow(ll a)
{
	if (a == 0) return 1;
	ll res = pow(a / 2);
	res = res * res % MOD;
	if (a % 2) res = res * 2 % MOD;
	return res;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		cin >> n >> m;

		ll a = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> board[i];
			for (int j = 0; j < m; j++)
			{
				if (board[i][j] == '#') a++;
			}
		}

		ll ans = pow(a);
		if (a == n * m) ans = (ans + MOD - 1) % MOD;

		cout << ans << '\n';
	}
}