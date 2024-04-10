#include<bits/stdc++.h>
#define B 735
#define Mx 50000
#define inf 0x3f3f3f3f
using namespace std;
int n,S=0,T,edge_t,Test_num,p;
int a[50002],to[50002],la[200002],dis[200002];
queue<int> q;
struct aaa
{
	int to,nx,f;
}edge[8000002];
inline void add(int x,int y,int z)
{
	edge[++edge_t]=(aaa){y,la[x],z},la[x]=edge_t;
	edge[++edge_t]=(aaa){x,la[y],0},la[y]=edge_t;
}
inline void Add(int x,int y)
{
	add(x,y+n,1),add(x,y+(n<<1)+n,1),add(x+(n<<1),y+(n<<1)+n,1);
}
inline bool bfs()
{
	for(int i=1;i<=T;++i)dis[i]=inf;
	for(q.push(dis[S]=0);q.size();)
	{
		p=q.front(),q.pop();
		for(int i=la[p],v;i;i=edge[i].nx)if(edge[i].f && dis[v=edge[i].to]>dis[p]+1)dis[v]=dis[p]+1,q.push(v);
	}
	return dis[T]<inf;
}
inline int dfs(int x,int f)
{
	if(x==T)return f;
	int used=0,tmp;
	for(int i=la[x],v;i;i=edge[i].nx)
		if(edge[i].f && dis[v=edge[i].to]==dis[x]+1)
		{
			tmp=dfs(v,min(edge[i].f,f-used)),edge[i].f-=tmp,edge[i^1].f+=tmp;
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
inline void solve()
{
	scanf("%d",&n),edge_t=1,T=(n<<2)+1;
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	for(int i=0;i<=T;++i)la[i]=0;
	for(int i=1;i<=n;++i)add(i,i+(n<<1)+n,1),add(S,i,1),add(S,i+(n<<1),1),add(i+n,T,1),add(i+(n<<1)+n,T,1);
	if(n<=B)
	{
		sort(a+1,a+n+1);
		for(int i=2;i<=n;++i)for(int j=1;j<i;++j)if(!(a[i]%a[j]))Add(i,j);
	}
	else
	{
		for(int i=1;i<=n;++i)to[a[i]]=i;
		for(int i=1;i<=Mx;++i)if(to[i])for(int j=(i<<1);j<=Mx;j+=i)if(to[j])Add(to[j],to[i]);
	}
	printf("%d\n",Dinic()-n);
	if(n>B)for(int i=1;i<=n;++i)to[a[i]]=0;
}
int main()
{
	for(scanf("%d",&Test_num);Test_num--;)solve();
	return 0;
}