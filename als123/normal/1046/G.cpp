#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
const int N=200005*2;
int n,m;
int a[N],b[N];
int nn;
int f[N],mx,id;
int ans[N],tot=0;
int main()
{
	scanf("%d%d",&n,&m);
	for (int u=1;u<=n;u++) scanf("%d",&a[u]);
	b[++nn]=-2;
	for (int u=2;u<=n;u++)	
	{
		b[++nn]=a[u]-a[u-1];
		b[++nn]=-1;
	}
	b[++nn]=-3;
	mx=0;
	for (int u=1;u<=nn;u++)
	{
		if (u<mx) f[u]=min(mx-u,f[2*id-u]);
		else f[u]=1;
		while (b[u+f[u]]==b[u-f[u]]) f[u]++;
		if (u+f[u]>mx)	{mx=u+f[u];id=u;}
	}
	if (f[n]>=n-1) ans[++tot]=(a[1]+a[n])%m;
	for (int u=1;u<=n;u++)//1~u
	{
		bool tf=false,tf1=false;//
		if (u==1) tf=true;
		else if (f[u]>=u-1) tf=true;
		if (u==n-1) tf1=true;
		else if (f[u+n]>=n-u-1) tf1=true;
		if (tf&&tf1)
		{
			int p1=a[1]+a[u],p2=(a[u+1]+a[n]-m);
			if (p1==p2) ans[++tot]=a[1]+a[u];
		}
	}
	sort(ans+1,ans+1+tot);
	printf("%d\n",tot);
	for (int u=1;u<=tot;u++) printf("%d ",ans[u]);
	return 0;
}