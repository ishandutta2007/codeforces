#include<bits/stdc++.h>
using namespace std;
#define lson x<<1
#define rson x<<1|1
#define mid ((l+r)>>1)
int n,m,val[200100],head[200100],cnt,dfn[200100],rev[200100],sz[200100],tot;
struct node{
	int to,next;
}edge[200100];
void ae(int u,int v){
	edge[cnt].next=head[u],edge[cnt].to=v,head[u]=cnt++;
}
void dfs(int x){
	dfn[x]=++tot,rev[tot]=x,sz[x]=1;
	for(int i=head[x];i!=-1;i=edge[i].next)dfs(edge[i].to),sz[x]+=sz[edge[i].to];
}
struct SegTree{
	int sum;
	bool tag;
}seg[800100];
void REV(int x,int l,int r){
	seg[x].tag^=1,seg[x].sum=(r-l+1)-seg[x].sum;
}
void pushdown(int x,int l,int r){
	if(!seg[x].tag)return;
	REV(lson,l,mid),REV(rson,mid+1,r),seg[x].tag=0;
}
void pushup(int x){
	seg[x].sum=seg[lson].sum+seg[rson].sum;
}
void build(int x,int l,int r){
	if(l==r){seg[x].sum=val[rev[l]];return;}
	build(lson,l,mid),build(rson,mid+1,r),pushup(x);
}
void modify(int x,int l,int r,int L,int R){
	if(l>R||r<L)return;
	if(L<=l&&r<=R){REV(x,l,r);return;}
	pushdown(x,l,r),modify(lson,l,mid,L,R),modify(rson,mid+1,r,L,R),pushup(x);
}
int query(int x,int l,int r,int L,int R){
	if(l>R||r<L)return 0;
	if(L<=l&&r<=R)return seg[x].sum;
	pushdown(x,l,r);
	return query(lson,l,mid,L,R)+query(rson,mid+1,r,L,R);
}
int main(){
	scanf("%d",&n),memset(head,-1,sizeof(head));
	for(int i=2,x;i<=n;i++)scanf("%d",&x),ae(x,i);
	dfs(1);
	for(int i=1;i<=n;i++)scanf("%d",&val[i]);
	build(1,1,n);
	scanf("%d",&m);
	for(int i=1,x;i<=m;i++){
		char s[10];
		scanf("%s%d",s,&x);
		if(s[0]=='g')printf("%d\n",query(1,1,n,dfn[x],dfn[x]+sz[x]-1));
		else modify(1,1,n,dfn[x],dfn[x]+sz[x]-1);
	}
	return 0;
}