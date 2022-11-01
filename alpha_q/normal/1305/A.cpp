#include <bits/stdc++.h>

using namespace std;

const int N = 1010;

int t, n, a[N], b[N];

int main() {
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 0; i < n; ++i) scanf("%d", a + i);
    for (int i = 0; i < n; ++i) scanf("%d", b + i);
    sort(a, a + n), sort(b, b + n);
    for (int i = 0; i < n; ++i) printf("%d ", a[i]); puts("");
    for (int i = 0; i < n; ++i) printf("%d ", b[i]); puts("");
  }
  return 0;
}