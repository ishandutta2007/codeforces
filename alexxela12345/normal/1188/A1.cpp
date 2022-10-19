#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
  int n;
  cin >> n;
  vector<int> cnt(n);
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    cnt[a - 1]++;
    cnt[b - 1]++;
  }
  for (int i = 0; i < n; i++) {
    if (cnt[i] == 2) {
      cout << "NO" << endl;
      return;
    }
  }
  cout << "YES" << endl;
}

signed main() {
  int t;
  t = 1;
  while (t--)
    solve();
}