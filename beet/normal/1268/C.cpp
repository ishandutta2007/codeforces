#include <bits/stdc++.h>
using namespace std;

using Int = long long;
const char newl = '\n';

template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
template<typename T> void drop(const T &x){cout<<x<<endl;exit(0);}
template<typename T=Int>
vector<T> read(size_t n){
  vector<T> ts(n);
  for(size_t i=0;i<n;i++) cin>>ts[i];
  return ts;
}


struct FullyIndexableDictionary{
  Int len,blk;
  vector<unsigned> bit;
  vector<Int> sum;

  FullyIndexableDictionary(){}
  FullyIndexableDictionary(Int len)
    :len(len),blk((len+31)>>5),bit(blk,0),sum(blk,0){}

  void set(Int k){
    bit[k>>5]|=1u<<(k&31);
  }

  void build(){
    sum[0]=0;
    for(Int i=1;i<blk;i++)
      sum[i]=sum[i-1]+__builtin_popcount(bit[i-1]);
  }

  bool operator[](Int k) const{
    return bool((bit[k>>5]>>(k&31))&1);
  }

  Int rank(Int k){
    return sum[k>>5]+__builtin_popcount(bit[k>>5]&((1u<<(k&31))-1));
  }

  Int rank(bool v,Int k){
    return (v?rank(k):k-rank(k));
  }

  Int select(bool v,Int k){
    if(k<0 or rank(v,len)<=k) return -1;
    Int l=0,r=len;
    while(l+1<r){
      Int m=(l+r)>>1;
      if(rank(v,m)>=k+1) r=m;
      else l=m;
    }
    return r-1;
  }

  Int select(bool v,Int i,Int l){
    return select(v,i+rank(v,l));
  }
};

template<class T,Int MAXLOG>
struct WaveletMatrix{
  Int len;
  FullyIndexableDictionary mat[MAXLOG];
  Int zs[MAXLOG],buff1[MAXLOG],buff2[MAXLOG];
  static const T npos=-1;

  WaveletMatrix(vector<T> data){
    len=data.size();
    vector<T> ls(len),rs(len);
    for(Int dep=0;dep<MAXLOG;dep++){
      mat[dep]=FullyIndexableDictionary(len+1);
      Int p=0,q=0;
      for(Int i=0;i<len;i++){
        bool k=(data[i]>>(MAXLOG-(dep+1)))&1;
        if(k) rs[q++]=data[i],mat[dep].set(i);
        else  ls[p++]=data[i];
      }
      zs[dep]=p;
      mat[dep].build();
      swap(ls,data);
      for(Int i=0;i<q;i++) data[p+i]=rs[i];
    }
  }

  T access(Int k){
    T res=0;
    for(Int dep=0;dep<MAXLOG;dep++){
      bool bit=mat[dep][k];
      res=(res<<1)|bit;
      k=mat[dep].rank(bit,k)+zs[dep]*dep;
    }
    return res;
  }

  // return the number of v in [0,k)
  Int rank(T v,Int k){
    Int l=0,r=k;
    for(Int dep=0;dep<MAXLOG;dep++){
      buff1[dep]=l;buff2[dep]=r;
      bool bit=(v>>(MAXLOG-(dep+1)))&1;
      l=mat[dep].rank(bit,l)+zs[dep]*bit;
      r=mat[dep].rank(bit,r)+zs[dep]*bit;
    }
    return r-l;
  }

  // return the position of k-th v
  Int select(T v,Int k){
    rank(v,len);
    for(Int dep=MAXLOG-1;dep>=0;dep--){
      bool bit=(v>>(MAXLOG-(dep+1)))&1;
      k=mat[dep].select(bit,k,buff1[dep]);
      if(k>=buff2[dep] or k<0) return -1;
      k-=buff1[dep];
    }
    return k;
  }

  Int select(T v,Int k,Int l){
    return select(v,k+rank(v,l));
  }

  // return k-th largest value in [l,r)
  T quantile(Int l,Int r,Int k){
    if(r-l<=k or k<0) return -1;
    T res=0;
    for(Int dep=0;dep<MAXLOG;dep++){
      Int p=mat[dep].rank(1,l);
      Int q=mat[dep].rank(1,r);
      if(q-p>k){
        l=p+zs[dep];
        r=q+zs[dep];
        res|=T(1)<<(MAXLOG-(dep+1));
      }else{
        k-=(q-p);
        l-=p;
        r-=q;
      }
    }
    return res;
  }

  T rquantile(Int l,Int r,Int k){
    return quantile(l,r,r-l-k-1);
  }

  Int freq_dfs(Int d,Int l,Int r,T val,T a,T b){
    if(l==r) return 0;
    if(d==MAXLOG) return (a<=val and val<b)?r-l:0;
    T nv=T(1)<<(MAXLOG-d-1)|val;
    T nnv=((T(1)<<(MAXLOG-d-1))-1)|nv;
    if(nnv<a or b<=val) return 0;
    if(a<=val and nnv<b) return r-l;
    Int lc=mat[d].rank(1,l),rc=mat[d].rank(1,r);
    return freq_dfs(d+1,l-lc,r-rc,val,a,b)
      +freq_dfs(d+1,lc+zs[d],rc+zs[d],nv,a,b);
  }

  // return number of points in [left, right) * [lower, upper)
  Int rangefreq(Int left,Int right,T lower,T upper){
    return freq_dfs(0,left,right,0,lower,upper);
  }

  pair<Int, Int> ll(Int l,Int r,T v){
    Int res=0;
    for(Int dep=0;dep<MAXLOG;dep++){
      buff1[dep]=l;buff2[dep]=r;
      bool bit=(v>>(MAXLOG-(dep+1)))&1;
      if(bit) res+=r-l+mat[dep].rank(bit,l)-mat[dep].rank(bit,r);
      l=mat[dep].rank(bit,l)+zs[dep]*bit;
      r=mat[dep].rank(bit,r)+zs[dep]*bit;
    }
    return make_pair(res,r-l);
  }

  Int lt(Int l,Int r,T v){
    auto p=ll(l,r,v);
    return p.first;
  }

  Int le(Int l,Int r,T v){
    auto p=ll(l,r,v);
    return p.first+p.second;
  }

  T succ(Int l,Int r,T v){
    Int k=le(l,r,v);
    return k==r-l?npos:rquantile(l,r,k);
  }

  T pred(Int l,Int r,T v){
    Int k=lt(l,r,v);
    return k?rquantile(l,r,k-1):npos;
  }
};


#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/tag_and_trait.hpp>
using namespace __gnu_pbds;
template <typename T>
using gtree = tree<T, null_type, less<T>, rb_tree_tag,
                   tree_order_statistics_node_update>;
// usage:
// find_by_order(Int k):
// return the iterator of k-th smallest element (0-indexed)
// order_of_key(T key):  return the index of key in tree


template <typename T,typename E>
struct SegmentTree{
  using F = function<T(T,T)>;
  using G = function<T(T,E)>;
  using H = function<E(E,E)>;
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

  template<typename C>
  Int find(Int st,C &check,T &acc,Int k,Int l,Int r){
    if(l+1==r){
      acc=f(acc,reflect(k));
      return check(acc)?k-n:-1;
    }
    propagate(k);
    Int m=(l+r)>>1;
    if(m<=st) return find(st,check,acc,(k<<1)|1,m,r);
    if(st<=l and !check(f(acc,dat[k]))){
      acc=f(acc,dat[k]);
      return -1;
    }
    Int vl=find(st,check,acc,(k<<1)|0,l,m);
    if(~vl) return vl;
    return find(st,check,acc,(k<<1)|1,m,r);
  }

  template<typename C>
  Int find(Int st,C &check){
    T acc=ti;
    return find(st,check,acc,1,0,n);
  }
};

//INSERT ABOVE HERE
signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  Int n;
  cin>>n;
  auto ps=read(n);
  for(Int &p:ps) p--;

  vector<Int> idx(n);
  for(Int i=0;i<n;i++) idx[ps[i]]=i;

  WaveletMatrix<Int, 20> wm(ps);
  gtree<Int> G;

  struct T{
    Int cnt,sum;
    T(Int cnt_,Int sum_):cnt(cnt_),sum(sum_){}
  };
  auto f=[&](T a,T b){return T(a.cnt+b.cnt,a.sum+b.sum);};
  auto g=[&](T a,Int add){return T(a.cnt,a.sum+a.cnt*add);};
  auto h=[&](Int a,Int b){return a+b;};
  SegmentTree<T, Int> sl(f,g,h,T(0,0),0);
  SegmentTree<T, Int> sr(f,g,h,T(0,0),0);
  sl.build(vector<T>(n,T(1,0)));
  sr.build(vector<T>(n,T(1,0)));

  Int inv=0;
  for(Int i=0;i<n;i++){
    if(i) cout<<' ';
    Int k=idx[i];
    // internal inversion
    inv+=wm.rangefreq(k,n,0,i);

    sl.update(0,k,1);
    sr.update(k,n,1);
    sl.set_val(k,T(0,0));
    sr.set_val(k,T(0,0));

    G.insert(k);
    Int p=*G.find_by_order((G.size()-1)/2);

    Int ans=inv;
    ans+=sr.query(0,p).sum;
    ans+=sl.query(p,n).sum;
    cout<<ans;
  }
  cout<<newl;
  return 0;
}