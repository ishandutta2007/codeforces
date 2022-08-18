#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

class DSU {
  int cur_age;
  vector<int> _root, age;
  
public:
  DSU (int _n) {
    _root = vector<int> (_n);
    age = vector<int> (_n, 0);
    cur_age = 1;
  }

  int get_root (int u) {
    if (age[u] < cur_age) {
      age[u] = cur_age;
      _root[u] = u;
    }
    return _root[u];
  }

  void set_root (int u, int val) {
    _root[u] = val;
    age[u] = cur_age;
  }

  void reset () {
    cur_age++;
  }

  int find (int u) {
    if (get_root(u) != u) {
      int p = find(get_root(u));
      set_root(u, p);
    }
    return get_root(u);
  }

  void merge (int u, int v) {
    u = find(u);
    v = find(v);

    set_root(u, v);
  }
};

struct Edge {
  int u, v, w;

  Edge (int _u = 0, int _v = 0, int _w = 0) :
    u(_u), v(_v), w(_w) {}
};

struct Event {
  int qid;
  Edge e;

  Event (int _qid, Edge _e) :
    qid(_qid), e(_e) {}
};

bool operator< (Event p, Event q) {
  if (p.e.w != q.e.w) {
    return p.e.w < q.e.w;
  }
  return p.qid < q.qid;
}

const int MAX_N = 5e5 + 5;

Edge edges [MAX_N];
int ans [MAX_N];

int main () {
  ios::sync_with_stdio(false);

  int n, m;
  cin >> n >> m;

  map<int, int> compr;
  for (int i = 1; i <= m; i++) {
    cin >> edges[i].u >> edges[i].v >> edges[i].w;
  }

  vector<Event> events;
  int qc;
  cin >> qc;
  for (int i = 0; i < qc; i++) {
    int k;
    cin >> k;
    ans[i] = 1;
    
    for (int j = 0; j < k; j++) {
      int idx;
      cin >> idx;

      events.push_back(Event(i, edges[idx]));
    }
  }

  for (int i = 1; i <= m; i++) {
    events.push_back(Event(qc, edges[i]));
  }

  sort(events.begin(), events.end());

  DSU dsu (n + 5);
  DSU aux (n + 5);

  int last_qid = -1;
  for (Event e : events) {
    if (e.qid == qc) {
      dsu.merge(e.e.u, e.e.v);
    } else {
      if (last_qid != e.qid) {
        aux.reset();
      }

      int u = dsu.find(e.e.u);
      int v = dsu.find(e.e.v);
      if (aux.find(u) == aux.find(v)) {
        ans[e.qid] = 0;
      }
      aux.merge(u, v);
    }

    last_qid = e.qid;
  }

  for (int i = 0; i < qc; i++) {
    cout << (ans[i] ? "YES" : "NO") << '\n';
  }
}