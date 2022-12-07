#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std; 
typedef long long LL;
const int N=4000005;
const int MOD=1e9+7;
int add (int x,int y) {x=x+y;return x>=MOD?x-MOD:x;}
int dec (int x,int y)	{x=x-y;return x<0?x+MOD:x;} 
int mul (int x,int y)	{return (LL)x*y%MOD;}
int Pow (int x,int y)
{
	int ans=1;
	while (y>0)
	{
		if (y&1) ans=mul(ans,x);
		x=mul(x,x);y>>=1;
	}
	return ans;
}
int JC[N],inv[N];
void Init (int n)
{
	JC[0]=1;for (int u=1;u<=n;u++) JC[u]=mul(JC[u-1],u);
	inv[n]=Pow(JC[n],MOD-2);
	for (int u=n-1;u>=0;u--) inv[u]=mul(inv[u+1],u+1);
}
int C (int x,int y)	{return x<y?0:mul(JC[x],mul(inv[y],inv[x-y])); }
int f[N][3];
void solve (int n)
{
	int t=Pow(3,MOD-2);
	f[0][0]=f[0][1]=f[0][2]=n+1;
	for (int u=1;u<=3*n;u++)
	{
		f[u][0]=mul(dec(dec(C(3*n+3,u+1),mul(2,f[u-1][0])),f[u-1][1]),t);
		f[u][1]=add(f[u][0],f[u-1][0]);
		f[u][2]=add(f[u][1],f[u-1][1]);
		//printf("%d %d %d %d %d\n",u,f[u][0],f[u][1],f[u][2],C(3*n+3,u+1));
	}
}
int main()
{
	Init(4000000);
	int n,q;
	scanf("%d%d",&n,&q);
	solve(n);
	while (q--)
	{
		int x;
		scanf("%d",&x);
		printf("%d\n",f[x][0]);
	}
	return 0;
}