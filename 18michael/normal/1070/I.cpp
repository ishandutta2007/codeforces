#include<cstdio>
#include<queue>
#define inf 0x3f3f3f3f
using namespace std;
int n,m,k,S=0,T,p,Test_num,edge_t,sum,tot;
int la[1202],deg[1202],c[602],dis[1202];
queue<int> q;
struct aaa
{
	int to,nx,val;
}edge[4802];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline int max(int x,int y)
{
	return x>y? x:y;
}
inline int min(int x,int y)
{
	return x<y? x:y;
}
inline void add_edge(int x,int y,int z)
{
	edge[++edge_t]=(aaa){y,la[x],z},la[x]=edge_t;
	edge[++edge_t]=(aaa){x,la[y],0},la[y]=edge_t;
}
inline bool bfs()
{
	for(int i=1;i<=T;++i)dis[i]=inf;
	dis[S]=0,q.push(S);
	while(!q.empty())
	{
		p=q.front(),q.pop();
		for(int i=la[p],v;i;i=edge[i].nx)
			if(edge[i].val && dis[v=edge[i].to]>dis[p]+1)
				dis[v]=dis[p]+1,q.push(v);
	}
	return dis[T]!=inf;
}
inline int dfs(int x,int f)
{
	if(x==T)return f;
	int used=0,tmp;
	for(int i=la[x],v;i;i=edge[i].nx)
		if(edge[i].val && dis[v=edge[i].to]==dis[x]+1)
		{
			tmp=dfs(v,min(edge[i].val,f-used)),edge[i].val-=tmp,edge[i^1].val+=tmp;
			if((used+=tmp)==f)break;
		}
	if(!used)dis[x]=0;
	return used;
}
inline int Dinic()
{
	int maxflow=0;
	while(bfs())maxflow+=dfs(S,inf);
	return maxflow;
}
int main()
{
	read(Test_num);
	while(Test_num--)
	{
		read(n),read(m),read(k),T=n+m+1,edge_t=tot=1,sum=0;for(int i=0;i<=T;++i)la[i]=deg[i]=c[i]=0;
		for(int i=1,x,y;i<=m;++i)read(x),read(y),add_edge(x,n+i,1),add_edge(y,n+i,1),add_edge(n+i,T,1),++deg[x],++deg[y];
		for(int i=1;i<=n;++i)if(deg[i]=max(deg[i]-k,0))add_edge(S,i,2*deg[i]),sum+=2*deg[i];
		if(Dinic()!=sum)for(int i=1;i<=m;++i)printf("0%c",i==m? '\n':' ');
		else
		{
			for(int i=1;i<=n;++i)
			{
				for(int j=la[i];j;j=edge[j].nx)if(edge[j].to>n && !edge[j].val)c[edge[j].to-n]=(++tot)/2;
				tot+=(!(tot&1));
			}
			tot=((tot-1)>>1);
			for(int i=1;i<=m;++i)printf("%d%c",c[i]? c[i]:(++tot),i==m? '\n':' ');
		}
	}
	return 0;
}