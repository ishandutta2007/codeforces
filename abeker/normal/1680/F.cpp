#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> pii;

const int MAXN = 1e6 + 5;

class UnionFind {
  int n, cnt_bad;
  vector <int> dad, rnk, clr, bad;
  stack <pair <int*, int>> changes;
public:
  UnionFind(int n) : n(n) {
    cnt_bad = 0;
    dad.resize(n);
    rnk.resize(n);
    clr.resize(n);
    bad.resize(n);
    iota(dad.begin(), dad.end(), 0);
  }
  UnionFind() {}
  pii find(int x) const {
    if (dad[x] == x)
      return {dad[x], 0};
    pii tmp = find(dad[x]);
    return {tmp.first, tmp.second ^ clr[x]};
  }
  void modify(int* ptr, int val) {
    changes.push({ptr, *ptr});
    *ptr = val;
  }
  void inc(int* ptr) {
    modify(ptr, *ptr + 1);
  }
  void revert(int sz) {
    for (; changes.size() > sz; changes.pop())
      *changes.top().first = changes.top().second;
  }
  int getSize() const {
    return changes.size();
  }
  void updateBad(int x, int val) {
    if (!bad[x] && val) {
      inc(bad.data() + x);
      inc(&cnt_bad);
    }
  }
  void join(int x, int y) {
    pii root_x = find(x);
    pii root_y = find(y);
    if (root_x.first == root_y.first) {
      updateBad(root_x.first, root_x.second == root_y.second);
      return;
    }
    if (rnk[root_x.first] > rnk[root_y.first])
      swap(root_x, root_y);
    modify(dad.data() + root_x.first, root_y.first);
    modify(clr.data() + root_x.first, root_x.second ^ root_y.second ^ 1);
    if (rnk[root_x.first] == rnk[root_y.first])
      inc(rnk.data() + root_y.first);
  }
  void getColours(vector <int> &c) const {
    if (cnt_bad)
      return;
    c.resize(n);
    for (int i = 0; i < n; i++)
      c[i] = find(i).second;
  }
};

class Tournament {
  int m, offset;
  vector <vector <pii>> tour;
  UnionFind dsu;
public:
  Tournament(int n, int m) : m(m) {
    dsu = UnionFind(n);
    for (offset = 1; offset < m; offset *= 2);
    tour.resize(2 * offset);
  }
  void update(int x, int lo, int hi, int from, int to, pii edge) {
    if (lo >= to || hi <= from)
      return;
    if (lo >= from && hi <= to) {
      tour[x].push_back(edge);
      return;
    }
    int mid = (lo + hi) / 2;
    update(2 * x, lo, mid, from, to, edge);
    update(2 * x + 1, mid, hi, from, to, edge);
  }
  void addEdge(int a, int b, int from, int to) {
    update(1, 0, offset, from, to, {a, b});
  }
  void dfs(int x, int &e, vector <int> &c) {
    if (!c.empty())
      return;
    int old = dsu.getSize();
    for (auto it : tour[x])
      dsu.join(it.first, it.second);
    if (x < offset) {
      dfs(2 * x, e, c);
      dfs(2 * x + 1, e, c);
    }
    else if (x < m + offset) {
      dsu.getColours(c);
      e = x - offset;
    }
    dsu.revert(old);
  }
};

int N, M;
int a[MAXN], b[MAXN];

void load() {
  scanf("%d%d", &N, &M);
  for (int i = 0; i < M; i++) {
    scanf("%d%d", a + i, b + i);
    a[i]--;
    b[i]--;
  }
}

void solve() {
  Tournament solver(N, M);
  for (int i = 0; i < M; i++) {
    solver.addEdge(a[i], b[i], 0, i);
    solver.addEdge(a[i], b[i], i + 1, M);
  }
  int which;
  vector <int> ans;
  solver.dfs(1, which, ans);
  if (ans.empty()) {
    puts("NO");
    return;
  }
  puts("YES");
  int flip = !ans[a[which]] && !ans[b[which]];
  for (auto it : ans)
    printf("%d", it ^ flip);
  puts("");
}

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    load();
    solve();
  }
  return 0;
}