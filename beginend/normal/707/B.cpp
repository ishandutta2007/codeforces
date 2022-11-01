#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define inf 0x7fffffff
#define N 100005
using namespace std;

int x[N],y[N],z[N],dark[N];

int main()
{
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	for (int i=1;i<=m;i++)
		scanf("%d%d%d",&x[i],&y[i],&z[i]);
	for (int i=1;i<=k;i++)
	{
		int w;
		scanf("%d",&w);
		dark[w]=1;
	}
	int ans=inf;
	for (int i=1;i<=m;i++)
		if (dark[x[i]]+dark[y[i]]==1) ans=min(ans,z[i]);
	if (ans==inf) ans=-1;
	printf("%d",ans);
}