#include<cstdio>
#include<queue>
#include<vector>
using namespace std;
int n,t,edge_t=0,dfn_t=0;
int la[200002]={},deg[200002]={},dfn[200002];
bool vis[200002]={};
typedef pair<int,int> P;
priority_queue<P,vector<P>,less<P> > pq;
struct aaa
{
	int to,nx;
}edge[400002];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline void add_edge(int x,int y)
{
	edge[++edge_t]=(aaa){y,la[x]},la[x]=edge_t,++deg[x];
	edge[++edge_t]=(aaa){x,la[y]},la[y]=edge_t,++deg[y];
}
inline void dfs(int x,int f)
{
	dfn[x]=(++dfn_t);
	for(int i=la[x],v;i;i=edge[i].nx)
		if((v=edge[i].to)!=f)
			dfs(v,x);
}
int main()
{
	read(n);if(!(n&1))return 0&puts("NO");puts("YES");
	for(int i=1,x;i<=n;++i){read(x);if(x)add_edge(i,x);}
	dfs(1,1);
	for(int i=1;i<=n;++i)if(!(deg[i]&1))pq.push(P(dfn[i],i));
	for(;;)
	{
		while(!pq.empty())
		{
			t=pq.top().second,pq.pop();
			if(!vis[t] && !(deg[t]&1))break;
		}
		if(vis[t] || (deg[t]&1))break;
		printf("%d\n",t),vis[t]=1;
		for(int i=la[t],v;i;i=edge[i].nx)
			if(!vis[v=edge[i].to] && !((--deg[v])&1))
				pq.push(P(dfn[v],v));
	}
	for(int i=1;i<=n;++i)if(!vis[i])printf("%d\n",i);
	return 0;
}