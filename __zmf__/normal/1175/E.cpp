//zhouakngyang txdy!
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include<bits/stdc++.h>
#define Macesuted cout<<"kawaii"<<endl
#define MatrixCascade cout<<"npsl"<<endl
#define Karry5307 cout<<"nmsl"<<endl
using namespace std;
//#define int long long
inline int read()
{
	int sum=0,nega=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')nega=-1;ch=getchar();}
	while(ch<='9'&&ch>='0')sum=sum*10+ch-'0',ch=getchar();
	return sum*nega;
}
const int N=5e5+9,M=21,K=5e5;
int n,l,r,q;
int dp[M][N]; 
inline int solve()
{
	int now=l,ans=0;
	for(int i=18;i>=0;i--)
		if(dp[i][now]<r&&dp[i][now]!=0)now=dp[i][now],ans+=(1<<i);
	now=dp[0][now];
	if(now<r)return -1;
	else return ans+1;
}
int main()
{
	n=read();q=read();
	for(int i=1;i<=n;i++)
	{
		l=read(),r=read();
		dp[0][l]=max(dp[0][l],r);
	}
	for(int i=1;i<=K;i++)dp[0][i]=max(dp[0][i],dp[0][i-1]);
	for(int i=1;i<=18;i++)
	{
		for(int j=0;j<=K;j++)
			if(dp[i-1][j]!=0&&dp[i-1][j]<=K)dp[i][j]=dp[i-1][dp[i-1][j]];
		for(int j=0;j<=K;j++)dp[i][j]=max(dp[i][j],dp[i][j-1]);
	}
	for(int i=1;i<=q;i++)
	{
		l=read(),r=read();
		printf("%d\n",solve());
	}
	return 0;
}