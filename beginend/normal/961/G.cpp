#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long LL;

const int N=200005;
const int MOD=1000000007;

int n,k,jc[N],ny[N];

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

int S(int n,int m)
{
	int ans=0;
	for (int i=1;i<=m;i++)
		if ((m-i)&1) (ans+=MOD-(LL)ksm(i,n)*ny[i]%MOD*ny[m-i]%MOD)%=MOD;
		else (ans+=(LL)ksm(i,n)*ny[i]%MOD*ny[m-i]%MOD)%=MOD;
	return ans;
}

int main()
{
	scanf("%d%d",&n,&k);
	jc[0]=jc[1]=ny[0]=ny[1]=1;
	for (int i=2;i<=n;i++) jc[i]=(LL)jc[i-1]*i%MOD,ny[i]=(LL)(MOD-MOD/i)*ny[MOD%i]%MOD;
	for (int i=2;i<=n;i++) ny[i]=(LL)ny[i]*ny[i-1]%MOD;
	int c=(S(n,k)+(LL)(n-1)*S(n-1,k)%MOD)%MOD,ans=0;
	for (int i=1;i<=n;i++)
	{
		int x;scanf("%d",&x);
		(ans+=(LL)x*c%MOD)%=MOD;
	}
	printf("%d",ans);
	return 0;
}