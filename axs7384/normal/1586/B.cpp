#include<bits/stdc++.h>
using namespace std;
int n,m,x,y,z,t;
int vis[100005];
int main()
{
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d%d",&n,&m);
		for (int i=1;i<=n;++i)
			vis[i]=0;
		for (int i=1;i<=m;++i)
		{
			scanf("%d%d%d",&x,&y,&z);
			vis[y]=1;
		}
		for (int i=1;i<=n;++i)
			if (!vis[i])
			{
				for (int j=1;j<=n;++j)
					if (i!=j)
						printf("%d %d\n",i,j);
				break;
			}
	}
	return 0;
}