#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long LL;

const int N=300005;

int n,x1,x2,a[N],f[N],g[N],nx1[N],nx2[N],id[N];

bool cmp(int x,int y)
{
	return a[x]<a[y];
}

void pri(int x,int y)
{
	puts("Yes");
	printf("%d %d\n",f[x],g[y]);
	for (int i=0;i<f[x];i++) printf("%d ",id[x+i]);
	puts("");
	for (int i=0;i<g[y];i++) printf("%d ",id[y+i]);
}

int main()
{
	scanf("%d%d%d",&n,&x1,&x2);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++) id[i]=i;
	sort(id+1,id+n+1,cmp);
	for (int i=n;i>=1;i--)
	{
		f[i]=f[i+1];g[i]=g[i+1];
		while (f[i]<=n&&(LL)a[id[i]]*f[i]<x1) f[i]++;
		while (g[i]<=n&&(LL)a[id[i]]*g[i]<x2) g[i]++;
	}
	nx1[n+1]=nx2[n+1]=n+1;
	for (int i=n;i>=1;i--)
	{
		if (f[i]<=n-i+1) nx1[i]=i;
		else nx1[i]=nx1[i+1];
		if (g[i]<=n-i+1) nx2[i]=i;
		else nx2[i]=nx2[i+1];
	}
	for (int i=1;i<=n;i++)
	{
		if (nx1[i]==i&&nx2[i+f[i]]<=n) {pri(i,nx2[i+f[i]]);return 0;}
		if (nx2[i]==i&&nx1[i+g[i]]<=n) {pri(nx1[i+g[i]],i);return 0;}
	}
	puts("No");
	return 0;
}