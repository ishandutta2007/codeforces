#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 5e2 + 20;
const int mod = 998244353;

int a[maxn] , dp[maxn][maxn] , pd[maxn][maxn];

inline void mkay(int &a)
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

	int n , m;
	cin >> n >> m;

	for(int i = 0; i < n; i++)
		cin >> a[i];

	for(int l = n - 1; l >= 0; l--)
	{
		for(int r = l; r < n; r++)
		{
			if(l == r)
			{
				dp[l][r] = pd[l][r] = 1;
				continue;
			}

			int mn = min_element(a + l , a + r + 1) - a;
			for(int i = mn; i <= r; i++)
			{
				int tmp = 1;
				if(l < mn)
					tmp = 1LL * tmp * dp[l][mn - 1] % mod;
				if(i > mn)
					tmp = 1LL * tmp * dp[mn + 1][i] % mod;
				if(i < r)
					tmp = 1LL * tmp * dp[i + 1][r] % mod;

				mkay(pd[l][r] += tmp);
			}

			for(int i = l; i <= mn; i++)
			{
				int tmp = 1;
				if(i > l)
					tmp = 1LL * tmp * dp[l][i - 1] % mod;
				mkay(dp[l][r] += 1LL * tmp * pd[i][r] % mod);
			}
		}
	}

	cout << dp[0][n - 1] << endl;
}