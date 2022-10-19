#include<bits/stdc++.h>
using namespace std;
int n,m,head[500100],cnt;
struct node{
	int to,next;
	bool tp;
}edge[1001000];
struct SegTree{
	int dfn[500100],sz[500100],rev[500100],dep[500100],tot;
	bool ini[500100];
	int mx[2000100][2];
	bool tag[2001000];
	#define lson x<<1
	#define rson x<<1|1
	#define mid ((l+r)>>1)
	#define REV(x) tag[x]^=1,swap(mx[x][0],mx[x][1])
	void pushdown(int x){if(tag[x])REV(lson),REV(rson),tag[x]=false;}
	void pushup(int x){mx[x][0]=max(mx[lson][0],mx[rson][0]),mx[x][1]=max(mx[lson][1],mx[rson][1]);}
	void dfs(int x,int fa){
		dfn[x]=++tot,sz[x]=1,rev[tot]=x;
		for(int i=head[x];i!=-1;i=edge[i].next)if(edge[i].to!=fa)dep[edge[i].to]=dep[x]+1,ini[edge[i].to]=ini[x]^edge[i].tp,dfs(edge[i].to,x),sz[x]+=sz[edge[i].to];
	}
	void build(int x,int l,int r){
		if(l==r){mx[x][ini[rev[l]]]=dep[rev[l]];return;}
		build(lson,l,mid),build(rson,mid+1,r),pushup(x);
	}
	void modify(int x,int l,int r,int L,int R){
		if(l>R||r<L)return;
		if(L<=l&&r<=R){REV(x);return;}
		pushdown(x),modify(lson,l,mid,L,R),modify(rson,mid+1,r,L,R),pushup(x);
	}
}seg[2];
void ae(int u,int v,bool w){
	edge[cnt].next=head[u],edge[cnt].to=v,edge[cnt].tp=w,head[u]=cnt++;
	edge[cnt].next=head[v],edge[cnt].to=u,edge[cnt].tp=w,head[v]=cnt++;
}
pair<int,int>dfs(int x,int fa){
	pair<int,int>ret=make_pair(-1,x);
	for(int i=head[x];i!=-1;i=edge[i].next)if(edge[i].to!=fa)ret=max(ret,dfs(edge[i].to,x));
	ret.first++;
	return ret;
}
int main(){
	scanf("%d",&n),memset(head,-1,sizeof(head));
	for(int i=1,x,y,z;i<n;i++)scanf("%d%d%d",&x,&y,&z),ae(x,y,z);
	int S=dfs(1,0).second,T=dfs(S,0).second;
	seg[0].dfs(S,0),seg[1].dfs(T,0);
	seg[0].build(1,1,n),seg[1].build(1,1,n);
	scanf("%d",&m);
	for(int i=1,x;i<=m;i++){
		scanf("%d",&x),x--;
		int u=edge[x<<1].to,v=edge[x<<1|1].to;
		if(seg[0].dep[u]<seg[0].dep[v])swap(u,v);
		seg[0].modify(1,1,n,seg[0].dfn[u],seg[0].dfn[u]+seg[0].sz[u]-1);
		if(seg[1].dep[u]<seg[1].dep[v])swap(u,v);
		seg[1].modify(1,1,n,seg[1].dfn[u],seg[1].dfn[u]+seg[1].sz[u]-1);
		printf("%d\n",max(seg[0].mx[1][0],seg[1].mx[1][0]));
	}
	return 0;
}