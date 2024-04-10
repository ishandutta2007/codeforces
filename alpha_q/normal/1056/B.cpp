#include <bits/stdc++.h>

using namespace std;

#pragma GCC diagnostic warning "-std=c++11"

int n, m;
long long ans;

inline long long get (int rem) {
  if (n < rem) return 0;
  long long two = (n - rem) / m;
  long long one = (max(0LL, 1LL - rem) + m - 1) / m;
  return max(0LL, two - one + 1LL);
}

void brute() {
  long long res = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      if ((i * 1LL * i + j * 1LL * j) % m == 0) {
        ++res;
      }
    }
  }
  cout << res << '\n';
}

int main() {
  cin >> n >> m;
  // brute();
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < m; ++j) {
      int yo = (i * i + j * j) % m;
      if (yo) continue;
      ans += get(i) * 1LL * get(j);
    }
  }
  cout << ans << '\n';
  return 0;
}