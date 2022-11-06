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
const int INF=1e15;
int n,val[100009],w[100009],dp[100009][6];
char a[100009];
signed main()
{
	n=read();
	scanf("%s",a+1);
	for(int i=1;i<=n;i++)w[i]=read();
	for(int i=0;i<=n;i++)
		for(int j=0;j<=4;j++)dp[i][j]=INF;
	for(int i=1;i<=n;i++)
		if(a[i]=='h')val[i]=1;
		else if(a[i]=='a')val[i]=2;
		else if(a[i]=='r')val[i]=3;
		else if(a[i]=='d')val[i]=4;
		else val[i]=0;
//	for(int i=1;i<=n;i++)cout<<val[i]<<" ";cout<<endl;
	dp[0][0]=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=3;j++)
			if(j!=val[i]-1)dp[i][j]=dp[i-1][j];
		if(val[i]!=0)dp[i][val[i]]=min(dp[i][val[i]],dp[i-1][val[i]-1]);
		if(val[i]!=0)dp[i][val[i]-1]=min(dp[i][val[i]-1],dp[i-1][val[i]-1]+w[i]);
	//	for(int j=0;j<=3;j++)cout<<dp[i][j]<<" ";cout<<endl;
	}
	int ans=INF;
	for(int i=0;i<=3;i++)ans=min(ans,dp[n][i]);
	cout<<ans<<endl;
	return 0;
}