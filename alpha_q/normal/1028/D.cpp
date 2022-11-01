#include <bits/stdc++.h>

using namespace std;

#pragma GCC diagnostic warning "-std=c++11"

const int MOD = 1e9 + 7;

int n;
char cmd[7];
long long p;
set <long long> s;
long long hiBuy = 0, loSell = 1e9 + 5;
long long ans = 1;
int cnt = 0;

int main() {
  scanf("%d", &n);
  s.insert(0), s.insert((long long) (1e9 + 5));
  for (int i = 1; i <= n; ++i) {
    scanf("%s %lld", cmd, &p);
    if (cmd[1] == 'D') {
      s.insert(p);
    } else {
      ++cnt;
      if (p > loSell or p < hiBuy) {
        puts("0");
        return 0;
      }
      if (p == loSell or p == hiBuy) {
        // 
      } else {
        ans *= 2LL, ans %= MOD;
      }
      auto it = s.find(p);
      if (it != s.begin()) {
        --it;
        hiBuy = *it;
        ++it;
      } else {
        hiBuy = 0;
      }
      if (it != (--s.end())) {
        ++it;
        loSell = *it;
        --it;
      } else {
        loSell = 1e9 + 5;
      }
      s.erase(p);
    }
  }
  long long tot = 0;
  for (long long x : s) {
    if (x > hiBuy and x < loSell) {
      ++tot;
    }
  }
  ans *= (tot + 1), ans %= MOD;
  cout << ans << '\n';
  return 0;
}


// buy............. ..............sell