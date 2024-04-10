#include<bits/stdc++.h>
using namespace std;
int ans[303030],vis[303030];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		
		ans[0]=0;
		for(int i=1;i<=3*n;i++)
			vis[i]=0;
		
		for(int i=1;i<=m;i++)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			if(vis[u]==0&&vis[v]==0)
			{
				vis[u]=1;
				vis[v]=1;
				ans[++ans[0]]=i;
			}
		}
		if(ans[0]>=n)
		{
			puts("Matching"); 
			for(int i=1;i<=n;i++)
				printf("%d ",ans[i]);
			printf("\n");
		}
		else
		{
			puts("IndSet");
			int nn=n;
			for(int i=1;i<=3*n;i++)
			{
				if(vis[i]==0)
				{
					printf("%d ",i);
					nn--;
					if(nn==0)
						break;
				}
			}
			printf("\n");
		}
	}
	return 0;
}