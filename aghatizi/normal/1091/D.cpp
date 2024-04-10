#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 1e6 + 20;
const int mod = 998244353;

int fac[maxn] , caf[maxn] , dp[maxn];

int bpw(int a , int b)
{
	if(!b)
		return 1;
	int x = bpw(a , b / 2);
	
	x = 1LL * x * x % mod;
	if(b&1)
		x = 1LL * x * a % mod;

	return x;
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

	int res = 0;
	dp[1] = 1;
	for(int i = 2; i <= n; i++)
		dp[i] = (1LL * dp[i - 1] * i + fac[i] - i + mod) % mod;

	cout << dp[n] << endl;
}