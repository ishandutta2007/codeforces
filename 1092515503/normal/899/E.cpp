#include<bits/stdc++.h>
using namespace std;
#define lson (x<<1)
#define rson (x<<1|1)
#define mid ((l+r)>>1)
int n,t,lim,ans;
pair<int,int>p[200010];
struct sec{
	int l,r,len;
	sec(){} 
	sec(int x,int y,int z){
		l=x,r=y,len=z;
	}
	friend bool operator <(const sec &x,const sec &y){
		if(x.len!=y.len)return x.len<y.len;
		return x.l>y.l;
	}
	friend sec operator +(const sec &x,const sec &y){
		sec z;
		z.l=x.l,z.r=y.r,z.len=x.len+y.len;
		return z;
	}
	sec max(const sec &x,const sec &y){
		if(x.len!=y.len)return (x.len>y.len)?x:y;
		return (x.l<y.l)?x:y;
	}
};
struct node{
	int lval,rval,len;
	sec l,r,mx;
	bool del;
}seg[800020];
void clear(int x){
	seg[x].del=true;
	seg[x].lval=seg[x].rval=-1;
	seg[x].l.len=seg[x].r.len=seg[x].mx.len=0;
	seg[x].len=0;
}
void pushup(int x){
	if(seg[x].del)return;
	if(seg[lson].del&&seg[rson].del){clear(x);return;}
	if(seg[lson].del){seg[x]=seg[rson];return;}
	if(seg[rson].del){seg[x]=seg[lson];return;}
	seg[x].l=seg[lson].l,seg[x].r=seg[rson].r;
	seg[x].mx=max(seg[lson].mx,seg[rson].mx);
	seg[x].len=seg[lson].len+seg[rson].len;
	seg[x].lval=seg[lson].lval;
	seg[x].rval=seg[rson].rval;
	if(seg[lson].rval==seg[rson].lval){
		if(seg[lson].l.len==seg[lson].len)seg[x].l=max(seg[x].l,seg[lson].l+seg[rson].l);
		if(seg[rson].r.len==seg[rson].len)seg[x].r=max(seg[x].r,seg[lson].r+seg[rson].r);
		seg[x].mx=max(seg[x].mx,seg[lson].r+seg[rson].l);		
	}
}
void pushdown(int x){
	if(seg[x].del)clear(lson),clear(rson);
}
void build(int x,int l,int r){
	if(l==r){seg[x].l=seg[x].r=seg[x].mx=sec(l,r,p[l].second),seg[x].lval=seg[x].rval=p[l].first,seg[x].len=p[l].second;return;}
	build(lson,l,mid),build(rson,mid+1,r),pushup(x);
}
void modify(int x,int l,int r,int L,int R){
	if(r<L||l>R)return;
	if(L<=l&&r<=R){clear(x);return;}
	pushdown(x),modify(lson,l,mid,L,R),modify(rson,mid+1,r,L,R),pushup(x);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&t);
		if(t==p[lim].first)p[lim].second++;
		else p[++lim].first=t,p[lim].second=1;
	}
	build(1,1,lim);
	while(!seg[1].del)ans++,modify(1,1,lim,seg[1].mx.l,seg[1].mx.r);
	printf("%d\n",ans);
	return 0;
}