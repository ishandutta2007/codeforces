#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
int n,m,p,S=0,T=1,tot=1,edge_t=1,v_t=0;
int ls[20002],rs[20002],L[20002],R[20002],la[25002]={},dis[25002],num[5002],from[5002],vNum[5002],vX[5002],vY[5002],vZ[5002];
queue<int> q;
struct aaa
{
	int to,nx,f;
}edge[500002];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline void add_edge(int x,int y,int z)
{
	edge[++edge_t]=(aaa){y,la[x],z},la[x]=edge_t;
	edge[++edge_t]=(aaa){x,la[y],0},la[y]=edge_t;
}
inline void build(int l,int r)
{
	int t=(++tot),mid=((l+r)>>1);if((L[t]=l)==(R[t]=r)){add_edge(num[l]=t,T,1);return ;}
	ls[t]=tot+1,build(l,mid),rs[t]=tot+1,build(mid+1,r),add_edge(t,ls[t],inf),add_edge(t,rs[t],inf);
}
inline void add(int x,int k,int l,int r)
{
	if(L[k]>=l && R[k]<=r){add_edge(x,k,1);return ;}
	if(l<=R[ls[k]])add(x,ls[k],l,r);
	if(r>=L[rs[k]])add(x,rs[k],l,r);
}
inline bool bfs()
{
	for(int i=1;i<=tot;++i)dis[i]=inf;
	dis[S]=0,q.push(S);
	while(!q.empty())
	{
		p=q.front(),q.pop();
		for(int i=la[p],v;i;i=edge[i].nx)
			if(edge[i].f && dis[v=edge[i].to]>dis[p]+1)
				dis[v]=dis[p]+1,q.push(v);
	}
	return dis[T]!=inf;
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
int main()
{
	read(n),read(m),build(1,m);
	for(int i=1,x,y;i<=n;++i)
	{
		++tot,read(x);
		if(!x)for(add_edge(S,tot,1),read(x);x--;)read(y),add_edge(tot,num[y],1);
		else if(x==1)add_edge(S,tot,1),read(x),read(y),add(tot,2,x,y);
		else vNum[++v_t]=i,add_edge(S,tot,2),read(vX[v_t]),add_edge(tot,num[vX[v_t]],1),read(vY[v_t]),add_edge(tot,num[vY[v_t]],1),read(vZ[v_t]),add_edge(tot,num[vZ[v_t]],1);
	}
	printf("%d\n",Dinic());
	for(int i=1,v;i<=m;++i)
		for(int j=la[num[i]];j;j=la[num[i]]=edge[j].nx)
			if(edge[j].f && (j&1))
			{
				for(v=num[i];v-(tot-n)<=0;)
					for(int k=la[v];k;k=la[v]=edge[k].nx)
						if(edge[k].f && (k&1))
						{
							--edge[k].f,v=edge[k].to;
							break;
						}
				from[i]=v-(tot-n);
				break;
			}
	for(int i=1;i<=v_t;++i)
	{
		if(from[vX[i]]!=vNum[i] && from[vY[i]]!=vNum[i] && from[vZ[i]]==vNum[i])from[vX[i]]=vNum[i];
		if(from[vY[i]]!=vNum[i] && from[vZ[i]]!=vNum[i] && from[vX[i]]==vNum[i])from[vY[i]]=vNum[i];
		if(from[vZ[i]]!=vNum[i] && from[vX[i]]!=vNum[i] && from[vY[i]]==vNum[i])from[vZ[i]]=vNum[i];
	}
	for(int i=1;i<=m;++i)if(from[i])printf("%d %d\n",from[i],i);
	return 0;
}