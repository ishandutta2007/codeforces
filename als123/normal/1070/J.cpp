#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<assert.h>
using namespace std;
typedef long long LL;
const int N=200005;
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
int n,m,k;
int a[N];
char ss[N];
int ans;
int f[N];
int nn;
void solve ()
{
	for (int u=0;u<=k;u++) f[u]=0;
	f[0]=1;
	for (int i=nn;i>=0;i--)
	for (int u=k;u>=a[i];u--)
	f[u]=add(f[u],f[u-a[i]]);
	
	for (int u=m;u<=k-n;u++) if (f[u]!=0) 	{ans=0;return ;}
	
//	for (int u=0;u<=k;u++) printf("%d ",f[u]);printf("\n");
	
	for (int u=0;u<=nn;u++)
	{
		for (int i=a[u];i<=k;i++) f[i]=dec(f[i],f[i-a[u]]);
		for (int i=m;i>=0;i--) if (f[i])
		{
			int x,y;
			y=m-i;
			if (a[u]>=y)
			{
				int left=k-i-a[u];
				assert(left<=n);
				x=n-left;
				assert(a[u]>=(x+y));
				ans=min(ans,y*x);
			}
		}
		
		for (int i=k;i>=a[u];i--) f[i]=add(f[i],f[i-a[u]]);
	}
}
int main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d%d",&n,&m,&k);
		scanf("%s",ss+1);
		for (int u=0;u<26;u++) a[u]=0;
		for (int u=1;u<=k;u++) a[ss[u]-'A']++;
		//sort(a,a+26);
		//for (int u=0;u<26;u++) printf("%d ",a[u]);
		//printf("\n");
		
		nn=0;
		for (int u=0;u<26;u++) if (a[u]!=0) a[nn++]=a[u];
		nn--;
		
		ans=n*m;
		solve();
		printf("%d\n",ans);
	}
	return 0;
}