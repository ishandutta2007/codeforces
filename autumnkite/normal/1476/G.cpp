#include <bits/stdc++.h>

struct update {
  int p, f, t;

  update(int p, int f, int t) : p(p), f(f), t(t) {}
};

struct query {
  int t, l, r, k, bt, bl, id;

  query(int t, int l, int r, int k, int bt, int bl, int id)
  : t(t), l(l), r(r), k(k), bt(bt), bl(bl), id(id) {}

  bool operator<(const query &rhs) const {
    if (bt != rhs.bt) {
      return bt < rhs.bt;
    }
    if (bl != rhs.bl) {
      return bt & 1 ? (bl > rhs.bl) : (bl < rhs.bl);
    }
    return bl & 1 ? (r > rhs.r) : (r < rhs.r);
  }
};

class state {
  std::vector<int> cnt;
  std::vector<int> res;
  std::vector<int> pos;

public:
  state(int n, int m) : cnt(m), res(m), pos(n + 1, m) {
    pos[0] = 0;
  }

  void insert(int x) {
    int c = ++cnt[x];
    res[--pos[c]] = cnt[x];
  }

  void erase(int x) {
    int c = cnt[x]--;
    res[pos[c]++] = cnt[x];
  }

  int get_ans(int k) const {
    static const int INF = std::numeric_limits<int>::max();
    int ans = INF;
    for (int i = pos[1]; i + k <= (int)res.size(); i = pos[res[i] + 1]) {
      ans = std::min(ans, res[i + k - 1] - res[i]);
    }
    if (ans == INF) {
      return -1;
    } else {
      return ans;
    }
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n, q;
  std::cin >> n >> q;
  int m = 0;
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
    m = std::max(m, a[i]);
    --a[i];
  }

  const int B = pow(n, 2.0 / 3);

  auto tmp(a);
  std::vector<update> M;
  std::vector<query> Q;
  for (int i = 0; i < q; ++i) {
    int op;
    std::cin >> op;
    if (op == 1) {
      int l, r, k;
      std::cin >> l >> r >> k;
      --l, --r;
      Q.emplace_back(M.size(), l, r, k, M.size() / B, l / B, Q.size());
    } else {
      int p, v;
      std::cin >> p >> v;
      m = std::max(m, v);
      --p, --v;
      M.emplace_back(p, tmp[p], v);
      tmp[p] = v;
    }
  }

  std::sort(Q.begin(), Q.end());
  std::vector<int> ans(Q.size());
  int t = 0, l = 0, r = -1;
  state st(n, m);
  for (int i = 0; i < (int)Q.size(); ++i) {
    while (r < Q[i].r) {
      st.insert(a[++r]);
    }
    while (l > Q[i].l) {
      st.insert(a[--l]);
    }
    while (r > Q[i].r) {
      st.erase(a[r--]);
    }
    while (l < Q[i].l) {
      st.erase(a[l++]);
    }
    while (t < Q[i].t) {
      if (l <= M[t].p && M[t].p <= r) {
        st.erase(M[t].f);
        st.insert(M[t].t);
      }
      a[M[t].p] = M[t].t;
      ++t;
    }
    while (t > Q[i].t) {
      --t;
      a[M[t].p] = M[t].f;
      if (l <= M[t].p && M[t].p <= r) {
        st.erase(M[t].t);
        st.insert(M[t].f);
      }
    }
    ans[Q[i].id] = st.get_ans(Q[i].k);
  }
  for (int x : ans) {
    std::cout << x << "\n";
  }
}