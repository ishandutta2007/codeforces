#include <bits/stdc++.h>
using namespace std;

#define int long long

int gcd(int a, int b) {
  while (a) {
    b %= a;
    swap(a, b);
  }
  return b;
}

void solve() {
  int n, k;
  cin >> n >> k;
  n++;
  int cur = 1;
  for (int i = 1; i <= k && i < 100; i++) {
    cur = cur / gcd(cur, i) * i;
  }
  if (n % cur == 0) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}

signed main() {
  int t;
  t = 1;
  while (t--)
    solve();
}