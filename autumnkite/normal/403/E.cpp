#include <bits/stdc++.h>

template<typename Val, 
         typename VV = std::plus<>>
class seg_tree {
public:
  typedef std::size_t size_type;

private:
  constexpr static size_type enlarge(size_type n) {
    size_type res = 1;
    while (res < n) {
      res <<= 1;
    }
    return res;
  }

protected:
  const size_type n, en;

  VV fun_vv;

  std::vector<Val> val;

  void up(size_type u) {
    val[u] = fun_vv(val[u << 1], val[u << 1 | 1]);
  }

  template<typename T>
  void build(size_type u, size_type l, size_type r, 
             const std::vector<T> &a) {
    if (l + 1 == r) {
      val[u] = Val(a[l]);
      return;
    }
    size_type mid = (l + r) >> 1;
    build(u << 1, l, mid, a);
    build(u << 1 | 1, mid, r, a);
    up(u);
  }

  void modify(size_type u, size_type l, size_type r, 
              size_type x, const Val &v) {
    if (l + 1 == r) {
      val[u] = v;
      return;
    }
    size_type mid = (l + r) >> 1;
    if (x < mid) {
      modify(u << 1, l, mid, x, v);
    } else {
      modify(u << 1 | 1, mid, r, x, v);
    }
    up(u);
  }

  Val query(size_type u, size_type l, size_type r, 
            size_type L, size_type R) const {
    if (L <= l && r <= R) {
      return val[u];
    }
    size_type mid = (l + r) >> 1;
    if (R <= mid) {
      return query(u << 1, l, mid, L, R);
    } else if (L >= mid) {
      return query(u << 1 | 1, mid, r, L, R);
    } else {
      return fun_vv(query(u << 1, l, mid, L, R), 
                    query(u << 1 | 1, mid, r, L, R));
    }
  }

public:
  seg_tree() : seg_tree(0) {}

  seg_tree(size_type _n)
  : n(_n), en(enlarge(n)), val(en << 1) {}

  template<typename T>
  seg_tree(const std::vector<T> &a)
  : n(a.size()), en(enlarge(n)), val(en << 1) {
    if (n) {
      build(1, 0, n, a);
    }
  }

  size_type size() const {
    return n;
  }

  void modify(size_type x, const Val &v) {
    modify(1, 0, n, x, v);
  }

  Val query(size_type l, size_type r) const {
    if (l < r) {
      return query(1, 0, n, l, r);
    } else {
      return Val();
    }
  }
};

const int INF = 0x3f3f3f3f;

struct node {
  std::pair<int, int> max;
  std::pair<int, int> min;

  node() : max(-INF, -1), min(INF, -1) {}
  
  node(const std::set<std::pair<int, int>> &S) : node() {
    if (!S.empty()) {
      max = *S.rbegin();
      min = *S.begin();
    }
  }

  node operator+(const node &rhs) const {
    node res;
    res.max = std::max(max, rhs.max);
    res.min = std::min(min, rhs.min);
    return res;
  }
};

class tree {
  int n;
  std::vector<int> fa;
  std::vector<std::vector<int>> E;
  int idx;
  std::vector<int> dfn, end;

  std::vector<std::set<std::pair<int, int>>> S;
  seg_tree<node> T;

  void dfs(int u) {
    dfn[u] = idx++;
    for (int v : E[u]) {
      dfs(v);
    }
    end[u] = idx;
  }

public:
  tree(std::vector<int> _fa)
      : n(_fa.size()), fa(_fa), E(n),
        idx(), dfn(n), end(n), S(n), T(n) {
    for (int i = 1; i < n; ++i) {
      E[fa[i]].push_back(i);
    }
    dfs(0);
  }

  void insert(int u, int v, int id) {
    S[dfn[u]].emplace(dfn[v], id);
    S[dfn[v]].emplace(dfn[u], id);
    T.modify(dfn[u], node(S[dfn[u]]));
    T.modify(dfn[v], node(S[dfn[v]]));
  }

  void erase(int u, int v, int id) {
    S[dfn[u]].erase(std::make_pair(dfn[v], id));
    S[dfn[v]].erase(std::make_pair(dfn[u], id));
    T.modify(dfn[u], node(S[dfn[u]]));
    T.modify(dfn[v], node(S[dfn[v]]));
  }

  int query(int u) {
    node tmp = T.query(dfn[u], end[u]);
    if (tmp.min.first < dfn[u]) {
      return tmp.min.second;
    } else if (tmp.max.first >= end[u]) {
      return tmp.max.second;
    } else {
      return -1;
    }
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n;
  std::cin >> n;
  std::vector<int> faA(n, -1), faB(n, -1);
  for (int i = 1; i < n; ++i) {
    std::cin >> faA[i];
    --faA[i];
  }
  for (int i = 1; i < n; ++i) {
    std::cin >> faB[i];
    --faB[i];
  }

  tree A(faA), B(faB);
  for (int i = 1; i < n; ++i) {
    A.insert(i, faB[i], i);
    B.insert(i, faA[i], i);
  }

  int s;
  std::cin >> s;
  std::vector<std::vector<int>> ans;
  ans.emplace_back(1, s);
  B.erase(s, faA[s], s);
  int now = 0;
  while (1) {
    now ^= 1;
    std::vector<int> id;
    if (now == 0) {
      for (int u : ans.back()) {
        for (int i = B.query(u); i != -1; i = B.query(u)) {
          B.erase(i, faA[i], i);
          id.push_back(i);
        }
      }
    } else {
      for (int u : ans.back()) {
        for (int i = A.query(u); i != -1; i = A.query(u)) {
          A.erase(i, faB[i], i);
          id.push_back(i);
        }
      }
    }
    if (id.empty()) {
      break;
    }
    std::sort(id.begin(), id.end());
    ans.emplace_back(id);
  }
  for (int i = 0; i < (int)ans.size(); ++i) {
    if (i & 1) {
      std::cout << "Red\n";
    } else {
      std::cout << "Blue\n";
    }
    for (int x : ans[i]) {
      std::cout << x << " ";
    }
    std::cout << "\n";
  }
}