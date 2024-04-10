#include<bits/stdc++.h>
using namespace std;
int n,m,num;
char s[100100],t[10];
#define lson x<<1
#define rson x<<1|1
#define mid ((l+r)>>1) 
struct SegTree{int tagl,tagr,lmn,rmn,mn;}seg[400100];
void ADDL(int x,int val){seg[x].tagl+=val,seg[x].lmn+=val,seg[x].mn+=val;}
void ADDR(int x,int val){seg[x].tagr+=val,seg[x].rmn+=val,seg[x].mn+=val;}
void pushdown(int x){
	ADDL(lson,seg[x].tagl),ADDL(rson,seg[x].tagl),seg[x].tagl=0;
	ADDR(lson,seg[x].tagr),ADDR(rson,seg[x].tagr),seg[x].tagr=0;
}
void pushup(int x){
	seg[x].mn=min(min(seg[lson].mn,seg[rson].mn),seg[lson].lmn+seg[rson].rmn);
	seg[x].lmn=min(seg[lson].lmn,seg[rson].lmn);
	seg[x].rmn=min(seg[lson].rmn,seg[rson].rmn);
}
void build(int x,int l,int r){if(l==r)seg[x].mn=0x3f3f3f3f;else build(lson,l,mid),build(rson,mid+1,r);}
void addl(int x,int l,int r,int L,int R,int val){
	if(l>R||r<L)return;
	if(L<=l&&r<=R)return ADDL(x,val);
	pushdown(x),addl(lson,l,mid,L,R,val),addl(rson,mid+1,r,L,R,val),pushup(x);
}
void addr(int x,int l,int r,int L,int R,int val){
	if(l>R||r<L)return;
	if(L<=l&&r<=R)return ADDR(x,val);
	pushdown(x),addr(lson,l,mid,L,R,val),addr(rson,mid+1,r,L,R,val),pushup(x);
}
void work(int x,int tp){
	if(s[x]=='a')addl(1,0,n+1,x,n+1,tp);
	if(s[x]=='c')addr(1,0,n+1,0,x,tp);
	if(s[x]=='b')addl(1,0,n+1,x,n+1,-tp),addr(1,0,n+1,0,x,-tp),num+=tp;
}
void iterate(int x,int l,int r){
	printf("(%d<%d,%d>,%d)",x,l,r,seg[x].mn);
	if(l==r)printf("[%d,%d,%d]",l,seg[x].lmn,seg[x].rmn);else pushdown(x),iterate(lson,l,mid),iterate(rson,mid+1,r);
}
int main(){
	scanf("%d%d%s",&n,&m,s+1);
	build(1,0,n+1);
	for(int i=1;i<=n;i++)work(i,1);
//	iterate(1,0,n+1),puts("");printf("%d\n",seg[1].mn+num);
	for(int i=1,x;i<=m;i++)scanf("%d%s",&x,t),work(x,-1),s[x]=t[0],work(x,1),printf("%d\n",seg[1].mn+num);
	return 0;
}
/*
3 0
bbb
*/