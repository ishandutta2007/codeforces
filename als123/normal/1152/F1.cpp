#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
typedef long long LL;
const int N=100005;
const int MOD=1e9+7;
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
int n,m,k,kk;
int f[N][14][1<<5];
int bin[1<<5];
int main()
{
	scanf("%d%d%d",&n,&m,&k);kk=(1<<k)-1;
	f[0][0][0]=1;
	bin[0]=0;for (int u=1;u<=kk;u++) bin[u]=bin[u>>1]+(u&1);
	for (int u=0;u<n;u++)
	for (int i=0;i<=m;i++)
	for (int j=0;j<=kk;j++)
	if (f[u][i][j])
	{
		f[u+1][i][j>>1]=add(f[u+1][i][j>>1],f[u][i][j]);
		f[u+1][i+1][j>>1|(1<<k-1)]=add(f[u+1][i+1][j>>1|(1<<k-1)],mul(f[u][i][j],bin[j]+1));
	}
	int ans=0;
	for (int u=0;u<=kk;u++) ans=add(ans,f[n][m][u]);
	printf("%d\n",ans);
	return 0;
}