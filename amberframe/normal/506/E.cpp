#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <string.h>
#include <time.h>

using namespace std;
typedef long long LL;
const int maxn = 405;
const LL mod = 10007;
const LL lim = 7e18;

int o,s,n,N;char str[maxn];
LL dp[maxn][maxn][maxn],f[maxn];
LL ans;
LL tr[maxn][maxn];
LL pw[maxn][maxn];
LL u[maxn][maxn];
LL v[maxn][maxn];

int check(int i,int j)
	{return i<j&&str[i]!=str[j];}
void add(LL &x,LL y)
	{x+=y;x>=mod?x-=mod:0;}

namespace expo {
	LL tmp1[maxn][maxn];
	LL tmp2[maxn][maxn];
	void mul(LL a[maxn][maxn],LL b[maxn][maxn])
	{
		for (int i=1;i<=o;i++)
		for (int j=i;j<=o;j++)
			tmp1[i][j]=a[i][j],tmp2[j][i]=b[i][j];
		for (int i=1;i<=o;i++)
		for (int j=i;j<=o;j++)
		{
			LL sum1=0,sum2=0,sum3=0,sum4=0;
			for (int k=i;k<=j;k+=4)
			{
				sum1+=tmp1[i][k]*tmp2[j][k];
				sum2+=tmp1[i][k+1]*tmp2[j][k+1];
				sum3+=tmp1[i][k+2]*tmp2[j][k+2];
				sum4+=tmp1[i][k+3]*tmp2[j][k+3];
			}
			a[i][j]=sum1+sum2+sum3+sum4;
		}
		for (int i=1;i<=o;i++)
		for (int j=i;j<=o;j++)
			a[i][j]%=mod;
	}
	void fpm(LL a[maxn][maxn],LL b[maxn][maxn],int K)
	{
		while (K) {
			if (K&1) mul(a,b);
			K>>=1;mul(b,b);
		}
	}
}
using namespace expo ;

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("gift.in","r",stdin);
		freopen("gift.out","w",stdout);
	#endif
	scanf("%s %d",str+1,&n);
	s=strlen(str+1);N=n+s;
	
	dp[1][s][check(1,s)]=1;
	for (int p=s-1;p>=0;p--)
	for (int i=1,j=i+p;j<=s;i++,j++)
	for (int k=0;k<=s;k++)
	if (LL w=dp[i][j][k]) {
		if (check(i,j)) {
			add(dp[i+1][j][k+check(i+1,j)],w);
			add(dp[i][j-1][k+check(i,j-1)],w);
		}
		else add(dp[i+1][j-1][k+check(i+1,j-1)],w);
	}
	
	for (int i=0;i<=s+1;i++)
	for (int j=0;j<i;j++)
	for (int k=0;k<=s;k++)
		add(f[k],dp[i][j][k]);
	
	int x=s-1,_=s+1>>1,y=x+_;o=y+_;
	for (int i=1;i<=x;i++) tr[i][i]=24;
	for (int i=x+1;i<=y;i++) tr[i][i]=25;
	for (int i=y+1;i<=o;i++) tr[i][i]=26;
	for (int i=1;i<y;i++) tr[i][i+1]=1;
	for (int i=x+1;i<=y;i++) tr[i][i+_]=1;
	
	for (int i=1;i<=o;i++) u[i][i]=1;
	memcpy(pw,tr,sizeof pw);fpm(u,pw,(N+1)/2-1);
	memcpy(v,u,sizeof u);mul(v,tr);
	
	for (int n24=0;n24<s;n24++)
	{
		int n25=s-n24+1>>1;
		ans=(ans+f[n24]*v[x-n24+1][y+n25])%mod;
		if ((N&1)&&(s-n24&1)==0)
			ans=(ans-f[n24]*u[x-n24+1][x+n25])%mod;
	}
	printf("%lld",ans<0?ans+mod:ans);
	return 0;
}