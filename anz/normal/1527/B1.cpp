#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

const int INF = 1e9;

int n;
string s;

int dp[1001][1001][2][2];
// , , ,   

int solve(int a, int b, int c, int f)
{
	int& ret = dp[a][b][c][f];
	if (ret != -INF) return ret;

	if (a == 0 && b == 0 && c == 0) return ret = 0;

	if (f == 0 && b > 0)
	{
		int res = -solve(a, b, c, 1);
		ret = max(ret, res);
	}

	if (a > 0)
	{
		int res = -solve(a - 1, b + 1, c, 0) - 1;
		ret = max(ret, res);
	}

	if (b > 0)
	{
		int res = -solve(a, b - 1, c, 0) - 1;
		ret = max(ret, res);
	}

	if (c > 0)
	{
		int res = -solve(a, b, 0, 0) - 1;
		ret = max(ret, res);
	}

	return ret;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	for (int i = 0; i <= 1000; i++) for (int j = 0; j <= 1000; j++)
		dp[i][j][0][0] = dp[i][j][0][1] = dp[i][j][1][0] = dp[i][j][1][1] = -INF;

	int t; cin >> t;
	while (t--)
	{
		cin >> n >> s;
		int a = 0, b = 0, c = 0;
		for (int i = 0; i < n / 2; i++)
		{
			if (s[i] == '0' && s[n - 1 - i] == '0') a++;
			else if (s[i] == '0' || s[n - 1 - i] == '0') b++;
		}

		if (n % 2 && s[n / 2] == '0') c = 1;

		int ans = solve(a, b, c, 0);
		if (ans > 0) cout << "ALICE\n";
		else if (ans < 0) cout << "BOB\n";
		else cout << "DRAW\n";
	}
}