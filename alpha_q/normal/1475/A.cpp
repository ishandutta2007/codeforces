#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int t; ll n;

int main() {
  cin >> t;
  while (t--) {
    scanf("%lld", &n);
    while (~n & 1) n >>= 1;
    puts(n == 1 ? "NO" : "YES");
  }
  return 0;
}