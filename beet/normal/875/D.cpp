#include<bits/stdc++.h>
using namespace std;
using Int = long long;

template <typename T,typename E>
struct SegmentTree{
  typedef function<T(T,T)> F;
  typedef function<T(T,E)> G;
  Int n;
  F f;
  G g;
  T d1;
  E d0;
  vector<T> dat;
  SegmentTree(Int n_,F f,G g,T d1,
	      vector<T> v=vector<T>()):
    f(f),g(g),d1(d1){
    init(n_);
    if(n_==(Int)v.size()) build(n_,v);
  }
  void init(Int n_){
    n=1;
    while(n<n_) n*=2;
    dat.clear();
    dat.resize(2*n-1,d1);
  }
  void build(Int n_, vector<T> v){
    for(Int i=0;i<n_;i++) dat[i+n-1]=v[i];
    for(Int i=n-2;i>=0;i--)
      dat[i]=f(dat[i*2+1],dat[i*2+2]);
  }
  void update(Int k,E a){
    k+=n-1;
    dat[k]=g(dat[k],a);
    while(k>0){
      k=(k-1)/2;
      dat[k]=f(dat[k*2+1],dat[k*2+2]);
    }
  }
  T query(Int a,Int b,Int k,Int l,Int r){
    if(r<=a||b<=l) return d1;
    if(a<=l&&r<=b) return dat[k];
    T vl=query(a,b,k*2+1,l,(l+r)/2);
    T vr=query(a,b,k*2+2,(l+r)/2,r);
    return f(vl,vr);
  }
  T query(Int a,Int b){
    return query(a,b,0,0,n);
  }
};


signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  Int n;
  cin>>n;
  //scanf("%lld",&n);
  vector<Int> x(n);
  //for(Int i=0;i<n;i++) scanf("%lld",&x[i]);
  for(Int i=0;i<n;i++) cin>>x[i];
  typedef pair<Int,Int> P;
  vector<P> vp(n);
  vector<Int> s[32];
  for(Int j=0;j<32;j++){
    s[j].push_back(-1);
  }
  for(Int i=0;i<n;i++){
    vp[i]=P(x[i],i);
    for(Int j=0;j<32;j++){
      if((x[i]>>j)&1) s[j].push_back(i);
    }
  }
  
  for(Int j=0;j<32;j++){
    s[j].push_back(n);
  }
  SegmentTree<P,P> ushi(n,
			[](P a,P b){return a.first>b.first?a:b;},
			[](P a,P b){return a;},
			P(-1,-1),
			vp);
  Int ans=0;
  queue<P> q;
  q.push(P(0,n));
  while(!q.empty()){
    P pp=q.front();q.pop();
    Int l=pp.first,r=pp.second;
    if(l==r) continue;
    Int p=ushi.query(l,r).second;
    Int a=l-1,b=r;
    for(Int j=0;j<32;j++){
      if((x[p]>>j)&1) continue;
      {
	Int k=*--lower_bound(s[j].begin(),s[j].end(),p);
        a=max(a,k);
      }
      {
	Int k=*upper_bound(s[j].begin(),s[j].end(),p);
        b=min(b,k);
      }
    }
    Int A=p-(a+1);
    Int B=b-(p+1);
    Int C=(p-l)-A;
    Int D=(r-(p+1))-B;
    //cout<<l<<" "<<p<<" "<<r<<endl;
    //cout<<A<<" "<<B<<" "<<C<<" "<<D<<endl;
    ans+=(B+1)*C+(A+1)*D+C*D;
    //cout<<(B+1)*C+(A+1)*D+C*D<<endl;
    q.push(P(l,p));
    q.push(P(p+1,r));
  }

  cout<<ans<<endl;
  //printf("%lld\n",ans);
  return 0;
}