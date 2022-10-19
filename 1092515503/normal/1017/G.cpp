#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll fni=0xc0c0c0c0c0c0c0c0;
const int N=100100;
#define lson x<<1
#define rson x<<1|1
#define mid ((l+r)>>1)
#define LSON lson,l,mid
#define RSON rson,mid+1,r
#define X x,l,r
struct SegTree{
	ll sum,smx;
	SegTree(){sum=0,smx=fni;}
	SegTree(ll a,ll b){sum=a,smx=b;}
	friend SegTree operator+(const SegTree&u,const SegTree&v){return SegTree(u.sum+v.sum,max(v.smx,u.smx+v.sum));}
}seg[N<<2];
bool tag[N<<2];
void RESET(int x,int l,int r){tag[x]=true,seg[x]=SegTree(-(r-l+1),-1);}
void pushdown(int x,int l,int r){if(tag[x])RESET(LSON),RESET(RSON),tag[x]=false;}
void build(int x,int l,int r){if(l==r)seg[x]=SegTree(-1,-1);else build(LSON),build(RSON),seg[x]=seg[lson]+seg[rson];}
SegTree query(int x,int l,int r,int L,int R){
	if(l>R||r<L)return SegTree();if(L<=l&&r<=R)return seg[x];
	pushdown(X);return query(LSON,L,R)+query(RSON,L,R);
}
void modify(int x,int l,int r,int P,ll val){
	if(l==r)seg[x].sum+=val,seg[x].smx+=val;
	else pushdown(X),P<=mid?modify(LSON,P,val):modify(RSON,P,val),seg[x]=seg[lson]+seg[rson];
}
void reset(int x,int l,int r,int L,int R){
	if(l>R||r<L)return;if(L<=l&&r<=R)return RESET(X);
	pushdown(X),reset(LSON,L,R),reset(RSON,L,R),seg[x]=seg[lson]+seg[rson];
}
int n,m,fa[N],dfn[N],sz[N],tot,son[N],rev[N],dep[N],top[N];
vector<int>v[N];
void dfs(int x){
	dfn[x]=++tot,rev[tot]=x;
	if(!top[x])top[x]=x;
	if(son[x])top[son[x]]=top[x],dfs(son[x]);
	for(auto y:v[x])if(y!=son[x])dfs(y);
}
ll query(int x){
	SegTree res;
	while(x)res=query(1,1,n,dfn[top[x]],dfn[x])+res,x=fa[top[x]];
	return res.smx;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=2;i<=n;i++)scanf("%d",&fa[i]),dep[i]=dep[fa[i]]+1,v[fa[i]].push_back(i);
	for(int i=n;i>=2;i--){
		sz[fa[i]]+=++sz[i];
		if(sz[son[fa[i]]]<sz[i])son[fa[i]]=i;
	}++sz[1],dfs(1);
	build(1,1,n);
	for(int i=1,x,y;i<=m;i++){
		scanf("%d%d",&x,&y);
		if(x==1)modify(1,1,n,dfn[y],1);
		if(x==2)reset(1,1,n,dfn[y],dfn[y]+sz[y]-1),modify(1,1,n,dfn[y],-query(y)-1);
		if(x==3)puts(query(y)>=0?"black":"white");
	}
	return 0;
}