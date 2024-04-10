#include<bits/stdc++.h>
using namespace std;
#define lson x<<1
#define rson x<<1|1
#define mid ((l+r)>>1) 
int n,m,head[200100],cnt,f[200100],g[200100],anc[200100][20],dep[200100],dfn[200100],sz[200100],tot;
struct edge{
	int to,next;
}edge[200100];
struct EDGE{
	int u,v,w;
	EDGE(int x=0,int y=0,int z=0){
		u=x,v=y,w=z;
	}
};
void ae(int u,int v){
	edge[cnt].next=head[u],edge[cnt].to=v,head[u]=cnt++;
}
vector<EDGE>v[200100];
void dfs_lca(int x){
	dfn[x]=++tot,sz[x]=1;
	for(int i=1;(1<<i)<=dep[x];i++)anc[x][i]=anc[anc[x][i-1]][i-1];
	for(int i=head[x];i!=-1;i=edge[i].next)dep[edge[i].to]=dep[x]+1,anc[edge[i].to][0]=x,dfs_lca(edge[i].to),sz[x]+=sz[edge[i].to];
}
int LCA(int x,int y){
	if(dep[x]>dep[y])swap(x,y);
	for(int i=19;i>=0;i--)if(dep[x]<=dep[y]-(1<<i))y=anc[y][i];
	if(x==y)return x;
	for(int i=19;i>=0;i--)if(anc[x][i]!=anc[y][i])x=anc[x][i],y=anc[y][i];
	return anc[x][0];
}
struct SegTree{
	int sum,tag;
}seg[800100];
void pushup(int x){
	seg[x].sum=seg[lson].sum+seg[rson].sum;
}
void pushdown(int x,int l,int r){
	seg[lson].sum+=(mid-l+1)*seg[x].tag,seg[rson].sum+=(r-mid)*seg[x].tag;
	seg[lson].tag+=seg[x].tag,seg[rson].tag+=seg[x].tag;
	seg[x].tag=0;
}
void modify(int x,int l,int r,int L,int R,int val){
	if(l>R||r<L)return;
	if(L<=l&&r<=R){seg[x].sum+=(r-l+1)*val,seg[x].tag+=val;return;}
	pushdown(x,l,r),modify(lson,l,mid,L,R,val),modify(rson,mid+1,r,L,R,val),pushup(x);
}
int query(int x,int l,int r,int P){
	if(l>P||r<P)return 0;
	if(l==r)return seg[x].sum;
	pushdown(x,l,r);
	return query(lson,l,mid,P)+query(rson,mid+1,r,P);
}
void dfs_dp(int x){
	for(int i=head[x];i!=-1;i=edge[i].next)dfs_dp(edge[i].to),g[x]+=f[edge[i].to];
	f[x]=g[x];
	for(int i=0;i<v[x].size();i++)f[x]=max(f[x],query(1,1,n,dfn[v[x][i].u])+query(1,1,n,dfn[v[x][i].v])+v[x][i].w+g[x]);
	modify(1,1,n,dfn[x],dfn[x]+sz[x]-1,g[x]-f[x]);
}
int main(){
	scanf("%d%d",&n,&m),memset(head,-1,sizeof(head));
	for(int i=2,Fa;i<=n;i++)scanf("%d",&Fa),ae(Fa,i);
	dfs_lca(1);
	for(int i=1,x,y,z;i<=m;i++)scanf("%d%d%d",&x,&y,&z),v[LCA(x,y)].push_back(EDGE(x,y,z));
	dfs_dp(1);
//	for(int i=1;i<=n;i++)printf("(%d,%d)\n",f[i],g[i]);
	printf("%d\n",f[1]);
	return 0;
}