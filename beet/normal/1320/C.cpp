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

template<typename T, typename ...Ts>
vector<T> fusion(vector<T> bs,Ts... ts){
  auto append=[&](auto vs){for(auto v:vs) bs.emplace_back(v);};
  initializer_list<Int>{(void(append(ts)),0)...};
  return bs;
}


template<typename V>
V compress(V v){
  sort(v.begin(),v.end());
  v.erase(unique(v.begin(),v.end()),v.end());
  return v;
}
template<typename T>
map<T, Int> dict(const vector<T> &v){
  map<T, Int> res;
  for(Int i=0;i<(Int)v.size();i++)
    res[v[i]]=i;
  return res;
}
map<char, Int> dict(const string &v){
  return dict(vector<char>(v.begin(),v.end()));
}

template <typename T,typename E,typename F,typename G,typename H>
struct SegmentTree{
  //using F = function<T(T,T)>;
  //using G = function<T(T,E)>;
  //using H = function<E(E,E)>;
  Int n,height;
  F f;
  G g;
  H h;
  T ti;
  E ei;
  vector<T> dat;
  vector<E> laz;
  SegmentTree(F f,G g,H h,T ti,E ei):
    f(f),g(g),h(h),ti(ti),ei(ei){}

  void init(Int n_){
    n=1;height=0;
    while(n<n_) n<<=1,height++;
    dat.assign(2*n,ti);
    laz.assign(2*n,ei);
  }

  void build(const vector<T> &v){
    Int n_=v.size();
    init(n_);
    for(Int i=0;i<n_;i++) dat[n+i]=v[i];
    for(Int i=n-1;i;i--)
      dat[i]=f(dat[(i<<1)|0],dat[(i<<1)|1]);
  }

  inline T reflect(Int k){
    return laz[k]==ei?dat[k]:g(dat[k],laz[k]);
  }

  inline void propagate(Int k){
    if(laz[k]==ei) return;
    laz[(k<<1)|0]=h(laz[(k<<1)|0],laz[k]);
    laz[(k<<1)|1]=h(laz[(k<<1)|1],laz[k]);
    dat[k]=reflect(k);
    laz[k]=ei;
  }

  inline void thrust(Int k){
    for(Int i=height;i;i--) propagate(k>>i);
  }

  inline void recalc(Int k){
    while(k>>=1)
      dat[k]=f(reflect((k<<1)|0),reflect((k<<1)|1));
  }

  void update(Int a,Int b,E x){
    if(a>=b) return;
    thrust(a+=n);
    thrust(b+=n-1);
    for(Int l=a,r=b+1;l<r;l>>=1,r>>=1){
      if(l&1) laz[l]=h(laz[l],x),l++;
      if(r&1) --r,laz[r]=h(laz[r],x);
    }
    recalc(a);
    recalc(b);
  }

  void set_val(Int a,T x){
    thrust(a+=n);
    dat[a]=x;laz[a]=ei;
    recalc(a);
  }

  T query(Int a,Int b){
    if(a>=b) return ti;
    thrust(a+=n);
    thrust(b+=n-1);
    T vl=ti,vr=ti;
    for(Int l=a,r=b+1;l<r;l>>=1,r>>=1) {
      if(l&1) vl=f(vl,reflect(l++));
      if(r&1) vr=f(reflect(--r),vr);
    }
    return f(vl,vr);
  }
};

//INSERT ABOVE HERE
signed main(){
  Int n,m,p;
  cin>>n>>m>>p;

  vector<Int> as(n),ps(n);
  for(Int i=0;i<n;i++) cin>>as[i]>>ps[i];

  vector<Int> bs(m),qs(m);
  for(Int i=0;i<m;i++) cin>>bs[i]>>qs[i];

  vector<Int> xs(p),ys(p),zs(p);
  for(Int i=0;i<p;i++) cin>>xs[i]>>ys[i]>>zs[i];

  auto us=compress(fusion(as,xs));
  auto vs=compress(fusion(bs,ys));

  auto du=dict(us);
  auto dv=dict(vs);

  const Int INF = 1e17;
  vector<Int> uu(us.size(),-INF);
  vector<Int> vv(vs.size(),-INF);
  for(Int i=0;i<n;i++){
    chmax(uu[du[as[i]]],-ps[i]);
    chmax(vv[dv[bs[i]]],-qs[i]);
  }

  vector<vector<Int>> G(us.size());
  for(Int i=0;i<p;i++)
    G[du[xs[i]]].emplace_back(i);

  auto f=[&](Int a,Int b){return max(a,b);};
  auto g=[&](Int a,Int b){return a+b;};

  SegmentTree<Int, Int, decltype(f), decltype(g), decltype(g)>
    seg(f,g,g,-INF*10,0);

  seg.build(vv);

  Int ans=-(ps[0]+qs[0]);
  for(Int i=0;i<(Int)us.size();i++){
    chmax(ans,uu[i]+seg.query(0,vv.size()));
    for(Int j:G[i])
      seg.update(dv[ys[j]]+1,vv.size(),zs[j]);
  }
  cout<<ans<<endl;
  return 0;
}