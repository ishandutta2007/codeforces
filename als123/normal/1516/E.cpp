#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
typedef long long LL;
const int N=505;
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
int n,kk,nn;
int f[N][N];
int h[N][N];
int JC[N],inv[N];
int C (int x,int y)
{
	if (x<y) return 0;
	return mul(JC[x],mul(inv[y],inv[x-y]));
}
void Init ()
{
	JC[0]=1;for (int u=1;u<=nn;u++) JC[u]=mul(JC[u-1],u);
	inv[nn]=Pow(JC[nn],MOD-2);
	for (int u=nn-1;u>=0;u--) inv[u]=mul(inv[u+1],u+1);
	
	h[0][0]=1;
	for (int i=1;i<=nn;i++)
	for (int u=1;u<=nn;u++)
	for (int j=2;j<=u;j++)
	h[u][i]=add(h[u][i],mul(C(u-1,j-1),mul(JC[j-1],h[u-j][i-1])));
}
int d[N];
int main()
{
	nn=400;
	Init();
//	printf("%d %d %d\n",h[4][3],h[4][2],C(5,2));
	memset(d,0,sizeof(d));
	scanf("%d%d",&n,&kk);
	d[0]=1;
	for (int u=1;u<=min(n,2*kk);u++) d[u]=mul(d[u-1],mul(Pow(u,MOD-2),n-u+1));
	for (int k=1;k<=kk;k++)
	{
		int ans=0;
		if (k%2==0) ans=1;
		for (int i=2*k;i>=2;i--)
		{
			for (int j=i/2;j>=1;j--)
			{
				int o=i-j;
				if (o>k) break;
				if ((k-o)%2!=0) continue;
				ans=add(ans,mul(d[i],h[i][j]));
			}
		}
		printf("%d ",ans);
	}
	return 0;
}