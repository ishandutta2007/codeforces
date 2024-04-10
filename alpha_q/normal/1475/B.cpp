#include <bits/stdc++.h>

using namespace std;

const int N = 1000010;

int t, n;
bool f[N];

int main() {
  f[0] = 1;
  for (int i = 1; i < N; ++i) {
    if (i >= 2020 and f[i - 2020]) f[i] = 1;
    if (i >= 2021 and f[i - 2021]) f[i] = 1;
  }
  cin >> t;
  while (t--) {
    scanf("%d", &n);
    puts(f[n] ? "YES" : "NO");
  }
  return 0;
}