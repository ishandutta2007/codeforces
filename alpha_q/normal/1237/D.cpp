#include <bits/stdc++.h>

using namespace std;

const int N = 400010;

int n, a[N], t[N + N], id[N], ans[N];

int get (int l, int r) {
  int ret = INT_MAX;
  for (l += n + n, r += n + n; l < r; l >>= 1, r >>= 1) {
    if (l & 1) ret = min(ret, t[l++]);
    if (r & 1) ret = min(ret, t[--r]);
  }
  return ret;
}

int main() {
  cin >> n;
  int mn = INT_MAX, mx = INT_MIN;
  for (int i = 0; i < n; ++i) {
    scanf("%d", a + i);
    a[n + i] = a[i], id[i] = i;
    mn = min(mn, a[i]);
    mx = max(mx, a[i]);
  }
  if (mn + mn >= mx) {
    for (int i = 1; i <= n; ++i) printf("-1 ");
    puts(""); return 0;
  }
  sort(id, id + n, [] (int i, int j) {return a[i] > a[j];});
  for (int i = 0; i < n + n; ++i) {
    t[n + n + i] = a[i];
  }
  for (int i = n + n - 1; i; --i) {
    t[i] = min(t[i << 1], t[i << 1 | 1]);
  }
  set <int> st;
  for (int it = 0; it < n; ++it) {
    int i = id[it];
    ans[i] = INT_MAX;
    if (mn + mn < a[i]) {
      int lo = i, hi = n + i - 1;
      while (lo < hi) {
        int mid = lo + hi >> 1;
        int cur = get(lo, mid + 1);
        if (cur + cur < a[i]) hi = mid;
        else lo = mid + 1;
      }
      ans[i] = lo - i;
    }
    if (!st.empty()) {
      int x = *st.lower_bound(i);
      ans[i] = min(ans[i], ans[x] + x - i);
    }
    ans[n + i] = ans[i];
    st.emplace(i); st.emplace(n + i);
  }
  for (int i = 0; i < n; ++i) printf("%d ", ans[i]); puts("");
  return 0;
}