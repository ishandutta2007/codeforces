#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
typedef long long LL;
const int N=5005;
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
int n,k;
int f[N],a[N];
int main()
{
	scanf("%d%d",&n,&k);f[0]=1;
	int ans=1;
	for (int u=1;u<=n;u++)
	{
		scanf("%d",&a[u]);ans=mul(ans,a[u]);
		for (int i=u;i!=0;i--) f[i]=add(f[i],mul(f[i-1],a[u]));
	}
	for (int u=0;u<=n;u++) if ((n-u)&1) f[u]=MOD-f[u];
	int Inv=Pow(n,MOD-2);Inv=Pow(Inv,k);
	for (int u=0;u<=min(n,k);u++)
	{
		int t=1;
		for (int i=k;i>k-u;i--) t=mul(t,i);
		ans=dec(ans,mul(Inv,mul(Pow(n,k-u),mul(f[n-u],t))));
	}
	printf("%d\n",ans);
	return 0;
}