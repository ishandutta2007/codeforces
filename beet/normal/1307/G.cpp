#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

template <typename T, bool isMin>
struct ConvexHullTrick {
#define F first
#define S second
  using P = pair<T, T>;
  deque<P> H;
  bool empty()const{return H.empty();}
  void clear(){H.clear();}

  inline int sgn(T x){return x==0?0:(x<0?-1:1);}

  using D = double;
  inline bool check(const P &a,const P &b,const P &c){
    if(b.S==a.S||c.S==b.S)
      return sgn(b.F-a.F)*sgn(c.S-b.S) >= sgn(c.F-b.F)*sgn(b.S-a.S);
    return (b.F-a.F)*(c.S-b.S) >= (b.S-a.S)*(c.F-b.F);
  }

  void addLine(T m,T b){
    if(!isMin) m*=-1,b*=-1;
    P line(m,b);
    if(empty()){
      H.emplace_front(line);
      return;
    }
    if(H.front().F<=m){
      if(H.front().F==m){
        if(H.front().S<=b) return;
        H.pop_front();
      }
      while(H.size()>=2&&
            check(line,H.front(),H[1])) H.pop_front();
      H.emplace_front(line);
    }else{
      assert(m<=H.back().F);
      if(H.back().F==m){
        if(H.back().S<=b) return;
        H.pop_back();
      }
      while(H.size()>=2&&
            check(H[H.size()-2],H.back(),line)) H.pop_back();
      H.emplace_back(line);
    }
  }

  inline T getY(const P &a,const T &x){
    return a.F*x+a.S;
  }

  T query(T x){
    assert(!empty());
    int l=-1,r=H.size()-1;
    while(l+1<r){
      int m=(l+r)>>1;
      if(getY(H[m],x)>=getY(H[m+1],x)) l=m;
      else r=m;
    }
    if(isMin) return getY(H[r],x);
    return -getY(H[r],x);
  }

  T queryMonotoneInc(T x){
    assert(!empty());
    while(H.size()>=2&&
          getY(H.front(),x)>=getY(H[1],x)) H.pop_front();
    if(isMin) return getY(H.front(),x);
    return -getY(H.front(),x);
  }

  T queryMonotoneDec(T x){
    assert(!empty());
    while(H.size()>=2&&
          getY(H.back(),x)>=getY(H[H.size()-2],x)) H.pop_back();
    if(isMin) return getY(H.back(),x);
    return -getY(H.back(),x);
  }
#undef F
#undef S
};


template<typename TF,typename TC>
struct PrimalDual{
  struct edge{
    int to;
    TF cap;
    TC cost;
    int rev;
    edge(){}
    edge(int to,TF cap,TC cost,int rev):
      to(to),cap(cap),cost(cost),rev(rev){}
  };

  static const TC INF;
  vector<vector<edge>> G;
  vector<TC> h,dist;
  vector<int> prevv,preve;

  PrimalDual(){}
  PrimalDual(int n):G(n),h(n),dist(n),prevv(n),preve(n){}

  void add_edge(int u,int v,TF cap,TC cost){
    G[u].emplace_back(v,cap,cost,G[v].size());
    G[v].emplace_back(u,0,-cost,G[u].size()-1);
  }

  void dijkstra(int s){
    struct P{
      TC first;
      int second;
      P(TC first,int second):first(first),second(second){}
      bool operator<(const P&a) const{return a.first<first;}
    };
    priority_queue<P> que;
    fill(dist.begin(),dist.end(),INF);

    dist[s]=0;
    que.emplace(dist[s],s);
    while(!que.empty()){
      P p=que.top();que.pop();
      int v=p.second;
      if(dist[v]<p.first) continue;
      for(int i=0;i<(int)G[v].size();i++){
        edge &e=G[v][i];
        if(e.cap==0) continue;
        if(dist[v]+e.cost+h[v]-h[e.to]<dist[e.to]){
          dist[e.to]=dist[v]+e.cost+h[v]-h[e.to];
          prevv[e.to]=v;
          preve[e.to]=i;
          que.emplace(dist[e.to],e.to);
        }
      }
    }
  }

  TC flow(int s,int t,TF f,int &ok){
    TC res=0;
    fill(h.begin(),h.end(),0);
    while(f>0){
      dijkstra(s);
      if(dist[t]==INF){
        ok=0;
        return res;
      }

      for(int v=0;v<(int)h.size();v++)
        if(dist[v]<INF) h[v]=h[v]+dist[v];

      TF d=f;
      for(int v=t;v!=s;v=prevv[v])
        d=min(d,G[prevv[v]][preve[v]].cap);

      f-=d;
      res=res+h[t]*d;
      for(int v=t;v!=s;v=prevv[v]){
        edge &e=G[prevv[v]][preve[v]];
        e.cap-=d;
        G[v][e.rev].cap+=d;
      }
    }
    ok=1;
    return res;
  }
};
template<typename TF, typename TC>
const TC PrimalDual<TF, TC>::INF = numeric_limits<TC>::max()/2;

//INSERT ABOVE HERE
signed main(){
  using ll = long long;

  ll n,m;
  scanf("%lld %lld",&n,&m);

  vector<ll> us(m),vs(m),ws(m);
  for(ll i=0;i<m;i++){
    scanf("%lld %lld %lld",&us[i],&vs[i],&ws[i]);
    us[i]--,vs[i]--;
  }

  using D = double;
  ConvexHullTrick<D, true> cht;

  PrimalDual<ll, ll> G(n);
  for(ll i=0;i<m;i++)
    G.add_edge(us[i],vs[i],1,ws[i]);

  int ok=1;
  ll sum=0,cnt=0;
  while(1){
    sum+=G.flow(0,n-1,1,ok);
    cnt++;
    if(!ok) break;
    if(cnt>=5000) break;
    cht.addLine(D(1)/D(cnt),D(sum)/D(cnt));
  }

  ll q;
  scanf("%lld",&q);
  vector<ll> xs(q);
  for(ll i=0;i<q;i++) scanf("%lld",&xs[i]);

  using P = pair<D, ll>;
  vector<P> vp;
  for(ll i=0;i<q;i++)
    vp.emplace_back(xs[i],i);
  sort(vp.begin(),vp.end());

  vector<D> ans(q);
  for(auto p:vp)
    ans[p.second]=cht.queryMonotoneInc(p.first);

  for(int i=0;i<q;i++)
    printf("%.8f\n",ans[i]);
  return 0;
}