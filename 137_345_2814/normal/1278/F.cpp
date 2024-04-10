#include<cstdio>
using namespace std;
#define N 5050
#define mod 998244353
int n,m,k,s[N][N];
int pw(int a,int p){int as=1;while(p){if(p&1)as=1ll*as*a%mod;a=1ll*a*a%mod;p>>=1;}return as;}
int calc(int x,int y){int as=1;for(int i=1;i<=y;i++)as=1ll*as*(x-i+1)%mod;return as;}
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	s[0][0]=1;
	for(int i=1;i<=k;i++)
	for(int j=1;j<=i;j++)
	s[i][j]=(s[i-1][j-1]+1ll*s[i-1][j]*j)%mod;
	int as=0;for(int i=1;i<=n&&i<=k;i++)as=(as+1ll*s[k][i]*pw(pw(m,mod-2),i)%mod*calc(n,i))%mod;
	printf("%d\n",as);
}