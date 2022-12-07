#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
const int MAX=(1<<30);
const int N=105*205;
int n,k;
int a[N];
int f[N],F[N];
int g[N];
int p[N];// 
void solve1 ()
{
	memset(g,127,sizeof(g));
	for (int u=1;u<=k;u++)
		for (int i=1;i<=n;i++)
			a[u*n+i]=a[i];
	n*=k;
	g[0]=0;
	int ans=0;
	for (int u=1;u<=n;u++)
	{
		int l=0,r=u;
		int lalal;
		while (l<=r)
		{
			int mid=(l+r)>>1;
			if (g[mid]<=a[u]) {lalal=mid;l=mid+1;}
			else r=mid-1;
		}
		g[lalal+1]=min(g[lalal+1],a[u]);
		ans=max(ans,lalal+1);
	}
	printf("%d\n",ans);
}
void solve2 ()
{
	int nn=n;
	for (int u=1;u<=n;u++)
		for (int i=1;i<=n;i++)
			a[u*n+i]=a[i];
	n*=n;
/*	for (int u=1;u<=n;u++) printf("%d ",a[u]);
	printf("\n");*/
	memset(g,127,sizeof(g));g[0]=0;
	for (int u=1;u<=n;u++)
	{
		int l=0,r=u;
		int lalal;
		while (l<=r)
		{
			int mid=(l+r)>>1;
			if (g[mid]<=a[u]) {lalal=mid;l=mid+1;}
			else r=mid-1;
		}
		g[lalal+1]=min(g[lalal+1],a[u]);
		f[u]=lalal+1;
	}
	/*for (int u=1;u<=n;u++) printf("%d ",f[u]);
	printf("\n");*/
	memset(g,-1,sizeof(g));g[0]=MAX;
	for (int u=n;u>=1;u--)
	{
		int l=0,r=n;
		int lalal;
		while (l<=r)
		{
			int mid=(l+r)>>1;
			if (g[mid]>=a[u]) {lalal=mid;l=mid+1;}
			else r=mid-1;
		}
		g[lalal+1]=max(g[lalal+1],a[u]);
		F[u]=lalal+1;
	}
/*	for (int u=1;u<=n;u++) printf("%d ",F[u]);
	printf("\n");*/
	//n
	int ans=0;
	for (int u=1;u<=nn;u++)//
		for (int i=1;i<=nn;i++)// 
			if (a[u]==a[i])
			{
				int tot=0;
				for (int j=u;j<=nn;j++)	tot=tot+(a[j]==a[u]);
				for (int j=1;j<=i;j++)	tot=tot+(a[j]==a[i]);
				//printf("u:%d i:%d p[a[u]]:%d F:%d f:%d\n",u,i,p[a[u]],F[i],f[nn*(nn-1)+u]);
				ans=max(ans,tot+p[a[u]]*(k-2*nn)+F[i]+f[nn*(nn-1)+u]-2);
			}
	printf("%d\n",ans);
}
int main()
{
	scanf("%d%d",&n,&k);
	for (int u=1;u<=n;u++) 	{scanf("%d",&a[u]);p[a[u]]++;}
	if (k<=n*2)	solve1();
	else	solve2();
	return 0;
}