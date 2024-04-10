#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,lim,sz;
ll a[200100],b[200100],sum;
vector<ll>v;
struct ST{
	#define lson x<<1
	#define rson x<<1|1
	#define mid ((l+r)>>1)
	struct SegTree{int sz;ll sum,tag;}seg[1600100];
	void ADD(int x,ll y){seg[x].tag+=y,seg[x].sum+=seg[x].sz*y;}
	void pushdown(int x){ADD(lson,seg[x].tag),ADD(rson,seg[x].tag),seg[x].tag=0;}
	void pushup(int x){seg[x].sum=seg[lson].sum+seg[rson].sum,seg[x].sz=seg[lson].sz+seg[rson].sz;};
	void turnon(int x,int l,int r,int P){if(l>P||r<P)return;if(l==r)seg[x].sum=seg[x].tag,seg[x].sz=1;else pushdown(x),turnon(lson,l,mid,P),turnon(rson,mid+1,r,P),pushup(x);}
	void turnoff(int x,int l,int r,int P){if(l>P||r<P)return;if(l==r)seg[x].sum=0,seg[x].sz=0;else pushdown(x),turnoff(lson,l,mid,P),turnoff(rson,mid+1,r,P),pushup(x);}
	void modify(int x,int l,int r,int L,int R,ll val){if(l>R||r<L)return;if(L<=l&&r<=R)ADD(x,val);else pushdown(x),modify(lson,l,mid,L,R,val),modify(rson,mid+1,r,L,R,val),pushup(x);}
	ll kth(int x,int l,int r,int k){if(l==r)return seg[x].sum;pushdown(x);if(seg[lson].sz>=k)return kth(lson,l,mid,k);else return kth(rson,mid+1,r,k-seg[lson].sz);}
	ll query(int x,int l,int r,int k){if(l==r)return seg[x].sum;pushdown(x);if(seg[lson].sz>=k)return query(lson,l,mid,k);return seg[lson].sum+query(rson,mid+1,r,k-seg[lson].sz);}
	void iterate(int x,int l,int r){printf("%d[%d,%d]:%d,%d\n",x,l,r,seg[x].sum,seg[x].sz);if(l!=r)pushdown(x),iterate(lson,l,mid),iterate(rson,mid+1,r);}
}s1,s2;//s1 is minimum,s2 is maximum
void turnon(int P){s1.turnon(1,1,lim,P),s1.modify(1,1,lim,P,lim,v[P-1]);s2.turnon(1,1,lim,lim-P+1),s2.modify(1,1,lim,lim-P+1,lim,v[P-1]);sz++,sum+=v[P-1];}
void turnoff(int P){s1.turnoff(1,1,lim,P),s1.modify(1,1,lim,P,lim,-v[P-1]);s2.turnoff(1,1,lim,lim-P+1),s2.modify(1,1,lim,lim-P+1,lim,-v[P-1]);sz--,sum-=v[P-1];}
ll query(){
	if(sz<=1)return 0;
	int l=1,r=sz>>1;
	while(l<r){
		int md=(l+r+1)>>1;
		if(s1.kth(1,1,lim,md)>=s2.kth(1,1,lim,md-1))l=md;
		else r=md-1;
	}
	ll ret=s1.query(1,1,lim,l);if(l>1)ret-=s2.query(1,1,lim,l-1);
	ret<<=1;
	if(sz&1)ret+=max(0ll,s1.kth(1,1,lim,(sz+1)>>1)-s2.kth(1,1,lim,sz>>1));
//	printf("(%d,%d)\n",sum,sz);
	return sum-ret;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]),v.push_back(a[i]);
	for(int i=1,x;i<=m;i++)scanf("%d%lld",&x,&b[i]),v.push_back(b[i]),b[i]=(x==1?b[i]:-b[i]);
	sort(v.begin(),v.end()),v.resize(lim=unique(v.begin(),v.end())-v.begin());
	for(int i=1;i<=n;i++)a[i]=lower_bound(v.begin(),v.end(),a[i])-v.begin()+1;
	for(int i=1;i<=m;i++){
		if(b[i]>0)b[i]=lower_bound(v.begin(),v.end(),b[i])-v.begin()+1;
		else b[i]=-(lower_bound(v.begin(),v.end(),-b[i])-v.begin()+1);
	}
	for(int i=1;i<=n;i++)turnon(a[i]);
	printf("%lld\n",query());
	for(int i=1;i<=m;i++){
		if(b[i]>0)turnon(b[i]);
		else turnoff(-b[i]);
//		s1.iterate(1,1,lim),puts("");
//		s2.iterate(1,1,lim),puts("");
		printf("%lld\n",query());
	}
	return 0;
}