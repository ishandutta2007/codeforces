#include<bits/stdc++.h>
using namespace std;
int n,m,l,r,mid,tot=0,las=0,edge_t,e_t,Vec_t=0,ok,dfn_t,rt_t,st_t,t;
int X[50002],Y[50002],C[50002],val[50002],id[50002],la[50002],lae[300002],Vec[50002],deg[50002],dfn[300002],low[300002],rt[300002],st[300002];
bool u[50002];
vector<int> ans;
vector<int> E[50002];
struct aaa
{
	int x,y,t,id;
};
vector<aaa> vec[50002];
struct bbb
{
	int to,nx,id;
}edge[100002];
struct ccc
{
	int to,nx;
}e[1800002];
inline bool cmp(int a,int b)
{
	return C[a]<C[b]? 1:0;
}
inline bool cmp1(int a,int b)
{
	return val[a]<val[b]? 1:0;
}
inline void add_edge(int x,int y,int z)
{
	if(!la[x])Vec[++Vec_t]=x;
	if(!la[y])Vec[++Vec_t]=y;
	edge[++edge_t]=(bbb){y,la[x],z},la[x]=edge_t,++deg[x];
	edge[++edge_t]=(bbb){x,la[y],z},la[y]=edge_t,++deg[y];
}
inline void add_e(int x,int y)
{
	e[++e_t]=(ccc){y,lae[x]},lae[x]=e_t;
}
inline void dfs(int x)
{
	u[x]=1;
	for(int i=la[x],v;i;i=edge[i].nx)if(!u[v=edge[i].to])dfs(v);
	if(la[x] && edge[la[x]].nx)add_e(edge[la[x]].id,edge[edge[la[x]].nx].id+m),add_e(edge[edge[la[x]].nx].id,edge[la[x]].id+m),add_e(edge[la[x]].id+m,edge[edge[la[x]].nx].id),add_e(edge[edge[la[x]].nx].id+m,edge[la[x]].id);
}
inline void Tarjan(int x)
{
	dfn[x]=low[x]=(++dfn_t),st[++st_t]=x;
	for(int i=lae[x],v;i;i=e[i].nx)
	{
		v=e[i].to;
		if(!dfn[v])Tarjan(v),low[x]=min(low[x],low[v]);
		else if(!rt[v])low[x]=min(low[x],dfn[v]);
	}
	if(dfn[x]==low[x])
	{
		++rt_t;
		do rt[st[st_t]]=rt_t,--st_t;while(st[st_t+1]!=x);
	}
}
inline bool check(int x)
{
	e_t=dfn_t=rt_t=st_t=0,t=(m<<1);
	for(int i=1;i<=m;++i)lae[i]=lae[i+m]=0;
	for(int i=1;i<=n;++i)
	{
		u[i]=0;
		for(int j=0;j<E[i].size();++j)lae[t+j+1]=0;
		for(int j=1;j<E[i].size();++j)add_e(t+j+1,t+j);
		for(int j=0;j<E[i].size();++j)
		{
			add_e(t+j+1,E[i][j]+m);
			if(j)add_e(E[i][j],t+j);
		}
		t+=E[i].size();
		for(int j=0;j<E[i].size();++j)lae[t+j+1]=0;
		for(int j=1;j<E[i].size();++j)add_e(t+j,t+j+1);
		for(int j=0;j<E[i].size();++j)
		{
			add_e(t+j+1,E[i][j]+m);
			if(j+1<E[i].size())add_e(E[i][j],t+j+2);
		}
		t+=E[i].size();
	}
	for(int i=1;i<=tot;++i)
	{
		for(edge_t=0;Vec_t;--Vec_t)la[Vec[Vec_t]]=deg[Vec[Vec_t]]=u[Vec[Vec_t]]=0;
		for(int j=0;j<vec[i].size();++j)add_edge(vec[i][j].x,vec[i][j].y,vec[i][j].id);
		for(int j=1;j<=Vec_t;++j)if(deg[Vec[j]]>=3)return 0;
		for(int j=1;j<=Vec_t;++j)if(!u[Vec[j]])dfs(Vec[j]);
	}
	for(int i=1;i<=m;++i)if(val[i]>x)add_e(i,i+m);
	for(int i=1;i<=t;++i)dfn[i]=rt[i]=0;
	for(int i=1;i<=(m<<1);++i)if(!dfn[i])Tarjan(i);
	for(int i=1;i<=m;++i)if(rt[i]==rt[i+m])return 0;
	return 1;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i)scanf("%d%d%d%d",&X[i],&Y[i],&C[i],&val[i]),id[i]=i,E[X[i]].push_back(i),E[Y[i]].push_back(i);
	sort(id+1,id+m+1,cmp);
	for(int i=1;i<=m;++i)
	{
		if(C[id[i]]!=las)++tot,las=C[id[i]];
		C[id[i]]=tot;
	}
	for(int i=1;i<=m;++i)vec[C[i]].push_back((aaa){X[i],Y[i],val[i],i});
	sort(id+1,id+m+1,cmp1);
	for(l=0,r=m;l<=r;)
	{
		mid=((l+r)>>1);
		if(check(val[id[mid]]))r=mid-1;
		else l=mid+1;
	}
	if(l>m)return 0&puts("No");
	check(val[id[l]]);
	for(int i=1;i<=m;++i)if(rt[i]<rt[i+m])ans.push_back(i);
	printf("Yes\n%d %d\n",val[id[l]],ans.size());
	for(int i=0;i<ans.size();++i)printf("%d ",ans[i]);
	return 0;
}