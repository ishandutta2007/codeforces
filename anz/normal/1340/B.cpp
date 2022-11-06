#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int bs[10] = { 119,36,93,109,46,107,123,37,127,111 };
int count_bit(int x)
{
	int res = 0;
	for (int i = 0; i < 7; i++)
	{
		if (x & (1 << i)) res++;
	}

	return res;
}

int n, k;
int dig[2001];
int pl[2001][10];

string ans;
int dp[2001][2001];
int solve(int idx, int rm)
{
	if (idx == n && rm == 0) return 1;

	int& ret = dp[idx][rm];
	if (ret != -1) return ret;

	for (int i = 9; i >= 0; i--)
	{
		if (pl[idx][i] == -1 || rm < pl[idx][i]) continue;

		ans += (char)('0' + i);
		if (solve(idx + 1, rm - pl[idx][i])) return ret = 1;
		ans.pop_back();
	}

	return ret = 0;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	memset(pl, -1, sizeof pl);

	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		string s; cin >> s;
		for (int j = 0; j < 7; j++)
		{
			dig[i] += ((s[j] - '0') << j);
		}

		for (int j = 0; j < 10; j++)
		{
			if ((bs[j] & dig[i]) == dig[i])
			{
				int cnt = count_bit(bs[j] & (~dig[i]));
				pl[i][j] = cnt;
			}
		}
	}

	memset(dp, -1, sizeof dp);

	if (solve(0, k)) cout << ans;
	else cout << -1;
}