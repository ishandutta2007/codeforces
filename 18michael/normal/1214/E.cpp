#include<bits/stdc++.h>
using namespace std;
int n,t=1,head,tail,edge_t=0,mx;
int d[100002],id[100002],v[400002],la[200002]={},dep[200002];
bool u[200002]={};
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
inline bool cmp(int a,int b)
{
	return d[a]>d[b]? 1:0;
}
inline void add_edge(int x,int y)
{
	printf("%d %d\n",x,y);
	edge[++edge_t]=(aaa){y,la[x]},la[x]=edge_t;
	edge[++edge_t]=(aaa){x,la[y]},la[y]=edge_t;
}
inline void dfs(int x,int f,int d)
{
	dep[x]=d;if(d>dep[mx])mx=x;
	for(int i=la[x],v;i;i=edge[i].nx)
		if((v=edge[i].to)!=f)
			dfs(v,x,d+1);
}
int main()
{
	read(n),head=2*n,tail=2*n-1;
	for(int i=1;i<=n;++i)read(d[i]),id[i]=i;
	sort(id+1,id+n+1,cmp);
	for(int i=1;i<n;++i)printf("%d %d\n",2*id[i]-1,2*id[i+1]-1);
	for(int i=1;i<=n;++i)v[++tail]=2*id[i]-1,u[2*id[i]-1]=1;
	for(int i=1;i<=n;++i)
	{
		while(tail-head>=d[id[i]])u[v[tail]]=0,--tail;
		printf("%d %d\n",v[tail],2*id[i]);
		if(i==n)break;v[++tail]=2*id[i];
		if(u[2*id[i+1]-1])++head;
		else v[--head]=2*id[i+1]-1;
	}
	return 0;
}