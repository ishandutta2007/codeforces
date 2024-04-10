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


class HLD {
private:
  void dfs_sz(Int v) {
    for(Int &u:G[v]){
      if(u==par[v]) continue;
      par[u]=v;
      dep[u]=dep[v]+1;
      dfs_sz(u);
      sub[v]+=sub[u];
      if(sub[u]>sub[G[v][0]]) swap(u,G[v][0]);
    }
  }

  void dfs_hld(Int v,Int c,Int &pos) {
    vid[v]=pos++;
    inv[vid[v]]=v;
    type[v]=c;
    for(Int u:G[v]){
      if(u==par[v]) continue;
      head[u]=(u==G[v][0]?head[v]:u);
      dfs_hld(u,c,pos);
    }
  }

public:
  vector<vector<Int> > G;
  vector<Int> vid, head, sub, par, dep, inv, type;

  HLD(Int n):
    G(n),vid(n,-1),head(n),sub(n,1),
    par(n,-1),dep(n,0),inv(n),type(n){}

  void add_edge(Int u,Int v) {
    G[u].emplace_back(v);
    G[v].emplace_back(u);
  }

  void build(vector<Int> rs={0}) {
    Int c=0,pos=0;
    for(Int r:rs){
      dfs_sz(r);
      head[r]=r;
      dfs_hld(r,c++,pos);
    }
  }

  Int lca(Int u,Int v){
    while(1){
      if(vid[u]>vid[v]) swap(u,v);
      if(head[u]==head[v]) return u;
      v=par[head[v]];
    }
  }

  Int distance(Int u,Int v){
    return dep[u]+dep[v]-2*dep[lca(u,v)];
  }

  // for_each(vertex)
  // [l, r) <- attention!!
  template<typename F>
  void for_each(Int u, Int v, const F& f) {
    while(1){
      if(vid[u]>vid[v]) swap(u,v);
      f(max(vid[head[v]],vid[u]),vid[v]+1);
      if(head[u]!=head[v]) v=par[head[v]];
      else break;
    }
  }

  template<typename T,typename Q,typename F>
  T for_each(Int u,Int v,T ti,const Q &q,const F &f){
    T l=ti,r=ti;
    while(1){
      if(vid[u]>vid[v]){
        swap(u,v);
        swap(l,r);
      }
      l=f(l,q(max(vid[head[v]],vid[u]),vid[v]+1));
      if(head[u]!=head[v]) v=par[head[v]];
      else break;
    }
    return f(l,r);
  }

  // for_each(edge)
  // [l, r) <- attention!!
  template<typename F>
  void for_each_edge(Int u, Int v,const F& f) {
    while(1){
      if(vid[u]>vid[v]) swap(u,v);
      if(head[u]!=head[v]){
        f(vid[head[v]],vid[v]+1);
        v=par[head[v]];
      }else{
        if(u!=v) f(vid[u]+1,vid[v]+1);
        break;
      }
    }
  }
};


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
  template<typename C>
  Int find(Int st,C &check,T &acc,Int k,Int l,Int r){
    if(l+1==r){
      acc=f(acc,dat[k]);
      return check(acc)?k-n:-1;
    }
    Int m=(l+r)>>1;
    if(m<=st) return find(st,check,acc,(k<<1)|1,m,r);
    if(st<=l&&!check(f(acc,dat[k]))){
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
  Int n,q;
  cin>>n>>q;
  vector<Int> fs(n,0);
  for(Int i=1;i<n;i++) cin>>fs[i];

  HLD G(n);
  vector<Int> us(n),vs(n),ws(n);
  for(Int i=1;i<n;i++){
    Int u,v,w;
    cin>>u>>v>>w;
    u--;v--;
    G.add_edge(u,v);
    us[i]=u;
    vs[i]=v;
    ws[i]=w;
  }
  G.build();

  vector<Int> xs(q),ys(q),zs(q);
  for(Int i=0;i<q;i++) cin>>xs[i]>>ys[i]>>zs[i],xs[i]--,ys[i]--;

  struct T{
    Int l,r,in,sum;
    T(){};
    T(Int l,Int r,Int in,Int sum):l(l),r(r),in(in),sum(sum){};
  };

  auto f=
    [&](T a,T b){
      if(a.in>=0&&b.in>=0)
        return T(0,0,a.in+b.in,a.sum+b.sum);
      if(a.in>=0)
        return T(a.in+b.l,b.r,-1,a.sum+b.sum);
      if(b.in>=0)
        return T(a.l,a.r+b.in,-1,a.sum+b.sum);
      return T(a.l,b.r,-1,a.sum+b.sum+fs[a.r+b.l]);
    };
  T ti(0,0,0,0);
  SegmentTree<T> seg(f,ti);
  seg.build(vector<T>(n,T(0,0,-1,0)));

  using P = pair<Int, Int>;
  vector<P> vp;
  for(Int i=1;i<n;i++)
    vp.emplace_back(-ws[i],i);
  for(Int i=0;i<q;i++)
    vp.emplace_back(-zs[i],n+i);

  sort(vp.begin(),vp.end());
  vector<Int> ans(q);
  for(auto p:vp){
    //cout<<p.second<<endl;
    if(p.second<n){
      // update
      Int k=p.second;
      if(G.dep[us[k]]>G.dep[vs[k]]) swap(us[k],vs[k]);
      // us[k] is parent of vs[k]
      seg.set_val(G.vid[vs[k]],T(0,0,1,0));
    }else{
      //query
      Int k=p.second-n;
      Int x=xs[k],y=ys[k];
      Int r=G.lca(x,y);

      T res1=ti,res2=ti;
      auto ask1=[&](Int l,Int r){
                  res1=f(seg.query(l,r),res1);
                };
      auto ask2=[&](Int l,Int r){
                  res2=f(seg.query(l,r),res2);
                };
      G.for_each_edge(r,x,ask1);
      G.for_each_edge(r,y,ask2);
      swap(res1.l,res1.r);
      res1=f(res1,res2);
      ans[k]=res1.sum+fs[res1.l]+fs[res1.r];
      if(res1.in>=0) ans[k]+=fs[res1.in];
    }
  }

  for(Int i=0;i<q;i++) cout<<ans[i]<<"\n";
  cout<<flush;
  return 0;
}