#include <iostream>
#include <vector>
#include <map>

using namespace std;

const int MAX_N = 5e5 + 5;

typedef long long ll;

class AddHistory {
  map<int, int> time_to_idx;
  vector<ll> pref;

public:
  AddHistory () : pref(1, 0LL) {
    time_to_idx[0] = 0;
  }

  void event (int arg, int t) {
    int idx = pref.size();
    pref.push_back(pref.back() + (ll) arg);
    time_to_idx[t] = idx;
  }

  ll query (int t) {
    ll ans = pref.back();
    auto lb = time_to_idx.lower_bound(t);
    if (lb != time_to_idx.begin()) {
      ans -= pref[prev(lb)->second];
    }
    return ans;
  }
};

struct SumAdder {
  ll init () {
    return 0;
  }

  ll operator() (ll a, ll b) {
    return a + b;
  }
};

class ZeroHistory {
  int mx = 0;
public:
  void event (int arg, int t) {
    mx = max(mx, t);
  }

  ll query (int t) {
    return mx >= t ? mx : 0;
  }
};

struct MaxAdder {
  ll init () {
    return 0;
  }

  ll operator() (ll a, ll b) {
    return max(a, b);
  }
};

template<class History, class Adder>
class Tree {
  vector<int> root;
  vector<vector<pair<int, int>>> log;
  // log[k] is vector consisting of <joined to, join time>
  vector<vector<int>> desc;
  vector<History> hist;

public:
  Tree (int n) : root(n), log(n), desc(n), hist(n, History()) {
    for (int i = 0; i < n; i++) {
      root[i] = i;
      log[i].push_back(make_pair(i, 0));
      desc[i].push_back(i);
    }
  }

  int find (int u) {
    if (root[u] != u) {
      return find(root[u]);
    }
    return u;
  }
  
  void merge (int u, int v, int t) {
    u = find(u);
    v = find(v);

    if (desc[u].size() < desc[v].size()) {
      swap(u, v);
    }

    root[v] = u;
    for (int w : desc[v]) {
      desc[u].push_back(w);
      log[w].push_back(make_pair(u, t));
    }
  }

  int size (int u) {
    return desc[find(u)].size();
  }
  
  void event (int u, int arg, int t) {
    hist[find(u)].event(arg, t);
  }

  ll query (int u, int t) {
    Adder adder;
    ll ans = adder.init();
    for (auto pr : log[u]) {
      ans = adder(ans, hist[pr.first].query(max(t, pr.second)));
    }
    return ans;
  }
};

class Solver {
  Tree<AddHistory, SumAdder> uni;
  Tree<ZeroHistory, MaxAdder> mil;

public:
  Solver (int n) : uni(n), mil(n) {}

  void merge_uni (int u, int v, int t) {
    u--; v--;
    uni.merge(u, v, t);
  }

  void merge_mil (int u, int v, int t) {
    u--; v--;
    mil.merge(u, v, t);
  }

  void add_uni (int u, int t) {
    u--;
    uni.event(u, uni.size(u), t);
  }

  void zero_mil (int u, int t) {
    u--;
    mil.event(u, 0, t);
  }

  ll query (int u) {
    u--;
    int last_zero = mil.query(u, 0);
    return uni.query(u, last_zero);
  }
};

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  int n, qc;
  cin >> n >> qc;

  Solver solver (n);
  for (int i = 1; i <= qc; i++) {
    char type;
    cin >> type;

    if (type == 'U') {
      int u, v;
      cin >> u >> v;
      solver.merge_uni(u, v, i);
    } else if (type == 'M') {
      int u, v;
      cin >> u >> v;
      solver.merge_mil(u, v, i);
    } else if (type == 'A') {
      int u;
      cin >> u;
      solver.add_uni(u, i);
    } else if (type == 'Z') {
      int u;
      cin >> u;
      solver.zero_mil(u, i);
    } else if (type == 'Q') {
      int u;
      cin >> u;
      cout << solver.query(u) << '\n';
    }
  }
}