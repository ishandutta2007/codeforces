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


// O(m^2 \log m \log U)
// U: maximum capacity
enum Objective{
  MINIMIZE = +1,
  MAXIMIZE = -1,
};
template<typename Flow, typename Cost,
         Objective objective = Objective::MINIMIZE>
struct MinCostFlow{
  template<typename T> inline void chmin(T &x,T y){x=min(x,y);}

  struct Edge{
    Int src,dst;
    Flow flow,cap;
    Cost cost;
    Int rev;
    Edge(Int src,Int dst,Flow cap,Cost cost,Int rev):
      src(src),dst(dst),flow(0),cap(cap),cost(cost),rev(rev){}
    Flow residual_cap()const{return cap-flow;}
  };

  struct EdgePtr{
    Int v,e;
    EdgePtr(Int v,Int e):v(v),e(e){}
  };

  Int n;
  vector<vector<Edge>> G;
  vector<Flow> b;
  vector<Cost> p;

  MinCostFlow(Int n):n(n),G(n),b(n,0){}

  EdgePtr add_edge(Int src,Int dst,Flow lower,Flow upper,Cost cost){
    Int e=G[src].size();
    Int r=(src==dst?e+1:G[dst].size());
    assert(lower<=upper);
    G[src].emplace_back(src,dst,+upper,+cost*objective,r);
    G[dst].emplace_back(dst,src,-lower,-cost*objective,e);
    return EdgePtr(src,e);
  }

  const Edge &get_edge(EdgePtr ep)const{return G[ep.v][ep.e];}

  void push(Edge &e,Flow amount){
    e.flow+=amount;
    G[e.dst][e.rev].flow-=amount;
  }

  void add_supply(Int v,Flow amount){b[v]+=amount;}
  void add_demand(Int v,Flow amount){b[v]-=amount;}

  Cost residual_cost(const Edge &e){
    return e.cost+p[e.src]-p[e.dst];
  }

  vector<Int> excess_vs,deficit_vs;
  void saturate_negative(const Flow delta){
    for(auto &es:G){
      for(auto &e:es){
        Flow cap=e.residual_cap();
        cap-=cap%delta;
        if(cap<0 or residual_cost(e)<0){
          push(e,cap);
          b[e.src]-=cap;
          b[e.dst]+=cap;
        }
      }
    }

    excess_vs.clear();
    deficit_vs.clear();
    for(Int v=0;v<n;v++){
      if(b[v]>0) excess_vs.emplace_back(v);
      if(b[v]<0) deficit_vs.emplace_back(v);
    }
  }

  const Cost unreachable = std::numeric_limits<Cost>::max();
  Cost farthest;
  vector<Cost> dist;
  vector<Edge*> parent;

  struct P{
    Cost first;
    Int second;
    P(Cost first,Int second):first(first),second(second){}
    bool operator<(const P o)const{return first>o.first;}
  };

  priority_queue<P> pq;

  template<typename Predicate>
  void eliminate(vector<Int> &vs,Predicate predicate){
    vs.erase(remove_if(begin(vs),end(vs),predicate),end(vs));
  }

  bool dual(const Flow delta){
    eliminate(excess_vs, [&](Int v){return b[v]<+delta;});
    eliminate(deficit_vs,[&](Int v){return b[v]>-delta;});

    dist.assign(n,unreachable);
    for(Int v:excess_vs) pq.emplace(dist[v]=0,v);

    parent.assign(n,nullptr);
    auto emplace=[&](Edge& e){
      if(e.residual_cap()<delta) return;
      Cost nxt=dist[e.src]+residual_cost(e);
      if(nxt>=dist[e.dst]) return;
      pq.emplace(dist[e.dst]=nxt,e.dst);
      parent[e.dst]=&e;
    };

    farthest=0;
    Int deficit_count=0;
    while(!pq.empty()){
      Cost d=pq.top().first;
      Int v=pq.top().second;
      pq.pop();
      if(dist[v]<d) continue;
      farthest=d;

      if(b[v]<=-delta) deficit_count++;
      if(deficit_count>=(Int)deficit_vs.size()) break;

      for(auto &e:G[v]) emplace(e);
    }
    pq=decltype(pq)();

    for(Int v=0;v<n;v++)
      p[v]+=min(dist[v],farthest);

    return deficit_count>0;
  }

  void primal(const Flow delta){
    for(Int t:deficit_vs){
      if(dist[t]>farthest) continue;
      Flow f=-b[t];
      Int v;
      for(v=t;parent[v];v=parent[v]->src)
        chmin(f,parent[v]->residual_cap());
      chmin(f,b[v]);

      f-=f%delta;
      if(f<=0) continue;

      for(v=t;parent[v];){
        auto &e=*parent[v];
        push(e,f);
        Int u=parent[v]->src;
        if(e.residual_cap()<=0) parent[v]=nullptr;
        v=u;
      }
      b[t]+=f;
      b[v]-=f;
    }
  }

  template<Flow SCALING_FACTOR=2>
  bool build(){
    p.resize(n);
    Flow max_flow=1;
    for(auto t:b) max_flow=max({max_flow,t,-t});
    for(auto &es:G)
      for(auto &e:es)
        max_flow=max({max_flow,e.residual_cap(),-e.residual_cap()});

    Flow delta=1;
    while(delta<max_flow) delta*=SCALING_FACTOR;
    for(;delta;delta/=SCALING_FACTOR){
      saturate_negative(delta);
      while(dual(delta)) primal(delta);
    }

    return excess_vs.empty() and deficit_vs.empty();
  }

  template<typename T=Cost>
  T get_cost(){
    T res=0;
    for(auto &es:G)
      for(auto &e:es)
        res+=T(e.flow)*T(e.cost)/T(objective);
    return res/T(2);
  }
  template<typename T=Cost> T get_gain(){return get_cost();}

  vector<Cost> get_potential(){
    fill(p.begin(),p.end(),0);
    for(Int i=0;i<n;i++)
      for(auto &es:G)
        for(auto &e:es)
          if(e.residual_cap()>0)
            chmin(p[e.dst],p[e.src]+e.cost);
    return p;
  }
};

template<typename Flow, typename Cost>
using MaxGainFlow = MinCostFlow<Flow, Cost, Objective::MAXIMIZE>;

//INSERT ABOVE HERE
signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  using ll = long long;

  Int n,m;
  cin>>n>>m;
  MinCostFlow<ll, ll> G(n);
  const Int INF = 2e9;

  Int ans=0;
  for(Int i=0;i<m;i++){
    Int u,v,c,f;
    cin>>u>>v>>c>>f;
    u--;v--;
    if(f==c){
      G.add_edge(u,v,0,f,-1);
      G.add_edge(u,v,0,INF,2);
    }
    if(f<c){
      G.add_edge(u,v,0,f,-1);
      G.add_edge(u,v,0,c-f,1);
      G.add_edge(u,v,0,INF,2);
    }
    if(f>c){
      G.add_edge(u,v,0,c,-1);
      G.add_edge(u,v,0,f-c,0);
      G.add_edge(u,v,0,INF,2);
    }
    ans+=f;
  }
  G.add_edge(n-1,0,0,INF,0);
  G.build();
  cout<<ans+G.get_cost()<<newl;
  return 0;
}