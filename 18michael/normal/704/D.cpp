#include<bits/stdc++.h>
#define LL long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
int n,m,r,b,idt,tot,S,T,S1=0,T1,edge_t=1,p;
LL sum=0,ans=0;
char s[100002];
int X[100002],Y[100002],t[100002],l[100002],d[100002],id[200002],val[200002],la[200012],dis[200012],cur[200012];
LL deg[200002];
int cnt[2][100002],mn[2][100002];
queue<int> q;
set<int> st[2];
struct aaa
{
	int to,nx;
	LL f;
}edge[1000002];
inline void add_edge(int x,int y,LL z)
{
	edge[++edge_t]=(aaa){y,la[x],z},la[x]=edge_t;
	edge[++edge_t]=(aaa){x,la[y],0},la[y]=edge_t;
}
inline bool add(int x,int y,int l,int r)
{
	if(l>r)return 1;
	return deg[x]+=l,deg[y]-=l,add_edge(x,y,r-l),0;
}
inline bool cmp(int x,int y)
{
	return val[x]<val[y];
}
inline bool bfs()
{
	for(int i=0;i<=T;++i)dis[i]=T+10,cur[i]=la[i];
	for(dis[S]=0,q.push(S);q.size();)
	{
		p=q.front(),q.pop();
		for(int i=la[p],v;i;i=edge[i].nx)if(edge[i].f && dis[v=edge[i].to]>dis[p]+1)dis[v]=dis[p]+1,q.push(v);
	}
	return dis[T]<T+10;
}
inline LL dfs(int x,LL f)
{
	if(x==T)return f;
	LL tmp,used=0;
	for(int &i=cur[x],v;i;i=edge[i].nx)
		if(edge[i].f && dis[v=edge[i].to]==dis[x]+1)
		{
			tmp=dfs(v,min(f-used,edge[i].f)),edge[i].f-=tmp,edge[i^1].f+=tmp;
			if((used+=tmp)==f)break;
		}
	if(!used)dis[x]=0;
	return used;
}
inline LL Dinic()
{
	LL maxflow=0;
	while(bfs())maxflow+=dfs(S,inf);
	return maxflow;
}
int main()
{
	scanf("%d%d%d%d",&n,&m,&r,&b),idt=tot=0;
	for(int i=1;i<=n;++i)scanf("%d%d",&X[i],&Y[i]),val[id[++idt]=i]=X[i],st[0].insert(X[i]),st[1].insert(Y[i]);
	for(int i=1;i<=m;++i)
	{
		scanf("%d%d%d",&t[i],&l[i],&d[i]),--t[i];
		if(!st[t[i]].count(l[i]))--i,--m;
		else if(!t[i])val[id[++idt]=n+i]=l[i];
	}
	sort(id+1,id+idt+1,cmp);
	for(int i=1;i<=idt;++i)(id[i]>n? l[id[i]-n]:X[id[i]])=(tot+=(val[id[i]]!=val[id[i-1]]));
	idt=tot=0;
	for(int i=1;i<=n;++i)val[id[++idt]=i]=Y[i];
	for(int i=1;i<=m;++i)if(t[i]==1)val[id[++idt]=n+i]=l[i];
	sort(id+1,id+idt+1,cmp),T1=(n<<1)+1,S=T1+1,T=T1+2,add_edge(T1,S1,inf);
	for(int i=1;i<=idt;++i)(id[i]>n? l[id[i]-n]:Y[id[i]])=(tot+=(val[id[i]]!=val[id[i-1]]));
	for(int i=1;i<=n;++i)++cnt[0][X[i]],++cnt[1][Y[i]],add(X[i],Y[i]+n,0,1);
	for(int i=1;i<=n;++i)mn[0][i]=mn[1][i]=n;
	for(int i=1;i<=m;++i)mn[t[i]][l[i]]=min(mn[t[i]][l[i]],d[i]);
	for(int i=1;i<=n;++i)
	{
		if(cnt[0][i] && add(S1,i,max((cnt[0][i]-mn[0][i]+1)/2,0),(cnt[0][i]+mn[0][i])/2))return 0&puts("-1");
		if(cnt[1][i] && add(i+n,T1,max((cnt[1][i]-mn[1][i]+1)/2,0),(cnt[1][i]+mn[1][i])/2))return 0&puts("-1");
	}
	for(int i=0;i<=T1;++i)
	{
		if(deg[i]>0)add_edge(i,T,deg[i]),sum+=deg[i];
		if(deg[i]<0)add_edge(S,i,-deg[i]);
	}
	if(Dinic()<sum)return 0&puts("-1");
	S=S1,T=T1,edge[2].f=edge[3].f=0,Dinic();
	for(int i=1;i<=n;++i)ans+=((s[i]=((b<r)^(edge[2*i+2].f)? 'b':'r'))=='b'? b:r);
	return 0&printf("%lld\n%s",ans,s+1);
}