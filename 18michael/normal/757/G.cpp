#include<bits/stdc++.h>
#define Mx 19
#define Mxa 8000000
#define LL long long
#define eps 1e-9
using namespace std;
int n,q,edge_t=0,col_t=0,G,tot,N,t=0,Rt,st_t,A_t=0;
LL lastans=0;
int p[200002],la[400002],col[400002],siz[400002],mx[400002],fa[400002],dep[400002],in[400002],st[400002],rt[400002];
LL pre[400002];
int mn[800002][22];
vector<int> son[400002];
typedef pair<int,int> P;
vector<P> vec[400002];
struct aaa
{
	int to,nx,v;
}edge[800002];
struct bbb
{
	int num,siz,t;
	LL dis,dis2;
	int son[3];
}a[Mxa+2];
inline int newnode(bbb x)
{
	return a[++A_t]=x,A_t;
}
inline void add_edge(int x,int y,int z)
{
	edge[++edge_t]=(aaa){y,la[x],z},la[x]=edge_t;
	edge[++edge_t]=(aaa){x,la[y],z},la[y]=edge_t;
}
inline void dfs(int x,int f)
{
	siz[x]=1,mx[x]=0;
	for(int i=la[x],v;i;i=edge[i].nx)if((v=edge[i].to)!=f && col[v]==col[x])dfs(v,x),siz[x]+=siz[v],mx[x]=max(mx[x],siz[v]);
}
inline void dfs1(int x,int f)
{
	if((mx[x]=max(mx[x],tot-siz[x]))<mx[G])G=x;
	for(int i=la[x],v;i;i=edge[i].nx)if((v=edge[i].to)!=f && col[v]==col[x])dfs1(v,x);
}
inline void dfs2(int x,int f,int c,int c1)
{
	col[x]=c1;
	for(int i=la[x],v;i;i=edge[i].nx)if((v=edge[i].to)!=f && col[v]==c)dfs2(v,x,c,c1);
}
inline int solve(int x)
{
	int g;dfs(x,0),tot=siz[x],dfs1(G=x,0),g=G;
	for(int i=la[g],v;i;i=edge[i].nx)if(col[v=edge[i].to]==col[g])dfs2(v,g,col[g],++col_t),fa[v=solve(v)]=g,son[g].push_back(v);
	return g;
}
inline void dfs4(int x,int f)
{
	for(int i=0,v;i<vec[x].size();++i)
	{
		if((v=vec[x][i].first)==f)
		{
			swap(vec[x][i],vec[x].back()),vec[x].pop_back(),--i;
			continue;
		}
		dfs4(v,x);
	}
	if(!vec[x].size())return ;
	int las=x;
	for(int i=0;i+1<vec[x].size();++i)add_edge(las,vec[x][i].first,vec[x][i].second),add_edge(las,++N,0),las=N;
	add_edge(las,vec[x].back().first,vec[x].back().second);
}
inline void dfs5(int x,int f)
{
	dep[x]=dep[f]+1,mn[in[x]=(++t)][0]=x;
	for(int i=la[x],v;i;i=edge[i].nx)if((v=edge[i].to)!=f)pre[v]=pre[x]+edge[i].v,dfs5(v,x),mn[++t][0]=x;
}
inline int merge(int x,int y)
{
	return dep[x]<dep[y]? x:y;
}
inline int LCA(int x,int y)
{
	if(in[x]>in[y])swap(x,y);
	int len=log2(in[y]-in[x]+1)+eps;
	return merge(mn[in[x]][len],mn[in[y]-(1<<len)+1][len]);
}
inline LL Dis(int x,int y)
{
	if(!x || !y)return 0;
	return pre[x]+pre[y]-(pre[LCA(x,y)]<<1);
}
inline void build(int x,int y)
{
	for(int i=0;i<son[x].size();++i)a[y].son[++a[y].t]=newnode((bbb){son[x][i],0,-1,0,0,{}}),build(son[x][i],a[y].son[a[y].t]);
}
inline void ins(int i)
{
	int x,y,z,w;st_t=0;
	for(int j=p[i];j;j=fa[j])st[++st_t]=j;
	x=rt[i-1],z=rt[i]=newnode((bbb){st[st_t],a[x].siz,-1,a[x].dis,a[x].dis2,{}});
	for(int j=st_t;j;x=y,z=w,--j)
	{
		++a[z].siz,a[z].dis+=Dis(p[i],st[j]),a[z].dis2+=Dis(p[i],fa[st[j]]);
		for(int k=0;k<=a[x].t;++k)
		{
			if(a[a[x].son[k]].num!=st[j-1])a[z].son[++a[z].t]=a[x].son[k];
			else y=a[x].son[k],w=a[z].son[++a[z].t]=newnode((bbb){st[j-1],a[y].siz,-1,a[y].dis,a[y].dis2,{}});
		}
	}
}
inline LL dfs3(int x,int f,int y,int z)
{
	LL res;
	if(y>1)
	{
		for(int i=0;i<=a[x].t;++i)
			if(a[a[x].son[i]].num==st[y-1])
			{
				res=dfs3(a[x].son[i],x,y-1,z);
				break;
			}
	}
	else res=a[x].dis;
	return res+a[f].dis+Dis(z,a[f].num)*(a[f].siz-a[x].siz)-a[x].dis2;
}
inline LL calc(int x,int y)
{
	int now=rt[y];st_t=0;
	for(int i=x;i;i=fa[i])st[++st_t]=i;
	return dfs3(now,0,st_t,x);
}
int main()
{
	scanf("%d%d",&n,&q),N=n;
	for(int i=1;i<=n;++i)scanf("%d",&p[i]);
	for(int i=1,x,y,z;i<n;++i)scanf("%d%d%d",&x,&y,&z),vec[x].push_back(P(y,z)),vec[y].push_back(P(x,z));
	dfs4(1,0),dfs5(1,0),Rt=solve(rt[0]=1),build(Rt,newnode((bbb){Rt,0,-1,0,0,{}}));
	for(int i=1;i<=Mx;++i)for(int j=1;j+(1<<i)-1<=t;++j)mn[j][i]=merge(mn[j][i-1],mn[j+(1<<(i-1))][i-1]);
	for(int i=1;i<=n;++i)ins(i);
	for(int o,x,y,z;q--;)
	{
		scanf("%d%d",&o,&x),x^=lastans;
		if(o==1)scanf("%d%d",&y,&z),y^=lastans,z^=lastans,printf("%lld\n",lastans=calc(z,y)-calc(z,x-1)),lastans&=1073741823;
		else swap(p[x],p[x+1]),ins(x);
	}
	return 0;
}