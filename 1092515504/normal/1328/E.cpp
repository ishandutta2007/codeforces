#include<bits/stdc++.h>
using namespace std;
#define lson x<<1
#define rson x<<1|1
#define mid ((l+r)>>1)
int n,m,dfn[200100],fa[200100],sz[200100],head[200100],cnt,tot,q[200100];
struct node{
	int to,next;
}edge[400100];
void ae(int u,int v){
	edge[cnt].next=head[u],edge[cnt].to=v,head[u]=cnt++;
	edge[cnt].next=head[v],edge[cnt].to=u,head[v]=cnt++;
}
void dfs(int x){
	dfn[x]=++tot,sz[x]=1;
	for(int i=head[x];i!=-1;i=edge[i].next)if(edge[i].to!=fa[x])fa[edge[i].to]=x,dfs(edge[i].to),sz[x]+=sz[edge[i].to];
}
struct SegTree{
	int mx,tag;
}seg[800100];
void add(int x,int y){
	seg[x].mx+=y,seg[x].tag+=y;
}
void pushup(int x){
	seg[x].mx=max(seg[lson].mx,seg[rson].mx);
}
void pushdown(int x){
	add(lson,seg[x].tag),add(rson,seg[x].tag),seg[x].tag=0;
}
void modify(int x,int l,int r,int L,int R,int val){
	if(l>R||r<L)return;
	if(L<=l&&r<=R){add(x,val);return;}
	pushdown(x),modify(lson,l,mid,L,R,val),modify(rson,mid+1,r,L,R,val),pushup(x);
}
int main(){
	scanf("%d%d",&n,&m),memset(head,-1,sizeof(head));
	for(int i=1,x,y;i<n;i++)scanf("%d%d",&x,&y),ae(x,y);
	dfs(1);
	for(int i=1,x;i<=m;i++){
		scanf("%d",&x);
		for(int j=1;j<=x;j++){
			scanf("%d",&q[j]);
			if(q[j]!=1)q[j]=fa[q[j]];
			modify(1,1,n,dfn[q[j]],dfn[q[j]]+sz[q[j]]-1,1);
		}
		puts(seg[1].mx==x?"YES":"NO");
		for(int j=1;j<=x;j++)modify(1,1,n,dfn[q[j]],dfn[q[j]]+sz[q[j]]-1,-1);
	}
	return 0;
}