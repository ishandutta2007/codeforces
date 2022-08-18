#include <bits/stdc++.h>

#define ran(i, a, b) for (auto i = (a); i < (b); i++)

using namespace std;

typedef long long ll;

struct MaxFlow {
  const static ll INF = 1e18;
  int source, sink;
  vector<int> start, now, lvl, adj, rcap, cap_loc, bfs;
  vector<int> cap, orig_cap;
  ll sink_pot = 0;
  vector<bool> visited;
  vector<ll> cost;
  priority_queue<pair<ll, int>, vector<pair<ll, int> >,
    greater<pair<ll, int> > >
    dist_que;
  void add_flow(int idx, ll flow, bool cont = true) {
    cap[idx] -= flow;
    if (cont) add_flow(rcap[idx], -flow, false);
  }
  MaxFlow(
    const vector<tuple<int, int, ll, ll, ll > > &edges) {
    for (auto &cur : edges) { //from, to, cap, rcap, cost
      start.resize(max(max(get<0>(cur), get<1>(cur)) + 2,
            (int)start.size()));
      ++start[get<0>(cur) + 1];
      ++start[get<1>(cur) + 1];
    }
    ran(i, 1, (int)start.size()) start[i] += start[i-1];
    now = start;
    adj.resize(start.back());
    cap.resize(start.back());
    rcap.resize(start.back());
    cost.resize(start.back());
    for (auto &cur : edges) {
      int u, v;
      ll c, rc, c_cost;
      tie(u, v, c, rc, c_cost) = cur;
      assert(u != v);
      adj[now[u]] = v;
      adj[now[v]] = u;
      rcap[now[u]] = now[v];
      rcap[now[v]] = now[u];
      cap_loc.push_back(now[u]);
      cost[now[u]] = c_cost;
      cost[now[v]] = -c_cost;
      cap[now[u]++] = c;
      cap[now[v]++] = rc;
      orig_cap.push_back(c);
    }
  }
  bool dinic_bfs(int min_cap) {
    lvl.clear();
    lvl.resize(start.size());
    bfs.clear();
    bfs.resize(1, source);
    now = start;
    lvl[source] = 1;
    ran(i, 0, (int)bfs.size()) {
      int u = bfs[i];
      while (now[u] < start[u + 1]) {
        int v = adj[now[u]];
        if (cost[now[u]] == 0 &&
            cap[now[u]] >= min_cap && lvl[v] == 0) {
          lvl[v] = lvl[u] + 1;
          if(v==sink) return true;
          bfs.push_back(v);
        }
        ++now[u];
      }
    }
    return false;
  }
  ll dinic_dfs(int u, ll flow, int min_cap) {
    if (u == sink) return flow;
    if (lvl[u] == lvl[sink]) return 0;
    ll res = 0;
    while (now[u] < start[u + 1]) {
      int v = adj[now[u]];
      if (lvl[v] == lvl[u] + 1 && cost[now[u]] == 0 &&
          cap[now[u]] >= min_cap) {
        ll cur = dinic_dfs(v, min(flow, (ll)cap[now[u]]),
            min_cap);
        if (cur) {
          add_flow(now[u], cur);
          flow -= cur;
          res += cur;
          if(!flow) break;
        }
      }
      ++now[u];
    }
    return res;
  }
  bool recalc_dist(bool check_imp = false) {
    now = start;
    visited.clear();
    visited.resize(start.size());
    dist_que.emplace(0, source);
    bool imp = false;
    while (!dist_que.empty()) {
      int u;
      ll dist;
      tie(dist, u) = dist_que.top();
      dist_que.pop();
      if (!visited[u]) {
        visited[u] = true;
        if (check_imp && dist != 0) imp = true;
        if (u == sink) sink_pot += dist;
        while (now[u] < start[u + 1]) {
          int v = adj[now[u]];
          if (!visited[v] && cap[now[u]])
            dist_que.emplace(dist + cost[now[u]], v);
          cost[now[u]] += dist;
          cost[rcap[now[u]++]] -= dist;
        }
      }
    }
    if (check_imp) return imp;
    return visited[sink];
  }
  // return whether there is a negative cycle
  bool recalc_dist_bellman_ford() {
    int i = 0;
    for (; i < (int)start.size() - 1 &&
        recalc_dist(true); ++i) {}
    return i == (int)start.size() - 1;
  }
  pair<ll, ll> calc_flow(int _source, int _sink) {
    source = _source;
    sink = _sink;
    assert(max(source, sink) < start.size() - 1);
    ll tot_flow = 0;
    ll tot_cost = 0;
    if (recalc_dist_bellman_ford()) {
      assert(false);
    } else {
        while (recalc_dist()){
        ll flow = 0;
        for(int min_cap = 1<<30; min_cap; min_cap >>= 1){
          while (dinic_bfs(min_cap)) {
            now = start;
            ll cur;
            while (cur = dinic_dfs(source, INF, min_cap))
              flow += cur;
          }
        }
        tot_flow += flow;
        tot_cost += sink_pot * flow;
      }
    }
    return {tot_flow, tot_cost};
  }
//!finish
//!start
  ll flow_on_edge(int idx) {
    assert(idx < cap.size());
    return orig_cap[idx] - cap[cap_loc[idx]];
  }
};
//!finish

/*
const int nmax = 1055;
int main() {
  int t;
  scanf("%d", &t);
  for (int i = 0; i < t; ++i) {
    vector<tuple<int, int, ll, ll, ll> > edges;
    int n;
    scanf("%d", &n);
    for (int j = 1; j <= n; ++j) {
      edges.emplace_back(j, 2 * n + 1, 1, 0, 0);
    }
    for (int j = 1; j <= n; ++j) {
      int card;
      scanf("%d", &card);
      edges.emplace_back(0, card, 1, 0, 0);
    }
    int ex_c;
    scanf("%d", &ex_c);
    for (int j = 0; j < ex_c; ++j) {
      int a, b;
      scanf("%d %d", &a, &b);
      if (b < a) swap(a, b);
      edges.emplace_back(a, b, nmax, 0, 1);
      edges.emplace_back(b, n + b, nmax, 0, 0);
      edges.emplace_back(n + b, a, nmax, 0, 1);
    }
    int v = 2 * n + 2;
    MaxFlow mf(edges);
    printf("%d\n", (int)mf.calc_flow(0, v - 1).second);
    //cout << mf.flow_on_edge(edge_index) << endl;
  }
}
//!end_codebook

/*
   int n,m;
   cin >> n >> m;
vector<tuple<int,
int, ll, ll> > edges; for(int i = 0; i < m; ++i){ int a,b; ll c;
scanf("%d %d %lld", &a, &b, &c);
if(a != b){
edges.emplace_back(a, b, c, c); //(a, b, c, 0) for directed
}
}
MaxFlow mf(edges);
cout << mf.calc_flow(1, n) << '\n';
this edge
*/

// solves http://www.spoj.com/problems/GREED
// solves http://www.spoj.com/problems/FASTFLOW/

typedef tuple<int, int, ll, ll, ll> Edge;

struct Card {
  int position; /* -1 = ours, 0 = atk, 1 = def */
  int value;

  Card () {}
  Card (int _pos, int _val) : position(_pos), value(_val) {}
};

bool operator< (Card c, Card d) {
  return c.value > d.value;
}

int killEveryone (vector<Card> cards) {
  sort(cards.begin(), cards.end());

  int ans = 0;
  deque<Card> Q;
  for (Card c : cards) {
    if (c.position == -1) {
      Q.push_back(c);
    } else if (c.position == 0) {
      if (Q.empty()) {
        return -1;
      }
      ans += Q.front().value - c.value;
      Q.pop_front();
    } else if (c.position == 1) {
      if (Q.empty()) {
        return -1;
      }
      Q.pop_back();
    }
  }

  for (Card c : Q) {
    ans += c.value;
  }

  return ans;
}

const int SOURCE = 0;
const int SINK = 1;
const int OUR = 50;
const int OPP = 200;

int withTrample (vector<Card> cards) {
  vector<int> ours;
  vector<int> theirs;
  
  for (Card c : cards) {
    if (c.position == -1) {
      ours.push_back(c.value);
    } else if (c.position == 0) {
      theirs.push_back(c.value);
    }
  }

  vector<Edge> edges;
  for (int i = 0; i < (int) ours.size(); i++) {
    edges.emplace_back(SOURCE, OUR + i, 1, 0, 0);
  }

  for (int i = 0; i < (int) theirs.size(); i++) {
    edges.emplace_back(OPP + i, SINK, 1, 0, 0);
  }

  for (int i = 0; i < (int) ours.size(); i++) {
    for (int j = 0; j < (int) theirs.size(); j++) {
      if (ours[i] >= theirs[j]) {
        edges.emplace_back(OUR + i, OPP + j, 1, 0, -(ours[i] - theirs[j]));
      } else {
        edges.emplace_back(OUR + i, OPP + j, 1, 0, 0);
      }
    }
  }

  MaxFlow mf (edges);
  return -mf.calc_flow(SOURCE, SINK).second;
}

int main () {
  int theirc, ourc;
  cin >> theirc >> ourc;

  vector<Card> cards;
  for (int i = 0; i < theirc; i++) {
    string attr;
    int val;
    cin >> attr >> val;

    if (attr[0] == 'A') {
      cards.push_back(Card(0, val));
    } else {
      cards.push_back(Card(1, val));
    }
  }

  for (int i = 0; i < ourc; i++) {
    int val;
    cin >> val;

    cards.push_back(Card(-1, val));
  }

  cout << max(killEveryone(cards), withTrample(cards)) << endl;
}