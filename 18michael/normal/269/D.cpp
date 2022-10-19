#include<bits/stdc++.h>
#define inf 1000000000
using namespace std;
int n,t,edge_t=0,tmp,L,R,Mid,val_t=0;
int h[100002],l[100002],r[100002],id[100002],la[100002],val[300002];
bool vis[100002];
struct aaa
{
	int l,r,id,o;
	inline bool operator < (const aaa &a) const
	{
		return (l==a.l)? (r==a.r? (id<a.id):(r<a.r)):(l<a.l);
	}
};
set<aaa> s;
set<aaa>::iterator it;
struct bbb
{
	int to,nx,v;
}edge[300002];
inline bool cmp(int x,int y)
{
	return h[x]<h[y];
}
inline int calc(int x,int y)
{
	return min(r[x],r[y])-max(l[x],l[y]);
}
inline void add_edge(int x,int y,int z)
{
	edge[++edge_t]=(bbb){y,la[x],z},la[x]=edge_t;
}
inline bool dfs(int x)
{
	if(x==n)return 1;
	vis[x]=1;
	for(int i=la[x],v;i;i=edge[i].nx)if(edge[i].v>=val[Mid] && !vis[v=edge[i].to] && dfs(v))return 1;
	return 0;
}
int main()
{
	scanf("%d%d",&n,&t);
	for(int i=1;i<=n;++i)scanf("%d%d%d",&h[i],&l[i],&r[i]),id[i]=i;
	h[0]=t,h[++n]=id[0]=0,id[n]=n,l[0]=l[n]=-inf,r[0]=r[n]=inf,sort(id,id+n+1,cmp);
	for(int i=0;i<=n;++i)
	{
		it=s.lower_bound((aaa){r[id[i]],-inf,-1,0});
		while(it!=s.begin() && (*(--it)).r>l[id[i]])
		{
			tmp=0;
			if((*it).r<r[id[i]])tmp|=1;
			if((*it).l>l[id[i]])tmp|=2;
			if(!(tmp&(*it).o))add_edge(id[i],(*it).id,val[++val_t]=calc(id[i],(*it).id));
			if((*it).r>r[id[i]])s.insert((aaa){r[id[i]],(*it).r,(*it).id,(*it).o|2});
			if((*it).l<l[id[i]])s.insert((aaa){(*it).l,l[id[i]],(*it).id,(*it).o|1});
			it=s.erase(it);
		}
		s.insert((aaa){l[id[i]],r[id[i]],id[i],0});
	}
	sort(val+1,val+val_t+1);
	for(L=1,R=val_t;L<=R;)
	{
		Mid=((L+R)>>1);
		for(int i=0;i<=n;++i)vis[i]=0;
		if(dfs(0))L=Mid+1;else R=Mid-1;
	}
	return 0&printf("%d",val[R]);
}