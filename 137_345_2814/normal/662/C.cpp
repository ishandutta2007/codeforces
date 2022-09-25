#include<cstdio>
using namespace std;
int n,m;
char s[105000];
int dp[1050000][21],v[1050000],v2[105000];
void solve()
{
	for(int i=0;i<1<<n;i++)dp[i][0]=v[i];
	for(int l=2,st=0;l<=1<<n;l<<=1,st++)
	for(int i=0;i<1<<n;i+=l)
	for(int j=i;j<i+(l>>1);j++)
	for(int k=st;k>=0;k--)
	dp[j][k+1]+=dp[j+(l>>1)][k],dp[j+(l>>1)][k+1]+=dp[j][k];
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s+1);
		for(int j=1;j<=m;j++)v2[j]|=(s[j]-'0')<<i-1;
	}
	for(int i=1;i<=m;i++)v[v2[i]]++;
	solve();
	int as=1e8;
	for(int i=0;i<1<<n;i++)
	{
		int tp=0;
		for(int j=0;j<=n;j++)tp+=dp[i][j]*(j<n-j?j:n-j);
		if(tp<as)as=tp;
	}
	printf("%d\n",as);
}