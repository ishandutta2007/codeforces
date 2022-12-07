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
int a[N],b[N],pos[N];
bool used[N];
int main()
{
	scanf("%d",&T);
	while (T--)
	{
		int n,k;
		scanf("%d%d",&n,&k);
		for (int u=1;u<=n;u++)	{scanf("%d",&a[u]);pos[a[u]]=u;used[u]=false;}
		for (int u=1;u<=k;u++) scanf("%d",&b[u]);
		int ans=1;
		for (int u=k;u>=1;u--)
		{
			int t=pos[b[u]],t1=0;
			if (t>1&&used[t-1]==false) t1++;
			if (t<n&&used[t+1]==false) t1++;
			used[t]=true;ans=mul(ans,t1);
		}
		printf("%d\n",ans);
	}
	return 0;
}