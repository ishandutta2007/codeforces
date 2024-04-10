#include<bits/stdc++.h>
using namespace std;
struct apple
{
	int bh,gx;
	long long zh;
	bool operator<(const apple &other)const
	{
		long long a1=gx*(zh-zh/2),a2=other.gx*(other.zh-other.zh/2);
		if(a1!=a2)return a1>a2;
		return bh<other.bh;
	}
	apple(int bh=0,int gx=0,long long zh=0):bh(bh),gx(gx),zh(zh){}
};
int bb=0;
long long lll;
vector<pair<int,long long> >g[100005];
apple q[2000005];
int dfs(int x,int la)
{
	int gs=0,sh=0;
	for(int i=0;i<g[x].size();i++)
	{
		int cu1=g[x][i].first;
		long long cu2=g[x][i].second;
		if(cu1==la)continue;
		gs++;
		int tt=dfs(cu1,x);
		sh+=tt;
		bb++;
		q[bb]=apple(bb,tt,cu2);
		lll+=tt*cu2;
	}
	if(!gs)return 1;
	return sh;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		long long s;
		cin>>n>>s;
		for(int i=1;i<=n;i++)g[i].clear();
		for(int i=1;i<n;i++)
		{
			int u,v;
			long long w;
			scanf("%d%d%lld",&u,&v,&w);
			g[u].push_back(make_pair(v,w));
			g[v].push_back(make_pair(u,w));
		}
		lll=0;
		bb=0;
		dfs(1,0);
		int m=bb;
		for(int i=1;i<=m;i++)
		{
			long long ff=q[i].zh>>1;
			while(ff)
			{
				bb++;
				q[bb]=apple(bb,q[i].gx,ff);
				ff>>=1;
			}
		}
		sort(q+1,q+bb+1);
		int ans=0;
		for(int i=1;i<=bb;i++)
		{
			if(lll<=s)break;
			ans++;
			lll-=q[i].gx*(q[i].zh-q[i].zh/2);
		}
		cout<<ans<<endl;
	}
	return 0;
}