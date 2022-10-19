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
  int n;
  cin >> n;
  vector<string> arr(n);
  map<string, int> m;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    m[arr[i]]++;
  }
  int mx = 0;
  for (auto &el : m) {
    mx = max(mx, el.second);
  }
  cout << mx << endl;
}

signed main() {
  int t;
  t = 1;
  while (t--)
    solve();
}