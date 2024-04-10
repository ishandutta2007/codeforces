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
const int N=5009;
int a[N],n,m,k;
int q[N][N],head[N],tail[N],dp[N][N];
signed main()
{
	n=read(),k=read(),m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=0;i<=m;i++)head[i]=1,tail[i]=0;tail[0]=1;
	for(int i=1;i<=n;i++)
		for(int j=0;j<=m;j++)
			dp[i][j]=-1e15;
	q[0][1]=0;dp[0][0]=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=m;j>=1;j--)
		{	
			while(head[j-1]<=tail[j-1]&&i-q[j-1][head[j-1]]>k)head[j-1]++;
			if(head[j-1]>tail[j-1])continue;
			dp[i][j]=dp[q[j-1][head[j-1]]][j-1]+a[i];
			while(head[j]<=tail[j]&&(dp[i][j]>=dp[q[j][tail[j]]][j]))tail[j]--;
			q[j][++tail[j]]=i;
		//	cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
		}
	}
	int ans=-1;
	for(int i=n-k+1;i<=n;i++)ans=max(ans,dp[i][m]);
	cout<<ans<<endl;
	return 0;
}