#include <bits/stdc++.h>
using namespace std;
#define G return failed = 1, void()
#define GG puts("-1"), exit(0)
using pii = pair<int, int>;
constexpr int N = 4e5 + 5;
bool visx[N], visy[N], occu[N];
int n, m, p[N], q[N], comp, compa;
vector<int> x[N];
vector<pii> a[N], b[N];
int main() {
  #ifdef ALEX_WEI
    FILE* IN = freopen("1.in", "r", stdin);
    FILE* OUT = freopen("1.out", "w", stdout);
  #endif
  ios::sync_with_stdio(0);
  cin >> n >> m;
  { // input
    for(int i = 1; i <= n; i++)
      for(int j = 1; j <= m; j++) {
        int v; cin >> v;
        if(v) {
          a[i].push_back({n + j, v});
          a[n + j].push_back({i, v});
        }
      }
    for(int i = 1; i <= n; i++)
      for(int j = 1; j <= m; j++) {
        int v; cin >> v;
        if(v) {
          b[i].push_back({n + j, v});
          b[n + j].push_back({i, v});
        }
      }
    auto cmp = [&](pii x, pii y) {return x.second < y.second;};
    for(int i = 1; i <= n + m; i++) {
      sort(a[i].begin(), a[i].end(), cmp);
      sort(b[i].begin(), b[i].end(), cmp);
    }
  }
  { // get components
    function<void(int, bool)> dfs = [&](int id, bool type) {
      visx[id] = 1, x[comp].push_back(id);
      for(auto _ : (type ? b[id] : a[id])) {
        int it = _.first;
        if(visy[it]) continue;
        visy[it] = 1;
        for(auto __ : (type ? b[it] : a[it])) {
          int adj = __.first;
          if(!visx[adj]) dfs(adj, type);
        }
      }
    };
    if(n < m) {
      for(int i = 1; i <= n; i++) if(!visx[i]) dfs(i, 0), comp++;
    }
    else {
      for(int i = n + 1; i <= n + m; i++) if(!visx[i]) dfs(i, 0), comp++;
    }
    compa = comp;
    memset(visx, 0, sizeof(visx));
    memset(visy, 0, sizeof(visy));
    if(n < m) {
      for(int i = 1; i <= n; i++) if(!visx[i]) dfs(i, 1), comp++;
    }
    else {
      for(int i = n + 1; i <= n + m; i++) if(!visx[i]) dfs(i, 1), comp++;
    }
    if(compa * 2 != comp) GG;
    auto cmp = [&](vector<int> &x, vector<int> &y) {
      return x.size() < y.size();
    };
    sort(x, x + compa, cmp);
    sort(x + compa, x + comp, cmp);
  }
  { // isomorphism
    auto clear = [&](int id, bool type) {
      type ? q[id] = 0 : p[id] = 0;
      for(pii it : (type ? b[id] : a[id]))
        type ? q[it.first] = 0 : p[it.first] = 0;
    };
    bool failed = 0;
    function<void(int, int)> dfs = [&](int ida, int idb) {
      assert(!p[ida] && !q[idb]);
      if(failed) return;
      p[ida] = idb, q[idb] = ida;
      if(a[ida].size() != b[idb].size()) G;
      for(int i = 0; i < a[ida].size(); i++) {
        pii u = a[ida][i], v = b[idb][i];
        if(u.second != v.second) G;
        int ita = u.first, itb = v.first;
        if(p[ita] && p[ita] != itb) G;
        if(q[itb] && q[itb] != ita) G;
        if(!p[ita]) dfs(ita, itb);
      }
    };
    int pta = 0, ptb = compa;
    while(pta < compa) {
      int ra = pta, rb = ptb;
      while(ra < compa && x[ra].size() == x[pta].size()) ra++;
      while(rb < comp && x[rb].size() == x[ptb].size()) rb++;
      if(ra - pta != rb - ptb) GG;
      for(int i = pta; i < ra; i++) {
        bool found = 0;
        for(int j = ptb; j < rb && !found; j++) {
          if(occu[j]) continue;
          for(int idb : x[j]) {
            for(int ida : x[i]) clear(ida, 0);
            for(int idb : x[j]) clear(idb, 1);
            failed = 0, dfs(x[i].front(), idb);
            if(!failed) {found = occu[j] = 1; break;}
          }
        }
        if(!found) GG;
      }
      pta = ra, ptb = rb;
    }
  }
  { // output
    for(int i = 1, j = 1; i <= n + m; i++) { // add this part
      if(p[i]) continue;
      while(q[j]) j++;
      p[i] = j, q[j] = i;
    }
    memset(visx, 0, sizeof(visx));
    vector<pii> row, col;
    for(int i = 1; i <= n + m; i++) {
      if(visx[i]) continue;
      int cur = i;
      do {
        if(cur != q[cur] && !visx[q[cur]]) {
          if(cur > n) col.push_back({cur - n, q[cur] - n});
          else row.push_back({cur, q[cur]});
        }
        visx[cur] = 1, cur = q[cur];
      } while(!visx[cur]);
    }
    cout << row.size() + col.size() << "\n";
    for(pii it : row) cout << "1 " << it.first << " " << it.second << "\n";
    for(pii it : col) cout << "2 " << it.first << " " << it.second << "\n";
  }
  return 0;
}
// 2022.10.10, 10:23-13:29