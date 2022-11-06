#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 2e3 + 20;
const int mod = 998244353;

int dp[maxn][maxn];

void mkay(int &a)
{
	if(a >= mod)
		a -= mod;
	else if(a < 0)
		a += mod;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n , m , k;
	cin >> n >> m >> k;

	dp[1][0] = m;
	for(int i = 2; i <= n; i++)
		for(int j = 0; j <= k; j++)
		{
			dp[i][j] = dp[i - 1][j];

			if(j)
				mkay(dp[i][j] += 1LL * dp[i - 1][j - 1] * (m - 1) % mod);
		}

	cout << dp[n][k] << endl;
}