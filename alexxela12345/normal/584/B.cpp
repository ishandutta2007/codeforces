#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
  int n;
  cin >> n;
  long long a1 = 1, a2 = 1;
  for (int i = 0; i < n; i++) {
    a1 *= 27;
    a2 *= 7;
    a1 %= MOD;
    a2 %= MOD;
  }
  cout << (a1 - a2 + MOD) % MOD << endl;
}