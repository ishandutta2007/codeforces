#include<bits/stdc++.h>
using namespace std;
const int N=300005;
// set<int> e[N];
set<pair<int,int> > e;
map<int,int> cnt;
vector<int> f[N];
int t,n,m;
int main()
{
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d%d",&n,&m);
		cnt.clear();
		e.clear();
		// for (int i=1;i<=n;++i)
		// {
			// cnt[i]=0;
			// e[i].clear();
		// }
		for (int i=1,x;i<=n;++i)
		{
			scanf("%d",&x);
			++cnt[x];
		}
		for (int i=1,x,y;i<=m;++i)
		{
			scanf("%d%d",&x,&y);
			// e[x].insert(y);
			// e[y].insert(x);
			e.insert({x,y});
			e.insert({y,x});
		}
		for (int i=0;i<=n;++i)
			f[i].clear();
		// for (int i=n;i;--i)
		// 	f[cnt[i]].push_back(i);
		for (auto p:cnt)
			f[p.second].push_back(p.first);
		for (int i=1;i<=n;++i)
			if (f[i].size())
				sort(f[i].begin(),f[i].end(),greater<int>());
		long long ans=0;
		// cout<<"?"<<f[1][0]<<endl;
		// for (int x=1;x<=n;++x)
		// {
		// 	int cntx=cnt[x];
		// 	if (cntx)
		for (int cntx=1;cntx<=n;++cntx)
			for (int x:f[cntx])
				for (int cnty=1;cnty<=cntx;++cnty)
					for (int y:f[cnty])
					{
						// cout<<x<<' '<<y<<endl;
						if (x!=y&&!e.count({x,y}))
						{
							// cout<<"!"<<' '<<(x+y)*(cntx+cnty)<<endl;
							ans=max(ans,(long long)(x+y)*(cntx+cnty));
							break;
						}
					}
		cout<<ans<<endl;
	}
	return 0;
}