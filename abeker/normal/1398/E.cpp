#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 2e5 + 5;

struct Node {
  int alive;
  ll sum;
  Node(int alive, ll sum) : alive(alive), sum(sum) {}
  Node() : alive(0), sum(0) {}
};

class Tournament {
  int offset;
  vector <Node> t;
  Node merge(Node lft, Node rig) const {
    return Node(lft.alive + rig.alive, lft.sum + rig.sum);
  }
public:
  Tournament(int n) {
    for (offset = 1; offset < n; offset *= 2);
    t.resize(2 * offset);
  }
  Tournament() {}
  void update(int x, int val) {
    x += offset;
    t[x] = val > 0 ? Node(1, val) : Node(0, 0);
    for (x /= 2; x; x /= 2)
      t[x] = merge(t[2 * x], t[2 * x + 1]);
  }
  int getKth(int x, int k) const {
    if (x >= offset)
      return x - offset;
    if (k <= t[2 * x].alive)
      return getKth(2 * x, k);
    return getKth(2 * x + 1, k - t[2 * x].alive);
  }
  ll getSum(int x, int k) const {
    if (x >= offset) 
      return k * t[x].sum;
    if (k <= t[2 * x].alive)
      return getSum(2 * x, k);
    return t[2 * x].sum + getSum(2 * x + 1, k - t[2 * x].alive);
  }
  int getTotal() const {
    return t[1].alive;
  }
};

int N;
Tournament counter[2];
int type[MAXN], damage[MAXN];
vector <int> vals[2];

void load() {
  scanf("%d", &N);
  for (int i = 0; i < N; i++)
    scanf("%d%d", type + i, damage + i);
}

int compress(int tp, int val) {
  return lower_bound(vals[tp].begin(), vals[tp].end(), val) - vals[tp].begin();
}

int get_pos(int tp, int x) {
  return tp ? x : (int)vals[tp].size() - x - 1;
}

ll query() {
  ll res = 0;
  vector <int> sz(2);
  for (int i = 0; i < 2; i++) {
    sz[i] = counter[i].getTotal();
    res += (i + 1) * counter[i].getSum(1, sz[i]);
  }
  if (!sz[1])
    return res;
  int lo = 1, hi = *min_element(sz.begin(), sz.end());
  while (lo < hi) {
    int mid = (lo + hi + 1) / 2;
    if (vals[0][get_pos(0, counter[0].getKth(1, mid))] > vals[1][get_pos(1, counter[1].getKth(1, mid))])
      lo = mid;
    else
      hi = mid - 1;
  }
  return res + counter[0].getSum(1, lo) - counter[1].getSum(1, lo);
}

void solve() {
  for (int i = 0; i < N; i++)
    vals[type[i]].push_back(abs(damage[i]));
  for (int i = 0; i < 2; i++) {
    sort(vals[i].begin(), vals[i].end());
    vals[i].resize(unique(vals[i].begin(), vals[i].end()) - vals[i].begin());
    counter[i] = Tournament(vals[i].size());
  }
  
  for (int i = 0; i < N; i++) {
    int idx = compress(type[i], abs(damage[i]));
    counter[type[i]].update(get_pos(type[i], idx), damage[i]);
    printf("%lld\n", query());
  }
}

int main() {
  load();
  solve();
  return 0;
}