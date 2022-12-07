#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
typedef long long LL;
const int N=5005;
const int MOD=998244353;
int add (int x,int y)   {x=x+y;return x>=MOD?x-MOD:x;}
int mul (int x,int y)   {return (LL)x*y%MOD;}
int dec (int x,int y)   {x=x-y;return x<0?x+MOD:x;}
int Pow (int x,int y)
{
	if (y==1) return x;
	int lalal=Pow(x,y>>1);
	lalal=mul(lalal,lalal);
	if (y&1) lalal=mul(lalal,x);
	return lalal;
}
int f[N][N],g[N][N];
int a[N],l[N];
int n;
int main()
{
	scanf("%d",&n);
	for (int u=1;u<=n;u++) scanf("%d",&a[u]);
	sort(a+1,a+1+n);
	l[1]=0;
	for (int u=2;u<=n;u++)
	{
		l[u]=l[u-1];
		while (a[l[u]+1]*2<=a[u]) l[u]++;
	}
	//for (int u=1;u<=n;u++) printf("%d ",l[u]);printf("\n");
	memset(f,0,sizeof(f));
	for (int u=1;u<=n;u++) f[1][u]=1;
	for (int u=1;u<=n;u++) g[1][u]=u;
	for (int u=2;u<=n;u++)
	{
	for (int i=u;i<=n;i++)
	{
		if (l[i]>=(u-2)) f[u][i]=add(f[u][i],mul(f[u-1][i],l[i]-(u-2)));
		if (l[i]>=u-1) f[u][i]=add(f[u][i],dec(g[u-1][l[i]],g[u-1][u-2]));
	//for (int j=u-1;j<=l[i];j++) f[u][i]=add(f[u][i],f[u-1][j]);
		g[u][i]=add(g[u][i-1],f[u][i]);
	}
	}
	printf("%d\n",f[n][n]);
	return 0;
}