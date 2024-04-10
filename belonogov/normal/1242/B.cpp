#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <queue>
#include <bitset>

#define F first
#define S second
#define pb push_back
#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()
#define pw(x) (1LL<<(x))

#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n";
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")\n"
#define dbv(a) cerr << #a << " = "; for (auto xxxx: a) cerr << xxxx << " "; cerr << endl

using namespace std;

typedef long long ll;
typedef double dbl;
const int INF = 1.01e9;


vector<int> p;

int getId(int v) {
  return (p[v] == v)? v : p[v] = getId(p[v]);
}

int main() {
#define TASK "A"
#ifdef HOME
  assert(freopen(TASK".in", "r", stdin));
#endif
  int n, m;
  scanf("%d%d", &n, &m);
  set<pair<int,int>> q;
  for (int i = 0; i < m; i++) {
    int v, u;
    scanf("%d%d", &v, &u); v--; u--;
    q.insert({v, u});
    q.insert({u, v});
  }
  p.resize(n);
  set<int> all_comp;
  vector<vector<int>> list_mem(n);
  for (int i = 0; i < n; i++) {
    p[i] = i;
    all_comp.insert(i);
    list_mem[i].pb(i);
  }


//  function<int(int)> getId = [&](int v) -> int {
//    return (p[v] == v)? v: p[v] = getId(p[v]);
//  };

  for (int v = 0; v < n; v++) {
//    db(v);
    auto cand = all_comp;
    for (auto set_id: cand) {
//      db(set_id);
      if (set_id == getId(v)) {
        continue;
      }
      int need_merge = -1;
      for (auto u: list_mem[set_id]) {
//        db(u);
        if (q.count({v, u}) == 0) {
//          int root_v = getId(v);
          int root_u = getId(u);
//          db2(root_u, set_id);
          assert(set_id == root_u);
          need_merge = root_u;
          break;
        }
      }
      if (need_merge != -1) {
        if (list_mem[need_merge].size() > list_mem[set_id].size()) {
          list_mem[need_merge].swap(list_mem[set_id]);
        }
        int root_v = getId(v);
//        db3("merge", root_v, need_merge);
        p[need_merge] = root_v;
        list_mem[root_v].insert(list_mem[root_v].end(), list_mem[need_merge].begin(), list_mem[need_merge].end());
        all_comp.erase(need_merge);
      }
    }
  }

  cout << (all_comp.size() - 1) << endl;








  return 0;
}