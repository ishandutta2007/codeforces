#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n;
int p[4001];

int dp[4001][4001];
int solve(int idx, int a)
{
	int& ret = dp[idx][a];
	if (ret != -1) return ret;

	if (idx == n)
	{
		if (a == n / 2) return ret = 1;
		else return ret = 0;
	}

	ret = 0;

	int ed = idx + 1;
	for (; ed < n; ed++)
	{
		if (p[idx] < p[ed]) break;
	}

	int sz = ed - idx;

	if (solve(ed, a + sz)) ret = 1;
	if (solve(ed, a)) ret = 1;

	return ret;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		cin >> n; n *= 2;
		for (int i = 0; i < n; i++) cin >> p[i];

		for (int i = 0; i <= n; i++) for (int j = 0; j <= n; j++) dp[i][j] = -1;

		int res = solve(0, 0);

		if (res) cout << "YES\n";
		else cout << "NO\n";
	}
}