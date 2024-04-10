#include <bits/stdc++.h>

using namespace std;

int n, a[69];

int solve (int l, int r) {
  if (l + 1 == r) return 1;
  int good = 1;
  for (int i = l + 1; i < r; ++i) {
    good &= (a[i - 1] <= a[i]);
  }
  if (good) return r - l;
  int mid = l + r >> 1;
  return max(solve(l, mid), solve(mid, r));
}

int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> a[i];
  cout << solve(0, n) << endl;
  return 0;
}