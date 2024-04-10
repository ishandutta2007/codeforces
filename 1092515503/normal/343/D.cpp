#include<bits/stdc++.h>
using namespace std;
#define lson x<<1
#define rson x<<1|1
#define mid ((l+r)>>1)
int n,q,head[500100],cnt,dep[500100],fa[500100],dfn[500100],sz[500100],son[500100],top[500100],rev[500100],tot,num[500100];
struct node{
	int to,next;
}edge[1000100];
void ae(int u,int v){
	edge[cnt].next=head[u],edge[cnt].to=v,head[u]=cnt++;
}
struct SegTree{
	int tag,sum;
}seg[2000100];
void pushdown(int x,int l,int r){
	if(seg[x].tag==-1)return;
	seg[lson].sum=(mid-l+1)*seg[x].tag,seg[lson].tag=seg[x].tag;
	seg[rson].sum=(r-mid)*seg[x].tag,seg[rson].tag=seg[x].tag;
	seg[x].tag=-1;
}
void pushup(int x){
	seg[x].sum=seg[lson].sum+seg[rson].sum;
}
void build(int x,int l,int r){
	seg[x].sum=0,seg[x].tag=-1;
	if(l==r)return;
	build(lson,l,mid),build(rson,mid+1,r);
}
void modify(int x,int l,int r,int L,int R,int val){
	if(l>R||r<L)return;
	if(L<=l&&r<=R){seg[x].tag=val,seg[x].sum=(r-l+1)*val;return;}
	pushdown(x,l,r),modify(lson,l,mid,L,R,val),modify(rson,mid+1,r,L,R,val),pushup(x);
}
int query(int x,int l,int r,int P){
	if(l>P||r<P)return 0;
	if(l==r)return seg[x].sum;
	pushdown(x,l,r);
	return query(lson,l,mid,P)+query(rson,mid+1,r,P);
}
void dfs1(int x,int Fa){
	sz[x]=1,fa[x]=Fa,dep[x]=dep[Fa]+1;
	for(int i=head[x],y;i!=-1;i=edge[i].next){
		if((y=edge[i].to)==Fa)continue;
		dfs1(y,x),sz[x]+=sz[y];
		if(sz[y]>sz[son[x]])son[x]=y;
	}
}
void dfs2(int x){
	if(son[x]){
		top[son[x]]=top[x];
		rev[son[x]]=++tot;
		dfn[tot]=son[x];
		dfs2(son[x]);
	}
	for(int i=head[x],y;i!=-1;i=edge[i].next){
		y=edge[i].to;
		if(y==fa[x]||y==son[x])continue;
		top[y]=y,rev[y]=++tot,dfn[tot]=y;
		dfs2(y);
	}
}
void del(int x){
	while(x){
		modify(1,1,n,rev[top[x]],rev[x],0);
		x=fa[top[x]];
	}
}
void add(int x){
	modify(1,1,n,rev[x],rev[x]+sz[x]-1,1);
}
int main(){
	scanf("%d",&n),memset(head,-1,sizeof(head));
	for(int i=2,x,y;i<=n;i++)scanf("%d%d",&x,&y),ae(x,y),ae(y,x);
	dfs1(1,0);
	top[1]=dfn[1]=rev[1]=tot=1;
	dfs2(1);
//	for(int i=1;i<=n;i++)printf("F:%d S:%d D:%d SON:%d T:%d R:%d DFN:%d\n",fa[i],sz[i],dep[i],son[i],top[i],rev[i],dfn[i]);
	build(1,1,n);
	scanf("%d",&q);
	for(int i=1,x,y;i<=q;i++){
		scanf("%d%d",&x,&y);
		if(x==1)add(y);
		else if(x==2)del(y);
		else printf("%d\n",query(1,1,n,rev[y]));
	}
	return 0;
}
/*
5 5 2 24
7 3 7 8 0 
1 2
1 5
3 1
4 1
1 2 1 3
1 2 5 3
4 5
1 5 1 3
2 1 3
*/