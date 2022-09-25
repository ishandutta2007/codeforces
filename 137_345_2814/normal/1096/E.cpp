#include<cstdio>
using namespace std;
#define N 10001
#define mod 998244353
int fr[N],ifr[N],n,m,s;
int pw(int a,int p){int ans=1;while(p){if(p&1)ans=1ll*ans*a%mod;a=1ll*a*a%mod;p>>=1;}return ans;}
int C(int i,int j){if(j<0||i<=0||i<j)return 0;return 1ll*fr[i]*ifr[j]%mod*ifr[i-j]%mod;}
int dp(int x,int y,int s)
{
	if(x<0||y*s<x)return 0;
	if(y==0||x==0||s==0)return 1;
	int ans=0;
	for(int i=0,tmp=1;i<=y;i++,tmp=-tmp)
	ans=(ans+1ll*tmp*C(y,i)*C(x-(s+1)*i+y-1,y-1)%mod+mod)%mod;
	return ans;
}
int main()
{
	scanf("%d%d%d",&n,&m,&s);fr[0]=ifr[0]=1;
	if(n==1){printf("1\n");return 0;}
	for(int i=1;i<=10000;i++)fr[i]=1ll*fr[i-1]*i%mod,ifr[i]=1ll*ifr[i-1]*pw(i,mod-2)%mod;
	int ans=0;
	for(int i=s;i<=m;i++)
	for(int j=1;j<=n;j++)
	ans=(ans+1ll*C(n-1,j-1)*dp(m-i*j,n-j,i-1)%mod*pw(j,mod-2))%mod;
	printf("%lld\n",1ll*ans*pw(C(m-s+n-1,n-1),mod-2)%mod);
}