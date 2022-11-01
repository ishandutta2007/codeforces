#include <bits/stdc++.h>

using namespace std;

int n, m, k;

int main() {
  cin >> n >> m >> k;
  if (n + k < m) {
    puts("0.0000000");
    return 0;
  }
  long double up = 1, down = 1;
  for (int i = 0; i <= k; ++i) up *= (m - i), down *= (n + 1 + i);
  long double ans = 1 - up / down;
  printf("%0.12f\n", (double) ans);
  return 0;
}