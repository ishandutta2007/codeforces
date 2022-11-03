#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}


struct FastIO{
  FastIO(){
    cin.tie(0);
    ios::sync_with_stdio(0);
  }
}fastio_beet;


template <typename T>
struct SegmentTree{
  using F = function<T(T,T)>;
  Int n;
  F f;
  T ti;
  vector<T> dat;
  SegmentTree(){};
  SegmentTree(F f,T ti):f(f),ti(ti){}
  void init(Int n_){    
    n=1;
    while(n<n_) n<<=1;
    dat.assign(n<<1,ti);
  }
  void build(const vector<T> &v){
    Int n_=v.size();
    init(n_);
    for(Int i=0;i<n_;i++) dat[n+i]=v[i];
    for(Int i=n-1;i;i--)
      dat[i]=f(dat[(i<<1)|0],dat[(i<<1)|1]);
  }
  void set_val(Int k,T x){
    dat[k+=n]=x;
    while(k>>=1)
      dat[k]=f(dat[(k<<1)|0],dat[(k<<1)|1]);    
  }
  T query(Int a,Int b){
    T vl=ti,vr=ti;
    for(Int l=a+n,r=b+n;l<r;l>>=1,r>>=1) {
      if(l&1) vl=f(vl,dat[l++]);
      if(r&1) vr=f(dat[--r],vr);
    }
    return f(vl,vr);
  }
};

//INSERT ABOVE HERE
signed main(){
  Int n,m;
  cin>>n>>m;
  vector<Int> a(n);
  for(Int i=0;i<n;i++) cin>>a[i];

  struct T{
    Int mi,ma;
    T():mi(-1),ma(-1){}
    T(Int mi,Int ma):mi(mi),ma(ma){}
  };
  auto f=[&](T x,T y){
           if(x.mi<0) return y;
           if(y.mi<0) return x;
           return T(a[x.mi]<a[y.mi]?x.mi:y.mi,a[x.ma]>a[y.ma]?x.ma:y.ma);
         };
  T ti;
  SegmentTree<T> seg(f,ti);
  vector<T> vt(n);
  for(Int i=0;i<n;i++) vt[i]=T(i,i);
  seg.build(vt);

  for(Int i=0;i<m;i++){
    Int l,r,x;
    cin>>l>>r>>x;
    l--;
    T v=seg.query(l,r);
    if(a[v.mi]==a[v.ma]&&a[v.mi]==x) cout<<-1<<"\n";
    else cout<<(a[v.mi]!=x?v.mi:v.ma)+1<<"\n";
  }
  cout<<flush;
  return 0;
}