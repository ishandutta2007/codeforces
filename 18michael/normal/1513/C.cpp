#include<cstdio>
#define Mx 200009
#define mod 1000000007
int Test_num,n,m,ans;
int dp[200012];
inline void init()
{
	for(int i=0;i<10;++i)dp[i]=1;
	for(int i=10;i<=Mx;++i)dp[i]=(dp[i-9]+dp[i-10])%mod;
}
inline void solve()
{
	scanf("%d%d",&n,&m),ans=0;
	while(n)ans=(ans+dp[n%10+m])%mod,n/=10;
	printf("%d\n",ans);
}
int main()
{
	init(),scanf("%d",&Test_num);
	while(Test_num--)solve();
	return 0;
}//