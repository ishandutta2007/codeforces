#include<cstdio>
#include<cstring>

int n,m,i,j,f[100005],g[100005],h[100005];

int main()
{
	scanf("%d",&n);
	m=0;
	for(i=1;i<=n;++i)
	{
		scanf("%d",&f[i]);
		if(f[i]==i)
		{
			g[i]=(++m);
			h[g[i]]=i;
		}
	}
	for(i=1;i<=n;++i)
	{
		if(f[i]==i)continue;
		if(f[i]!=i)
		{
			if(f[i]!=f[f[i]])break;
			g[i]=g[f[i]];
		}
	}
	if(i>n)
	{
		printf("%d\n",m);
		for(i=1;i<n;++i)printf("%d ",g[i]);
		printf("%d\n%d",g[n],h[1]);
		for(i=2;i<=m;++i)printf(" %d",h[i]);
	}else printf("-1");
	return 0;
}