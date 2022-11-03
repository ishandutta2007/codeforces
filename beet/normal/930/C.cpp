#include<bits/stdc++.h>
using namespace std;
using Int = long long;

template <typename T,typename E>
struct SegmentTree{
  using F = function<T(T,T)>;
  using G = function<T(T,E)>;
  Int n;
  F f;
  G g;
  T ti;
  vector<T> dat;
  SegmentTree(){};
  SegmentTree(Int n_,F f,G g,T ti):
    f(f),g(g),ti(ti){
    init(n_);
  }
  void init(Int n_){
    n=1;
    while(n<n_) n*=2;
    dat.clear();
    dat.resize(2*n-1,ti);
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
  inline T query(Int a,Int b){
    T vl=ti,vr=ti;
    for(Int l=a+n,r=b+n;l<r;l>>=1,r>>=1) {
      if(l&1) vl=f(vl,dat[(l++)-1]);
      if(r&1) vr=f(dat[(--r)-1],vr);
    }
    return f(vl,vr);
  }

  Int find(Int a,Int b,function<bool(T)> &check,Int k,Int l,Int r){
    if(!check(dat[k])||r<=a||b<=l) return -1;
    if(k>=n-1) return k-(n-1);
    Int m=(l+r)>>1;
    Int vl=find(a,b,check,k*2+1,l,m);
    if(~vl) return vl;
    return find(a,b,check,k*2+2,m,r);
  }
  
  Int find(Int a,Int b,function<bool(T)> &check){
    return find(a,b,check,0,0,n);
  }
  
};


template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

//INSERT ABOVE HERE
signed main(){
  Int n,m;
  cin>>n>>m;
  vector<Int> s(m+1);
  for(Int i=0;i<n;i++){
    Int l,r;
    cin>>l>>r;
    s[--l]++;
    s[r]--;
  }
  partial_sum(s.begin(),s.end(),s.begin());
  vector<Int> dp(m),dp2(m);
  
  SegmentTree<Int, Int> seg(n+1,
			    [](Int a,Int b){return max(a,b);},
			    [](Int a,Int b){++a;return b;}
			    ,0);
  auto seg2=seg;
  
  for(Int i=0;i<m;i++){
    dp[i]=seg.query(0,s[i]+1)+1;
    seg.update(s[i],dp[i]);
  }
  for(Int i=m-1;i>=0;i--){
    dp2[i]=seg2.query(0,s[i]+1)+1;
    seg2.update(s[i],dp2[i]);
  }
  //for(Int i=0;i<m;i++) cout<<i<<" "<<s[i]<<":"<<dp[i]<<" "<<dp2[i]<<endl;
  Int ans=0;
  for(Int i=0;i<m;i++) chmax(ans,dp[i]+dp2[i]-1);
  cout<<ans<<endl;
  return 0;
}