#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
const int lim=11;
ll pov[20]={1,42,1764,74088,3111696,130691232,5489031744ll,230539333248ll,9682651996416ll,406671383849472ll,17080198121677824ll};
#define lson x<<1
#define rson x<<1|1
#define mid ((l+r)>>1)
struct SegTree{
	ll tagmodi,tagadd,mn;
}seg[400100];
void ADD(int x,ll y){if(seg[x].tagmodi)seg[x].tagmodi+=y;else seg[x].tagadd+=y;seg[x].mn-=y;}
void REFRESH(int x){seg[x].mn=*lower_bound(pov,pov+lim,seg[x].tagmodi)-seg[x].tagmodi;}
void MODI(int x,ll y){seg[x].tagmodi=y,seg[x].tagadd=0,REFRESH(x);}
void pushdown(int x){
	if(seg[x].tagmodi){
		seg[lson].tagmodi=seg[rson].tagmodi=seg[x].tagmodi;
		seg[lson].mn=seg[rson].mn=seg[x].mn;
		seg[lson].tagadd=seg[rson].tagadd=0;
		seg[x].tagmodi=0;
	}
	if(seg[x].tagadd)ADD(lson,seg[x].tagadd),ADD(rson,seg[x].tagadd),seg[x].tagadd=0;
}
void pushup(int x){seg[x].mn=min(seg[lson].mn,seg[rson].mn);}
void build(int x,int l,int r){
	if(l==r){scanf("%lld",&seg[x].tagmodi),REFRESH(x);return;}
	build(lson,l,mid),build(rson,mid+1,r),pushup(x);
}
void setval(int x,int l,int r,int L,int R,int val){
	if(l>R||r<L)return;
	if(L<=l&&r<=R){MODI(x,val);return;}
	pushdown(x),setval(lson,l,mid,L,R,val),setval(rson,mid+1,r,L,R,val),pushup(x);
}
bool find(int x,int l,int r){
	if(seg[x].mn>=0)return seg[x].mn==0;
	if(seg[x].tagmodi){REFRESH(x);return seg[x].mn==0;}
	pushdown(x);
	bool ret=find(lson,l,mid)|find(rson,mid+1,r);
	pushup(x);
	return ret;
}
bool add(int x,int l,int r,int L,int R,int val){
	if(l>R||r<L)return false;
	if(L<=l&&r<=R){
		ADD(x,val);
		return find(x,l,r);
	}
	pushdown(x);
	bool ret=add(lson,l,mid,L,R,val)|add(rson,mid+1,r,L,R,val);
	pushup(x);
	return ret;
}
ll query(int x,int l,int r,int P){
	if(l==r)return seg[x].tagmodi;
	pushdown(x);
	ll ret=(P<=mid?query(lson,l,mid,P):query(rson,mid+1,r,P));
	pushup(x);
	return ret;
}
//void iterate(int x,int l,int r){if(l==r)printf("(%lld:%lld)",seg[x].tagmodi,seg[x].mn);else pushdown(x),iterate(lson,l,mid),iterate(rson,mid+1,r),pushup(x);}
int main(){
	scanf("%d%d",&n,&m);
	build(1,1,n);
	for(int i=1,a,b,c,d;i<=m;i++){
		scanf("%d%d",&a,&b);
		if(a==1)printf("%lld\n",query(1,1,n,b));
		else{
			scanf("%d%d",&c,&d);
			if(a==2)setval(1,1,n,b,c,d);
			else while(add(1,1,n,b,c,d));
		}
//		iterate(1,1,n),puts("");
	}
	return 0;
}