#include <bits/stdc++.h>

using namespace std;

#pragma GCC diagnostic warning "-std=c++11"

long long n;

int main() {
  cin >> n;
  int ans = 0;
  while ((1LL << ans) <= n) {
    ++ans;
  }
  cout << ans << endl;
  return 0;
}