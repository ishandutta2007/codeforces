#include<bits/stdc++.h>
using namespace std;
int gs[200005];
int main()
{
	int T=1;
	while(T--)
	{
		int n,m,ans=0;
		cin>>n>>m;
		while(m--)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			if(u>v)swap(u,v);
			gs[u]++;
			if(gs[u]==1)ans++;
		}
		int q;
		cin>>q;
		while(q--)
		{
			int op;
			scanf("%d",&op);
			if(op==1)
			{
				int u,v;
				scanf("%d%d",&u,&v);
				if(u>v)swap(u,v);
				gs[u]++;
				if(gs[u]==1)ans++;
			}else if(op==2)
			{
				int u,v;
				scanf("%d%d",&u,&v);
				if(u>v)swap(u,v);
				gs[u]--;
				if(gs[u]==0)ans--;
			}else printf("%d\n",n-ans);
		}
	}
	return 0;
}