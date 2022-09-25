#include<cstdio>
#include<map>
using namespace std;
#define mod 998244353
#define mod2 998244352
#define N 102
int k,n,m,b[N];
struct dp{int s[N][N];dp(){for(int i=1;i<=k;i++)for(int j=1;j<=k;j++)s[i][j]=0;}}e;
void mul(dp &a,dp b)
{
	dp c;
	for(int i=1;i<=k;i++)
	for(int l=1;l<=k;l++)
	if(a.s[i][l])
	for(int j=1;j<=k;j++)
	c.s[i][j]=(c.s[i][j]+1ll*a.s[i][l]*b.s[l][j])%mod2;
	for(int i=1;i<=k;i++)
	for(int j=1;j<=k;j++)
	a.s[i][j]=c.s[i][j];
}
map<int,int> s1;
void pw(dp &a,int p){dp ans;for(int i=1;i<=k;i++)ans.s[i][i]=1;while(p){if(p&1)mul(ans,a);mul(a,a);p>>=1;}a=ans;}
int pw(int a,int p){int ans=1;while(p){if(p&1)ans=1ll*ans*a%mod;a=1ll*a*a%mod;p>>=1;}return ans;}
int fakebsgs(int a,int b)
{
	int sz=50000;
	for(int i=1,s=a;i<=sz;i++,s=1ll*s*a%mod)
	{
		if(b==s)return i;
		s1[s]=i;
	}
	int tmp=pw(a,sz),st=tmp;
	for(int i=1;i<=20000;i++)
	{
		int tmp2=1ll*st*pw(b,mod-2)%mod;
		if(s1[tmp2]!=0)
		return i*sz-s1[tmp2];
		st=1ll*st*tmp%mod;
	}
}
int exgcd(int a,int b,int &x,int &y)
{
	if(!b){x=1,y=0;return a;}
	int g=exgcd(b,a%b,x,y);int t=x;x=y;y=t-a/b*y;return g;
}
int main()
{
	scanf("%d",&k);
	for(int i=1;i<=k;i++)scanf("%d",&b[i]),e.s[i][1]=b[i];
	for(int i=1;i<k;i++)e.s[i][i+1]=1;
	scanf("%d%d",&n,&m);
	pw(e,n-k);
	int tmp=e.s[1][1],s1=fakebsgs(3,m);
	int x,y;int gcd=exgcd(tmp,mod2,x,y);
	if(s1%gcd){printf("-1\n");return 0;}
	x=(1ll*x*s1/gcd%(mod2/gcd)+(mod2/gcd))%(mod2/gcd);
	printf("%d\n",pw(3,x));
}