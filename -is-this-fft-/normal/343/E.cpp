#include <bits/stdc++.h>
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
        shared_ptr<ll> flow;
        ll cap, rcap;
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
        for(int i = 0; i < bfs.size(); ++i){
            int u = bfs[i];
            for(int j = 0; j < adj[u].size(); ++j){
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
        while(now[u] < adj[u].size()){
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
        assert(edge_index < edges.size());
        return *edges[edge_index].flow;
    }
};

struct Edge {
  int u, v, w;
  Edge () {}
  Edge (int _u, int _v, int _w) :
    u(_u), v(_v), w(_w) {}
};

class GomoryHu {
  int vertexc;
  vector<vector<int>> capac;
  vector<int> comp;
  vector<int> compsz;
  vector<Edge> tree_edges;
  
  void find_cut (int vertex, int source, vector<int> &partition,
                 vector<vector<int>> &curcapac,
                 vector<vector<int>> &indices, MaxFlow &mf) {
    partition[vertex] = 1;
    for (int nxt = 0; nxt < vertexc; nxt++) {
      if (comp[nxt] == source || comp[nxt] == nxt) {
        if (!partition[nxt]) {
          if (curcapac[vertex][nxt] > 0) {
            if (abs(mf.flow_on_edge(indices[vertex][nxt])) < curcapac[vertex][nxt]) {
              find_cut(nxt, source, partition, curcapac, indices, mf);
            }
          }
        }
      }
    }
  }
  
  void split_component (int vertex) {
    int source = vertex;
    int sink = -1;
    for (int i = 0; i < vertexc; i++) {
      if (comp[i] == vertex && i != vertex) {
        sink = i;
      }
    }

    vector<vector<int>> newcapac (vertexc, vector<int> (vertexc, 0));
    for (int i = 0; i < vertexc; i++) {
      int ic = (comp[i] == vertex ? i : comp[i]);
      for (int j = 0; j < vertexc; j++) {
        int jc = (comp[j] == vertex ? j : comp[j]);
        newcapac[ic][jc] += capac[i][j];
      }
    }

    vector<vector<int>> edgeIndices (vertexc, vector<int> (vertexc, 0));
    MaxFlow mf (source, sink);
    for (int i = 0; i < vertexc; i++) {
      if (comp[i] == vertex || comp[i] == i) {
        for (int j = i + 1; j < vertexc; j++) {
          if (comp[j] == vertex || comp[j] == j) {
            if (newcapac[i][j] > 0) {
              edgeIndices[i][j] = mf.add_edge(i, j, newcapac[i][j], newcapac[i][j]);
              edgeIndices[j][i] = edgeIndices[i][j];
            }
          }
        }
      }
    }
    
    int newWeight = mf.calc_max_flow();
    
    vector<int> partition (vertexc, 0);
    find_cut(sink, source, partition, newcapac, edgeIndices, mf);

    for (int i = 0; i < vertexc; i++) {
      if (comp[i] == source && partition[i]) {
        comp[i] = sink;
        compsz[source]--;
        compsz[sink]++;
      }
    }
    
    vector<Edge> newedges;
    for (Edge e : tree_edges) {
      if (e.u == source) {
        if (partition[e.v]) {
          e.u = sink;
        }
      }

      if (e.v == source) {
        if (partition[e.u]) {
          e.v = sink;
        }
      }

      newedges.push_back(e);
    }
    newedges.push_back(Edge(source, sink, newWeight));
    tree_edges = newedges;
  }
  
public:
  GomoryHu (int _vertexc) {
    vertexc = _vertexc;
    capac = vector<vector<int>> (vertexc, vector<int> (vertexc, 0));
    comp = vector<int> (vertexc, 0);
    compsz = vector<int> (vertexc, 0);
    compsz[0] = vertexc;
    tree_edges = vector<Edge> ();
  }

  void set_capac (int u, int v, int w) {
    capac[u][v] = w;
    capac[v][u] = w;
  }

  vector<Edge> build_tree () {
    for (int i = 0; i < vertexc - 1; i++) {
      for (int j = 0; j < vertexc; j++) {
        if (compsz[j] >= 2) {
          split_component(j); // will happen N - 1 times
        }
      }
    }
    return tree_edges;
  }
};

bool operator< (Edge e, Edge f) {
  if (e.w != f.w) {
    return e.w < f.w;
  }
  return make_pair(e.u, e.v) < make_pair(f.u, f.v);
}

const int MAX_N = 205;

int root [MAX_N];
int find (int u) {
  if (u != root[u]) {
    root[u] = find(root[u]);
  }
  return root[u];
}

vector<int> path [MAX_N];
void merge (int u, int v) {
  u = find(u);
  v = find(v);

  root[u] = v;
  path[v].insert(path[v].end(), path[u].begin(), path[u].end());
}

int main () {
  int vertexc, edgec;
  cin >> vertexc >> edgec;

  for (int i = 0; i < vertexc; i++) {
    root[i] = i;
    path[i] = {i};
  }

  GomoryHu gh (vertexc);
  for (int i = 0; i < edgec; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    u--; v--;

    gh.set_capac(u, v, w);
  }

  vector<Edge> tree = gh.build_tree();
  sort(tree.rbegin(), tree.rend());
  int sum = 0;
  for (Edge e : tree) {
    sum += e.w;
    merge(e.u, e.v);
  }

  int root = find(0);
  cout << sum << endl;
  for (int u : path[root]) {
    cout << u + 1 << " ";
  }
  cout << endl;
}

/*
//!finish
int main(){
    int n,m;
    cin >> n >> m;
    auto mf = MaxFlow(1,n); // arguments source and sink, memory usage O(largest node index + input size), sink doesn't need to be last index
    int edge_index;
    for(int i = 0; i < m; ++i){
        int a,b,c;
        cin >> a >> b >> c;
        //mf.add\_edge(a,b,c); // for directed edges
        edge_index = mf.add_edge(a,b,c,c); // store edge index if care about flow value
    }
    cout << mf.calc_max_flow() << '\n';
    //cout << mf.flow\_on\_edge(edge\_index) << endl; // return flow on this edge
}
//!end_codebook
    // solves http://www.spoj.com/problems/FASTFLOW/
    */