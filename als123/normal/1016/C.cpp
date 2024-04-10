#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
typedef long long LL;
const LL N=300005;
LL a[N],b[N];
LL n;
LL suma[N],sumb[N];
LL g[N],h[N];
bool vis[N][2];
LL ans=0;
void solve (LL x,LL t)
{
	memset(g,0,sizeof(g));
	memset(h,0,sizeof(h));
	memset(suma,0,sizeof(suma));
	memset(sumb,0,sizeof(sumb));
	for (LL u=n;u>=1;u--) g[u]=g[u+1]+a[u];
	for (LL u=n;u>=1;u--) h[u]=h[u+1]+b[u];
	LL lalal=0;
	for (LL u=n;u>=1;u--)
	{
		lalal=lalal+a[u];
		suma[u]=suma[u+1]+lalal;
	}
	for (LL u=n;u>=1;u--)
	{
		sumb[u]=sumb[u+1]+b[u]*(n-u+1);
	}
	memset(vis,false,sizeof(vis));
	LL i=1,j=1,sum=x;
	for (LL u=1;u<=2*n;u++)
	{
		vis[i][j]=true;
		LL tt=u+t;//??????????? 
		//sum=sum+a[u]*tt;
		if (j==1)
		{
			sum=sum+a[i]*tt;
			if (vis[i][j+1]==true)//???????????????? 
			{
				lalal=suma[i+1]+g[i+1]*tt+sumb[i+1]+h[i+1]*(tt+n-i);
				ans=max(ans,lalal+sum);
				//printf("%lld %lld %lld\n",i,j,suma[i+1]+g[i+1]*tt+sumb[i+1]+h[i+1]*(tt+n-i));
				i++;
			}
			else//?????? 
			{
				lalal=suma[i+1]+g[i+1]*tt+sumb[i]+h[i]*(tt+n-i);
				//printf("%lld %lld %lld %lld %lld %lld %lld\n",i,j,suma[i+1],g[i+1]*tt,sumb[i],h[i]*(tt+n-i),suma[i+1]+g[i+1]*tt+sumb[i]+h[i]*(tt+n-i));
				ans=max(ans,lalal+sum);
				j++;
			}
		}
		else
		{
			sum=sum+b[i]*tt;
			if (vis[i][j-1]==true)	i++;
			else j--;
		}
	}
}
int main()
{
	scanf("%lld",&n);
	for (LL u=1;u<=n;u++) scanf("%lld",&a[u]);
	for (LL u=1;u<=n;u++) scanf("%lld",&b[u]);
	solve(0,-1);
	LL lalal=b[1];
	for (LL u=1;u<n;u++) a[u]=a[u+1];
	for (LL u=1;u<n;u++) b[u]=b[u+1];
	n--;
	for (LL u=1;u<=n;u++) swap(a[u],b[u]);
	solve(lalal,1);
	printf("%lld\n",ans);
	return 0;
}