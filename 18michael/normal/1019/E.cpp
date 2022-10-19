#include<bits/stdc++.h>
#define LL long long
using namespace std;
int n,m,edge_t=0,e_t=0,tot,col_t=0,G,G1,A,B,st_t;
int la[100002],lae[200002],col[200002],siz[200002],mx[200002],st[200002];
struct aaa
{
	int to,nx,a,b;
}edge[200002],e[400002];
struct bbb
{
	LL x,y;
};
vector<bbb> vec,vec1,vec2;
inline bool cmp(bbb a,bbb b)
{
	return a.x==b.x? (a.y<b.y):(a.x<b.x);
}
inline bbb mns(bbb a,bbb b)
{
	return (bbb){a.x-b.x,a.y-b.y};
}
inline bbb add(bbb a,bbb b)
{
	return (bbb){a.x+b.x,a.y+b.y};
}
inline __int128 cross(bbb a,bbb b)
{
	return (__int128)a.x*b.y-(__int128)a.y*b.x;
}
inline vector<bbb> GetConvexHull(vector<bbb> vec)
{
	vector<bbb> vec1;
	sort(vec.begin(),vec.end(),cmp),st_t=0;
	for(int i=0;i<vec.size();++i)
	{
		for(;st_t>1 && cross(mns(vec[i],vec[st[st_t]]),mns(vec[st[st_t-1]],vec[st[st_t]]))>=0;--st_t);
		st[++st_t]=i;
	}
	for(int i=1;i<=st_t;++i)vec1.push_back(vec[st[i]]);
	return vec1;
}
inline vector<bbb> merge(vector<bbb> vec,vector<bbb> vec1)
{
	vector<bbb> vec2;
	int t=1,t1=1;
	vec2.push_back(add(vec[0],vec1[0]));
	for(int i=vec.size()-1;i;--i)vec[i]=mns(vec[i],vec[i-1]);
	for(int i=vec1.size()-1;i;--i)vec1[i]=mns(vec1[i],vec1[i-1]);
	for(;t<vec.size() && t1<vec1.size();)
	{
		if(cross(vec[t],vec1[t1])<0)vec2.push_back(add(vec2.back(),vec[t])),++t;
		else vec2.push_back(add(vec2.back(),vec1[t1])),++t1;
	}
	for(;t<vec.size();)vec2.push_back(add(vec2.back(),vec[t])),++t;
	for(;t1<vec1.size();)vec2.push_back(add(vec2.back(),vec1[t1])),++t1;
	return vec2;
}
inline void add_edge(int x,int y,int z,int w,int &edge_t,int la[],aaa edge[])
{
	edge[++edge_t]=(aaa){y,la[x],z,w},la[x]=edge_t;
	edge[++edge_t]=(aaa){x,la[y],z,w},la[y]=edge_t;
}
inline void dfs(int x,int f)
{
	int las=x;
	for(int i=la[x],v;i;i=edge[i].nx)if((v=edge[i].to)!=f)add_edge(las,++tot,0,0,e_t,lae,e),add_edge(tot,v,edge[i].a,edge[i].b,e_t,lae,e),las=tot,dfs(v,x);
}
inline void dfs1(int x,int f,int c)
{
	siz[x]=1;
	for(int i=lae[x],v;i;i=e[i].nx)if((v=e[i].to)!=f && col[v]==col[x])dfs1(v,x,c),siz[x]+=siz[v];
}
inline void dfs2(int x,int f,int c)
{
	mx[x]=max(siz[x],tot-siz[x]);
	if(mx[x]<=mx[G])G=x,G1=f;
	for(int i=lae[x],v;i;i=e[i].nx)
		if((v=e[i].to)!=f && col[v]==col[x])
		{
			dfs2(v,x,c);
			if(G==v)A=e[i].a,B=e[i].b;
		}
}
inline void dfs3(int x,int f,int c,LL A,LL B,vector<bbb> &vec)
{
	vec.push_back((bbb){A,B});
	for(int i=lae[x],v;i;i=e[i].nx)if((v=e[i].to)!=f && col[v]==col[x])dfs3(v,x,c,A+e[i].a,B+e[i].b,vec);
}
inline void dfs4(int x,int f,int c,int c1)
{
	col[x]=c1;
	for(int i=lae[x],v;i;i=e[i].nx)if((v=e[i].to)!=f && col[v]==c)dfs4(v,x,c,c1);
}
inline void solve1(int x,int c)
{
	int g,g1,a,b;
	dfs1(x,0,c);
	if((tot=siz[x])==1)return ;
	dfs2(G=x,0,c),g=G,g1=G1,a=A,b=B,vec1.clear(),vec2.clear(),dfs3(g,g1,c,0,0,vec1),dfs3(g1,g,c,0,0,vec2),vec1=merge(GetConvexHull(vec1),GetConvexHull(vec2));
	for(int i=0;i<vec1.size();++i)vec.push_back(add(vec1[i],(bbb){a,b}));
	dfs4(g,g1,c,++col_t),solve1(g,col_t),dfs4(g1,g,c,++col_t),solve1(g1,col_t);
}
int main()
{
	scanf("%d%d",&n,&m),tot=n;
	for(int i=1,x,y,z,w;i<n;++i)scanf("%d%d%d%d",&x,&y,&z,&w),add_edge(x,y,z,w,edge_t,la,edge);
	dfs(1,0),vec.push_back((bbb){0,0}),solve1(1,0),vec=GetConvexHull(vec);
	for(int i=0,t=0;i<m;printf("%lld ",vec[t].x*i+vec[t].y),++i)for(;t+1<vec.size() && vec[t].x*i+vec[t].y<=vec[t+1].x*i+vec[t+1].y;++t);
	return 0;
}