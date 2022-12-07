#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
typedef long long LL;
const int N=55;
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
int n,m; 
int a[N],w[N];
int f[N][N][N];//iji 
int main()
{
	scanf("%d%d",&n,&m);
	for (int u=1;u<=n;u++) scanf("%d",&a[u]);
	int sum=0,sum1=0;
	for (int u=1;u<=n;u++) 	
	{
		scanf("%d",&w[u]);
		sum=add(sum,w[u]);
		if (a[u]==1) sum1=add(sum1,w[u]);
	}
	for (int u=1;u<=n;u++)
	{
		memset(f,0,sizeof(f));
		f[0][0][0]=1;
		for (int i=0;i<=m;i++)
		for (int j=0;j<=i;j++)
		for (int k=0;k<=i;k++) if (f[i][j][k]!=0)
		{
			int t,t1,t2,t3,o;
			if (a[u]==1) t=w[u]+k;
			else t=w[u]-k;
			t1=sum+j-(i-j);// 
			t2=sum1+j;
			t3=t1-t2;
			o=Pow(t1,MOD-2);
			//
			if (a[u]==1) f[i+1][j+1][k+1]=add(f[i+1][j+1][k+1],mul(f[i][j][k],mul(t,o)));
			else f[i+1][j][k+1]=add(f[i+1][j][k+1],mul(f[i][j][k],mul(t,o)));
			//, 
			if (a[u]==1) f[i+1][j+1][k]=add(f[i+1][j+1][k],mul(f[i][j][k],mul(dec(t2,t),o)));
			else  f[i+1][j+1][k]=add(f[i+1][j+1][k],mul(f[i][j][k],mul(t2,o)));
			//,
			if (a[u]==0) f[i+1][j][k]=add(f[i+1][j][k],mul(f[i][j][k],mul(dec(t3,t),o)));
			else  f[i+1][j][k]=add(f[i+1][j][k],mul(f[i][j][k],mul(t3,o)));
		}
		int ans=0;
		for (int i=0;i<=m;i++)
		for (int j=0;j<=m;j++) if (f[m][i][j]!=0)
		{
			int t=w[u];
			if (a[u]==1) t=t+j;
			else t=t-j;
			//printf("%d %d %d %d\n",u,i,j,f[m][i][j]);
			ans=add(ans,mul(t,f[m][i][j]));
		}
		printf("%d\n",ans);
	}
	return 0;
}