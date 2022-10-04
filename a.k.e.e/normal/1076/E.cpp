#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;
const int MAXN=300005;
int n,m;
struct Node
{
	int v;
	Node *next;
}pool[MAXN<<1|1],*h[MAXN];
int etot=0;
void addEdge(int u,int v)
{
	Node *p=&pool[++etot];
	p->v=v;p->next=h[u];h[u]=p; 
}
int dfn[MAXN],dep[MAXN],dedfn[MAXN],dfn_cnt,size[MAXN];
ll ans[MAXN];
void dfs(int u,int pa)
{
	dfn[u]=++dfn_cnt;
	dedfn[dfn[u]]=u;
	size[u]=1;
	for(Node *p=h[u];p;p=p->next)
		if(p->v!=pa)
		{
			dep[p->v]=dep[u]+1;
			dfs(p->v,u);
			size[u]+=size[p->v];
		}
}
struct Opt
{
	int x,y,c;
	Opt(){}
	Opt(int x,int y,int c):x(x),y(y),c(c){} 
	inline bool operator <(const Opt &b)const
		{return x<b.x;}
}op[MAXN*4];
ll c[MAXN];
void add(int x,int d)
{
	for(;x<=n;x+=(x&-x))
		c[x]+=d;
}
ll query(int x)
{
	ll ans=0;
	for(;x;x-=(x&-x))
		ans+=c[x];
	return ans;
}

int main()
{
	int Q,u,v,x;
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		scanf("%d%d",&u,&v);
		addEdge(u,v);addEdge(v,u);
	}
	dep[1]=1;
	dfs(1,-1);
	scanf("%d",&Q);
	while(Q--)
	{
		scanf("%d%d%d",&u,&v,&x);
		op[++m]=Opt(dfn[u]-1,dep[u]-1,x);
		op[++m]=Opt(dfn[u]+size[u]-1,dep[u]-1,-x);
		op[++m]=Opt(dfn[u]-1,dep[u]+v,-x);
		op[++m]=Opt(dfn[u]+size[u]-1,dep[u]+v,x);
	}
	for(int i=1;i<=m;i++)
		if(op[i].y>n)op[i].y=n;
	sort(op+1,op+m+1);
	int cur=m;
	for(int i=n;i;i--)
	{
		for(;cur && op[cur].x==i;--cur)
			if(op[cur].y)add(op[cur].y,op[cur].c);
		ans[dedfn[i]]=query(n)-query(dep[dedfn[i]]-1);
	}
	for(int i=1;i<n;i++)
		cout<<ans[i]<<' ';
	cout<<ans[n]<<endl;
	return 0;
}