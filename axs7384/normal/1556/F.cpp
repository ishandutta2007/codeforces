#include<bits/stdc++.h>
using namespace std;
#define ll long long
// #define int long long
const int mod=1e9+7;
int ksm(int x,int y)
{
	int ans=1;
	for (;y;y/=2,x=(ll)x*x%mod)
		if (y&1)
			ans=(ll)ans*x%mod;
	return ans;
}
const int N=14;
int f[1<<N|5],h[1<<N|5];
int win[20][20];
//int g[20],invg[20];
int g[15][1<<N|5];
int lg[1<<N|5];
int a[20];
int n;
int ans;
signed main()
{
	scanf("%d",&n);
	for (int i=0;i<n;++i)
		scanf("%d",&a[i]);
	for (int i=0;i<n;++i)
		for (int j=0;j<n;++j)
			win[i][j]=(ll)a[i]*ksm(a[i]+a[j],mod-2)%mod;
	for (int i=0;i<n;++i)
		lg[1<<i]=i;
	for (int i=0;i<n;++i)
	{
		g[i][0]=1;
		for (int j=1;j<(1<<n);++j)
			g[i][j]=(ll)g[i][j-(j&(-j))]*win[i][lg[j&(-j)]]%mod;
	}
	int full=(1<<n)-1;
	for (int i=1;i<(1<<n);++i)
	{
		f[i]=f[i-(i&(-i))]+1;
		h[i]=1;
		for (int j=(i-1)&i;j;j=(j-1)&i)
		{
			int p=1;
			for (int k=0;k<n;++k)
				if ((1<<k)&j)
					p=(ll)p*g[k][i^j]%mod;
			h[i]=(h[i]-(ll)p*h[j]%mod+mod)%mod;
		}
		int sum=1;
		for (int j=0;j<n;++j)
		{
			if ((1<<j)&i)
				sum=(ll)sum*g[j][full^i]%mod;
		}
		(ans+=(ll)f[i]*h[i]%mod*sum%mod)%=mod;
	}
	cout<<ans<<endl;
	return 0;
}