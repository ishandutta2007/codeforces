#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3e5 + 5;
const int MAXV = 1e6 + 5;
const int offset = 1 << 20;

struct Node {
  int maks, pos, lazy;
};

struct Query {
  int l, r, v;
};

int N, K, Q;
stack <Query> todo;
Node tour[2 * offset];
int p[MAXN], a[MAXN], s[MAXN];
int lft[MAXN], rig[MAXN];
int lb[MAXN], ub[MAXN];
vector <int> ch[MAXN];
vector <int> q[MAXV];

void load() {
  scanf("%d%d", &N, &Q);
  p[0] = p[N + 1] = MAXV;
  for (int i = 1; i <= N; i++)
    scanf("%d", p + i);
  for (int i = 1; i <= N; i++)
    scanf("%d", a + i);
  K = count(a + 1, a + N + 1, 0);
  for (int i = 1; i < K; i++)
    scanf("%d", s + i);
}

Node merge(Node lhs, Node rhs) {
  return {max(lhs.maks, rhs.maks), lhs.maks > rhs.maks ? lhs.pos : rhs.pos, 0};
}

void prop(int x) {
  tour[x].maks += tour[x].lazy;
  if (x < offset) {
    tour[2 * x].lazy += tour[x].lazy;
    tour[2 * x + 1].lazy += tour[x].lazy;
  }
  tour[x].lazy = 0;
}

void refresh(int x) {
  tour[x] = merge(tour[2 * x], tour[2 * x + 1]);
}

void update(int x, int lo, int hi, int from, int to, int val) {
  prop(x);
  if (lo >= to || hi <= from)
    return;
  if (lo >= from && hi <= to) {
    tour[x].lazy += val;
    prop(x);
    return;
  }
  int mid = (lo + hi) / 2;
  update(2 * x, lo, mid, from, to, val);
  update(2 * x + 1, mid, hi, from, to, val);
  refresh(x);
}

void update(int from, int to, int val) {
  update(1, 0, offset, from, to, val);
}

void modify(int x) {
  int to, val;
  if (x < 0) {
    to = -x + 1;
    val = -1;
  }
  else {
    to = x + 1;
    val = 1;
  }
  update(0, to, val);
  todo.push({0, to, -val});
}

void revert() {
  for (; !todo.empty(); todo.pop())
    update(todo.top().l, todo.top().r, todo.top().v);
}

Node query() {
  prop(1);
  return tour[1];
}

void dfs_min(int x) {
  for (auto it : ch[x]) {
    ub[it] = min(ub[it], ub[x] - 1);
    dfs_min(it);
  }
}

void dfs_max(int x) {
  for (auto it : ch[x]) {
    dfs_max(it);
    lb[x] = max(lb[x], lb[it] + 1);
  }
}

void solve() {
  stack <int> mono;
  mono.push(0);
  for (int i = 1; i <= N; i++) {
    while (p[mono.top()] < p[i])
      mono.pop();
    lft[i] = mono.top();
    mono.push(i);
  }
  mono = stack <int> ();
  mono.push(N + 1);
  for (int i = N; i; i--) {
    while (p[mono.top()] < p[i])
      mono.pop();
    rig[i] = mono.top();
    mono.push(i);
  }
  for (int i = 0; i <= N; i++) {
    lb[i] = 0;
    ub[i] = MAXV - 1;
    if (a[i])
      lb[i] = ub[i] = a[i];
    ch[i].clear();
  }
  for (int i = 1; i <= N; i++)
    ch[p[lft[i]] > p[rig[i]] ? rig[i] : lft[i]].push_back(i);
  dfs_min(0);
  dfs_max(0);
  bool ok = true;
  vector <int> all;
  for (int i = 1; i <= N; i++) {
    ok &= lb[i] <= ub[i];
    if (!a[i]) {
      q[ub[i]].push_back(lb[i]);
      all.push_back(ub[i]);
    }
  }
  for (int i = 1; i < K; i++) {
    q[s[i]].push_back(-s[i]);
    all.push_back(s[i]);
  }
  sort(all.begin(), all.end());
  all.resize(unique(all.begin(), all.end()) - all.begin());
  int lo = 0, hi = MAXV;
  for (auto it : all) {
    for (; !q[it].empty(); q[it].pop_back())
      modify(q[it].back());
    Node tmp = query();
    ok &= tmp.maks <= 1;
    if (tmp.maks == 1) {
      lo = max(lo, tmp.pos);
      hi = min(hi, it);
    }
  }
  revert();
  while (Q--) {
    int d;
    scanf("%d", &d);
    puts(ok && d >= lo && d <= hi ? "YES" : "NO");
  }
}

void init() {
  for (int i = 0; i < offset; i++)
    tour[i + offset] = {0, i, 0};
  for (int i = offset - 1; i; i--)
    refresh(i);
}

int main() {
  init();
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    load();
    solve();
  }
  return 0;
}