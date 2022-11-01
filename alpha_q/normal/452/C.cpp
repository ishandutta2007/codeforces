#include <bits/stdc++.h>

using namespace std;

long double n, m;

int main() {
  cin >> n >> m;
  if (n == 1 and m == 1) {
    puts("1");
    return 0;
  }
  long double ans = (n * m - 1 + (n - 1) * (m - 1)) / (n * (n * m - 1));
  printf("%0.16f\n", (double) ans);
  return 0;
}

// [nm-1 + (n-1)(m-1)]/n(mn-1)

// (2 * n * m - n - m) / (n * (n * m - 1))