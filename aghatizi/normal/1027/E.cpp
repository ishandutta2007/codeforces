#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 5e2 + 20;
const int mod = 998244353;

int dp[maxn][maxn] , pd[maxn][maxn];

void mkay(int &a)
{
	if(a >= mod)
		a -= mod;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n , k;
	cin >> n >> k;

	for(int j = 1; j <= n; j++)
	{
		dp[0][j] = 1;
		for(int i = 1; i <= n; i++)
			for(int last = 1; last <= j && last <= i; last++)
				mkay(dp[i][j] += dp[i - last][j]);

		for(int i = 1; i <= n; i++)
			for(int k = 0; k < j; k++)
				mkay(dp[i][j] += mod - dp[i][k]);

	}

	for(int j = 1; j <= n; j++)
	{
		pd[0][j] = 1;

		for(int i = 1; i <= n; i++)
			for(int last = 1; last <= i && last * j < k; last++)
				mkay(pd[i][j] += pd[i - last][j]);
	}

	int res = 0;

	for(int i = 1; i <= n; i++)
		mkay(res += 2LL * dp[n][i] * pd[n][i] % mod);

	cout << res << endl;
}