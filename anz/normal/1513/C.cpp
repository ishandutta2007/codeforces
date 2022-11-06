#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

typedef vector<vector<ll> > vvll;

const ll MOD = 1e9 + 7;

string n;
ll m;
ll cnt[10];

ll mat[200001][10][10];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	for (int i = 0; i < 10; i++)
		mat[0][i][i] = 1;

	for (int k = 0; k < 200000; k++)
	{
		for (int i = 0; i < 9; i++) for (int j = 0; j < 10; j++)
			mat[k + 1][i + 1][j] = mat[k][i][j];
		for (int j = 0; j < 10; j++)
		{
			mat[k + 1][0][j] += mat[k][9][j];
			mat[k + 1][1][j] += mat[k][9][j];
			mat[k + 1][0][j] %= MOD;
			mat[k + 1][1][j] %= MOD;
		}
	}

	int t; cin >> t;
	while (t--)
	{
		cin >> n >> m;
		memset(cnt, 0, sizeof cnt);
		for (char c : n) cnt[c - '0']++;

		ll ans = 0;
		for (int i = 0; i < 10; i++) for (int j = 0; j < 10; j++)
		{
			ans += mat[m][i][j] * cnt[j];
			ans %= MOD;
		}

		cout << ans << '\n';
	}
}