#include <bits/stdc++.h>
using namespace std;

bool prime(int k) {
  if (k == 1) return 0;
  for (int i = 2; i*i <= k; i++) {
    if (k%i == 0) return 0;
  }
  return 1;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    bool win = 1;
    if (__builtin_popcount(n) == 1 && n != 2) win = 0;
    if (n%2 == 0 && prime(n/2)) win = 0;
    cout << (win ? "Ashishgup" : "FastestFinger") << '\n';
  }
}