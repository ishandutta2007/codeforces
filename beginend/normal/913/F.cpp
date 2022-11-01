#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long LL;

const int N=2005;
const int MOD=998244353;

int n,win[N],los[N],cp[N][N],strong[N],ans[N],a,b;

int ksm(int x,int y)
{
	int ans=1;
	while (y)
	{
		if (y&1) ans=(LL)ans*x%MOD;
		x=(LL)x*x%MOD;y>>=1;
	}
	return ans;
}

int main()
{
	scanf("%d%d%d",&n,&a,&b);
	win[0]=los[0]=1;win[1]=(LL)a*ksm(b,MOD-2)%MOD;los[1]=(1+MOD-win[1])%MOD;
	for (int i=2;i<=n;i++) win[i]=(LL)win[i-1]*win[1]%MOD,los[i]=(LL)los[i-1]*los[1]%MOD;
	cp[1][0]=cp[1][1]=1;
	for (int s=2;s<=n;s++)
	{
		cp[s][0]=1;
		for (int i=1;i<=s;i++)
		{
			cp[s][i]=(LL)cp[s-1][i]*los[i]%MOD+(LL)cp[s-1][i-1]*win[s-i]%MOD;
			cp[s][i]-=cp[s][i]>=MOD?MOD:0;
		}
	}
	strong[1]=1;
	for (int s=2;s<=n;s++)
	{
		strong[s]=1;
		for (int i=1;i<s;i++)
		{
			strong[s]+=MOD-(LL)strong[i]*cp[s][i]%MOD;
			strong[s]-=strong[s]>=MOD?MOD:0;
		}
	}
	ans[0]=ans[1]=0;
	for (int s=2;s<=n;s++)
	{
		for (int i=1;i<s;i++)
		{
			ans[s]+=(LL)strong[i]*cp[s][i]%MOD*((LL)i*(s-i)+(LL)i*(i-1)/2+(LL)ans[i]+(LL)ans[s-i])%MOD;
			ans[s]-=ans[s]>=MOD?MOD:0;
		}
		ans[s]+=(LL)strong[s]*cp[s][s]%MOD*(s*(s-1)/2)%MOD;
		ans[s]=(LL)ans[s]*ksm(1+MOD-(LL)strong[s]*cp[s][s]%MOD,MOD-2)%MOD;
	}
	printf("%d",ans[n]);
	return 0;
}