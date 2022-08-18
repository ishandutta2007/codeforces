#include <iostream>
#include <vector>
#include <set>

using namespace std;

typedef long long ll;

const int MAX_N = 1e5 + 5;

int par [MAX_N];
vector<int> adj [MAX_N];
ll weight [MAX_N];

ll cumw [MAX_N];
int lvl [MAX_N];

void build (int u) {
  lvl[u] = lvl[par[u]] + 1;
  cumw[u] = cumw[par[u]] + weight[u];
  for (int nxt : adj[u]) {
    build(nxt);
  }
}

struct Elem {
  int src, sol;

  Elem (int _src = 0, int _sol = 0) :
    src(_src), sol(_sol) {}
};

bool operator< (Elem p, Elem q) {
  return make_pair(p.sol, p.src) < make_pair(q.sol, q.src);
}

struct ByLvl {
  bool operator() (const Elem &p, const Elem &q) {
    if (lvl[p.src] != lvl[q.src]) return lvl[p.src] < lvl[q.src];
    return p < q;
  }
};

struct ByCumw {
  bool operator() (const Elem &p, const Elem &q) {
    if (cumw[p.src] != cumw[q.src]) return cumw[p.src] < cumw[q.src];
    return p < q;
  }
};

struct AugSet {
  set<Elem, ByLvl> bylvl;
  set<Elem, ByCumw> bycumw;
  set<Elem> bysol;
  int addsol;

  void del_raw (Elem e) {
    bylvl.erase(e);
    bycumw.erase(e);
    bysol.erase(e);
  }

  void insert (Elem e) {
    bylvl.insert(Elem(e.src, e.sol - addsol));
    bycumw.insert(Elem(e.src, e.sol - addsol));
    bysol.insert(Elem(e.src, e.sol - addsol));
  }

  void add_to_all (int k) {
    addsol += k;
  }

  void del_by_cumw (ll cap) { // delete all with cumw > cap
    while (cumw[bycumw.rbegin()->src] > cap) del_raw(*bycumw.rbegin());
  }

  void del_by_lvl (int cap) {
    while (lvl[bylvl.rbegin()->src] > cap) del_raw(*bylvl.rbegin());
  }

  int best_sol () {
    return bysol.begin()->sol + addsol;
  }

  void print () {
    cout << "addsol = " << addsol << "; ";
    for (Elem e : bylvl) {
      cout << "(" << e.src << ", " << e.sol << ")" << " ";
    }
    cout << endl;
  }
  
  vector<Elem> to_vec () {
    vector<Elem> ans;
    for (Elem e : bylvl) {
      ans.push_back(Elem(e.src, e.sol + addsol));
    }
    return ans;
  }

  int size () {
    return bylvl.size();
  }
  
  AugSet () : bylvl(set<Elem, ByLvl> ()), bycumw(set<Elem, ByCumw> ()), addsol(0) {}
};

AugSet* paths [MAX_N];

int L;
ll S;
void solve (int u) {
  for (int nxt : adj[u]) {
    solve(nxt);
  }

  int bss = 0;
  pair<int, int> bigc = {-1, -1};
  for (int nxt : adj[u]) {
    bss += paths[nxt]->best_sol();
    bigc = max(bigc, {paths[nxt]->size(), nxt});
  }
  
  if (adj[u].empty()) {
    paths[u] = new AugSet ();
  } else {
    paths[u] = paths[bigc.second];
    int bs = paths[u]->best_sol();
    paths[u]->add_to_all(bss - bs);
  }
  
  for (int nxt : adj[u]) {
    if (nxt != bigc.second) {
      int bs = paths[nxt]->best_sol();
      paths[nxt]->add_to_all(bss - bs);
      vector<Elem> v = paths[nxt]->to_vec();
      for (auto e : v) {
        paths[u]->insert(e);
      }
    }
  }

  paths[u]->insert(Elem(u, bss + 1));

  paths[u]->del_by_cumw(S + cumw[par[u]]);
  paths[u]->del_by_lvl(L + lvl[par[u]]);
}

int main () {
  ios::sync_with_stdio(false);

  int n;
  cin >> n >> L >> S;

  for (int i = 1; i <= n; i++) {
    cin >> weight[i];
    if (weight[i] > S) {
      cout << -1 << endl;
      return 0;
    }
  }

  for (int i = 2; i <= n; i++) {
    cin >> par[i];
    adj[par[i]].push_back(i);
  }

  build(1);
  solve(1);
  cout << paths[1]->best_sol() << endl;
}