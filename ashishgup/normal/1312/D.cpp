#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 2e5 + 5;
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

int n, m;

int32_t main()
{
	IOS;
	precompute();
	cin >> n >> m;
	int fixed = 0;
	for(int l = 1; l <= n - 2; l++)
	{
		fixed += l * nCr(n - 2, l);
		fixed %= MOD;
	}
	int lhs = 0;
	for(int x = n - 1; x <= m; x++)
	{
		lhs += nCr(x - 1, n - 2);
		lhs %= MOD;
	}
	int ans = lhs * fixed;
	ans %= MOD;
	cout << ans;
	return 0;
}