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
const int N=3e5+9;
int n,x,a[N],dp[N][3];
signed main()
{
	n=read(),x=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=n;i++)
	{
		dp[i][0]=max(dp[i-1][0]+a[i],0ll);
		dp[i][1]=max(dp[i-1][0]+a[i]*x,max(dp[i-1][1]+a[i]*x,0ll));
		dp[i][2]=max(max(dp[i-1][1],dp[i-1][2])+a[i],0ll);
	}
	int ans=0;
	for(int i=1;i<=n;i++)
		for(int j=0;j<3;j++)
			ans=max(ans,dp[i][j]);
	cout<<ans<<endl;
	return 0;
}