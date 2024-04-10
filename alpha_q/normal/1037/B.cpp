#include <bits/stdc++.h>

using namespace std;

#pragma GCC diagnostic warning "-std=c++11"

typedef long long ll;

const int N = 200010;

int n, les, eq, mor; ll s, a[N];

int main() {
  scanf("%d %lld", &n, &s);
  for (int i = 1; i <= n; ++i) {
    scanf("%lld", a + i);
    if (a[i] == s) ++eq;
    if (a[i] < s) ++les;
    if (a[i] > s) ++mor;
  }
  sort(a + 1, a + n + 1);
  int k = n >> 1;
  if (a[k + 1] == s) {
    cout << "0\n";
    return 0;
  }
  ll ans = 0;
  if (les > k) {
    int last = 1;
    while (last < n and a[last + 1] < s) {
      ++last;
    }
    for (int i = last, j = les - k; i > 0 and j > 0; --i, --j) {
      ans += (s - a[i]);
    }
  } else {
    int last = n;
    while (last > 0 and a[last - 1] > s) {
      --last;
    }
    for (int i = last, j = mor - k; i <= n and j > 0; ++i, --j) {
      ans += (a[i] - s);
    }
  }
  cout << ans << '\n';
  return 0;
}