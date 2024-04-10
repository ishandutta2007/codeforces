#include<bits/stdc++.h>
using namespace std;
#define int long long
const int INF=1e16;
#define lson x<<1
#define rson x<<1|1
#define mid ((l+r)>>1)
int n,q,head[500100],sz[500100],dep[500100],cnt,res[500100];
struct Edge{
	int to,next,val;
}edge[1001000];
void ae(int u,int v,int w){
	edge[cnt].next=head[u],edge[cnt].to=v,edge[cnt].val=w,head[u]=cnt++; 
}
struct SegTree{
	int mn,tag;
}seg[2001000];
void ADD(int x,int y){
	seg[x].mn+=y,seg[x].tag+=y;
}
void pushdown(int x){
	ADD(lson,seg[x].tag);
	ADD(rson,seg[x].tag);
	seg[x].tag=0;
}
void pushup(int x){
	seg[x].mn=min(seg[lson].mn,seg[rson].mn);
}
void build(int x,int l,int r){
	if(l==r){
		if(sz[l]==1)seg[x].mn=dep[l];
		else seg[x].mn=INF;
		return;
	}
	build(lson,l,mid),build(rson,mid+1,r),pushup(x);
}
void modify(int x,int l,int r,int L,int R,int val){
	if(l>R||r<L)return;
	if(L<=l&&r<=R){ADD(x,val);return;}
	pushdown(x),modify(lson,l,mid,L,R,val),modify(rson,mid+1,r,L,R,val),pushup(x);
}
int query(int x,int l,int r,int L,int R){
	if(l>R||r<L)return INF;
	if(L<=l&&r<=R)return seg[x].mn;
	pushdown(x);
	return min(query(lson,l,mid,L,R),query(rson,mid+1,r,L,R));
}
struct Query{
	int r,s,id;
	Query(int x=0,int y=0,int z=0){r=x,s=y,id=z;}
};
vector<Query>v[500100];
void dfs1(int x){
	sz[x]=1;
	for(int i=head[x];i!=-1;i=edge[i].next)dep[edge[i].to]=dep[x]+edge[i].val,dfs1(edge[i].to),sz[x]+=sz[edge[i].to];
}
void dfs2(int x){
	for(int i=0;i<v[x].size();i++)res[v[x][i].id]=query(1,1,n,v[x][i].r,v[x][i].s);
	for(int i=head[x];i!=-1;i=edge[i].next){
		modify(1,1,n,edge[i].to,edge[i].to+sz[edge[i].to]-1,-edge[i].val);
		if(edge[i].to>1)modify(1,1,n,1,edge[i].to-1,edge[i].val);
		if(edge[i].to+sz[edge[i].to]-1<n)modify(1,1,n,edge[i].to+sz[edge[i].to],n,edge[i].val);
		dfs2(edge[i].to);
		modify(1,1,n,edge[i].to,edge[i].to+sz[edge[i].to]-1,edge[i].val);
		if(edge[i].to>1)modify(1,1,n,1,edge[i].to-1,-edge[i].val);
		if(edge[i].to+sz[edge[i].to]-1<n)modify(1,1,n,edge[i].to+sz[edge[i].to],n,-edge[i].val);
	}
}
signed main(){
	scanf("%lld%lld",&n,&q),memset(head,-1,sizeof(head));
	for(int i=2,x,y;i<=n;i++)scanf("%lld%lld",&x,&y),ae(x,i,y);
	dfs1(1),build(1,1,n);
//	for(int i=1;i<=n;i++)printf("%lld %lld\n",dep[i],sz[i]);
	for(int i=1,x,y,z;i<=q;i++)scanf("%lld%lld%lld",&x,&y,&z),v[x].push_back(Query(y,z,i));
	dfs2(1);
	for(int i=1;i<=q;i++)printf("%lld\n",res[i]);
	return 0;
}