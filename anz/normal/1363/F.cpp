#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

const int INF = 987654321;

int n;
string s, t;

int ps1[26][2001];
int ps2[26][2001];

int dp[2001][2001];
int solve(int i, int j)
{
	if (i == 0) return 0;
	int& ret = dp[i][j];
	if (ret != -1) return ret;

	ret = solve(i - 1, j) + 1;

	if (s[i - 1] == t[j - 1])
		ret = min(ret, solve(i - 1, j - 1));

	int idx = t[j - 1] - 'a';
	int s1 = ps1[idx][n] - ps1[idx][i];
	int s2 = ps2[idx][n] - ps2[idx][j];

	if (s1 > s2)
		ret = min(ret, solve(i, j - 1));

	return ret;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int T; cin >> T;
	while (T--)
	{
		cin >> n;
		cin >> s >> t;

		int cnt[2][26] = { 0, };
		for (int i = 0; i < n; i++)
		{
			cnt[0][s[i] - 'a']++;
			cnt[1][t[i] - 'a']++;
		}

		bool flag = false;
		for (int i = 0; i < 26; i++)
		{
			if (cnt[0][i] != cnt[1][i])
			{
				flag = true;
				break;
			}
		}

		if (flag)
		{
			cout << "-1\n";
			continue;
		}
		
		for (int i = 0; i <= n; i++) for (int j = 0; j <= n; j++)
			dp[i][j] = -1;

		int s1[26] = { 0, };
		int s2[26] = { 0, };

		for (int i = 0; i < n; i++)
		{
			s1[s[i] - 'a']++;
			s2[t[i] - 'a']++;

			for (int j = 0; j < 26; j++)
			{
				ps1[j][i + 1] = s1[j];
				ps2[j][i + 1] = s2[j];
			}
		}

		cout << solve(n, n) << '\n';
	}
}