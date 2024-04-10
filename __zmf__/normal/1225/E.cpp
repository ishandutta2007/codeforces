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
const int mod=1e9+7;
int n,m,flag;
char a[2009][2009];
int dp[2][2009][2009],sum[2][2009][2009],R[2][2009][2009];
signed main()
{
	n=read(),m=read();
	for(int i=1;i<=n;i++)scanf("%s",a[i]+1);
	for(int i=n;i>=1;i--)
		for(int j=m;j>=1;j--)
		{
			flag=0;
			if(a[i][j]=='R')flag=1;
			R[0][i][j]=R[0][i][j+1]+flag;
			R[1][i][j]=R[1][i+1][j]+flag;
		//	cout<<R[0][i][j]<<" "<<R[1][i][j]<<" "<<i<<" "<<j<<endl;
		}
	if(n+m==2)return puts("1"),0;
	dp[0][n][m]=dp[1][n][m]=sum[0][n][m]=sum[1][n][m]=1;
	for(int i=n;i>=1;i--)
		for(int j=m;j>=1;j--)
		{
			if(i==n&&j==m)continue;
			dp[0][i][j]=(sum[1][i][j+1]-sum[1][i][m-R[0][i][j+1]+1]+mod)%mod;
			dp[1][i][j]=(sum[0][i+1][j]-sum[0][n-R[1][i+1][j]+1][j]+mod)%mod;
			sum[0][i][j]=(sum[0][i+1][j]+dp[0][i][j])%mod;
			sum[1][i][j]=(sum[1][i][j+1]+dp[1][i][j])%mod;
		}
	cout<<(dp[0][1][1]+dp[1][1][1]+mod+mod)%mod<<endl;
	return 0;
}