#include<bits/stdc++.h>
#define Mx 16
#define LL long long
using namespace std;
int n,edge_t=0,dfn_t=0,q;
LL ans=0;
char c;
int la[100002],dfn[100002],dep[100002];
LL pre[100002];
int fa[100002][18];
struct cmp
{
	inline bool operator () (int x,int y) const
	{
		return dfn[x]<dfn[y];
	}
};
set<int,cmp> s;
set<int,cmp>::iterator it,it1;
struct aaa
{
	int to,nx,val;
}edge[200002];
inline void add_edge(int x,int y,int z)
{
	edge[++edge_t]=(aaa){y,la[x],z},la[x]=edge_t;
	edge[++edge_t]=(aaa){x,la[y],z},la[y]=edge_t;
}
inline void dfs(int x,int f,int d)
{
	dfn[x]=(++dfn_t),fa[x][0]=f,dep[x]=d;
	for(int i=1;i<=Mx;++i)fa[x][i]=fa[fa[x][i-1]][i-1];
	for(int i=la[x],v;i;i=edge[i].nx)
		if((v=edge[i].to)!=f)
			pre[v]=pre[x]+edge[i].val,dfs(v,x,d+1);
}
inline int LCA(int x,int y)
{
	if(dep[x]<dep[y])swap(x,y);
	for(int i=Mx;~i;--i)if(dep[fa[x][i]]>=dep[y])x=fa[x][i];
	if(x==y)return x;
	for(int i=Mx;~i;--i)if(fa[x][i]!=fa[y][i])x=fa[x][i],y=fa[y][i];
	return fa[x][0];
}
inline LL dis(int x,int y)
{
	return pre[x]+pre[y]-pre[LCA(x,y)]*2;
}
int main()
{
	scanf("%d",&n);
	for(int i=1,x,y,z;i<n;++i)scanf("%d%d%d",&x,&y,&z),add_edge(x,y,z);
	dfs(1,0,1),scanf("%d",&q);
	for(int x;q--;)
	{
		do c=getchar();while(c!='+' && c!='-' && c!='?');
		if(c=='?')
		{
			printf("%lld\n",ans>>1);
			continue;
		}
		scanf("%d",&x);
		if(c=='+')
		{
			if(!s.empty())it=s.lower_bound(x),--(it1=(it==s.begin()? s.end():it)),it=(it==s.end()? s.begin():it),ans+=dis(x,*it)+dis(x,*it1)-dis(*it,*it1);
			s.insert(x);
		}
		else
		{
			s.erase(x);
			if(!s.empty())it=s.lower_bound(x),--(it1=(it==s.begin()? s.end():it)),it=(it==s.end()? s.begin():it),ans-=dis(x,*it)+dis(x,*it1)-dis(*it,*it1);
		}
	}
	return 0;
}