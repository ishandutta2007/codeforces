#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}


template <typename T,typename E,typename F,typename G>
struct SegmentTree{
  //using F = function<T(T,T)>;
  //using G = function<T(T,E)>;
  int n;
  F f;
  G g;
  T ti;
  vector<T> dat;
  SegmentTree(){};
  SegmentTree(F f,G g,T ti):f(f),g(g),ti(ti){}

  void init(int n_){    
    n=1;
    while(n<n_) n<<=1;
    dat.assign(n<<1,ti);
  }
  void build(const vector<T> &v){
    int n_=v.size();
    init(n_);
    for(int i=0;i<n_;i++) dat[n+i]=v[i];
    for(int i=n-1;i;i--)
      dat[i]=f(dat[(i<<1)|0],dat[(i<<1)|1]);
  }
  void update(int k,E a){
    k+=n;
    dat[k]=g(dat[k],a);
    while(k>>=1)
      dat[k]=f(dat[(k<<1)|0],dat[(k<<1)|1]);
  }
  void set_val(int k,T x){
    dat[k+=n]=x;
    while(k>>=1)
      dat[k]=f(dat[(k<<1)|0],dat[(k<<1)|1]);    
  }
  T query(int a,int b){
    T vl=ti,vr=ti;
    for(int l=a+n,r=b+n;l<r;l>>=1,r>>=1) {
      if(l&1) vl=f(vl,dat[l++]);
      if(r&1) vr=f(dat[--r],vr);
    }
    return f(vl,vr);
  }
};

struct FastIO{
  FastIO(){
    cin.tie(0);
    ios::sync_with_stdio(0);
  }
}fastio_beet;

//INSERT ABOVE HERE
const int INF = 1e8;
struct T{
  int ans;
  vector<int> ma,mi;    
  T(int k):ans(-1),ma(1<<(k-1),-INF),mi(1<<(k-1),INF){}
  T(vector<int> v):ans(0){
    int k=v.size();
    ma.resize(1<<(k-1));
    mi.resize(1<<(k-1));
    for(int b=0;b<(1<<k);b+=2){
      int res=0;
      for(int i=0;i<k;i++){
        if((b>>i)&1) res+=v[i];
        else res-=v[i];
      }
      ma[b/2]=mi[b/2]=res;
    }
  }
};
signed main(){
  int n,k;
  cin>>n>>k;
  vector<vector<int> > a(n,vector<int>(k));
  for(int i=0;i<n;i++)
    for(int j=0;j<k;j++) cin>>a[i][j];


  auto f=[&](T a,T b){
           if(a.ans<0) return b;
           if(b.ans<0) return a;           
           T res(k);
           res.ans=max(a.ans,b.ans);
           for(int i=0;i<(1<<(k-1));i++){
             res.ma[i]=max(a.ma[i],b.ma[i]);
             res.mi[i]=min(a.mi[i],b.mi[i]);
             
             chmax(res.ans,abs(a.ma[i]-b.mi[i]));
             chmax(res.ans,abs(a.mi[i]-b.ma[i]));
           }
           return res;
         };
  auto g=[&](T a,T b){a.ans--;return b;};

  T ti(k);
  SegmentTree<T, T, decltype(f), decltype(g)> seg(f,g,ti);
  vector<T> vt;
  for(int i=0;i<n;i++) vt.emplace_back(a[i]);
  seg.build(vt);
  
  int q;
  cin>>q;
  for(int i=0;i<q;i++){
    int t;
    cin>>t;
    if(t==1){
      int x;
      cin>>x;
      x--;
      for(int j=0;j<k;j++) cin>>a[x][j];
      seg.update(x,T(a[x]));
    }
    if(t==2){
      int l,r;
      cin>>l>>r;
      l--;
      T res=seg.query(l,r);
      cout<<res.ans<<"\n";
    }
  }
  cout<<flush;
  return 0;
}