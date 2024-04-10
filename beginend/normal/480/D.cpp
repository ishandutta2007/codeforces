#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

const int N=505;

int n,m,f[N][N*2],g[N*2];
struct data{int l,r,w,s,v;}a[N];

bool cmp(data a,data b)
{
	return a.r<b.r||a.r==b.r&&a.l>b.l;
}

int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d%d%d%d%d",&a[i].l,&a[i].r,&a[i].w,&a[i].s,&a[i].v);
	std::sort(a+1,a+n+1,cmp);
	a[n+1].l=0;a[n+1].r=n*2;a[n+1].s=m;
	for (int i=1;i<=n+1;i++)
		for (int j=a[i].w;j<=m;j++)
		{
			int p=a[i].l;g[p]=0;
			for (int k=1;k<i;k++)
				if (a[k].l>=a[i].l)
				{
					while (p<a[k].r) p++,g[p]=g[p-1];
					g[p]=std::max(g[p],g[a[k].l]+f[k][std::min(j-a[i].w,a[i].s)]);
				}
			f[i][j]=g[p]+a[i].v;
		}
	printf("%d",f[n+1][m]);
	return 0;
}