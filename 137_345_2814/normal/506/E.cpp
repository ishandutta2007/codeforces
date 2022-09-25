#include<cstdio>
#include<cstring>
#define mod 10007
using namespace std;
#define N 420
struct mat{int s[410][410];}t;
int n,m,dp[N][N][N],ct,as[N];
char s[N];
void mul(mat &a,mat &b)
{
	mat c;
	for(int i=1;i<=ct;i++)for(int j=1;j<=ct;j++)c.s[i][j]=0;
	for(int k=1;k<=ct;k++)
	for(int i=1;i<=k;i++)
	if(a.s[i][k])
	for(int j=k;j<=ct;j++)
	c.s[i][j]=(c.s[i][j]+1ll*a.s[i][k]*b.s[k][j])%mod;
	a=c;
}
void pw(mat &a,int p)
{
	mat b;
	for(int i=1;i<=ct;i++)for(int j=1;j<=ct;j++)b.s[i][j]=(i==j);
	while(p){if(p&1)mul(b,a);mul(a,a);p>>=1;}
	a=b;
}
int main()
{
	scanf("%s%d",s+1,&n);
	m=strlen(s+1);
	dp[1][m][0]=1;
	for(int i=1;i<=m;i++)
	for(int j=m;j>=i;j--)
	for(int k=0;k<=m;k++)
	{
		if(s[j]==s[i])
		{
			if(j-i<=1)as[k]=(as[k]+dp[i][j][k])%mod;
			else dp[i+1][j-1][k]=(dp[i+1][j-1][k]+dp[i][j][k])%mod;
		}
		else
		dp[i+1][j][k+1]=(dp[i+1][j][k+1]+dp[i][j][k])%mod,
		dp[i][j-1][k+1]=(dp[i][j-1][k+1]+dp[i][j][k])%mod;
	}
	if((~(n+m))&1)
	{
		int v1=m,v2=(m+1)/2;
		ct=v1+v2*2;
		for(int i=1;i<=v1;i++)t.s[i][i]=24,t.s[i][i+1]=1;
		for(int i=1;i<=v2;i++)t.s[v1+i*2-1][v1+i*2]=t.s[v1+i*2-1][v1+i*2+1]=1,t.s[v1+i*2-1][v1+i*2-1]=25,t.s[v1+i*2][v1+i*2]=26;
		pw(t,(n+m)/2);
		int as1=0;
		for(int i=0;i<v1;i++)
		as1=(as1+1ll*t.s[v1+1-i][v1+(v1-i+1)/2*2]*as[i])%mod;
		printf("%d\n",as1);
	}
	else
	{
		int v1=m,v2=(m+1)/2;
		ct=v1+v2*2;
		for(int i=1;i<=v1;i++)t.s[i][i]=24,t.s[i][i+1]=1;
		for(int i=1;i<=v2;i++)t.s[v1+i*2-1][v1+i*2]=t.s[v1+i*2-1][v1+i*2+1]=1,t.s[v1+i*2-1][v1+i*2-1]=25,t.s[v1+i*2][v1+i*2]=26;
		pw(t,(n+m)/2);
		int as1=0;
		for(int i=0;i<v1;i++)
		as1=(as1+26ll*t.s[v1+1-i][v1+(v1-i+1)/2*2]%mod*as[i])%mod;
		for(int i=1;i<=m;i++)
		{
			for(int j=0;j<=m-1;j++)
			as1=(as1+1ll*t.s[v1-j+1][v1+(v1-j+1)/2*2-1]*dp[i][i][j])%mod;
		}
		printf("%d\n",as1);
	}
}