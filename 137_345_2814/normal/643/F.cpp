#include<cstdio>
using namespace std;
#define N 133
#define M 2005000
#define K 23333
#define mod 4294967295ll
#define int unsigned int
int dp[K][N],n,p,q,as,f[N][N];
struct mat{int s[N][N];mat(){for(int i=0;i<=p;i++)for(int j=0;j<=p;j++)s[i][j]=0;}}v[N],a;
mat mul(mat a,mat b){mat c;for(int i=0;i<=p;i++)for(int k=0;k<=p;k++)if(a.s[i][k])for(int j=0;j<=p;j++)c.s[i][j]=(c.s[i][j]+1ull*a.s[i][k]*b.s[k][j])&mod;return c;}
mat pw(mat a,int b){mat as;for(int i=0;i<=p;i++)as.s[i][i]=1;while(b){if(b&1)as=mul(as,a);a=mul(a,a);b>>=1;}return as;}
#define ll long long
ll exgcd(ll a,ll b,ll &x,ll &y){if(!b){x=1,y=0;return a;}int g=exgcd(b,a%b,y,x);y=y-a/b*x;return g;}
int getinv(int s){ll x,y;exgcd(s,1ull<<32,x,y);
return (x+(1ull<<32))&mod;}
int C(int i,int j)
{
	int st1=1,st2=0;
	for(int k=1;k<=j;k++)
	{
		int l=i-k+1,r=k;
		while(~l&1)l>>=1,st2++;
		while(~r&1)r>>=1,st2--;
		st1=(1ull*st1*l)&mod;
		st1=(1ull*st1*getinv(r))&mod;
	}
	st1<<=st2;
	return st1&mod;
}
signed main()
{
	scanf("%u%u%u",&n,&p,&q);
	for(int i=0;i<=p;i++)dp[0][i]=1;
	if(p>=n)p=n-1;
	for(int j=0;j<=p;j++)for(int k=0;k<=j;k++)f[j][k]=C(n-(p-j),j-k);
	for(int i=1;i<=q&&i<=16000;i++)
	for(int j=0;j<=p;j++)
	for(int k=0;k<=j;k++)
	dp[i][j]+=dp[i-1][k]*f[j][k];
	for(int j=0;j<=p;j++)for(int k=0;k<=j;k++)a.s[j][k]=f[j][k];
	a=pw(a,16000);
	for(int j=0;j<=p;j++)v[0].s[j][j]=1;
	for(int i=1;i<=130;i++)v[i]=mul(v[i-1],a);
	for(int i=1;i<=q;i++)
	{
		int as1=0;
		int st1=i%16000,st2=i/16000;
		for(int j=0;j<=p;j++)
		as1+=1ull*v[st2].s[p][j]*dp[st1][j];
		as^=1ull*i*as1;
	}
	printf("%u\n",as);
}