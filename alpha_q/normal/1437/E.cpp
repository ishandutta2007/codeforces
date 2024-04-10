#include <bits/stdc++.h>

using namespace std;

const int N = 500010;
const int INF = 1e8 + 69;

bitset <N> fix;
int n, k, a[N], id[N], t[N << 1], f[N], lastFixed[N];

void update (int p, int v) {
  for (t[p += n + 1] = v; p > 1; p >>= 1) {
    t[p >> 1] = min(t[p], t[p ^ 1]);
  }
}

int query (int l, int r) {
  int ret = INF;
  for (l += n + 1, r += n + 1; l < r; l >>= 1, r >>= 1) {
    if (l & 1) ret = min(ret, t[l++]);
    if (r & 1) ret = min(ret, t[--r]);
  }
  return ret;
}

int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", a + i);
    id[i] = i;
  }
  while (k--) {
    int x;
    scanf("%d", &x);
    fix[x] = 1;
  }
  for (int i = 1; i <= n; ++i) {
    lastFixed[i] = fix[i - 1] ? i - 1 : lastFixed[i - 1];
  }
  sort(id + 1, id + n + 1, [] (int i, int j) {
    return a[i] - i == a[j] - j ? i < j : a[i] - i < a[j] - j;
  });
  update(0, -1);
  for (int i = 1; i <= n; ++i) {
    update(i, INF);
  }
  for (int it = 1; it <= n; ++it) {
    int i = id[it], cur = query(lastFixed[i], i);
    f[i] = i + cur; update(i, cur - 1);
  }
  // for (int i = 1; i <= n; ++i) {
  //   cout << f[i] << " ";
  // }
  cout << '\n';
  int ans = f[n];
  if (!fix[n]) {
    for (int i = lastFixed[n]; i <= n; ++i) {
      ans = min(ans, f[i] + n - i);
    }
  }
  if (ans > INF / 2) ans = -1;
  cout << ans << '\n';
  return 0;
}