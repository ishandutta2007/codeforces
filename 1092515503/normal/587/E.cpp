#include<bits/stdc++.h>
using namespace std;
int n,m,a[200100];
struct lb{//linear basis?
	int d[32],sz;
	void print(){
		for(int i=0;i<=29;i++)if(d[i])printf("%d:%lld\n",i,d[i]);
	}
	lb(){memset(d,0,sizeof(d)),sz=0;}
	void operator +=(int x){
		for(int i=29;i>=0;i--){
			if(!(x&(1ll<<i)))continue;
			if(d[i])x^=d[i];
			else{d[i]=x,sz++;break;}
		}
	}
	int& operator [](int x){
		return d[x];
	}
	void operator +=(lb &x){
		for(int i=29;i>=0;i--)if(x[i])*this+=x[i];
	}
	friend lb operator +(lb x,lb y){
		lb z=x;
		for(int i=29;i>=0;i--)if(y[i])z+=y[i];
		return z;
	}
	int num(){for(int i=29;i>=0;i--)if(d[i])return d[i];return 0;}
};
#define lson x<<1
#define rson x<<1|1
#define mid ((l+r)>>1)
namespace AES{//adjecent elements' segtree
	lb seg[800100];
	void build(int x,int l,int r){
		if(r-l==1){seg[x]+=a[l]^a[r];return;}
		build(lson,l,mid),build(rson,mid,r),seg[x]=seg[lson]+seg[rson];
	}
	void modify(int x,int l,int r,int P,int val){
		if(l>P||r<=P)return;
		if(r-l==1){val^=seg[x].num();seg[x]=lb();seg[x]+=val;return;}
		modify(lson,l,mid,P,val),modify(rson,mid,r,P,val),seg[x]=seg[lson]+seg[rson];
	}
	lb query(int x,int l,int r,int L,int R){
		if(L<=l&&r<=R)return seg[x];
		if(mid>=R)return query(lson,l,mid,L,R);
		if(mid<=L)return query(rson,mid,r,L,R);
		return query(lson,l,mid,L,R)+query(rson,mid,r,L,R);
	}
}
namespace OSS{//original sequence's segtree
	int seg[800100];
	void pushdown(int x){seg[lson]^=seg[x],seg[rson]^=seg[x],seg[x]=0;}
	void build(int x,int l,int r){
		if(l==r){seg[x]=a[l];return;}
		build(lson,l,mid),build(rson,mid+1,r);
	}
	void modify(int x,int l,int r,int L,int R,int val){
		if(l>R||r<L)return;
		if(L<=l&&r<=R){seg[x]^=val;return;}
		pushdown(x),modify(lson,l,mid,L,R,val),modify(rson,mid+1,r,L,R,val);
	}
	int query(int x,int l,int r,int P){
		if(l==r)return seg[x];
		pushdown(x);
		return P<=mid?query(lson,l,mid,P):query(rson,mid+1,r,P);
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	if(n!=1)AES::build(1,1,n);OSS::build(1,1,n);
	for(int i=1,a,b,c,d;i<=m;i++){
		scanf("%d",&a);
		if(a==1){
			scanf("%d%d%d",&b,&c,&d);
			OSS::modify(1,1,n,b,c,d);
			AES::modify(1,1,n,b-1,d);
			AES::modify(1,1,n,c,d);
		}else{
			scanf("%d%d",&b,&c);
			lb res;
			if(b!=c)res=AES::query(1,1,n,b,c);
			res+=OSS::query(1,1,n,c);
			printf("%d\n",1<<res.sz);
		}
	}
	return 0;
}