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
const int N=2e6+9;
int taxi,mod=1e9+7,n,dp[N];
inline bool cmp(int xxx,int yyy)
{
	return xxx>yyy;
}
signed main()
{
	n=2e6;
	dp[1]=dp[2]=0,dp[3]=dp[4]=1;
	for(int i=5;i<=n;i++)
	{
		if(i%3==2)dp[i]=(2*dp[i-2]+dp[i-1])%mod;
		else dp[i]=(1+4*dp[i-4]+4*dp[i-3]+dp[i-2])%mod;
	}
	for(int i=1;i<=n;i++)dp[i]=dp[i]*4%mod;
	taxi=read();
	for(int ttt=1;ttt<=taxi;ttt++)
	{
		n=read();
		printf("%lld\n",dp[n]);
	}
	return 0;
}