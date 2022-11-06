#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 3e5 + 20;
const int mod = 998244353;

int a[maxn] , dp[maxn];

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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	int m = 0;
	for(int i = 0; i < n; i++)
		cin >> a[i] , m += a[i];

	for(int i = m; i >= 0; i--)
		dp[i] = 1LL * (n - 1) * (m + 1LL * (m - i) * dp[i + 1] % mod) % mod * bpw(i , mod - 2) % mod;

	for(int i = 1; i <= m; i++)
		mkay(dp[i] += dp[i - 1]);

	int res = 1LL * dp[m] * (n - 1) % mod;
	mkay(res = -res);

	for(int i = 0; i < n; i++)
		mkay(res += dp[m - a[i]]);
	
	res = 1LL * res * bpw(n , mod - 2) % mod;
	cout << res << endl;
}