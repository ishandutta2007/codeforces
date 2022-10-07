#include <bits/stdc++.h>

class fenwick_tree {
  int n;
  std::vector<long long> c;

  void add_one(int x, long long v) {
    for (++x; x <= n; x += x & -x) {
      c[x] += v;
    }
  }

public:
  fenwick_tree(int t_n) : n(t_n), c(n + 1) {}

  void add(int l, int r, long long v) {
    add_one(l, v);
    if (r < n) {
      add_one(r, -v);
    }
  }

  long long query(int x) {
    long long s = 0;
    for (++x; x; x ^= x & -x) {
      s += c[x];
    }
    return s;
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n, q;
  std::cin >> n >> q;
  
  std::vector<long long> tag(n);
  fenwick_tree T(n);
  std::map<int, int> col;
  col[0] = 0;
  while (q--) {
    std::string op;
    std::cin >> op;
    if (op == "Color") {
      int l, r, c;
      std::cin >> l >> r >> c;
      --l, --c;
      auto it = col.upper_bound(l);
      int lst = l, lstc = std::prev(it)->second;
      while (it != col.end() && it->first <= r) {
        T.add(lst, it->first, tag[lstc] - tag[c]);
        lst = it->first;
        lstc = it->second;
        it = col.erase(it);
      }
      T.add(lst, r, tag[lstc] - tag[c]);
      col[l] = c;
      col[r] = lstc;
    } else if (op == "Add") {
      int c, w;
      std::cin >> c >> w;
      --c;
      tag[c] += w;
    } else {
      int x;
      std::cin >> x;
      --x;
      int c = std::prev(col.upper_bound(x))->second;
      std::cout << T.query(x) + tag[c] << "\n";
    }
  }
}