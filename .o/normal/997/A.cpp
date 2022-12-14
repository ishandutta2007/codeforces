#include <bits/stdc++.h>

using namespace std;

int main() {
  int n; long long x, y; string a;
  cin >> n >> x >> y >> a;
  vector<int> cnt(2);
  cnt[a[0] - '0'] += 1;
  for(int i = 1; i < n; i++) {
    if(a[i] != a[i-1]) cnt[a[i] - '0'] += 1;
  }

  if(cnt[0] == 0) {
    cout << 0 << endl;
    return 0;
  }

  long long ans = 1e18;
  for(int p = 0; p < cnt[0]; p++) {
    ans = min(ans, p * x + (cnt[0] - p) * y);
  }
  cout << ans << endl;
}