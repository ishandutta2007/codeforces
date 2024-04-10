#include <bits/stdc++.h>

struct state {
  int v;
  int c;
  long long s;

  state() : v(), c(), s() {}
  
  state(int _v, int _c, long long _s) : v(_v), c(_c), s(_s) {}

  void add(int x) {
    int t = (x - 1) / v + 1;
    s += 1ll * c * (t - 1);
    v = x / t;
  }
};

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
  }
  std::vector<state> f;
  int ans = 0;
  for (int i = n - 1; i >= 0; --i) {
    for (auto &st : f) {
      st.add(a[i]);
    }
    f.emplace_back(a[i], 1, 0);
    std::vector<state> g;
    for (auto st : f) {
      if (g.empty() || g.back().v != st.v) {
        g.push_back(st);
      } else {
        g.back().c += st.c;
        g.back().s += st.s;
      }
    }
    f.swap(g);
    for (auto st : f) {
      ans = (ans + st.s) % 998244353;
    }
  }
  std::cout << ans << "\n";
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T;
  std::cin >> T;
  while (T--) {
    solve();
  }
}