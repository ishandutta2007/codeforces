#include <bits/stdc++.h>

using namespace std;

#pragma GCC diagnostic warning "-std=c++11"

typedef long long ll;

int t;
ll a, b;

bool isPrime (ll x) {
  if (x < 2) return 0;
  if (x == 2) return 1;
  if (x % 2 == 0) return 0;
  for (ll i = 3; i * i <= x; i += 2) {
    if (x % i == 0) return 0;
  }
  return 1;
}

int main() {
  cin >> t;
  while (t--) {
    cin >> a >> b;
    if (a - b > 1) {
      puts("NO");
      continue;
    }
    puts(isPrime(a + b) ? "YES" : "NO");
  } 
  return 0;
}