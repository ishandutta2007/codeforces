//zhouakngyang txdy!
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
const int mod=998244353;
int n,m,c[509];
int dp[509][509],sum[509][509];
signed main()
{
	n=read(),m=read();
	for(int i=1;i<=n;i++)c[i]=read();
	for(int i=1;i<=n+1;i++)dp[i][i-1]=sum[i][i-1]=1;
	for(int len=1;len<=n;len++)
		for(int i=1;i+len-1<=n;i++)
		{
			int j=i+len-1;
			if(len==1)
			{
				sum[i][j]=dp[i][j]=1;continue;
			}
			int Min=1e9+7,p=i;
			for(int k=i;k<=j;k++)
				if(Min>c[k])Min=c[k],p=k;
//			dp[i][j]=(dp[i][j]+sum[i][p-1]*sum[p+1][j]%mod)%mod;
//			for(int k=i;k<=j;k++)sum[i][j]=(sum[i][j]+dp[i][k]*dp[k+1][j]%mod)%mod;
//			cout<<i<<" "<<j<<" "<<dp[i][j]<<" "<<sum[i][j]<<" "<<p<<endl;
			sum[i][j]=(sum[i][j]+dp[i][p-1]*dp[p+1][j]%mod)%mod;
			dp[i][j]=sum[i][j];
			for(int k=i;k<j;k++)dp[i][j]=(dp[i][j]+sum[i][k]*dp[k+1][j]%mod)%mod;
		}
	cout<<dp[1][n]<<endl;
	return 0;
}