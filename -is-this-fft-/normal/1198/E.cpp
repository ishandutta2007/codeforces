#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>
#include <cassert>
#include <map>

using namespace std;

struct MaxFlow{
  typedef long long ll;
  const ll INF = 1e18;
  struct Edge{
    int u,v;
    ll c,rc;
    shared_ptr<ll> flow;
    Edge(int _u, int _v, ll _c, ll _rc = 0):u(_u),v(_v),c(_c),rc(_rc){
    }
  };
  struct FlowTracker{
    ll cap, rcap;
    shared_ptr<ll> flow;
    bool dir;
    FlowTracker(ll _cap, ll _rcap, shared_ptr<ll> _flow, int _dir):cap(_cap),rcap(_rcap),flow(_flow),dir(_dir){ }
    ll rem() const {
      if(dir == 0){
        return cap-*flow;
      }
      else{
        return rcap+*flow;
      }
    }
    void add_flow(ll f){
      if(dir == 0)
        *flow += f;
      else
        *flow -= f;
      assert(*flow <= cap);
      assert(-*flow <= rcap);
    }
    operator ll() const { return rem(); }
    void operator-=(ll x){ add_flow(x); }
    void operator+=(ll x){ add_flow(-x); }
  };
  int source,sink;
  vector<vector<int> > adj;
  vector<vector<FlowTracker> > cap;
  vector<Edge> edges;
  MaxFlow(int _source, int _sink):source(_source),sink(_sink){
    assert(source != sink);
  }
  int add_edge(int u, int v, ll c, ll rc = 0){
    edges.push_back(Edge(u,v,c,rc));
    return edges.size()-1;
  }
  vector<int> now,lvl;
  void prep(){
    int max_id = max(source, sink);
    for(auto edge : edges)
      max_id = max(max_id, max(edge.u, edge.v));
    adj.resize(max_id+1);
    cap.resize(max_id+1);
    now.resize(max_id+1);
    lvl.resize(max_id+1);
    for(auto &edge : edges){
      auto flow = make_shared<ll>(0);
      adj[edge.u].push_back(edge.v);
      cap[edge.u].push_back(FlowTracker(edge.c, edge.rc, flow, 0));
      if(edge.u != edge.v){
        adj[edge.v].push_back(edge.u);
        cap[edge.v].push_back(FlowTracker(edge.c, edge.rc, flow, 1));
      }
      assert(cap[edge.u].back() == edge.c);
      edge.flow = flow;
    }
  }
  bool dinic_bfs(){
    fill(now.begin(),now.end(),0);
    fill(lvl.begin(),lvl.end(),0);
    lvl[source] = 1;
    vector<int> bfs(1,source);
    for(int i = 0; i < (int) bfs.size(); ++i){
      int u = bfs[i];
      for(int j = 0; j < (int) adj[u].size(); ++j){
        int v = adj[u][j];
        if(cap[u][j] > 0 && lvl[v] == 0){
          lvl[v] = lvl[u]+1;
          bfs.push_back(v);
        }
      }
    }
    return lvl[sink] > 0;
  }
  ll dinic_dfs(int u, ll flow){
    if(u == sink)
      return flow;
    while(now[u] < (int) adj[u].size()){
      int v = adj[u][now[u]];
      if(lvl[v] == lvl[u] + 1 && cap[u][now[u]] != 0){
        ll res = dinic_dfs(v,min(flow,(ll)cap[u][now[u]]));
        if(res > 0){
          cap[u][now[u]] -= res;
          return res;
        }
      }
      ++now[u];
    }
    return 0;
  }
  ll calc_max_flow(){
    prep();
    ll ans = 0;
    while(dinic_bfs()){
      ll cur = 0;
      do{
        cur = dinic_dfs(source,INF);
        ans += cur;
      }while(cur > 0);
    }
    return ans;
  }
  ll flow_on_edge(int edge_index){
    assert(edge_index < (int) edges.size());
    return *edges[edge_index].flow;
  }
};

// auto mf = MaxFlow(1,n);
// arguments source and sink, memory usage
// O(largest node index + input size), sink
// doesn't need to be last index
// int edge_index;
// for(int i = 0; i < m; ++i){
//    int a,b,c;
//    cin >> a >> b >> c;
//mf.add\_edge(a,b,c); // for directed edges
//      edge_index = mf.add_edge(a,b,c,c); // store edge index if care about flow value
//   }
//  cout << mf.calc_max_flow() << '\n';
//cout << mf.flow\_on\_edge(edge\_index) << endl; // return flow on this edge
//}

const int MAX_N = 200;
const int SOURCE = 501;
const int SINK = 502;
const int INF = 1e9 + 5;

int x1 [MAX_N];
int y1 [MAX_N];
int x2 [MAX_N];
int y2 [MAX_N];

int xbig [MAX_N];
int ybig [MAX_N];

int main () {
  ios::sync_with_stdio(false);

  int n, m;
  cin >> n >> m;

  map<int, int> xc, yc;
  xc[0] = 0;
  xc[n] = 0;
  yc[0] = 0;
  yc[n] = 0;
  for (int i = 0; i < m; i++) {
    cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
    x1[i]--; y1[i]--;

    xc[x1[i]] = 0;
    xc[x2[i]] = 0;
    yc[y1[i]] = 0;
    yc[y2[i]] = 0;
  }

  int xs = 0;
  for (auto it = xc.begin(); it != xc.end(); it++) {
    it->second = xs;
    xbig[xs] = it->first;
    xs++;
  }

  int ys = 0;
  for (auto it = yc.begin(); it != yc.end(); it++) {
    it->second = ys;
    ybig[ys] = it->first;
    ys++;
  }

  auto mf = MaxFlow (SOURCE, SINK);
  for (int i = 0; i < xs - 1; i++) {
    mf.add_edge(SOURCE, i, xbig[i + 1] - xbig[i]);
  }
  for (int i = 0; i < ys - 1; i++) {
    mf.add_edge(MAX_N + i, SINK, ybig[i + 1] - ybig[i]);
  }

  for (int i = 0; i < m; i++) {
    for (int x = xc[x1[i]]; x < xc[x2[i]]; x++) {
      for (int y = yc[y1[i]]; y < yc[y2[i]]; y++) {
        mf.add_edge(x, MAX_N + y, INF);
      }
    }
  }

  cout << mf.calc_max_flow() << '\n';
}