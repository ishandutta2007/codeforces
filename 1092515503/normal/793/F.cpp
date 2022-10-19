#include<bits/stdc++.h>
using namespace std;
int n,m,q,res[100100],lp[100100];
vector<pair<int,int> >v[100100];
#define lson x<<1
#define rson x<<1|1
#define mid ((l+r)>>1)
struct SegTree{int mx,smx,tag;}seg[400100];
void MOD(int x,int y){seg[x].mx=seg[x].tag=y;}
void pushdown(int x){
	if(seg[x].tag==-1)return;
	if(seg[lson].mx>seg[rson].mx)MOD(lson,seg[x].tag);
	else if(seg[rson].mx>seg[lson].mx)MOD(rson,seg[x].tag);
	else MOD(lson,seg[x].tag),MOD(rson,seg[x].tag);
	seg[x].tag=-1;
}
void pushup(int x){
	seg[x].mx=max(seg[lson].mx,seg[rson].mx),seg[x].smx=-1;
	seg[x].smx=max(seg[x].smx,seg[x].mx==seg[lson].mx?seg[lson].smx:seg[lson].mx);
	seg[x].smx=max(seg[x].smx,seg[x].mx==seg[rson].mx?seg[rson].smx:seg[rson].mx);
}
void build(int x,int l,int r){
	seg[x].tag=-1;
	if(l==r)seg[x].mx=l,seg[x].smx=-1;
	else build(lson,l,mid),build(rson,mid+1,r),pushup(x);
}
void modify(int x,int l,int r,int L,int R){
	if(l>L||seg[x].mx<L)return;
	if(r<=L&&seg[x].smx<L)return MOD(x,R);
	pushdown(x),modify(lson,l,mid,L,R),modify(rson,mid+1,r,L,R),pushup(x);
}
int query(int x,int l,int r,int P){
	if(l==r)return seg[x].mx;
	pushdown(x);
	return P<=mid?query(lson,l,mid,P):query(rson,mid+1,r,P); 
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1,x,y;i<=m;i++)scanf("%d%d",&x,&y),lp[y]=x;
	scanf("%d",&q);for(int i=1,x,y;i<=q;i++)scanf("%d%d",&x,&y),v[y].emplace_back(x,i);
	build(1,1,n);
	for(int i=1;i<=n;i++){
		if(lp[i])modify(1,1,n,lp[i],i);
		for(auto x:v[i])res[x.second]=query(1,1,n,x.first);
	}
	for(int i=1;i<=q;i++)printf("%d\n",res[i]);
	return 0;
}