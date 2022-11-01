#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 200010;
const ll INF = 1e13 + 5;

int n, p[N];
ll s[N], t[4 * N], lz[4 * N];

void init (int u = 1, int b = 1, int e = n) {
  if (b == e) return void(t[u] = s[b]);
  int m = b + e >> 1;
  init(u + u, b, m), init(u + u + 1, m + 1, e);
  t[u] = min(t[u + u], t[u + u + 1]);
}

void push (int u, int b, int e) {
  t[u] += lz[u];
  if (b ^ e) {
    lz[u + u] += lz[u];
    lz[u + u + 1] += lz[u];
  }
  lz[u] = 0;
}

void update (int l, int r, ll v, int u = 1, int b = 1, int e = n) {
  if (lz[u] != 0) push(u, b, e);
  if (b > r or e < l) return;
  if (b >= l and e <= r) {
    lz[u] += v;
    return push(u, b, e);
  }
  int m = b + e >> 1;
  update(l, r, v, u + u, b, m);
  update(l, r, v, u + u + 1, m + 1, e);
  t[u] = min(t[u + u], t[u + u + 1]);
}

int query (int u = 1, int b = 1, int e = n) {
  if (lz[u] != 0) push(u, b, e);
  if (b == e) return b;
  int m = b + e >> 1;
  if (lz[u + u + 1]) push(u + u + 1, m + 1, e);
  if (t[u + u + 1] == 0) return query(u + u + 1, m + 1, e);
  return query(u + u, b, m);
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) scanf("%lld", s + i);
  init();
  for (int i = 1; i <= n; ++i) {
    int pos = query();
    p[pos] = i;
    update(pos + 1, n, -i);
    update(pos, pos, INF);
    // for (int i = 1; i <= n; ++i) printf("%d ", p[i]);
    // puts("");
  }
  for (int i = 1; i <= n; ++i) printf("%d ", p[i]);
  puts("");
  return 0;
}