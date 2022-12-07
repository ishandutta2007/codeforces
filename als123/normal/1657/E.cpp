#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
typedef long long LL;
const int N=255;
const int MOD=998244353;
int add (int x,int y)   {x=x+y;return x>=MOD?x-MOD:x;}
int mul (int x,int y)   {return (LL)x*y%MOD;}
int dec (int x,int y)   {x=x-y;return x<0?x+MOD:x;}
int Pow (int x,int y)
{
	int now=1;
	while (y){if (y&1) now=mul(now,x);x=mul(x,x);y>>=1;}
	return now;
}
int C[N][N];
void init (int _n)
{
	C[0][0]=1;
	for (int u=1;u<=_n;u++)
	{
		C[u][0]=1;
		for (int i=1;i<=u;i++) C[u][i]=add(C[u-1][i-1],C[u-1][i]);
	}
}
int n,k;
int f[N][N];
int main()
{
	memset(f,0,sizeof(f));
	scanf("%d%d",&n,&k);n--;
	init(n);
	//printf("%d\n",C[n][n-1]);
	f[0][0]=1;
	for (int u=1;u<=k;u++)
	{
		for (int i=0;i<=n;i++)
		{
			for (int j=0;j<=i;j++)
			{
				int cnt=j*(j-1)/2+(i-j)*j;
				int l=C[n-(i-j)][j];
			//	printf("%d %d %d\n",k-u+1,cnt,l);
				f[u][i]=add(f[u][i],mul(mul(l,f[u-1][i-j]),Pow(k-u+1,cnt)));
			}
		//	printf("YES:%d %d %d\n",u,i,f[u][i]); 
		}
	}
	printf("%d\n",f[k][n]);
	return 0;
}