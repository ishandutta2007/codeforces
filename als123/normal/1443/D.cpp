#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
typedef long long LL;
const int N=200005;
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
int T;
int a[N];
int main()
{
	scanf("%d",&T);
	while (T--)
	{
		int n;
		scanf("%d",&n);
		for (int u=1;u<=n;u++) scanf("%d",&a[u]);
		int mn=a[1],d=0;
		bool tf=true;
		for (int u=2;u<=n;u++)
		{
			a[u]=a[u]-d;
			if (a[u]<0) tf=false;
			if (a[u]<mn) mn=a[u];
			else	{int t=a[u]-mn;d=d+t;}
		}
		if (tf) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}