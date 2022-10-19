#include<bits/stdc++.h>
#define LL long long
using namespace std;
int n,G=1,edge_t=0,s_t=0;
LL ans=0;
int la[100002],siz[100002],mx[100002],in[100002],out[100002];
typedef pair<int,int> P;
set<int> s[100002];
set<P,greater<P> > s1;
set<P> s2;
struct aaa
{
	int to,nx,val;
}edge[200002];
inline void add_edge(int x,int y,int z)
{
	edge[++edge_t]=(aaa){y,la[x],z},la[x]=edge_t;
	edge[++edge_t]=(aaa){x,la[y],z},la[y]=edge_t;
}
inline void dfs(int x,int f)
{
	siz[x]=1;
	for(int i=la[x],v;i;i=edge[i].nx)if((v=edge[i].to)!=f)dfs(v,x),siz[x]+=siz[v],mx[x]=max(mx[x],siz[v]),ans+=(LL)edge[i].val*min(siz[v],n-siz[v]);
}
inline void dfs1(int x,int f)
{
	if((mx[x]=max(mx[x],n-siz[x]))<mx[G])G=x;
	for(int i=la[x],v;i;i=edge[i].nx)if((v=edge[i].to)!=f)dfs1(v,x);
}
inline void dfs2(int x,int f)
{
	s[in[x]=out[x]=s_t].insert(x);
	for(int i=la[x],v;i;i=edge[i].nx)if((v=edge[i].to)!=f)dfs2(v,x);
}
int main()
{
	scanf("%d",&n);
	for(int i=1,x,y,z;i<n;++i)scanf("%d%d%d",&x,&y,&z),add_edge(x,y,z);
	dfs(1,0),dfs1(1,0),printf("%lld\n",ans<<1);
	for(int i=la[G];i;++s_t,i=edge[i].nx)dfs2(edge[i].to,G),s1.insert(P(siz[s_t]=(s[s_t].size()<<1),s_t)),s2.insert(P(*s[s_t].begin(),s_t));
	s[in[G]=s_t].insert(G),s1.insert(P(siz[s_t]=1,s_t)),s2.insert(P(G,s_t)),out[G]=(++s_t),s1.insert(P(siz[s_t]=1,s_t));
	for(int i=1,x,y;i<=n;++i)
	{
		if((*s1.begin()).first==n-i+1 && (*s1.begin()).second!=out[i])x=*s[(*s1.begin()).second].begin(),y=(*s1.begin()).second;
		else if((*s2.begin()).second!=out[i])x=(*s2.begin()).first,y=(*s2.begin()).second;
		else x=(*(++s2.begin())).first,y=(*(++s2.begin())).second;
		printf("%d ",x),s2.erase(P(x,y)),s[y].erase(x),s1.erase(P(siz[out[i]],out[i])),s1.erase(P(siz[y],y));
		if(s[y].size())s2.insert(P(*s[y].begin(),y));
		if(--siz[out[i]])s1.insert(P(siz[out[i]],out[i]));
		if(--siz[y])s1.insert(P(siz[y],y));
	}
	return 0;
}