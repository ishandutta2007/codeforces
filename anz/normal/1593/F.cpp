#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

const int INF = 1e9;

int n, a, b;
string s;
int dp[40][40][40][40];
int back[40][40][40][40];

int solve(int idx, int r, int rd, int bd)
{
	if (idx == n)
	{
		if (rd == 0 && bd == 0 && r != 0 && r != n)
			return abs(n - r - r);
		else return INF;
	}

	int& ret = dp[idx][r][rd][bd];
	if (ret != -1) return ret;

	ret = INF;

	int res1 = solve(idx + 1, r + 1, (rd * 10 + s[idx] - '0') % a, bd);
	int res2 = solve(idx + 1, r, rd, (bd * 10 + s[idx] - '0') % b);

	if (res1 < res2)
	{
		ret = res1;
		back[idx][r][rd][bd] = 0;
	}
	else
	{
		ret = res2;
		back[idx][r][rd][bd] = 1;
	}

	return ret;
}

void print(int idx, int r, int rd, int bd)
{
	if (idx == n) return;

	if (back[idx][r][rd][bd] == 0)
	{
		cout << 'R';
		print(idx + 1, r + 1, (rd * 10 + s[idx] - '0') % a, bd);
	}
	else
	{
		cout << 'B';
		print(idx + 1, r, rd, (bd * 10 + s[idx] - '0') % b);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int T; cin >> T;
	while (T--)
	{
		memset(dp, -1, sizeof dp);

		cin >> n >> a >> b;
		cin >> s;

		int ans = solve(0, 0, 0, 0);

		if (ans == INF)
		{
			cout << "-1\n";
			continue;
		}

		print(0, 0, 0, 0);
		cout << '\n';
	}
}