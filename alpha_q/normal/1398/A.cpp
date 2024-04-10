#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int t, n, a[N];

int main() {
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
      scanf("%d", a + i);
    }
    if (a[1] + a[2] > a[n]) {
      puts("-1");
    } else {
      printf("1 2 %d\n", n);
    }
  }
  return 0;
}