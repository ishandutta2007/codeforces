//zhouakngyang txdy!
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read()
{
	int sum=0,nega=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')nega=-1;ch=getchar();}
	while(ch<='9'&&ch>='0')sum=sum*10+ch-'0',ch=getchar();
	return sum*nega;
}
const int N=1e6+9,mod=1e9+7;
int dp[N],ans,sum[N],jc[N],n,k,inv[N];
inline int Pow(int x,int y)
{
	int res=1,base=x;
	while(y)
	{
		if(y&1)res=res*base%mod;
		base=base*base%mod;
		y>>=1;
	}
	return res;
}
signed main()
{
	n=read();k=read();
	dp[0]=sum[0]=1;
	jc[0]=1;
	for(int i=1;i<=n;i++)jc[i]=jc[i-1]*i%mod;inv[n]=Pow(jc[n],mod-2);
	for(int i=n-1;i>=0;i--)inv[i]=inv[i+1]*(i+1)%mod;
	for(int i=1;i<=n;i++)
	{
		if(i<=k)dp[i]=sum[i-1]*jc[i-1]%mod;
		else dp[i]=(sum[i-1]-sum[i-k-1]+mod)%mod*jc[i-1]%mod;
		sum[i]=(sum[i-1]+dp[i]*inv[i]%mod)%mod;
	}
	long long ans=0;
//	for(int i=1;i<=n;i++)cout<<dp[i]<<" ";cout<<endl;
	for(int i=1;i<=n;i++)
	{
		ans=(ans+dp[i-1]*jc[n-1]%mod*inv[i-1]%mod*inv[n-i]%mod*jc[n-i]%mod)%mod;
//		cout<<ans<<endl;
	}
	ans=(jc[n]-ans+mod)%mod;cout<<ans<<endl;
	return 0;
}