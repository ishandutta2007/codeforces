#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 5005;
const int MOD = 998244353;

int pow(int a, int b, int m)
{
	int ans=1;
	while(b)
	{
		if(b&1)
			ans=(ans*a)%m;
		b/=2;
		a=(a*a)%m;
	}
	return ans;
}

int fact[N], invfact[N];
int cache3[N];

int modinv(int k)
{
	if(k < N)
	{
		int &ans = cache3[k];
		if(ans != -1)
			return ans;
		return ans = pow(k, MOD-2, MOD);
	}
	else
		return pow(k, MOD - 2, MOD);
}

void precompute()
{
	fact[0]=fact[1]=1;
	for(int i=2;i<N;i++)
	{
		fact[i]=fact[i-1]*i;
		fact[i]%=MOD;
	}
	invfact[N-1]=modinv(fact[N-1]);
	for(int i=N-2;i>=0;i--)
	{
		invfact[i]=invfact[i+1]*(i+1);
		invfact[i]%=MOD;
	}
}

int nCr(int x, int y)
{
	if(y>x)
		return 0;
	int num=fact[x];
	num*=invfact[y];
	num%=MOD;
	num*=invfact[x-y];
	num%=MOD;
	return num;
}

int n;
int a[N], f[N], cache[N][N], cache2[N][N];

int dp(int prev, int taken);

int dp2(int prev, int taken)
{
	if(prev == n + 1)
		return 0;
	int &ans = cache2[prev][taken];
	if(ans != -1)
		return ans;
	ans = 0;
	int nxt = prev + 1;
	int cur = f[nxt];
	cur *= modinv(n - taken);
	cur %= MOD;
	cur *= dp(nxt, taken + 1);
	cur %= MOD;
	ans += cur;
	ans += dp2(prev + 1, taken);
	ans %= MOD;
	return ans;
}

int dp(int prev, int taken)
{	
	if(taken == n)
		return 0;
	int &ans = cache[prev][taken];
	if(ans != -1)
		return ans;
	ans = 0;
	if(f[prev] > 1)
	{
		int cur = f[prev] - 1;
		cur *= modinv(n - taken);
		cur %= MOD;
		ans += cur;
	}
	ans += dp2(prev, taken);
	ans %= MOD;
	return ans;
}

int32_t main()
{
	IOS;
	memset(cache, -1, sizeof(cache));
	memset(cache2, -1, sizeof(cache2));
	memset(cache3, -1, sizeof(cache3));
	precompute();
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		f[a[i]]++;
	}
	int ans = 0;
	for(int i = 1; i <= n; i++)
	{
		int cur = f[i] * modinv(n);
		cur %= MOD;
		cur *= dp(i, 1);
		cur %= MOD;
		ans += cur;
	}
	ans %= MOD;
	cout << ans;
	return 0;
}