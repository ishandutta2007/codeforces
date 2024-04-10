#include <bits/stdc++.h>

using namespace std;

const int N = 200010;

int n, q, k, x;
vector <int> t[N + N];

int query (int l, int r, int d, int u) {
  int ret = 0;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l & 1) ret += (upper_bound(t[l].begin(), t[l].end(), u) - lower_bound(t[l].begin(), t[l].end(), d)), ++l;
    if (r & 1) --r, ret += (upper_bound(t[r].begin(), t[r].end(), u) - lower_bound(t[r].begin(), t[r].end(), d));
  }
  return ret;
}

inline long long comb (long long x) {
  return x * (x - 1) / 2;
}

int main() {
  scanf("%d %d", &n, &q);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &x);
    t[n + i].push_back(x);
  }
  for (int i = n - 1; i; --i) {
    merge(t[i << 1].begin(), t[i << 1].end(), t[i << 1 | 1].begin(), t[i << 1 | 1].end(), back_inserter(t[i]));
  }
  while (q--) {
    int l, d, r, u;
    scanf("%d %d %d %d", &l, &d, &r, &u);
    long long ans = comb(n) - comb(l - 1) - comb(n - r) - comb(d - 1) - comb(n - u);
    ans += comb(query(0, l - 1, 1, d - 1));
    ans += comb(query(r, n, 1, d - 1));
    ans += comb(query(0, l - 1, u + 1, n));
    ans += comb(query(r, n, u + 1, n));
    printf("%lld\n", ans);
  }
  return 0;
}