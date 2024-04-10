#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

typedef long long LL;

const int N=200005;
const LL inf=(LL)1e16;

int n,m,k,id[N],tot;
struct edge{int x,y,w;}e[N];
LL f[805][805],a[N*2];

bool cmp(edge a,edge b)
{
	return a.w<b.w;
}

int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for (int i=1;i<=m;i++) scanf("%d%d%d",&e[i].x,&e[i].y,&e[i].w);
	std::sort(e+1,e+m+1,cmp);
	for (int i=1;i<=std::min(m,k);i++)
	{
		int x=e[i].x,y=e[i].y;
		if (!id[x]) id[x]=++tot;
		if (!id[y]) id[y]=++tot;
		f[id[x]][id[y]]=f[id[y]][id[x]]=e[i].w;
	}
	for (int i=1;i<tot;i++)
		for (int j=i+1;j<=tot;j++)
			if (!f[i][j]) f[i][j]=f[j][i]=inf;
	for (int l=1;l<=tot;l++)
		for (int i=1;i<=tot;i++)
			for (int j=1;j<=tot;j++)
				f[i][j]=std::min(f[i][j],f[i][l]+f[l][j]);
	int s=0;
	for (int i=1;i<tot;i++)
		for (int j=i+1;j<=tot;j++)
			if (f[i][j]<inf) a[++s]=f[i][j];
	std::sort(a+1,a+s+1);
	printf("%lld\n",a[k]);
	return 0;
}