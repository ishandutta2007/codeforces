#include <bits/stdc++.h>
using namespace std;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
using Int = long long;
const char newl = '\n';

template<typename T>
struct RangeCount{
  struct BIT{
    vector<T> dat;
    BIT(){}
    BIT(int n){dat.assign(++n,0);}
    T sum(int k){
      T res=0;
      for(;k;k-=k&-k) res+=dat[k];
      return res;
    }
    void add(int k,T v){
      for(++k;k<(int)dat.size();k+=k&-k) dat[k]+=v;
    }
  };
  int n;
  vector< vector<int> > val;
  vector<BIT> dat;
  RangeCount(){}
  RangeCount(int n_){
    n=1;
    while(n<n_) n<<=1;
    val.assign(n<<1,vector<int>());
    dat.reserve(n<<1);
  }
  void preupdate(int a,int x){
    a+=n;
    while(a){
      val[a].emplace_back(x);
      a>>=1;
    }
  }
  void build(){
    for(int i=0;i<n*2;i++){
      auto &v=val[i];
      sort(v.begin(),v.end());
      v.erase(unique(v.begin(),v.end()),v.end());
      dat.emplace_back(v.size());
    }
  }
  void update(int a,int x,T z){
    a+=n;
    while(a){
      auto &v=val[a];
      int k=lower_bound(v.begin(),v.end(),x)-v.begin();
      dat[a].add(k,z);
      a>>=1;
    }
  }
  T calc(int k,int x,int y){
    auto &v=val[k];
    int p=lower_bound(v.begin(),v.end(),x)-v.begin();
    int q=lower_bound(v.begin(),v.end(),y)-v.begin();
    return dat[k].sum(q)-dat[k].sum(p);
  }
  // [a, b) * [x, y)
  T query(int a,int b,int x,int y){
    T res=0;
    for(int l=a+n,r=b+n;l<r;l>>=1,r>>=1){
      if(l&1) res+=calc(l++,x,y);
      if(r&1) res+=calc(--r,x,y);
    }
    return res;
  }
};

//INSERT ABOVE HERE
signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n,q;
  cin>>n>>q;
  vector<int> as(n+1);
  for(int i=1;i<=n;i++) cin>>as[i];

  vector<int> ts(q),ps(q),xs(q),ls(q),rs(q);
  for(int i=0;i<q;i++){
    cin>>ts[i];
    if(ts[i]==1) cin>>ps[i]>>xs[i];
    if(ts[i]==2) cin>>ls[i]>>rs[i],rs[i]++;
  }

  vector<int> bs(as);
  vector<set<int>> G(n+1);
  auto init=[&](){
    as=bs;
    for(int i=1;i<=n;i++) G[i].clear();

    for(int i=1;i<=n;i++){
      G[i].emplace(0);
      G[i].emplace(n+1);
    }
  };

  using ll = long long;
  RangeCount<ll> seg(n+2);

  auto add=[&](int cur,int flg){
    int v=as[cur];
    int pre=*--G[v].lower_bound(cur);
    int nxt=*G[v].upper_bound(cur);
    G[v].emplace(cur);

    // cout<<pre<<':'<<cur<<':'<<nxt<<endl;
    if(flg){
      seg.update(pre,nxt,-(nxt-pre));
      seg.update(pre,cur,+(cur-pre));
      seg.update(cur,nxt,+(nxt-cur));
    }else{
      seg.preupdate(pre,nxt);
      seg.preupdate(pre,cur);
      seg.preupdate(cur,nxt);
    }
  };

  auto rmv=[&](int cur,int flg){
    int v=as[cur];
    int pre=*--G[v].lower_bound(cur);
    int nxt=*G[v].upper_bound(cur);
    G[v].erase(cur);

    if(flg){
      seg.update(pre,nxt,+(nxt-pre));
      seg.update(pre,cur,-(cur-pre));
      seg.update(cur,nxt,-(nxt-cur));
    }else{
      seg.preupdate(pre,nxt);
      seg.preupdate(pre,cur);
      seg.preupdate(cur,nxt);
    }
  };

  init();
  for(int i=1;i<=n;i++) add(i,0);

  for(int i=0;i<q;i++){
    if(ts[i]!=1) continue;
    rmv(ps[i],0);
    as[ps[i]]=xs[i];
    add(ps[i],0);
  }
  seg.build();


  init();
  for(int i=1;i<=n;i++) add(i,1);

  for(int i=0;i<q;i++){
    if(ts[i]==1){
      rmv(ps[i],1);
      as[ps[i]]=xs[i];
      add(ps[i],1);
    }
    if(ts[i]==2){
      cout<<seg.query(ls[i],rs[i],ls[i],rs[i])<<newl;
    }
  }

  return 0;
}