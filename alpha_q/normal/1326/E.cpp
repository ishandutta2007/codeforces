#include <bits/stdc++.h>

using namespace std;

const int N = 300010;

int n, a[N], x, ans[N], rev[N], t[4 * N], lazy[4 * N];

inline void push (int u, int b, int e) {
  t[u] += lazy[u];
  if (b ^ e) lazy[u << 1] += lazy[u], lazy[u << 1 | 1] += lazy[u];
  lazy[u] = 0;
}

void update (int l, int r, int v, int u = 1, int b = 1, int e = n) {
  if (lazy[u]) push(u, b, e);
  if (b > r or e < l) return;
  if (b >= l and e <= r) {
    lazy[u] += v;
    return push(u, b, e);
  }
  int mid = b + e >> 1;
  update(l, r, v, u << 1, b, mid), update(l, r, v, u << 1 | 1, mid + 1, e);
  t[u] = max(t[u << 1], t[u << 1 | 1]);
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", a + i);
    rev[a[i]] = i;
  }
  int ans = n;
  update(1, rev[n], 1);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &x);
    while (t[1] <= 0) update(1, rev[--ans], 1);
    update(1, x, -1);
    printf("%d ", ans);
  }
  cout << '\n';
  return 0;
}