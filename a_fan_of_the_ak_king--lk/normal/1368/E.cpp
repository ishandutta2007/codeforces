#include<bits/stdc++.h>
using namespace std;
int n,m,vis[1000005],T,u,v,t[1000005];
int ans[1000005],k,i;
vector<int> g[1000005];
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d",&n,&m);
		for(i=1;i<=n;++i)
			g[i].clear();
		for(i=1;i<=m;++i)
		{
			scanf("%d %d",&u,&v);
			g[v].push_back(u);
		}
		for(i=1;i<=n;++i)
			t[i]=vis[i]=0;
		for(i=1;i<=n;++i)
		{
			bool flag=true;
			for(auto it:g[i])
				if(!vis[it]&&t[it])
				{
					flag=false;
					break;
				}
			if(!flag)
				vis[i]=1;
			else
			{
				flag=false;
				for(auto it:g[i])
					if(!vis[it])
					{
						flag=true;
						break;
					}
				t[i]=flag;
			}
		}
		k=0;
		for(i=1;i<=n;++i)
			if(vis[i])
				ans[++k]=i;
		printf("%d\n",k);
		for(i=1;i<=k;++i)
			printf("%d ",ans[i]);
		printf("\n");
	}
}