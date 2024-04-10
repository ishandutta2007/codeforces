#include<bits/stdc++.h>
#define LL long long
#define inf 0x3f3f3f3f
using namespace std;
int n,D;
LL ans;
int deg[250002],Nx[250002],La[250002];
LL sum[250002];
LL f[250002][2];
bool vis[250002];
vector<int> vec[250002];
typedef pair<int,int> P;
set<P> s[250002];
set<P>::iterator it;
multiset<LL,greater<LL> > ms[250002];
inline void add_edge(int x,int y,int z)
{
	s[x].insert(P(y,z)),++deg[x];
	s[y].insert(P(x,z)),++deg[y];
}
inline void dfs(int x,int fa)
{
	vector<LL> Vec,Del;int v,d=max(deg[x]-D,0);LL tmp;vis[x]=1,f[x][0]=0;
	
	for(;ms[x].size()>d;sum[x]-=*ms[x].begin(),ms[x].erase(ms[x].begin()));
	for(set<P>::iterator it=s[x].begin();it!=s[x].end();++it)
		if((v=(*it).first)!=fa)
		{
			dfs(v,x),f[x][0]+=f[v][0],tmp=f[v][1]+(*it).second-f[v][0];
			if(tmp<0)
			{
				if(d && ms[x].size()==d)Vec.push_back(*ms[x].begin()),sum[x]-=*ms[x].begin(),ms[x].erase(ms[x].begin());
				f[x][0]+=tmp,d=max(d-1,0);
				continue;
			}
			if(!d || (ms[x].size()==d && tmp>=*ms[x].begin()))continue;
			Del.push_back(tmp);
			if(ms[x].size()<d)
			{
				sum[x]+=tmp,ms[x].insert(tmp);
				continue;
			}
			Vec.push_back(*ms[x].begin()),sum[x]+=tmp-*ms[x].begin(),ms[x].erase(ms[x].begin()),ms[x].insert(tmp);
		}
	f[x][1]=(f[x][0]+=sum[x]);
	if(d>ms[x].size())f[x][0]=inf;
	else if(!ms[x].empty())f[x][1]-=*ms[x].begin();
	for(;!Vec.empty();Vec.pop_back())sum[x]+=Vec.back(),ms[x].insert(Vec.back());
	for(;!Del.empty();Del.pop_back())sum[x]-=Del.back(),ms[x].erase(ms[x].lower_bound(Del.back()));
}
int main()
{
	scanf("%d",&n),Nx[0]=1,La[n+1]=n;
	for(int i=1,x,y,z;i<n;++i)scanf("%d%d%d",&x,&y,&z),add_edge(x,y,z);
	for(int i=1;i<=n;++i)vec[deg[i]].push_back(i),Nx[i]=i+1,La[i]=i-1;
	for(D=0;D<n;printf("%lld ",ans),++D)
	{
		for(int i=ans=0,v,d;i<vec[D].size();++i)
		{
			v=vec[D][i],Nx[La[v]]=Nx[v],La[Nx[v]]=La[v];
			for(it=s[v].begin();it!=s[v].end();it=s[v].erase(it))
			{
				if(!(d=max(deg[(*it).first]-D,0)))continue;
				s[(*it).first].erase(P(v,(*it).second));
				if(ms[(*it).first].size()<d)
				{
					ms[(*it).first].insert((*it).second),sum[(*it).first]+=(*it).second;
					continue;
				}
				if(*ms[(*it).first].begin()>(*it).second)sum[(*it).first]+=(*it).second-*ms[(*it).first].begin(),ms[(*it).first].erase(ms[(*it).first].begin()),ms[(*it).first].insert((*it).second);
			}
		}
		for(int i=Nx[0];i<=n;i=Nx[i])if(!vis[i])dfs(i,0),ans+=f[i][0];
		for(int i=Nx[0];i<=n;i=Nx[i])vis[i]=0;
	}
	return 0;
}