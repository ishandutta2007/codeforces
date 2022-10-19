#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

const int MAXN = 2e5 + 5;
const int MAXQ = 1e6 + 5;

class Fenwick {
  int n;
  vector <ll> fen;
public:
  Fenwick(int n) : n(n) {
    fen.resize(n + 1);
  }
  Fenwick() {}
  void update(int x, ll val) {
    for (; x <= n; x += x & -x)
      fen[x] += val;
  }
  void update(int x, int y, ll val) {
    update(x, val);
    update(y + 1, -val);
  }
  ll get(int x) const {
    ll res = 0;
    for (; x; x -= x & -x)
      res += fen[x];
    return res;
  }
};

class Solver {
  int n;
  Fenwick A, B;
public:
  Solver(int n) : n(n) {
    A = B = Fenwick(n);
  }
  void update(int from, int to, int val) {
    A.update(from, to, val);
    B.update(from, to, (ll)(1 - from) * val);
    B.update(to + 1, n, (ll)(to - from + 1) * val);
  }
  ll get(int x) const {
    return A.get(x) * x + B.get(x);
  }
  ll query(int from, int to) const {
    return get(to) - get(from - 1);
  } 
};

int N, Q;
int l[MAXQ], r[MAXQ];
int p[MAXN], inv[MAXN];
int lft[MAXN], rig[MAXN];
vector <pii> in_rect[MAXN], out_rect[MAXN];
vector <int> in_query[MAXN], out_query[MAXN];
vector <pii> rect[MAXN];
ll ans[MAXQ];

void load() {
  scanf("%d%d", &N, &Q);
  for (int i = 1; i <= N; i++) {
    scanf("%d", p + i);
    inv[p[i]] = i;
  }
  for (int i = 0; i < Q; i++)
    scanf("%d%d", l + i, r + i);
}

void add_rectangle(int x1, int x2, int y1, int y2) {
  in_rect[x1].push_back({y1, y2});
  out_rect[x2].push_back({y1, y2});
}

void process_triple(int a, int b, int c) {
  if (b >= c)
    return;
  int lo = min({a, b, c});
  int hi = max({a, b, c});
  if (lo > lft[a] && hi < rig[a])
    rect[a].push_back({hi, lo});
}

void solve() {
  for (int i = 0; i < Q; i++) {
    in_query[l[i]].push_back(i);
    out_query[r[i]].push_back(i);
  }
  stack <int> s;
  for (int i = 1; i <= N; i++) {
    while (!s.empty() && p[s.top()] < p[i])
      s.pop();
    lft[i] = s.empty() ? 0 : s.top();
    s.push(i);
  }
  s = stack <int> ();
  for (int i = N; i; i--) {
    while (!s.empty() && p[s.top()] < p[i])
      s.pop();
    rig[i] = s.empty() ? N + 1 : s.top();
    s.push(i);
  }
  for (int i = 1; i <= N; i++)
    for (int j = i; j <= N; j += i)
      process_triple(inv[j], inv[i], inv[j / i]);
  for (int i = 1; i <= N; i++) {
    int maks = 0;
    sort(rect[i].begin(), rect[i].end());
    rect[i].push_back({rig[i], 0});
    for (int j = 0; j < (int)rect[i].size() - 1; j++) {
      maks = max(maks, rect[i][j].second);
      add_rectangle(lft[i] + 1, maks, rect[i][j].first, rect[i][j + 1].first - 1);
    }
  }
  Solver A(N), B(N);
  for (int i = 1; i <= N; i++) {
    auto calc = [&](int from, int to, int val) -> ll {
      return (ll)A.query(from, to) * val + B.query(from, to);
    };
    for (auto it : in_query[i])
      ans[it] -= calc(l[it], r[it], i - 1);
    for (auto it : in_rect[i]) {
      A.update(it.first, it.second, 1);
      B.update(it.first, it.second, 1 - i);
    }
    for (auto it : out_rect[i]) {
      A.update(it.first, it.second, -1);
      B.update(it.first, it.second, i);
    }
    for (auto it : out_query[i])
      ans[it] += calc(l[it], r[it], i);
  }
  for (int i = 0; i < Q; i++)
    printf("%lld\n", ans[i]);
}

int main() {
  load();
  solve();
  return 0;
}