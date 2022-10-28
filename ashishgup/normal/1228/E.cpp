#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 250 * 250 * 2 + 5;
const int MOD = 1e9 + 7;

int fact[N], invfact[N];

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

int modinv(int k)
{
	return pow(k, MOD-2, MOD);
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
int n, K;

int32_t main()
{
	IOS;
	precompute();
	cin >> n >> K;
	int ans = pow(K, n * n, MOD);
	int sign = 1;
	for(int i = 0; i <= n; i++)
	{
		for(int j = 0; j <= n; j++)
		{
			if(i + j == 0)
				continue;
			int tot = i * n + j * n - i * j;
			int sign = 1;
			if((i + j) % 2)
				sign *= -1;
			int ways = pow(K - 1, tot, MOD);
			ways *= nCr(n, i);
			ways %= MOD;
			ways *= nCr(n, j);
			ways %= MOD;
			ways *= pow(K, n * n - tot, MOD);
			ways %= MOD;
			ans += (sign * ways) % MOD;
			ans %= MOD;
			ans += MOD;
			ans %= MOD;
		}
	}
	cout << ans;
	return 0;
}