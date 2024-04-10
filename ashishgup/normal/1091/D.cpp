#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e6+5;
const int MOD=998244353;

int n, ans=0;
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

int32_t main()
{
	IOS;
	precompute();
	cin>>n;
	int ans=fact[n]*n;
	ans%=MOD;
	for(int k=1;k<=n;k++)
	{
		int cur=k*k;
		cur%=MOD;
		cur*=nCr(n, k+1);
		cur%=MOD;
		cur*=fact[n-k-1];
		cur%=MOD;
		ans-=cur;
		ans+=MOD;
		ans%=MOD;
	}
	ans-=(n-1);
	ans+=MOD;
	ans%=MOD;
	cout<<ans;
	return 0;
}