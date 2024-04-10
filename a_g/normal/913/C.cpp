#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, L;
  cin >> n >> L;
  vector<int> c(n);
  for (int& x: c) cin >> x;
  for (int i = 1; i < n; i++) {
    c[i] = min(c[i], 2*c[i-1]);
  }
  vector<int> cnt(n);
  for (int i = 0; i < n-1; i++) {
    if (L&1) {
      cnt[i] = 1;
      L--;
    }
    L >>= 1;
  }
  cnt[n-1] = L;
  long long cur = 0;
  for (int i = 0; i < n; i++) {
    cur += 1LL*cnt[i]*c[i];
  }
  long long ans = cur;
  for (int i = 0; i < n-1; i++) {
    if (cnt[i] == 2) {
      cur -= 2*c[i];
      cnt[i+1]++;
      cur += c[i+1];
      ans = min(ans, cur);
    }
    else if (cnt[i] == 1) {
      cnt[i+1]++;
      cur += c[i+1]-c[i];
      ans = min(ans, cur);
    }
    cnt[i] = 0;
  }

  cout << ans << '\n';
}