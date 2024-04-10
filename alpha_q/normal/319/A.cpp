#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

int n;
string s;
long long x;

int main() {
  cin >> s;
  n = s.size();
  for (int i = 0; i < n; ++i) {
    x <<= 1LL, x += s[i] - '0', x %= MOD;
  }
  for (int i = 1; i < n; ++i) {
    x <<= 1LL, x %= MOD;
  }
  printf("%lld\n", x);
  return 0;
}