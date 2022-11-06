//zhouakngyang txdy!
#include<bits/stdc++.h>
using namespace std;
//#define int long long
inline int read()
{
	int sum=0,nega=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')nega=-1;ch=getchar();}
	while(ch<='9'&&ch>='0')sum=sum*10+ch-'0',ch=getchar();
	return sum*nega;
}
const int mod=1e9+7;
int taxi,n,m;
long long ans,dp[13][200009];
int main()
{
	for(int i=0;i<=9;i++)dp[i][0]=1;
	for(int i=1;i<=200000;i++)
		for(int j=0;j<=9;j++)
			if(i+j>=10)dp[j][i]=(dp[1][i+j-10]+dp[0][i+j-10])%mod;
			else dp[j][i]=1;
	taxi=read();
	for(int ttt=1;ttt<=taxi;ttt++)
	{
		ans=0;
		n=read();m=read();
		while(n!=0)
		{
			ans=ans+dp[n%10][m];ans=ans%mod;
			n=n/10;
		}
		printf("%lld\n",ans);
	}
	return 0;
}