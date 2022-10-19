#include<bits/stdc++.h>
using namespace std;
struct apple
{
	int bh,gx,co;
	long long zh;
	bool operator<(const apple &other)const
	{
		if(co!=other.co)return co<other.co;
		long long a1=gx*(zh-zh/2),a2=other.gx*(other.zh-other.zh/2);
		if(a1!=a2)return a1>a2;
		return bh<other.bh;
	}
	apple(int bh=0,int gx=0,int co=0,long long zh=0):bh(bh),gx(gx),co(co),zh(zh){}
};
int bb=0;
long long lll,l1[2000005],l2[2000005];
vector<pair<pair<int,int>,long long> >g[100005];
apple q[2000005];
int dfs(int x,int la)
{
	int gs=0,sh=0;
	for(int i=0;i<g[x].size();i++)
	{
		int cu1=g[x][i].first.first,coi=g[x][i].first.second;
		long long cu2=g[x][i].second;
		if(cu1==la)continue;
		gs++;
		int tt=dfs(cu1,x);
		sh+=tt;
		bb++;
		q[bb]=apple(bb,tt,coi,cu2);
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
			int u,v,c;
			long long w;
			scanf("%d%d%lld%d",&u,&v,&w,&c);
			g[u].push_back(make_pair(make_pair(v,c),w));
			g[v].push_back(make_pair(make_pair(u,c),w));
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
				q[bb]=apple(bb,q[i].gx,q[i].co,ff);
				ff>>=1;
			}
		}
		sort(q+1,q+bb+1);
		int fj=bb+1;
		for(int i=1;i<=bb;i++)if(q[i].co==2)
		{
			fj=i;
			break;
		}
		for(int i=0;i<=bb;i++)l1[i]=l2[i]=0;
		int ans=2147483647,yb=bb-fj+1;
		for(int i=1;i<fj;i++)l1[i]=l1[i-1]+q[i].gx*(q[i].zh-q[i].zh/2);
		for(int i=fj;i<=bb;i++)l2[i-fj+1]=l2[i-fj]+q[i].gx*(q[i].zh-q[i].zh/2);
		for(int i=0;i<fj;i++)
		{
			if(lll-l1[i]-l2[yb]>s)continue;
			int ef=lower_bound(l2,l2+yb+1,lll-s-l1[i])-l2;
			ans=min(ans,2*ef+i);
		}
		cout<<ans<<endl;
	}
	return 0;
}