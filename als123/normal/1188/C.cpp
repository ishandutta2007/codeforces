#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
typedef long long LL;
const int N=1005;
const int MOD=998244353;
int add (int x,int y)   {x=x+y;return x>=MOD?x-MOD:x;}
int mul (int x,int y)   {return (LL)x*y%MOD;}
int dec (int x,int y)   {x=x-y;return x<0?x+MOD:x;}
int Pow (int x,int y)
{
	if (y==0) return 1;
	if (y==1) return x;
	int lalal=Pow(x,y>>1);
	lalal=mul(lalal,lalal);
	if (y&1) lalal=mul(lalal,x);
	return lalal;
}
int n,k;
int a[N];
int b[N];
int g[N][N],f[N][N];
int solve (int x)
{
	b[0]=0;
	for (int u=1;u<=n;u++)
	{
		b[u]=b[u-1];
		while (a[u]-a[b[u]+1]>=x) b[u]++;
	}
	//for (int u=1;u<=n;u++) printf("%d ",b[u]);printf("\n");
	for (int u=1;u<=n;u++)	{f[1][u]=1;g[1][u]=u;}
	for (int u=2;u<=k;u++)
	for (int i=u;i<=n;i++)
	{
		f[u][i]=g[u-1][b[i]];
		g[u][i]=add(g[u][i-1],f[u][i]);
	//	printf("%d %d %d\n",u,i,g[u][i]);
	}
	return g[k][n];
}
int main()
{
	scanf("%d%d",&n,&k);
	for (int u=1;u<=n;u++) scanf("%d",&a[u]);
	sort(a+1,a+1+n);
	int ans=0;
	for (int u=1;u<=(a[n]-a[1])/(k-1);u++)	
	{
	//	printf("%d %d\n",u,solve(u));
		ans=add(ans,solve(u));
	}
	printf("%d\n",ans);
	return 0;
}