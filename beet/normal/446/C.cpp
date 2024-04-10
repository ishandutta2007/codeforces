#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}


template<size_t N,typename R>
struct SquareMatrix{
  typedef array<R, N> arr;
  typedef array<arr, N> mat;
  mat dat;
  
  SquareMatrix(){
    for(size_t i=0;i<N;i++)
      for(size_t j=0;j<N;j++)
        dat[i][j]=R::add_identity();
  }
  
  SquareMatrix& operator=(const SquareMatrix& a){
    dat=a.dat;
    return (*this);
  }
  bool operator==(const SquareMatrix& a) const{
    return dat==a.dat;
  }
  
  size_t size() const{return N;};
  arr& operator[](size_t k){return dat[k];};
  const arr& operator[](size_t k) const {return dat[k];};
  
  static SquareMatrix add_identity(){return SquareMatrix();}  
  static SquareMatrix mul_identity(){
    SquareMatrix res;
    for(size_t i=0;i<N;i++) res[i][i]=R::mul_identity();
    return res;
  }
  
  SquareMatrix operator*(const SquareMatrix &B) const{
    SquareMatrix res=add_identity();
    for(size_t i=0;i<N;i++)
      for(size_t j=0;j<N;j++)
        for(size_t k=0;k<N;k++)
          res[i][j]=res[i][j]+(dat[i][k]*B[k][j]);
    return res;
  }
  
  SquareMatrix operator+(const SquareMatrix &B) const{
    SquareMatrix res=add_identity();
    for(size_t i=0;i<N;i++)
      for(size_t j=0;j<N;j++)
        res[i][j]=dat[i][j]+B[i][j];
    return res;
  }
  
  SquareMatrix pow(long long n) const{
    SquareMatrix a=*this,res=mul_identity();    
    while(n){
      if(n&1) res=res*a;      
      a=a*a;      
      n>>=1;
    }
    return res;
  }
};

template<typename T,T MOD = 1000000007>
struct Mint{
  T v;
  Mint():v(0){}
  Mint(signed v):v(v){}
  Mint(long long t){v=t%MOD;if(v<0) v+=MOD;}

  Mint pow(long long k){
    Mint res(1),tmp(v);
    while(k){
      if(k&1) res*=tmp;
      tmp*=tmp;
      k>>=1;
    }
    return res;
  }
  
  static Mint add_identity(){return Mint(0);}
  static Mint mul_identity(){return Mint(1);}
  
  Mint inv(){return pow(MOD-2);}
  
  Mint& operator+=(Mint a){v+=a.v;if(v>=MOD)v-=MOD;return *this;}
  Mint& operator-=(Mint a){v+=MOD-a.v;if(v>=MOD)v-=MOD;return *this;}
  Mint& operator*=(Mint a){v=1LL*v*a.v%MOD;return *this;}
  Mint& operator/=(Mint a){return (*this)*=a.inv();}
  
  Mint operator+(Mint a) const{return Mint(v)+=a;};
  Mint operator-(Mint a) const{return Mint(v)-=a;};
  Mint operator*(Mint a) const{return Mint(v)*=a;};
  Mint operator/(Mint a) const{return Mint(v)/=a;};

  Mint operator-() const{return v?Mint(MOD-v):Mint(v);}

  bool operator==(const Mint a)const{return v==a.v;}
  bool operator!=(const Mint a)const{return v!=a.v;}
  bool operator <(const Mint a)const{return v <a.v;}
};

struct FastIO{
  FastIO(){
    cin.tie(0);
    ios::sync_with_stdio(0);
  }
}fastio_beet;

template <typename T,typename E>
struct SegmentTree{
  using F = function<T(T,T)>;
  using G = function<T(T,E)>;
  using H = function<E(E,E)>;
  int n,height;
  F f;
  G g;
  H h;
  T ti;
  E ei;
  vector<T> dat;
  vector<E> laz;
  SegmentTree(F f,G g,H h,T ti,E ei):
    f(f),g(g),h(h),ti(ti),ei(ei){}
  
  void init(int n_){
    n=1;height=0;
    while(n<n_) n<<=1,height++;
    dat.assign(2*n,ti);
    laz.assign(2*n,ei);
  }
  void build(const vector<T> &v){
    int n_=v.size();
    init(n_);
    for(int i=0;i<n_;i++) dat[n+i]=v[i];
    for(int i=n-1;i;i--)
      dat[i]=f(dat[(i<<1)|0],dat[(i<<1)|1]);
  }
  inline T reflect(int k){
    return laz[k]==ei?dat[k]:g(dat[k],laz[k]);
  }
  inline void eval(int k){
    if(laz[k]==ei) return;
    laz[(k<<1)|0]=h(laz[(k<<1)|0],laz[k]);
    laz[(k<<1)|1]=h(laz[(k<<1)|1],laz[k]);
    dat[k]=reflect(k);
    laz[k]=ei;
  }
  inline void thrust(int k){
    for(int i=height;i;i--) eval(k>>i);
  }
  inline void recalc(int k){    
    while(k>>=1)
      dat[k]=f(reflect((k<<1)|0),reflect((k<<1)|1));
  }
  void update(int a,int b,E x){
    thrust(a+=n);
    thrust(b+=n-1);
    for(int l=a,r=b+1;l<r;l>>=1,r>>=1){
      if(l&1) laz[l]=h(laz[l],x),l++;
      if(r&1) --r,laz[r]=h(laz[r],x);
    }
    recalc(a);
    recalc(b);
  }
  void set_val(int a,T x){
    thrust(a+=n);
    dat[a]=x;laz[a]=ei;
    recalc(a);
  }
  T query(int a,int b){
    thrust(a+=n);
    thrust(b+=n-1);
    T vl=ti,vr=ti;
    for(int l=a,r=b+1;l<r;l>>=1,r>>=1) {
      if(l&1) vl=f(vl,reflect(l++));
      if(r&1) vr=f(reflect(--r),vr);
    }
    return f(vl,vr);
  }
};

//INSERT ABOVE HERE
signed main(){
  const int MOD = 1e9+9;
  using M = Mint<int, MOD>;
  using SM = SquareMatrix<2, M>;

  const int MAX = 1<<19;
  vector<SM> vf(MAX);
  vector<SM> vi(MAX);

  SM fib;
  fib[0][0]=M(1);fib[0][1]=M(1);
  fib[1][0]=M(1);fib[1][1]=M(0);

  SM inv;
  inv[0][0]=M(0);inv[0][1]=M(1);
  inv[1][0]=M(1);inv[1][1]=M(MOD-1);

  vf[0]=SM::mul_identity();
  vi[0]=SM::mul_identity();
  for(int i=1;i<MAX;i++){
    vf[i]=vf[i-1]*fib;
    vi[i]=vi[i-1]*inv;
  }
  
  vector<SM> va(MAX);
  va[0]=SM::add_identity();
  for(int i=0;i+1<MAX;i++)
    va[i+1]=va[i]+vf[i];

  struct T{
    int l,r;
    M v;
    T(int l,int r,M v):l(l),r(r),v(v){};
  };

  auto f=[&](T a,T b){
           if(a.l<0) return b;
           if(b.l<0) return a;
           return T(a.l,b.r,a.v+b.v);
         };
  auto g=[&](T a,SM b){
           return T(a.l,a.r,a.v+((b*va[a.r-a.l])*vf[a.l])[0][0]);
         };
  auto h=[&](SM a,SM b){return a+b;};

  T ti(-1,-1,M(0));
  SM ei;
  SegmentTree<T, SM> seg(f,g,h,ti,ei);
 
  int n,q;
  cin>>n>>q;
  vector<int> a(n);
  for(int i=0;i<n;i++) cin>>a[i];

  vector<T> vt;
  for(int i=0;i<n;i++) vt.emplace_back(i,i+1,M(a[i]));
  seg.build(vt);

  for(int i=0;i<q;i++){
    int t,l,r;
    cin>>t>>l>>r;
    l--;
    if(t==1) seg.update(l,r,vi[l]);
    if(t==2) cout<<seg.query(l,r).v.v<<"\n";
  }
  
  cout<<flush;
  return 0;
}