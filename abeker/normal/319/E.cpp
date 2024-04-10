#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> pii;

const int MAXN = 1e5 + 5;

class UnionFind {
  vector <int> dad, rnk;
  vector <int> lft, rig;
public:
  UnionFind(const vector <pii> &segments) {
    int n = segments.size();
    dad.resize(n);
    rnk.resize(n);
    lft.resize(n);
    rig.resize(n);
    iota(dad.begin(), dad.end(), 0);
    for (int i = 0; i < n; i++) {
      lft[i] = segments[i].first;
      rig[i] = segments[i].second;
    }
  }
  int find(int x) {
    return dad[x] == x ? x : dad[x] = find(dad[x]);
  }
  void join(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y)
      return;
    if (rnk[x] > rnk[y])
      swap(x, y);
    dad[x] = y;
    rnk[y] += rnk[x] == rnk[y];
    lft[y] = min(lft[y], lft[x]);
    rig[y] = max(rig[y], rig[x]);
  }
  pii getUnion(int x) {
    x = find(x);
    return {lft[x], rig[x]};
  }
};

class Tournament {
  int offset;
  vector <unordered_set <int>> active;
public:
  Tournament(int n) {
    for (offset = 1; offset < n; offset *= 2);
    active.resize(2 * offset);
  }
  void update(int x, int lo, int hi, int from, int to, int val, bool remove) {
    if (lo >= to || hi <= from)
      return;
    if (lo >= from && hi <= to) {
      if (remove)
        active[x].erase(val);
      else
        active[x].insert(val);
      return;
    }
    int mid = (lo + hi) / 2;
    update(2 * x, lo, mid, from, to, val, remove);
    update(2 * x + 1, mid, hi, from, to, val, remove);
  }
  void read(int pos, vector <int> &v) const { 
    for (pos += offset; pos; pos /= 2) 
      for (auto it : active[pos])
        v.push_back(it);
  }
  void insert(pii segment, int val) {
    update(1, 0, offset, segment.first + 1, segment.second, val, false);
  }
  void remove(pii segment, int val) {
    update(1, 0, offset, segment.first + 1, segment.second, val, true);
  }
};

int N;
int w[MAXN], a[MAXN], b[MAXN];

void load() {
  scanf("%d", &N);
  for (int i = 0; i < N; i++)
    scanf("%d%d%d", w + i, a + i, b + i);
}

void solve() {
  vector <int> all;
  for (int i = 0; i < N; i++)
    if (w[i] == 1) {
      all.push_back(a[i]);
      all.push_back(b[i]);
    }
  sort(all.begin(), all.end());
  all.resize(unique(all.begin(), all.end()) - all.begin());
  auto compress = [&](int &val) {
    val = lower_bound(all.begin(), all.end(), val) - all.begin();
  };
  vector <pii> intervals;
  for (int i = 0; i < N; i++) 
    if (w[i] == 1) {
      compress(a[i]);
      compress(b[i]);
      intervals.push_back({a[i], b[i]});
    }
  int curr = 0;
  UnionFind dsu(intervals);
  Tournament tree(all.size());
  for (int i = 0; i < N; i++) 
    if (w[i] == 1) {
      vector <int> todo;
      tree.read(a[i], todo);
      tree.read(b[i], todo);
      for (auto it : todo) 
        tree.remove(dsu.getUnion(it), it);
      for (auto it : todo)
        dsu.join(it, curr);
      tree.insert(dsu.getUnion(curr), dsu.find(curr));
      curr++;
    }
    else {
      a[i]--;
      b[i]--;
      pii tmp = dsu.getUnion(b[i]);
      puts(tmp.second <= intervals[a[i]].first || tmp.first >= intervals[a[i]].second || 
          (tmp.first >= intervals[a[i]].first && tmp.second <= intervals[a[i]].second) ? "NO" : "YES");
    }
}

int main() {
  load();
  solve();
  return 0;
}