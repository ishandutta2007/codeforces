#include<bits/stdc++.h>
using namespace std;
const int V=1000000;
typedef long long ll;
int n,m,q,a[200100],b[200100];
ll C;
multiset<int>A,B;
void insertA(int x){A.insert(x),C+=x;}
void eraseA(int x){A.erase(A.find(x)),C-=x;}
#define lson x<<1
#define rson x<<1|1
#define mid ((l+r)>>1)
struct SegTree{int num;ll sum;}seg[V<<2];
void modify(int x,int l,int r,int P,int tp){
	seg[x].num+=tp,seg[x].sum+=tp*P;
	if(l!=r)P<=mid?modify(lson,l,mid,P,tp):modify(rson,mid+1,r,P,tp);
}
ll query(int x,int l,int r,int P){
	if(l>P)return 0;
	if(r<=P)return 1ll*P*seg[x].num-seg[x].sum;
	return query(lson,l,mid,P)+query(rson,mid+1,r,P);
}
int Kth(int x,int l,int r,int K){
	if(l==r)return l;
	return seg[lson].num>=K?Kth(lson,l,mid,K):Kth(rson,mid+1,r,K-seg[lson].num);
}
void insertB(int x){B.insert(x),C-=x,modify(1,0,V,x,1);}
void eraseB(int x){B.erase(B.find(x)),C+=x,modify(1,0,V,x,-1);}
ll queryA(int K,int x){
//	printf("%d %d\n",K,x);
	return 1ll*(n-m)*K+C+1ll*(m-n)*x+1ll*(n-1)*max(0,x-K-min(*A.begin(),*B.begin()))-query(1,0,V,x-K);
}
ll queryB(int K,int x){
	return 1ll*(n-m)*K+C+1ll*(m-n)*x+1ll*n*max(0,x-K-min(*A.begin(),*B.begin()))-query(1,0,V,x-K);
}
ll solve(int K){
	ll ret=max(queryA(K,*A.begin()),queryB(K,*B.begin()));
	auto it=A.lower_bound(Kth(1,0,V,m-1)+K);
	if(it!=A.end())ret=max(ret,queryA(K,*it));
	if(it!=A.begin())ret=max(ret,queryA(K,*--it));
	ret=max(ret,queryB(K,*B.rbegin()));
	return ret;
}
int main(){
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),insertA(a[i]);
	for(int i=1;i<=m;i++)scanf("%d",&b[i]),insertB(b[i]);
	for(int i=1,tp,x;i<=q;i++){
		scanf("%d%d",&tp,&x);
		if(tp==1)eraseA(a[x]),scanf("%d",&a[x]),insertA(a[x]);
		if(tp==2)eraseB(b[x]),scanf("%d",&b[x]),insertB(b[x]);
		if(tp==3)printf("%lld\n",solve(x));
	}
	return 0;
}