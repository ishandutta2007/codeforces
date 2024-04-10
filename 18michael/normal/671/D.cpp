#include<bits/stdc++.h>
#define LL long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
int n,m,edge_t=0,a_t=0;
LL ans=0;
int la[300002],rt[300002],dep[300002];
typedef pair<int,int> P;
vector<P> vec[300002];
struct aaa
{
	int to,nx;
}edge[600002];
struct bbb
{
	int val,to,ls,rs,dis,laz;
}a[300002];
inline void add_edge(int x,int y)
{
	edge[++edge_t]=(aaa){y,la[x]},la[x]=edge_t;
	edge[++edge_t]=(aaa){x,la[y]},la[y]=edge_t;
}
inline int merge(int x,int y)
{
	if(!x || !y)return (x|y);
	if(a[x].val>a[y].val)swap(x,y);
	if(a[x].laz)a[a[x].ls].val+=a[x].laz,a[a[x].ls].laz+=a[x].laz,a[a[x].rs].val+=a[x].laz,a[a[x].rs].laz+=a[x].laz,a[x].laz=0;
	a[x].rs=merge(a[x].rs,y);
	if(a[a[x].rs].dis>a[a[x].ls].dis)swap(a[x].ls,a[x].rs);
	return a[x].dis=a[a[x].ls].dis+1,x;
}
inline void dfs(int x,int f)
{
	rt[x]=0,dep[x]=dep[f]+1;
	for(int i=0;i<vec[x].size();++i)a[++a_t]=(bbb){vec[x][i].second,vec[x][i].first,0,0,0,0},rt[x]=merge(rt[x],a_t);
	for(int i=la[x],v;i;i=edge[i].nx)
		if((v=edge[i].to)!=f)
		{
			dfs(v,x);
			if(!(~ans))return ;
			rt[x]=merge(rt[x],rt[v]);
		}
	while(rt[x] && dep[a[rt[x]].to]>=dep[x])rt[x]=merge(a[rt[x]].ls,a[rt[x]].rs);
	if(x>1)
	{
		if(!rt[x])return (void)(ans=-1);
		ans+=a[rt[x]].val,a[rt[x]].laz-=a[rt[x]].val,a[rt[x]].val=0;
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1,x,y;i<n;++i)scanf("%d%d",&x,&y),add_edge(x,y);
	for(int i=1,x,y,z;i<=m;++i)scanf("%d%d%d",&x,&y,&z),vec[x].push_back(P(y,z));
	dfs(1,0),printf("%lld",ans);
	return 0;
}