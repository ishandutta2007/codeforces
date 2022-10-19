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
  string s;
  cin >> s;
  int n = s.size();
  vector<int> cnt(n);
  for (int i = 0; i < n - 4; i++) {
    if (s.substr(i, 5) == "metal") {
      cnt[i]++;
    }
  }
  for (int i = n - 2; i >= 0; i--) {
    cnt[i] += cnt[i + 1];
  }
  cnt.push_back(0);
  int ans = 0;
  for (int i = 0; i + 5 < n; i++) {
    if (s.substr(i, 5) == "heavy") {
      ans += cnt[i + 5];
    }
  }
  cout << ans << endl;
}

signed main() {
  int t;
  t = 1;
  while (t--)
    solve();
}