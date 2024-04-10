#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,q,a[200100],b[200100];
ll mn[200100];
#define lson x<<1
#define rson x<<1|1
#define mid ((l+r)>>1)
struct SegTree{ll mn,tag;}seg[800100];
void ADD(int x,ll y){seg[x].mn+=y,seg[x].tag+=y;}
void pushup(int x){seg[x].mn=min(seg[lson].mn,seg[rson].mn);}
void pushdown(int x){ADD(lson,seg[x].tag),ADD(rson,seg[x].tag),seg[x].tag=0;}
void build(int x,int l,int r){
	if(l==r){seg[x].mn=b[l];return;}
	build(lson,l,mid),build(rson,mid+1,r),pushup(x); 
}
void modify(int x,int l,int r,int P,int val){
	if(l>=P)return;
	if(r<P){ADD(x,val);return;}
	pushdown(x),modify(lson,l,mid,P,val),modify(rson,mid+1,r,P,val),pushup(x);
}
vector<pair<int,int> >v[200100];
multiset<ll>s;
int main(){
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<n;i++)scanf("%d%d",&a[i],&b[i]);
	for(int i=1,x,y,z;i<=m;i++)scanf("%d%d%d",&x,&y,&z),v[x].push_back(make_pair(y,z));
	build(1,0,n-1);
	for(int i=1;i<=n;i++){
		for(auto j:v[i])modify(1,0,n-1,j.first,j.second);
		mn[i]=seg[1].mn,s.insert(mn[i]+a[i]);
	}
	printf("%lld\n",*s.begin());
	for(int i=1,x,y;i<=q;i++)scanf("%d%d",&x,&y),s.erase(s.find(mn[x]+a[x])),a[x]=y,s.insert(mn[x]+a[x]),printf("%lld\n",*s.begin());
	return 0;
}
/*
5 3 0
1231 2342
2342 5435
5654 2322
6456 5343
1 3 8688
3 2 7576
5 5 8768
*/