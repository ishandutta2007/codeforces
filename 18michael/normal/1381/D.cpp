#include<cstdio>
#include<set>
#include<utility>
#define Mx 16
using namespace std;
typedef pair<int,int> P;
set<P> s;
int n,a,b,c,A,B,mx,num,edge_t,Test_num;
int la[100002];
bool u[100002],vis[100002];
struct aaa
{
	int to,nx;
}edge[200002];
struct bbb
{
	int mx,fr,se,th;
}F[100002];
inline void swap(int &x,int &y)
{
	int z=x;x=y,y=z;
}
inline void add_edge(int x,int y)
{
	edge[++edge_t]=(aaa){y,la[x]},la[x]=edge_t;
	edge[++edge_t]=(aaa){x,la[y]},la[y]=edge_t;
}
inline void dfs(int x,int f,int d)
{
	if(x==b)return (void)(c=d,u[x]=1);
	for(int i=la[x],v;i;i=edge[i].nx)
		if((v=edge[i].to)!=f)
		{
			dfs(v,x,d+1);
			if(~c)return (void)(u[x]=1);
		}
}
inline void upd(int x,int y,int z)
{
	if(y>F[x].mx)F[x].th=F[x].se,F[x].se=F[x].mx,F[x].mx=y,F[x].fr=z;
	else if(y>F[x].se)F[x].th=F[x].se,F[x].se=y;
	else if(y>F[x].th)F[x].th=y;
}
inline void dfs1(int x,int f)
{
	F[x]=(bbb){0,x,0,0};
	for(int i=la[x],v;i;i=edge[i].nx)if((v=edge[i].to)!=f)dfs1(v,x),upd(x,F[v].mx+1,v);
}
inline bool dfs2(int x,int f)
{
	if(vis[x] && F[x].th>=c)return 1;
	for(int i=la[x],v;i;i=edge[i].nx)
		if((v=edge[i].to)!=f)
		{
			if(F[x].fr!=v)upd(v,F[x].mx+1,x);
			else upd(v,F[x].se+1,x);
			if(dfs2(v,x))return 1;
		}
	return 0;
}
inline void dfs3(int x,int f,int d)
{
	if(d>mx)mx=d,num=x;
	for(int i=la[x],v;i;i=edge[i].nx)if((v=edge[i].to)!=f && !u[v])dfs3(v,x,d+1);
}
inline void dfs4(int x,int f)
{
	vis[x]=1;
	for(int i=la[x],v;i;i=edge[i].nx)if((v=edge[i].to)!=f && !u[v])dfs4(v,x);
}
inline void dfs5(int x,int f,int y)
{
	if(x==y)return (void)(u[A=x]=1);
	for(int i=la[x],v;i;i=edge[i].nx)
		if((v=edge[i].to)!=f && !u[v])
		{
			dfs5(v,x,y);
			if(u[v])return (void)(u[x]=1);
		}
}
inline void dfs6(int x,int f,int d)
{
	if(!d)return (void)(B=x);u[x]=0;
	for(int i=la[x],v;i;i=edge[i].nx)if((v=edge[i].to)!=f && u[v])dfs6(v,x,d-1);
}
inline void solve()
{
	scanf("%d%d%d",&n,&a,&b),edge_t=0;
	for(int i=1;i<=n;++i)la[i]=u[i]=vis[i]=0;
	for(int i=1,x,y;i<n;++i)scanf("%d%d",&x,&y),add_edge(x,y);
	A=a,B=b,c=-1,dfs(A,0,0),s.clear();
	while(!s.count(P(A,B)))s.insert(P(A,B)),dfs3(num=A,0,mx=0),dfs5(A,0,num),dfs6(B,0,mx),dfs4(B,0),swap(A,B);
	for(int i=1;i<=n;++i)u[i]=0;
	A=b,B=a,c=-1,dfs(B,0,0);
	while(!s.count(P(A,B)))s.insert(P(A,B)),dfs3(num=A,0,mx=0),dfs5(A,0,num),dfs6(B,0,mx),dfs4(B,0),swap(A,B);
	for(int i=1;i<=n;++i)u[i]=0;
	c=-1,dfs(a,0,0),dfs1(1,0),puts(dfs2(1,0)? "YES":"NO");
}
int main()
{
	scanf("%d",&Test_num);
	while(Test_num--)solve();
	return 0;
}