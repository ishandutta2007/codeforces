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
  int n, v;
  cin >> n >> v;
  vector<int> cnt(4000);
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    cnt[a] += b;
  }
  int ans = 0;
  for (int i = 1; i < 4000; i++) {
    int k = min(v, cnt[i - 1]);
    k = min(k, v);
    int k1 = min(v - k, cnt[i]);
    cnt[i] -= k1;
    ans += k1 + k;
  }
  cout << ans << endl;
}

signed main() {
  int t;
  t = 1;
  while (t--)
    solve();
}