#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>
#include <cassert>
#include <set>

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

typedef long long ll;

const int MAX_N = 4e5 + 5;

vector<pair<int, int>> edges;
set<int> unmatched;
set<pair<int, int>> adj [MAX_N]; // <oth, index>
int match [MAX_N]; 

void del (int u) {
  if (match[u] != -1) {
    auto e = edges[match[u]];
    int oth = e.first ^ e.second ^ u;
    match[oth] = -1;
  }
  
  for (auto e : adj[u]) {
    adj[e.first].erase({u, e.second});
  }
}

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int l, r, m, qc;
  cin >> l >> r >> m >> qc;

  int source = l + r, sink = l + r + 1;
  auto mf = MaxFlow (source, sink);
  edges = vector<pair<int, int>> (m);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--; v--;
    
    mf.add_edge(u, l + v, 1);

    adj[u].insert({l + v, i});
    adj[l + v].insert({u, i});
    edges[i] = {u, l + v};
  }

  for (int i = 0; i < l; i++) {
    mf.add_edge(source, i, 1);
  }

  for (int i = l; i < l + r; i++) {
    mf.add_edge(i, sink, 1);
  }

  mf.calc_max_flow();

  for (int i = 0; i < l + r; i++) {
    match[i] = -1;
    unmatched.insert(i);
  }

  ll sum = 0;
  set<int> matched;
  for (int i = 0; i < m; i++) {
    if (mf.flow_on_edge(i)) {
      match[edges[i].first] = i;
      match[edges[i].second] = i;
      unmatched.erase(edges[i].first);
      unmatched.erase(edges[i].second);
      matched.insert(edges[i].first);
      matched.insert(edges[i].second);
      sum += i + 1;
    }
  }

  for (int q = 0; q < qc; q++) {
    int type;
    cin >> type;

    if (type == 1) {
      // pick a neighbor of an unmatched vertex
      int b = -1;
      while (!unmatched.empty()) {
        int a = *unmatched.begin();
        if (adj[a].empty()) {
          unmatched.erase(a);
        } else {
          b = adj[a].begin()->first;
          break;
        }
      }

      if (b == -1) {
        b = *matched.begin();
      }

      sum -= 1 + match[b];
      auto e = edges[match[b]];
      int c = e.first ^ e.second ^ b;
      matched.erase(b);
      matched.erase(c);
      unmatched.insert(c);
      del(b);

      cout << 1 << '\n';
      cout << (b < l ? 1 + b : -(b - l + 1)) << '\n';
      cout << sum << '\n';
      cout << endl;
    } else {
      cout << (int) matched.size() / 2 << '\n';
      for (int u : matched) {
        if (u < l) {
          cout << 1 + match[u] << '\n';
        }
      }
      cout << endl;
    }
  }
}

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