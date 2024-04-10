#include <bits/stdc++.h>

using namespace std;

const int N = 400010;

int n, a[N], zero[N], zr, one[N], on;

int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", a + i);
  }
  // int yo = 0;
  // for (int i = 1; i <= n; ++i) {
  //   for (int j = i + 1; j <= n; ++j) {
  //     yo ^= (a[i] + a[j]);
  //   }
  // }
  int ans = 0;
  for (int i = 1; i < 26; ++i) {
    int lo = 1 << (i - 1), hi = (1 << i) - 1;
    zr = on = 0;
    for (int j = 1; j <= n; ++j) {
      int cur = a[j] & ((1 << i) - 1);
      if (cur >= lo) one[on++] = (cur ^ lo);
      else zero[zr++] = cur;
    }
    sort(zero, zero + zr), sort(one, one + on);
    int tot = 0;
    for (int j = 1; j < zr; ++j) {
      tot += (zero + j - lower_bound(zero, zero + j, lo - zero[j]));
    }
    for (int j = 1; j < on; ++j) {
      tot += (one + j - lower_bound(one, one + j, lo - one[j]));
    }
    for (int j = 0; j < zr; ++j) {
      tot += (upper_bound(one, one + on, lo - zero[j] - 1) - one);
    }
    tot &= 1;
    if (tot) ans |= lo;
  }
  // cout << yo << " " << ans << endl;
  // assert(ans == yo);
  cout << ans << '\n';
  return 0;
}