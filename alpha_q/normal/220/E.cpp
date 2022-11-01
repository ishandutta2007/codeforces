#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

int n, a[N];
long long k;
vector <int> t[N + N];

int big (int l, int r, int x) {
  int ret = 0;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l & 1) {
      ret += (int) t[l].size() - (upper_bound(t[l].begin(), t[l].end(), x) - t[l].begin());
      ++l;
    }
    if (r & 1) {
      --r;
      ret += (int) t[r].size() - (upper_bound(t[r].begin(), t[r].end(), x) - t[r].begin());
    }
  }
  return ret;
}

int small (int l, int r, int x) {
  int ret = 0;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l & 1) {
      ret += lower_bound(t[l].begin(), t[l].end(), x) - t[l].begin();
      ++l;
    }
    if (r & 1) {
      --r;
      ret += lower_bound(t[r].begin(), t[r].end(), x) - t[r].begin();
    }
  }
  return ret;
}

int main() {
  scanf("%d %lld", &n, &k);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a + i);
    t[n + i].push_back(a[i]);
  }
  for (int i = n - 1; i; --i) {
    merge(t[i << 1].begin(), t[i << 1].end(), t[i << 1 | 1].begin(), t[i << 1 | 1].end(), back_inserter(t[i]));
  }
  long long curr = 0;
  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    curr += (long long) big(0, i, a[i]);
  }
  for (int i = 1, j = 1; i < n; ++i) {
    while (j < n - 1 and curr > k) {
      long long out = (long long) (big(0, i, a[j]) + small(j, n, a[j]));
      curr -= out, ++j;
    }
    if (curr <= k) {
      ans += (long long) (n - j);
    }
    if (i == j) {
      ++j;
    } else {
      long long add = (long long) (big(0, i, a[i]) + small(j, n, a[i]));
      curr += add;
    }
  }
  printf("%lld\n", ans);
  return 0;
}