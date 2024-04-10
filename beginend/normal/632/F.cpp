#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

const int N=2505;

int n,a[N][N],f[N],cnt;
struct edge{int x,y,w;}e[N*N];

bool cmp(edge a,edge b)
{
	return a.w<b.w;
}

int find(int x)
{
	if (f[x]==x) return x;
	else return f[x]=find(f[x]);
}

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			scanf("%d",&a[i][j]);
	for (int i=1;i<=n;i++) if (a[i][i]) {puts("NOT MAGIC");return 0;}
	for (int i=1;i<n;i++)
		for (int j=i+1;j<=n;j++)
			if (a[i][j]!=a[j][i]) {puts("NOT MAGIC");return 0;}
			else e[++cnt]=(edge){i,j,a[i][j]};
	std::sort(e+1,e+cnt+1,cmp);
	for (int i=1;i<=n;i++) f[i]=i;
	for (int i=1;i<=cnt;i++)
	{
		int j=i;
		while (j<cnt&&e[j+1].w==e[j].w) j++;
		for (int k=i;k<=j;k++) if (find(e[k].x)==find(e[k].y)) {puts("NOT MAGIC");return 0;}
		for (int k=i;k<=j;k++) f[find(e[k].x)]=find(e[k].y);
		i=j;
	}
	puts("MAGIC");
	return 0;
}