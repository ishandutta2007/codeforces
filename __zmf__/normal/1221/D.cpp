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
int taxi,n,a[300009],b[300009];
long long dp[300009][3],INF=1e18+9;
signed main()
{
	taxi=read();
	for(int ttt=1;ttt<=taxi;ttt++)
	{
		n=read();
		for(int i=1;i<=n;i++)a[i]=read(),b[i]=read();
		for(int i=1;i<=n;i++)
			for(int j=0;j<=2;j++)
				dp[i][j]=INF;
		dp[1][0]=0,dp[1][1]=b[1],dp[1][2]=b[1]*2;
		for(int i=2;i<=n;i++)
			for(int j=0;j<=2;j++)
				for(int k=0;k<=2;k++)
					if(a[i-1]+j!=a[i]+k)dp[i][k]=min(dp[i][k],dp[i-1][j]+k*b[i]);
		printf("%lld\n",min(min(dp[n][1],dp[n][0]),dp[n][2]));
	}
	return 0;
}