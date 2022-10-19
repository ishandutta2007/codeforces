#include<cstdio>
#include<algorithm>
#include<set>
#include<queue>
#include<vector>
using namespace std;
int n,m,t,n1,Test_num;
int p[500002],q[500002],deg[500002];
set<int> s;
vector<int> tmp;
vector<int> vec[500002],son[500002];
typedef pair<int,int> P;
priority_queue<P,vector<P>,less<P> > pq,ept;
inline void dfs(int x)
{
	int now=0,t=0;set<int>::iterator it;
	for(s.erase(x);(it=s.upper_bound(now))!=s.end();)
	{
		for(now=(*it);t<vec[x].size() && vec[x][t]<(*it);++t);
		if(t==vec[x].size() || vec[x][t]!=(*it))son[x].push_back(*it),dfs(*it);
	}
}
inline void dfs1(int x,int f)
{
	bool ok=0;tmp.clear();if(f)tmp.push_back(f);
	for(int i=0;i<son[x].size();++i)if(!son[son[x][i]].size())tmp.push_back(son[x][i]);
	if(tmp.size()){p[x]=t+1,q[x]=t+tmp.size()+1;for(int i=0;i<tmp.size();++i)p[tmp[i]]=t+i+2,q[tmp[i]]=t+i+1;t=q[x],ok=1;}
	for(int i=0;i<son[x].size();++i)if(son[son[x][i]].size())dfs1(son[x][i],ok? 0:x),ok=1;
}
int main()
{
	scanf("%d",&Test_num);
	while(Test_num--)
	{
		scanf("%d%d",&n,&m),n1=n,s.clear(),t=0,pq=ept;
		for(int i=1;i<=n;++i)vec[i].clear(),son[i].clear(),p[i]=deg[i]=0;
		for(int i=1,x,y;i<=m;++i)scanf("%d%d",&x,&y),vec[x].push_back(y),vec[y].push_back(x),++deg[x],++deg[y];
		for(int i=1;i<=n;++i)sort(vec[i].begin(),vec[i].end()),pq.push(P(deg[i],i));
		for(int v;!pq.empty() && pq.top().first>=n1-1;pq.pop())
		{
			if(pq.top().first!=deg[v=pq.top().second])
			{
				pq.push(P(deg[v],v));
				continue;
			}
			p[v]=q[v]=(++t),--n1;
			for(int i=0;i<vec[v].size();++i)--deg[vec[v][i]];
		}
		for(int i=1;i<=n;++i)if(!p[i])s.insert(i);
		for(int v;!s.empty();)dfs(v=(*s.begin())),dfs1(v,0);
		for(int i=1;i<=n;++i)printf("%d%c",p[i],i==n? '\n':' ');
		for(int i=1;i<=n;++i)printf("%d%c",q[i],i==n? '\n':' ');
	}
	return 0;
}