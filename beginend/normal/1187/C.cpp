#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

const int N=1005;

int n,m,f[N],ans[N];
struct val{int l,r,op;}a[N];

int find(int x)
{
	if (f[x]==x) return x;
	else return f[x]=find(f[x]);
}

int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) f[i]=i;
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&a[i].op,&a[i].l,&a[i].r);
		if (a[i].op)
		{
			for (int j=a[i].l;j<a[i].r;j++)
				if (find(j)!=find(j+1)) f[find(j)]=find(j+1);
		}
	}
	int p=n;
	for (int i=1;i<=n;i++)
	{
		if (i>1&&find(i)!=find(i-1)) p--;
		ans[i]=p;
	}
	for (int i=1;i<=m;i++)
		if (!a[i].op&&ans[a[i].l]==ans[a[i].r]) {puts("NO");return 0;}
	puts("YES");
	for (int i=1;i<=n;i++) printf("%d ",ans[i]);
	return 0;
}