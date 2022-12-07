#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
typedef long long LL;
const int N=200005;
const int M=3005;
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
int f[M][M];//ij
int g[M][M];//ij
int sum=0,sum1=0;
int h,h1;
void Init ()
{
	memset(f,0,sizeof(f));memset(g,0,sizeof(g));
	f[0][0]=1;g[0][0]=1;
	for (int i=0;i<=m;i++)
	for (int j=0;j<=i;j++)
	{
		int t,t1,t2,t3,o;
		t1=sum+j-(i-j);o=Pow(t1,MOD-2);
		t2=sum1+j;t3=t1-t2;

		f[i+1][j+1]=add(f[i+1][j+1],mul(f[i][j],mul(t2,o)));
		f[i+1][j]=add(f[i+1][j],mul(f[i][j],mul(t3,o)));
	}
	for (int i=0;i<=m;i++) h=add(h,mul(f[m][i],i+sum1));
	for (int i=0;i<=m;i++) h1=add(h1,mul(f[m][m-i],sum-sum1-i));
}
int main()
{
	scanf("%d%d",&n,&m);
	for (int u=1;u<=n;u++) scanf("%d",&a[u]);
	for (int u=1;u<=n;u++) 	
	{
		scanf("%d",&w[u]);
		sum=add(sum,w[u]);
		if (a[u]==1) sum1=add(sum1,w[u]);
	}
	Init();
	for (int u=1;u<=n;u++)
	{
		if (a[u]==1) printf("%d\n",mul(h,mul(w[u],Pow(sum1,MOD-2))));
		else printf("%d\n",mul(h1,mul(w[u],Pow(sum-sum1,MOD-2))));
	}
	return 0;
}