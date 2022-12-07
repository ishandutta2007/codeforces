#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
typedef long long LL;
const int N=1000005;
const int MOD=998244353;
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
int n;
int f[N];
int g[N];
int main()
{
	for (int u=1;u<=1000000;u++)
	for (int i=u+u;i<=1000000;i+=u)
	g[i]=add(g[i],1);
	scanf("%d",&n);
	f[1]=1;f[0]=1;
	int sum=2;
	for (int u=2;u<=n;u++)
	{
	//	for (int i=0;i<u;i++) f[u]=add(f[u],f[i]);
		f[u]=sum;
		f[u]=add(f[u],g[u]);
		sum=add(sum,f[u]);
	//	for (int i=1;i<u;i++) if (u%i==0) f[u]=add(f[u],1);
	}
	printf("%d\n",f[n]);
	return 0;
}