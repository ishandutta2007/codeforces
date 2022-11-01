#include <bits/stdc++.h>

using namespace std;

#pragma GCC diagnostic warning "-std=c++11"

const int LG = 20;
const int N = 400010;

vector <int> g[N];
int n, q, p[N], euler[N + N];
int h[N], in[N], spt[LG][N], lg[N + N];
int ptr, t[N + N], best[N + N], at[N + N];
int st[N + N], top, lt[N + N], rt[N + N], out[N + N];

void go (int u = 1, int far = 0) {
  h[u] = far;
  euler[++ptr] = u;
  in[u] = ptr;
  for (int v : g[u]) {
    go(v, far + 1);
    euler[++ptr] = u;
  }
}

inline int lca (int u, int v) {
  if (u == -1) return v;
  if (v == -1) return u;
  int l = in[u], r = in[v];
  if (l > r) swap(l, r);
  int len = r - l + 1;
  // cout << "# " << len << " " << lg[len] << endl;
  int one = spt[lg[len]][l];
  int two = spt[lg[len]][r - (1 << lg[len]) + 1];
  return h[one] < h[two] ? one : two;
}

void init (int u = 1, int b = 1, int e = n) {
  lt[u] = b, rt[u] = e;
  if (b == e) {
    t[u] = b;
    return;
  }
  int mid = b + e >> 1;
  init(u + u, b, mid);
  init(u + u + 1, mid + 1, e);
  t[u] = lca(t[u + u], t[u + u + 1]);
}

inline int merge (int one, int two) {
  if (one == -1) return two;
  if (two == -1) return one;
  return lca(one, two);
}

int query (int l, int r, int flag = 0, int u = 1, int b = 1, int e = n) {
  // cout << "yo\n";
  if (l > r or b > r or e < l) return -1;
  if (b >= l and e <= r) {
    if (flag) st[++top] = u;
    return t[u];
  }
  int mid = b + e >> 1;
  int one = query(l, r, flag, u + u, b, mid);
  int two = query(l, r, flag, u + u + 1, mid + 1, e);
  return merge(one, two);
}

void dfs (int u = 1, int b = 1, int e = n) {
  best[u] = at[u] = -1, out[u] = b;
  if (b == e) return;
  for (int i = b; i <= e; ++i) {
    // cout << "started\n";
    int rest = merge(query(b, i - 1), query(i + 1, e));
    // cout << "ended\n";
    // cout << rest << endl;
    if (rest == -1) continue;
    if (h[rest] > best[u]) {
      best[u] = h[rest];
      out[u] = i, at[u] = rest;
    }
  }
  int mid = b + e >> 1;
  dfs(u + u, b, mid);
  dfs(u + u + 1, mid + 1, e);
}

int main() {
  for (int i = 2; i < N + N; ++i) {
    lg[i] = lg[i >> 1] + 1;
  }
  scanf("%d %d", &n, &q);
  for (int i = 2; i <= n; ++i) {
    scanf("%d", p + i);
    g[p[i]].push_back(i);
  }
  go();
  assert(ptr == n + n - 1);
  for (int i = 1; i <= ptr; ++i) {
    // cout << i << " ---> " << euler[i] << " " << h[euler[i]] << endl;
    spt[0][i] = euler[i];
  }
  // cout << endl;
  for (int j = 1; j < LG; ++j) {
    for (int i = 1; i <= ptr; ++i) {
      int one = spt[j - 1][i];
      int nxt = i + (1 << (j - 1));
      int two = (nxt <= ptr ? spt[j - 1][nxt] : one);
      spt[j][i] = (h[one] < h[two] ? one : two);
    }
  }
  // cout << "6969696\n";
  init();
  // cout << "6969696\n";
  dfs();
  // cout << "----------------\n";
  while (q--) {
    int l, r;
    scanf("%d %d", &l, &r);
    top = 0;
    int cur = query(l, r, 1);
    int dep = h[cur];
    int mx = -1, emp = -1;
    // for (int i = 1; i <= top; ++i) {
    //   int u = st[i];
    //   cout << st[i] << " " << lt[st[i]] << " " << rt[st[i]] << endl;
    //   cout << best[u] << " " << out[u] << " " << at[u] << endl;
    // }
    for (int i = 1; i <= top; ++i) {
      int u = st[i];
      int ltt = lt[u], rtt = rt[u];
      int one = query(l, ltt - 1);
      int two = query(rtt + 1, r);
      // cout << one << " " << two << endl;
      int now = lca(merge(one, two), at[u]);
      if (h[now] > mx) {
        mx = h[now], emp = out[u];
      }
      if (ltt + 1 == rtt) {
        now = lca(merge(one, two), out[u]);
        if (h[now] > mx) {
          mx = h[now], emp = at[u];
        }  
      }
    }
    assert(emp != -1);
    assert(mx >= 0);
    printf("%d %d\n", emp, mx);
  }
  return 0;
}