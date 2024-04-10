#include <bits/stdc++.h>

using namespace std;

const int N = 1010;

int t, n;
long long x, a[N];

int main() {
//  freopen("in.txt", "r", stdin);
  cin >> t;
  while (t--) {
    cin >> n >> x;
    bool all = true, some = false;
    long long balance = 0;
    for (int i = 1; i <= n; ++i) {
      scanf("%lld", a + i);
      if (a[i] != x) all = false;
      if (a[i] == x) some = true;
      balance += a[i] - x;
    }
    if (all) {
      puts("0");
      continue;
    }
    if (!balance or some) {
      puts("1");
      continue;
    }
    puts("2");
  }
  return 0;
}