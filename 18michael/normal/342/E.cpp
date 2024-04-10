#include<bits/stdc++.h>
#define Mx 16
using namespace std;
int n,m,p,S,edge_t=0;
int la[100002]={},dis[100002],dep[100002];
int fa[100002][17];
bitset<100002> bs;
queue<int> q;
struct aaa
{
	int to,nx;
}edge[200002];
struct bbb
{
	int opt,x;
}qry[100002];
inline void add_edge(int x,int y)
{
	edge[++edge_t]=(aaa){y,la[x]},la[x]=edge_t;
	edge[++edge_t]=(aaa){x,la[y]},la[y]=edge_t;
}
inline void dfs(int x,int f,int d)
{
	fa[x][0]=f,dep[x]=d;
	for(int i=la[x],v;i;i=edge[i].nx)
		if((v=edge[i].to)!=f)
			dfs(v,x,d+1);
}
inline void get_fa()
{
	for(int i=1;i<=Mx;++i)
		for(int j=1;j<=n;++j)
			fa[j][i]=fa[fa[j][i-1]][i-1];
}
inline int LCA(int x,int y)
{
	if(dep[x]<dep[y])swap(x,y);
	for(int i=Mx;~i;--i)
		if(dep[fa[x][i]]>=dep[y])
			x=fa[x][i];
	if(x==y)return x;
	for(int i=Mx;~i;--i)
		if(fa[x][i]!=fa[y][i])
			x=fa[x][i],y=fa[y][i];
	return fa[x][0];
}
int main()
{
	scanf("%d%d",&n,&m),S=max((int)(sqrt(n*log(2)/log(n))),1);
	for(int i=1,x,y;i<n;++i)scanf("%d%d",&x,&y),add_edge(x,y);
	dfs(1,1,1),get_fa();for(int i=1;i<=m;++i)scanf("%d%d",&qry[i].opt,&qry[i].x);
	for(int i=1,st,ed;(st=(i-1)*S+1)<=m;++i)
	{
		ed=min(i*S,m),bs[1]=1,q.push(1),dis[1]=0;for(int j=2;j<=n;++j)bs[j]=0;
		for(int j=1;j<st;++j)if(qry[j].opt==1 && !bs[qry[j].x])bs[qry[j].x]=1,q.push(qry[j].x),dis[qry[j].x]=0;
		while(!q.empty())
		{
			p=q.front(),q.pop();
			for(int i=la[p],v;i;i=edge[i].nx)
				if(!bs[v=edge[i].to])
					bs[v]=1,q.push(v),dis[v]=dis[p]+1;
		}
		for(int j=st;j<=ed;++j)
			if(qry[j].opt==2)
			{
				for(int k=st;k<j;++k)
					if(qry[k].opt==1)
						dis[qry[j].x]=min(dis[qry[j].x],dep[qry[j].x]+dep[qry[k].x]-2*dep[LCA(qry[j].x,qry[k].x)]);
				printf("%d\n",dis[qry[j].x]);
			}
	}
	return 0;
}