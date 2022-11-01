#include <bits/stdc++.h>

using namespace std;

const int N = 55;

int n, a[N];

int main() {
  cin >> n;
  int mn = 6969, cnt = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    mn = min(mn, a[i]);
  }
  for (int i = 1; i <= n; ++i) {
    if (a[i] == mn) ++cnt;
  }
  if (cnt <= n / 2) {
    puts("Alice");
  } else {
    puts("Bob");
  }
  return 0;
}

// 2 2 2 2 | 2 2 2 6