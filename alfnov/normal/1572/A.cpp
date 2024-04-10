#include<bits/stdc++.h>
using namespace std;
vector<int>g[200005];
int deg[200005];
int main()
{
	int T=1;
	cin>>T;
	while(T--)
	{
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)g[i].clear(),deg[i]=0;
		for(int i=1;i<=n;i++)
		{
			int l;
			scanf("%d",&l);
			while(l--)
			{
				int u;
				scanf("%d",&u);
				g[u].push_back(i);
				deg[i]++;
			}
		}
		set<int>s;
		s.clear();
		for(int i=1;i<=n;i++)if(!deg[i])s.insert(i);
		int cnt=0,lst=0,ans=1;
		while(s.size())
		{
			cnt++;
			set<int>::iterator it=s.lower_bound(lst);
			if(it!=s.end())
			{
				int x=*it;
				s.erase(x),lst=x;
				for(int i=0;i<g[x].size();i++)
				{
					int cu=g[x][i];
					deg[cu]--;
					if(!deg[cu])s.insert(cu);
				}
			}else
			{
				ans++;
				int x=*(s.begin());
				s.erase(x),lst=x;
				for(int i=0;i<g[x].size();i++)
				{
					int cu=g[x][i];
					deg[cu]--;
					if(!deg[cu])s.insert(cu);
				}
			}
		}
		if(cnt!=n)printf("-1\n");
		else printf("%d\n",ans);
	}
	return 0;
}