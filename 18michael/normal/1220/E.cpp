#include<bits/stdc++.h>
#define LL long long
using namespace std;
int n,m,s,p,edge_t=0;LL ans=0,t=0;
int w[200002],la[200002]={},deg[200002]={};
LL mx[200002]={};
queue<int> q;
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
inline void Topo()
{
	for(int i=1;i<=n;++i)if(deg[i]==1 && i!=s)q.push(i);
	while(!q.empty())
	{
		p=q.front(),q.pop();
		for(int i=la[p],v;i;i=edge[i].nx)
		{
			if((--deg[v=edge[i].to])==1 && v!=s)q.push(v);
			mx[v]=max(mx[v],mx[p]+w[p]);
		}
	}
}
int main()
{
	read(n),read(m);
	for(int i=1;i<=n;++i)scanf("%d",&w[i]);
	for(int i=1,x,y;i<=m;++i)scanf("%d%d",&x,&y),add_edge(x,y);
	scanf("%d",&s),Topo();
	for(int i=1;i<=n;++i)if(deg[i]>1 || i==s)ans+=w[i],t=max(t,mx[i]);
	return 0&printf("%lld",ans+t);
}