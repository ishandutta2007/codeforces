#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

const int N=200005;

int n,m,q,f[N],bel[N];

int find(int x)
{
	if (f[x]==x) return x;
	else return f[x]=find(f[x]);
}

int main()
{
	scanf("%d%d%d",&n,&m,&q);
	for (int i=1;i<=m;i++) f[i]=i;
	for (int i=1;i<=q;i++)
	{
		int x,y;scanf("%d%d",&x,&y);
		if (!bel[x]) bel[x]=y;
		else
		{
			int u=find(y),v=find(bel[x]);
			f[u]=v;
		}
	}
	int ans=m-1;
	for (int i=1;i<=m;i++) if (f[i]!=i) ans--;
	for (int i=1;i<=n;i++) if (!bel[i]) ans++;
	printf("%d\n",ans);
	return 0;
}