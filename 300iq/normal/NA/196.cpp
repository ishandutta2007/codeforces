#include <bits/stdc++.h>

#define SZ(AA) ((int)((AA).size()))
#define ALL(AA) (AA).begin(), (AA).end()

using namespace std;

typedef vector<int> VI;
typedef pair<int, int> PII;
typedef long long LL;
typedef long double LD;

struct graph {
  int n;
  vector<vector<int> > ve;

  graph(int _n) : n(_n), ve(n) {}

  void add_edge(int a, int b) {
    ve[a].push_back(b);
  }

  vector<int> cycle(const vector<int> &F) {
    vector<bool> vis(n), end(n), forb(n);
    for (int v : F) {
      forb[v] = true;
    }
    vector<int> res;
    function<bool(int)> dfs = [&](int v) -> bool {
      vis[v] = true;
      res.push_back(v);
      for (int w : ve[v]) {
        if (forb[w]) {
          continue;
        }
        if (vis[w] && !end[w]) {
          reverse(ALL(res));
          while (!res.empty() && res.back() != w) {
            res.pop_back();
          }
          reverse(ALL(res));
          return true;
        } else if (!vis[w] && dfs(w)) {
          return true;
        }
      }
      end[v] = true;
      res.pop_back();
      return false;
    };
    for (int v = 0; v < n; ++v) {
      if (!forb[v] && !vis[v]) {
        if (dfs(v)) {
          assert(!res.empty());
          break;
        }
      }
    }
    return res;
  }

  pair<bool, vector<int>> fset() {
    auto C1 = cycle({});
    if (C1.empty()) {
      return {false, {}};
    }
    if (!cycle(C1).empty()) {
      return {true, {}};
    }
    const int D = SZ(C1);
    vector<int> id(n, -1);
    for (int i = 0; i < D; ++i) {
      id[C1[i]] = i;
    }
    auto comb = [&](PII &a, const PII &b) -> void {
      a.first = min(a.first, b.first);
      a.second = max(a.second, b.second);
    };
    vector<PII> dp(n, {-1, -1});
    function<PII(int)> rec = [&](int v) -> PII {
      if (dp[v].first != -1) {
        return dp[v];
      }
      dp[v] = {D, -1};
      for (int w : ve[v]) {
        if (id[w] != -1) {
          comb(dp[v], {id[w], id[w]});
        } else {
          comb(dp[v], rec(w));
        }
      }
      return dp[v];
    };
    vector<bool> vis(n);
    queue<int> Q;
    int x = 0, y = D - 1;
    for (int i = D - 1; i > x; --i) {
      assert(i <= y);
      Q.push(C1[i]);
      int best = -1;
      while (!Q.empty()) {
        int v = Q.front(); Q.pop();
        for (int w : ve[v]) {
          if (id[w] > x && id[w] <= i) {
            best = max(best, id[w]);
          } else if (id[w] == -1 && !vis[w]) {
            vis[w] = true;
            Q.push(w);
          }
        }
      }
      if (best != -1) {
        x = best;
        y = i;
      } else if (rec(C1[i]).first <= x) {
        y = i;
      }
    }
    if (rec(C1[x]).first <= x) {
      y = x;
    }
    assert(x <= y);
    for (int i = x - 1; i >= 0; --i) {
      if (rec(C1[i]).first <= i) {
        y = x - 1;
        break;
      }
    }
    vector<int> delta(D);
    for (int i = 0; i < D; ++i) {
      int bi = rec(C1[i]).second;
      if (bi > i) {
        ++delta[i + 1];
        --delta[bi];
      }
    }
    vector<int> X;
    for (int i = 0, sum = 0; i < D; ++i) {
      sum += delta[i];
      if (sum == 0 && i >= x && i <= y) {
        X.push_back(C1[i]);
      }
    }
    return {true, X};
  }
};

int main(void) {
  int n, m; scanf("%d%d", &n, &m);
  graph G(n);
  for (int i = 0; i < m; ++i) {
    int a, b; scanf("%d%d", &a, &b);
    --a; --b;
    G.add_edge(a, b);
  }
  auto r = G.fset();
  if (r.second.empty()) {
    puts("-1");
  } else {
    printf("%d\n", r.second[0] + 1);
  }
  return 0;
}