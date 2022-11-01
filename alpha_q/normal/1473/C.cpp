#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int t, n, k, p[N];

int main() {
  cin >> t;
  while (t--) {
    cin >> n >> k;
    for (int i = 1; i <= k; ++i) p[i] = i;
    n -= k; int pos = k - n;
    for (int i = pos, j = k; i <= k; ++i, --j) {
      p[i] = j;
    }
    for (int i = 1; i <= k; ++i) printf("%d ", p[i]);
    puts("");
  }
  return 0;
}