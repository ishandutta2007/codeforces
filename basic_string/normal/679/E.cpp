#include<bits/stdc++.h>
using namespace std;
const int N=1e5+3;
using ll=long long;
const ll pw[]={1LL,42LL,1764LL,74088LL,3111696LL,130691232LL,5489031744LL,230539333248LL,9682651996416LL,406671383849472LL,17080198121677824LL,717368321110468608LL,1000000000000000000LL};
int a[N],u,v,w;
struct T{
	ll a,x,m;
}s[N*4];
ll get(ll x){return*lower_bound(begin(pw),end(pw),x)-x;}
inline void cov(T&k,ll x){k.a=0,k.x=x,k.m=get(x);}
inline void add(T&k,ll x){if(k.x)k.x+=x,k.m=get(k.x);else k.m-=x,k.a+=x;}
inline void mg(T&k,T&a,T&b){if(a.x&&a.x==b.x)k=a;else k.a=k.x=0,k.m=min(a.m,b.m);}
void bd(int k,int l,int r){
	if(l==r)return cov(s[k],a[l]);
	int m=l+r>>1;
	bd(k*2,l,m),bd(k*2+1,m+1,r),mg(s[k],s[k*2],s[k*2+1]);
}
inline void dn(T&k,T&a,T&b){if(k.x)cov(a,k.x),cov(b,k.x);else if(k.a)add(a,k.a),add(b,k.a),k.a=0;}
void qry(int k,int l,int r){
	if(l==r){cout<<s[k].x<<'\n';return;}
	int m=l+r>>1;
	dn(s[k],s[k*2],s[k*2+1]),u>m?qry(k*2+1,m+1,r):qry(k*2,l,m);
}
void uc(int k,int l,int r){
	if(u<=l&&r<=v)return cov(s[k],w);
	int m=l+r>>1;
	if(dn(s[k],s[k*2],s[k*2+1]),u<=m)uc(k*2,l,m);
	if(m<v)uc(k*2+1,m+1,r);
	mg(s[k],s[k*2],s[k*2+1]);
}
ll ua(int k,int l,int r){
	if(u<=l&&r<=v&&(s[k].m>=w||s[k].x))return add(s[k],w),s[k].m;
	int m=l+r>>1;
	ll w=1e18;
	if(dn(s[k],s[k*2],s[k*2+1]),u<=m)w=ua(k*2,l,m);
	if(m<v)w=min(w,ua(k*2+1,m+1,r));
	return mg(s[k],s[k*2],s[k*2+1]),w;
}
int main(){ios::sync_with_stdio(0),cin.tie(0);
	int n,q,i;
	for(cin>>n>>q,i=1;i<=n;++i)cin>>a[i];
	for(bd(1,1,n);q--;)if(cin>>i>>u,i==1)qry(1,1,n);else if(cin>>v>>w,i==2)uc(1,1,n);else while(!ua(1,1,n));
	return 0;
}