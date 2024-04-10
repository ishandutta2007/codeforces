#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
typedef long long LL;
const int N=105;
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
int f[N][N][N];
int n,m,k;
int JC[N];
int C[N][N];
int dfs (int x,int y,int z)
{
	if (x==0)	return z==0;
	if (f[x][y][z]!=-1) return f[x][y][z];
	if (x<y&&z!=0) return 0;
	if (x<z) return f[x][y][z]=0;
	if (y==1)
	{
		if (z==1) f[x][y][z]=JC[x];
		else f[x][y][z]=0;
	}
	else
	{
		f[x][y][z]=0;
		for (int l=1;l<=(x+1)/2;l++)
		{
			int sum=0;
			for (int a=0;a<=z;a++)
			{
				sum=add(sum,mul(C[x-1][l-1],mul(dfs(l-1,y-1,a),dfs(x-l,y-1,z-a))));
			}
			if (l*2!=x+1) sum=add(sum,sum);
			f[x][y][z]=add(f[x][y][z],sum);
		}
	}
//	printf("%d %d %d %d\n",x,y,z,f[x][y][z]);
	return f[x][y][z];
}
int main()
{
//	freopen("a.in","r",stdin);
	memset(f,-1,sizeof(f));
	scanf("%d%d%d%d",&n,&m,&k,&MOD);
	JC[0]=1;for (int u=1;u<=n;u++) JC[u]=mul(JC[u-1],u);
	C[0][0]=1;
	for (int u=1;u<=n;u++)
	{
		C[u][0]=1;
		for (int i=1;i<=u;i++) C[u][i]=add(C[u-1][i-1],C[u-1][i]);
	}
	//printf("%d\n",C[5][3]);
	//for (int u=1;u<=n;u++)
	printf("%d\n",dfs(n,m,k));
	return 0;
}