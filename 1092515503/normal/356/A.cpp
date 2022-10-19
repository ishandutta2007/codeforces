#include<bits/stdc++.h>
using namespace std;
#define lson (x<<1)
#define rson (x<<1|1)
#define mid ((l+r)>>1)
struct node{
	int mn,mx,tag;
}seg[1200011];
void pushup(int x){
	seg[x].mn=min(seg[lson].mn,seg[rson].mn),seg[x].mx=max(seg[lson].mx,seg[rson].mx);
}
void pushdown(int x){
	if(!seg[x].tag)return;
	seg[lson].mx=seg[lson].tag=seg[lson].mn=seg[rson].mx=seg[rson].tag=seg[rson].mn=seg[x].tag;
	seg[x].tag=0;
}
void section_modify(int x,int l,int r,int L,int R,int val){
	if(l>R||r<L)return;
	if(seg[x].mn)return;
	if(L<=l&&r<=R&&!seg[x].mx){seg[x].mn=seg[x].mx=seg[x].tag=val;return;}
	section_modify(lson,l,mid,L,R,val),section_modify(rson,mid+1,r,L,R,val),pushup(x);
}
void point_modify(int x,int l,int r,int P){
	if(l>P||r<P)return;
	if(l==r){seg[x].mn=seg[x].tag=seg[x].mx=0;return;}
	pushdown(x),point_modify(lson,l,mid,P),point_modify(rson,mid+1,r,P),pushup(x);
}
int query(int x,int l,int r,int P){
	if(l>P||r<P)return 0;
	if(l==r)return seg[x].tag;
	pushdown(x);
	return query(lson,l,mid,P)+query(rson,mid+1,r,P);
}
int n,m,t1,t2,t3;
int main(){
	scanf("%d%d",&n,&m);
	while(m--)scanf("%d%d%d",&t1,&t2,&t3),section_modify(1,1,n,t1,t2,t3),point_modify(1,1,n,t3);
	for(int i=1;i<=n;i++)printf("%d ",query(1,1,n,i));
	return 0;
}