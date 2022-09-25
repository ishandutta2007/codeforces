#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define mod 998244353
#define ll long long
#define N 2050
#define md 1000000007
char a[2][N],c[N];
int dp[N][2][N],n,m;
ll ha[N][2],rha[N][2],ha2[N],pw[N],ch=131,as;
int getha(int i,int j,int k){return ((ha[j][k]-ha[i-1][k]*pw[j-i+1]%mod)%mod+mod)%mod;}
int getrha(int i,int j,int k){return ((rha[i][k]-rha[j+1][k]*pw[j-i+1]%mod)%mod+mod)%mod;}
int getcha(int i,int j){return ((ha2[j]-ha2[i-1]*pw[j-i+1]%mod)%mod+mod)%mod;}
int main()
{
	scanf("%s%s%s",a[0]+1,a[1]+1,c+1);
	n=strlen(a[0]+1);m=strlen(c+1);
	if(m==1)
	{
		for(int i=1;i<=n;i++)as+=(a[0][i]==c[1])+(a[1][i]==c[1]);
		printf("%d\n",as);return 0;
	}
	if(m==2)
	{
		for(int i=1;i<=n;i++)
		{
			if(a[0][i]==c[1]&&a[0][i-1]==c[2])as++;
			if(a[0][i]==c[1]&&a[0][i+1]==c[2])as++;
			if(a[0][i]==c[1]&&a[1][i]==c[2])as++;
			if(a[1][i]==c[1]&&a[1][i-1]==c[2])as++;
			if(a[1][i]==c[1]&&a[1][i+1]==c[2])as++;
			if(a[1][i]==c[1]&&a[0][i]==c[2])as++;
		}
		printf("%d\n",as);return 0;
	}
	pw[0]=1;
	for(int i=1;i<=2000;i++)pw[i]=pw[i-1]*ch%mod;
	for(int i=1;i<=n;i++)ha[i][0]=(ha[i-1][0]*ch+a[0][i])%mod,ha[i][1]=(ha[i-1][1]*ch+a[1][i])%mod;
	for(int i=1;i<=m;i++)ha2[i]=(ha2[i-1]*ch+c[i])%mod;
	for(int i=n;i>=1;i--)rha[i][0]=(rha[i+1][0]*ch+a[0][i])%mod,rha[i][1]=(rha[i+1][1]*ch+a[1][i])%mod;
	for(int i=1;i<=n;i++)
	for(int j=i;j<=n;j++)
	if(2*(j-i+1)<=m&&i!=j)
	{
		if(getrha(i,j,1)==getcha(1,j-i+1)&&getha(i,j,0)==getcha(j-i+2,2*(j-i+1)))
		dp[j][0][2*(j-i+1)]++;
		if(getrha(i,j,0)==getcha(1,j-i+1)&&getha(i,j,1)==getcha(j-i+2,2*(j-i+1)))
		dp[j][1][2*(j-i+1)]++;
	}
	for(int i=1;i<=n;i++)
	{
		if(a[0][i]==c[1])dp[i][0][1]++;
		if(a[1][i]==c[1])dp[i][1][1]++;
		if(a[0][i]==c[1]&&a[1][i]==c[2])dp[i][1][2]++;
		if(a[1][i]==c[1]&&a[0][i]==c[2])dp[i][0][2]++;
	}
	for(int i=2;i<=n;i++)
	for(int j=1;j<=m;j++)
	{
		if(a[0][i]==c[j+1])dp[i][0][j+1]=(dp[i][0][j+1]+dp[i-1][0][j])%md;
		if(a[1][i]==c[j+1])dp[i][1][j+1]=(dp[i][1][j+1]+dp[i-1][1][j])%md;
		if(a[0][i]==c[j+1]&&a[1][i]==c[j+2])dp[i][1][j+2]=(dp[i][1][j+2]+dp[i-1][0][j])%md;
		if(a[1][i]==c[j+1]&&a[0][i]==c[j+2])dp[i][0][j+2]=(dp[i][0][j+2]+dp[i-1][1][j])%md;
	}
	for(int i=1;i<=n;i++)
	for(int j=i;j<=n;j++)
	if(2*(j-i+1)<m&&i!=j)
	{
		if(getha(i,j,0)==getcha(m-(j-i+1)*2+1,m-(j-i+1))&&getrha(i,j,1)==getcha(m-(j-i+1)+1,m))as=(as+dp[i-1][0][m-2*(j-i+1)])%md;
		if(getha(i,j,1)==getcha(m-(j-i+1)*2+1,m-(j-i+1))&&getrha(i,j,0)==getcha(m-(j-i+1)+1,m))as=(as+dp[i-1][1][m-2*(j-i+1)])%md;
	}
	for(int i=1;i<=n;i++)as=(as+dp[i][0][m]+dp[i][1][m])%md;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	dp[i][0][j]=dp[i][1][j]=0;
	for(int i=1;i*2<=n;i++)swap(a[0][i],a[0][n-i+1]),swap(a[1][i],a[1][n-i+1]);
	for(int i=1;i<=n;i++)ha[i][0]=(ha[i-1][0]*ch+a[0][i])%mod,ha[i][1]=(ha[i-1][1]*ch+a[1][i])%mod;
	for(int i=n;i>=1;i--)rha[i][0]=(rha[i+1][0]*ch+a[0][i])%mod,rha[i][1]=(rha[i+1][1]*ch+a[1][i])%mod;
	for(int i=1;i<=n;i++)
	for(int j=i;j<=n;j++)
	if(2*(j-i+1)<=m&&i!=j)
	{
		if(getrha(i,j,1)==getcha(1,j-i+1)&&getha(i,j,0)==getcha(j-i+2,2*(j-i+1)))dp[j][0][2*(j-i+1)]++;
		if(getrha(i,j,0)==getcha(1,j-i+1)&&getha(i,j,1)==getcha(j-i+2,2*(j-i+1)))dp[j][1][2*(j-i+1)]++;
	}
	for(int i=1;i<=n;i++)
	{
		if(a[0][i]==c[1])dp[i][0][1]++;
		if(a[1][i]==c[1])dp[i][1][1]++;
		if(a[0][i]==c[1]&&a[1][i]==c[2])dp[i][1][2]++;
		if(a[1][i]==c[1]&&a[0][i]==c[2])dp[i][0][2]++;
	}
	for(int i=2;i<=n;i++)
	for(int j=1;j<=m;j++)
	{
		if(a[0][i]==c[j+1])dp[i][0][j+1]=(dp[i][0][j+1]+dp[i-1][0][j])%md;
		if(a[1][i]==c[j+1])dp[i][1][j+1]=(dp[i][1][j+1]+dp[i-1][1][j])%md;
		if(a[0][i]==c[j+1]&&a[1][i]==c[j+2])dp[i][1][j+2]=(dp[i][1][j+2]+dp[i-1][0][j])%md;
		if(a[1][i]==c[j+1]&&a[0][i]==c[j+2])dp[i][0][j+2]=(dp[i][0][j+2]+dp[i-1][1][j])%md;
	}
	for(int i=1;i<=n;i++)
	for(int j=i;j<=n;j++)
	if(2*(j-i+1)<m&&i!=j)
	{
		if(getha(i,j,0)==getcha(m-(j-i+1)*2+1,m-(j-i+1))&&getrha(i,j,1)==getcha(m-(j-i+1)+1,m))as=(as+dp[i-1][0][m-2*(j-i+1)])%md;
		if(getha(i,j,1)==getcha(m-(j-i+1)*2+1,m-(j-i+1))&&getrha(i,j,0)==getcha(m-(j-i+1)+1,m))as=(as+dp[i-1][1][m-2*(j-i+1)])%md;
	}
	for(int i=1;i<=n;i++)as=(as+dp[i][0][m]+dp[i][1][m])%md;
	printf("%d\n",(as+md)%md);
}