#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 5e3 + 20;
const int mod = 998244353;

int dp[maxn][maxn] , fac[maxn] , caf[maxn] , ans[maxn];

inline void mkay(int &a)
{
	if(a >= mod)
		a -= mod;
	else if(a < 0)
		a += mod;
}

int bpw(int a , int b)
{
	int res = 1;
	while(b > 0)
	{
		if(b & 1)
			res = 1LL * res * a % mod;
		a = 1LL * a * a % mod;
		b >>= 1;
	}

	return res;
}

int c(int s , int r)
{
	if(r < 0 || r > s)
		return 0;

	return 1LL * fac[s] * caf[r] % mod * caf[s - r] % mod;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	fac[0] = 1;
	for(int i = 1; i < maxn; i++)
		fac[i] = 1LL * fac[i - 1] * i % mod;
	
	caf[maxn - 1] = bpw(fac[maxn - 1] , mod - 2);
	for(int i = maxn - 1; i > 0; i--)
		caf[i - 1] = 1LL * caf[i] * i % mod;

	int n;
	cin >> n;

	// dp[i][j] = i ta adad hadeaghal j ta <
	// = i - j ta daste stirling
	dp[0][0] = 1;
	for(int i = 1; i <= n; i++)
		for(int j = 0; j < i; j++)
		{
			dp[i][j] = 1LL * (i - j) * dp[i - 1][j] % mod;
			if(j)
				mkay(dp[i][j] += 1LL * (i - j) * dp[i - 1][j - 1] % mod);
		}

	for(int i = 1; i <= n; i++)
		for(int j = 0; j < i; j++)
			dp[i][j] = 1LL * dp[i][j] * c(n , i) % mod * fac[n - i] % mod;

	for(int i = n - 1; i >= 0; i--)
		for(int j = 0; j < i; j++)
			mkay(dp[i][j] += dp[i + 1][j]);
	
	for(int i = 0; i < n; i++)
	{
		int res = 0;
		for(int j = i; j < n; j++)
		{
			int tmp = 1LL * c(j , i) % mod * dp[j + 1][j] % mod;
			if((j - i) % 2)
				mkay(res -= tmp);
			else
				mkay(res += tmp);
		}
		cout << res << " ";
	}

	cout << endl;
}