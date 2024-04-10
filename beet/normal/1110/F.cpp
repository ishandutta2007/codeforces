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


template <typename T,typename E,typename F,typename G,typename H>
struct SegmentTree{
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
  inline void eval(Int k){
    if(laz[k]==ei) return;
    laz[(k<<1)|0]=h(laz[(k<<1)|0],laz[k]);
    laz[(k<<1)|1]=h(laz[(k<<1)|1],laz[k]);
    dat[k]=reflect(k);
    laz[k]=ei;
  }
  inline void thrust(Int k){
    for(Int i=height;i;i--) eval(k>>i);
  }
  inline void recalc(Int k){    
    while(k>>=1)
      dat[k]=f(reflect((k<<1)|0),reflect((k<<1)|1));
  }
  void update(Int a,Int b,E x){
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
const Int MAX = 1<<19;
const Int INF = 1e17;

auto f=[](Int a,Int b){return min(a,b);};                   
auto g=std::plus<Int>();

SegmentTree<Int, Int, decltype(f), decltype(g), decltype(g)> seg(f,g,g,INF,0);

Int n,q;
using P = pair<Int, Int>;
vector<P> G[MAX];
Int dep[MAX],sz[MAX];
Int vs[MAX],ls[MAX],rs[MAX],ans[MAX];
vector<Int> qs[MAX];

Int dfs1(Int v,Int d){
  dep[v]=d;
  sz[v]=1;
  for(P e:G[v]){
    Int u=e.first,c=e.second;
    sz[v]+=dfs1(u,d+c);    
  }
  if(G[v].empty()) seg.set_val(v,dep[v]);
  return sz[v];
}

Int ofs=0;
void dfs2(Int v){
  for(P e:G[v]){
    Int u=e.first,c=e.second;
    ofs+=c;
    seg.update(u,u+sz[u],-2*c);
    
    dfs2(u);    

    ofs-=c;
    seg.update(u,u+sz[u],2*c);
  }

  for(Int x:qs[v])
    chmin(ans[x],ofs+seg.query(ls[x],rs[x]));
}

signed main(){
  cin>>n>>q;
  for(Int i=1;i<n;i++){
    Int p,w;
    cin>>p>>w;
    p--;
    G[p].emplace_back(i,w);
  }
  for(Int i=0;i<q;i++){
    cin>>vs[i]>>ls[i]>>rs[i];
    vs[i]--;ls[i]--;
    ans[i]=INF;
    qs[vs[i]].emplace_back(i);
  }  
  seg.build(vector<Int>(n,INF));
  dfs1(0,0);
  dfs2(0);  
  for(Int i=0;i<q;i++) cout<<ans[i]<<"\n";
  cout<<flush;
  return 0;
}