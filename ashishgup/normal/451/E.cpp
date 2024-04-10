#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e6+5;
const int MOD=1e9+7;

int n, s;
int a[N];
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

int nCr(int n, int r) //Difference between n and r is small
{		
	if(n<0 || r>n)
		return 0;
	int ans=1;
	for(int i=n;i>=n-r+1;i--)
	{
		ans*=(i%MOD);
		ans%=MOD;
	}
	ans*=invfact[r];
	ans%=MOD;
	return ans;
}

int32_t main()
{
	IOS;
	precompute();
	cin>>n>>s;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	int ans=0;
	for(int i=0;i<(1LL<<n);i++)
	{
		int ct=0;
		int sum=s;
		for(int j=0;j<n;j++)
		{
			if(i&(1LL<<j))
			{
				ct++;
				sum-=(a[j+1]+1);
			}
		}
		int cur=nCr(sum+n-1, n-1);
		if(ct%2)
			ans=(ans-cur+MOD)%MOD;
		else
			ans=(ans+cur)%MOD;
	}
	cout<<ans;
	return 0;
}