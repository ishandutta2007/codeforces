#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
typedef long long LL;
const int N=405;
int MOD;
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
int C[N][N];
int n;
int f[N][N];
int h[N];
int main()
{
	
	scanf("%d%d",&n,&MOD);
	C[0][0]=1;
	for (int u=1;u<=400;u++)
	{
		C[u][0]=1;
		for (int i=1;i<=u;i++) C[u][i]=add(C[u-1][i-1],C[u-1][i]);
	}
	h[1]=1;
	for (int u=2;u<=400;u++)
	for (int i=1;i<=u;i++)
	h[u]=add(h[u],C[u-1][i-1]);
	memset(f,0,sizeof(f));
	f[0][0]=1;f[1][1]=1;
	for (int u=2;u<=n;u++)
	for (int i=1;i<=u;i++)
	{
		//if (u!=2||i!=1) f[u][i]=add(f[u][i],mul(C[i][1],f[max(0,u-2)][i-1]));
		for (int j=u;j>=1;j--)
		{
			int d=u-j+1;
			if (d>i) break;
			if (j==2) continue;
			f[u][i]=add(f[u][i],mul(h[d],mul(C[i][d],f[max(0,j-2)][i-d])));
		}
		//printf("%d %d %d\n",u,i,f[u][i]);
	}
	int ans=0;
	for (int u=1;u<=n;u++) ans=add(ans,f[n][u]);
	printf("%d\n",ans);
	return 0;
}