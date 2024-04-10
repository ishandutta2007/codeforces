
#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
 
const int N = 1001;
const int MOD = 1e9 + 7;
const int K = 51;
 
int n, k;
int cache[N][N][51], cache2[N][K];
long long fact[2 * N], invfact[2 * N];
 
long long pow(long long a, long long b, long long m)
{
	long long ans=1;
	while(b)
	{
		if(b&1)
			ans=(ans*a)%m;
		b/=2;
		a=(a*a)%m;
	}
	return ans;
}
 
long long modinv(long long k)
{
	return pow(k, MOD-2, MOD);
}
 
void precompute()
{
	fact[0]=fact[1]=1;
	for(long long i=2;i<2 * N;i++)
	{
		fact[i]=fact[i-1]*i;
		fact[i]%=MOD;
	}
	invfact[2 * N-1]=modinv(fact[2 * N-1]);
	for(long long i=2 * N-2;i>=0;i--)
	{
		invfact[i]=invfact[i+1]*(i+1);
		invfact[i]%=MOD;
	}
}
 
long long nCr(long long x, long long y)
{
	if(y>x)
		return 0;
	long long num=fact[x];
	num*=invfact[y];
	num%=MOD;
	num*=invfact[x-y];
	num%=MOD;
	return num;
}
 
int dp(int x, int last, int k)
{
	if(x < 0)
		return 0;
	if(k == 0)
		return (x == 0);
	if(last <= 0)
		return 0;
	int &ans = cache[x][last][k];
	if(ans != -1)
		return ans;
	ans = dp(x - last, last - 1, k - 1) + dp(x, last - 1, k);
	ans %= MOD;
	return ans;
}
 
int dp2(int n, int k)
{
	int &ans = cache2[n][k];
	if(ans != -1)
		return ans;
	ans = 0;
	for(int x = k * (k - 1) / 2; x <= n; x++)
	{
		long long cur = dp(x, n, k);
		cur *= nCr(n - x + k, k);
		cur %= MOD;
		cur *= fact[k];
		cur %= MOD;
		ans += cur;
		ans %= MOD;
	}
	return ans;
}
 
int32_t main()
{
	IOS;
	memset(cache, -1, sizeof(cache));
	memset(cache2, -1, sizeof(cache2));
	precompute();
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n >> k;
		if(k >= 51)
			cout << 0 << endl;
		else
			cout << dp2(n, k) << endl;
	}
	return 0;
}