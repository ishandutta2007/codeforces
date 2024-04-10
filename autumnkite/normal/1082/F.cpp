#include <bits/stdc++.h>

class trie {
  static constexpr int INF = std::numeric_limits<int>::max() / 2;

  struct node {
    node *son[10];
    int cnt;
    std::vector<std::vector<int>> f;

    node() : son{}, cnt() {}
  };

  node *rt;

  void dfs(node *u, int d, int k) {
    u->f.assign(d + 1, std::vector<int>(k + 1, INF));
    for (int h = 0; h <= d; ++h) {
      for (int i = d && h == d; i <= k; ++i) {
        u->f[h][i] = u->cnt * (d - h);
      }
    }
    for (node *v : u->son) {
      if (v != nullptr) {
        dfs(v, d + 1, k);
        for (int h = 0; h <= d; ++h) {
          std::vector<int> g(k + 1, INF);
          for (int i = 0; i <= k; ++i) {
            for (int j = 0; j <= i; ++j) {
              g[i] = std::min(g[i], u->f[h][i - j]
                                    + std::min(v->f[h][j], v->f[d + 1][j]));
            }
          }
          u->f[h].swap(g);
        }
      }
    }
  }

public:
  trie() : rt() {}

  void insert(const std::string &s, int m) {
    if (rt == nullptr) {
      rt = new node();
    }
    node *u = rt;
    for (char c : s) {
      node *&v = u->son[c - '0'];
      if (v == nullptr) {
        v = new node();
      }
      u = v;
    }
    u->cnt += m;
  }

  long long get_ans(int k) {
    dfs(rt, 0, k);
    return rt->f[0][k];
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n, k;
  std::cin >> n >> k;
  trie T;
  for (int i = 0; i < n; ++i) {
    std::string s;
    int m;
    std::cin >> s >> m;
    T.insert(s, m);
  }
  std::cout << T.get_ans(k) << "\n";
}