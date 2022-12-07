#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
typedef long long LL;
const int N=1000005;
const int MOD=1e9+7;
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
int JC[N],inv[N];
int C (int x,int y)	{if (x<y) return 0;return mul(JC[x],mul(inv[y],inv[x-y]));}
int n,m,a,b;
int F (int n,int m)
{
	if (n==m) return 1;
	return mul(m,Pow(n,n-m-1));
}
void Init (int n)
{
	JC[0]=1;for (int u=1;u<=n;u++) JC[u]=mul(JC[u-1],u);
	inv[n]=Pow(JC[n],MOD-2);
	for (int u=n-1;u>=0;u--) inv[u]=mul(inv[u+1],u+1);
}
int main()
{
	scanf("%d%d%d%d",&n,&m,&a,&b);
	Init(max(n,m));
	int ans=0;
	for (int u=0;u<=n-2;u++)
	{
		int t=mul(mul(mul(mul(JC[n-2],inv[n-2-u]),C(m-1,u)),Pow(m,n-u-2)),F(n,u+2));
		//printf("%d %d %d %d %d\n",u,t,F(n,u+2),mul(mul(JC[n-2],inv[n-2-u]),C(m-1,u)),(mul(mul(JC[n-2],inv[n-2-u]),C(m-1,u)),Pow(m,n-u-2)));
		ans=add(ans,t);
	}
	printf("%d\n",ans);
	return 0;
}