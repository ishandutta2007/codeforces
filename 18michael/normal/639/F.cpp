#include<bits/stdc++.h>
#define Mx 18
using namespace std;
int n,m,q,R=0,edge_t=0,e_t=0,dfn_t=0,st_t=0,rt_t=0,N,M;
int la[300002],lae[300002],dfn[300002],low[300002],st[300002],Rt[300002],num[300002],dep[300002],dfn2[300002];
int rt[2][300002],fa[300002][22];
bool u[300002];
vector<int> vec,vec1,vec2;
struct aaa
{
	int to,nx;
}edge[600002],e[600002];
inline bool cmp(int x,int y)
{
	return dfn2[x]<dfn2[y]? 1:0;
}
inline void decode(int &x)
{
	if(!((x+=R)%=n))x=n;
}
inline void getroot(int x)
{
	if(x==Rt[x])return ;
	getroot(Rt[x]),Rt[x]=Rt[Rt[x]];
}
inline void add_edge(int x,int y)
{
	if(x==y)return ;
	edge[++edge_t]=(aaa){y,la[x]},la[x]=edge_t;
	edge[++edge_t]=(aaa){x,la[y]},la[y]=edge_t;
}
inline void add_e(int x,int y)
{
	e[++e_t]=(aaa){y,lae[x]},lae[x]=e_t;
	e[++e_t]=(aaa){x,lae[y]},lae[y]=e_t;
}
inline void Tarjan(int x,bool o)
{
	int cnt=0;
	dfn[x]=low[x]=(++dfn_t),st[++st_t]=x,st[st_t+1]=0;
	for(int i=la[x],v;i;i=edge[i].nx)
	{
		v=edge[i].to;
		if(!dfn[v])Tarjan(v,o),low[x]=min(low[x],low[v]);
		else if(!rt[o][v])low[x]=min(low[x],dfn[v]);
		cnt+=(low[v]<dfn[x]);
	}
	if(cnt<2)for(++rt_t,Rt[rt_t]=rt_t;st[st_t+1]!=x;--st_t)rt[o][st[st_t]]=rt_t;
}
inline void dfs(int x,int f,int y)
{
	dfn2[x]=(++dfn_t),dep[x]=dep[fa[x][0]=f]+1,num[x]=y;
	for(int i=1;i<=Mx;++i)fa[x][i]=fa[fa[x][i-1]][i-1];
	for(int i=lae[x],v;i;i=e[i].nx)if((v=e[i].to)!=f)dfs(v,x,y);
}
inline int LCA(int x,int y)
{
	if(dep[x]<dep[y])swap(x,y);
	for(int i=Mx;~i;--i)
		if(dep[fa[x][i]]>=dep[y])
			x=fa[x][i];
	if(x==y)return x;
	for(int i=Mx;~i;--i)
		if(fa[x][i]!=fa[y][i])
			x=fa[x][i],y=fa[y][i];
	return fa[x][0];
}
inline bool solve()
{
	for(int i=0;i<vec.size();++i)u[vec[i]]=la[vec[i]]=dfn[vec[i]]=low[vec[i]]=rt[1][vec[i]]=0;
	for(int i=0;i<vec2.size();++i)u[vec2[i]]=la[vec2[i]]=dfn[vec2[i]]=low[vec2[i]]=rt[1][vec2[i]]=0;
	vec.clear(),vec2.clear(),edge_t=dfn_t=rt_t=0,scanf("%d%d",&N,&M);
	for(int i=1,x;i<=N;++i)
	{
		scanf("%d",&x),decode(x);
		if(!u[x=rt[0][x]])vec.push_back(x),u[x]=1;
	}
	vec1=vec;
	for(int i=1,x,y;i<=M;++i)
	{
		scanf("%d%d",&x,&y),decode(x),decode(y),add_edge(x=rt[0][x],y=rt[0][y]);
		if(!u[x])vec.push_back(x),u[x]=1;
		if(!u[y])vec.push_back(y),u[y]=1;
	}
	for(int i=0;i<vec.size();++i)if(!u[num[vec[i]]])vec.push_back(num[vec[i]]),u[num[vec[i]]]=1;
	sort(vec.begin(),vec.end(),cmp);
	for(int i=0,j,x;i<vec.size();)
	{
		for(j=i+1;j<vec.size() && num[vec[i]]==num[vec[j]];++j);
		for(st[st_t=1]=vec[i];(++i)<j;)
		{
			if(vec[i]==vec[i-1])continue;
			for(vec2.push_back(x=LCA(vec[i],st[st_t]));dep[st[st_t-1]]>=dep[x];--st_t)add_edge(st[st_t-1],st[st_t]);
			if(x!=st[st_t])add_edge(x,st[st_t]),st[st_t]=x;
			st[++st_t]=vec[i];
		}
		for(;st_t>1;--st_t)add_edge(st[st_t-1],st[st_t]);
	}
	st_t=0;
	for(int i=0;i<vec1.size();++i)if(!dfn[vec1[i]])Tarjan(vec1[i],1);
	for(int i=1;i<vec1.size();++i)if(rt[1][vec1[i]]!=rt[1][vec1[0]])return 0;
	return 1;
}
int main()
{
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1,x,y;i<=m;++i)scanf("%d%d",&x,&y),add_edge(x,y);
	for(int i=1;i<=n;++i)if(!dfn[i])Tarjan(i,0);
	for(int i=1;i<=n;++i)
		for(int j=la[i],v;j;j=edge[j].nx)
		{
			getroot(rt[0][i]),getroot(rt[0][v=edge[j].to]);
			if(Rt[rt[0][i]]!=Rt[rt[0][v]])Rt[Rt[rt[0][v]]]=Rt[rt[0][i]],add_e(rt[0][i],rt[0][v]);
		}
	dfn_t=0;
	for(int i=1;i<=rt_t;++i)if(!num[i])dfs(i,0,i);
	for(int i=1;i<=n;++i)la[i]=dfn[i]=low[i]=0;
	for(int i=1;i<=q;++i)if(solve())puts("YES"),(R+=i)%=n;else puts("NO");
	return 0;
}