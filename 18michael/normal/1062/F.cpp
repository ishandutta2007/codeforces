#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
int n,m,edge_t,tot,ans=0;bool ok;
int la[300002]={},out[300002]={},into[300002]={},rx[300002],ry[300002],r[300002]={};
queue<int> q,ept;
struct aaa
{
	int to,nx;
}edge[300002];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline void add_edge(int x,int y)
{
	edge[++edge_t]=(aaa){y,la[x]},la[x]=edge_t,++into[y];
}
inline void Topo(int z[])
{
	int d,u;
	while(!q.empty())
	{
		d=q.front(),q.pop();
		if(q.empty())z[d]+=n-tot;
		else if(q.size()==1)
		{
			ok=1;
			for(int i=la[q.front()];i;i=edge[i].nx)
			{
				u=edge[i].to;
				if(into[u]==1)
				{
					ok=0;
					break;
				}
			}
			if(ok)z[d]+=n-tot;
		}
		for(int i=la[d];i;i=edge[i].nx)
		{
			u=edge[i].to;
			if(!(--into[u]))q.push(u),++tot;
		}
	}
}
inline void Solve(int x[],int y[],int z[])
{
	edge_t=tot=0,q=ept,memset(into,0,sizeof(into)),memset(la,0,sizeof(la));
	for(int i=1;i<=m;++i)add_edge(x[i],y[i]);
	for(int i=1;i<=n;++i)if(!into[i])q.push(i),++tot;
	Topo(z);
}
int main()
{
	read(n),read(m);
	for(int i=1;i<=m;++i)read(rx[i]),read(ry[i]);
	Solve(rx,ry,r),Solve(ry,rx,r);
	for(int i=1;i<=n;++i)if(r[i]>=n-2)++ans;
	printf("%d\n",ans);
	return 0;
}