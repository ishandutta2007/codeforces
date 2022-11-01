#include <bits/stdc++.h>

using namespace std;

const int N = 200010;

int n, k, a[N];
bitset <N> good;

bool ok (int x) {
  for (int i = 1; i <= n; ++i) {
    if (a[i] <= x) good[i] = 1;
    else good[i] = 0;
  }
  if (k & 1) {
    int od = 0, ev = 0;
    for (int i = 1; i <= n; ++i) {
      if (good[i]) ++od, ++i;
    }
    for (int i = 2; i < n; ++i) {
      if (good[i]) ++ev, ++i;
    }
    return od > (k >> 1) or ev >= (k >> 1);
  }
  int od = 0, ev = 0;
  for (int i = 1; i < n; ++i) {
    if (good[i]) ++od, ++i;
  }
  for (int i = 2; i <= n; ++i) {
    if (good[i]) ++ev, ++i;
  }
  return od >= (k >> 1) or ev >= (k >> 1);
}

int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", a + i);
  }
  int lo = 0, hi = 1 << 30;
  while (lo < hi) {
    int mid = lo + hi >> 1;
    if (ok(mid)) hi = mid;
    else lo = mid + 1;
  }
  cout << lo << '\n';
  return 0;
}