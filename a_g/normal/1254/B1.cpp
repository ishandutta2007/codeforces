#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  long long s = 0;
  for (int& x: a) {
    cin >> x;
    s += x;
  }
  if (s == 1) {
    cout << "-1\n";
    return 0;
  }

  long long ans = 1e18;
  auto check = [&] (long long k) {
    long long steps = 0;
    long long cur = 0;
    for (int i = 0; i < n; i++) {
      cur += a[i];
      cur %= k;
      if (2*cur > k) cur -= k;
      if (2*cur < -k) cur += k;
      steps += abs(cur);
    }
    ans = min(steps, ans);
    while (s%k == 0) s/= k;
  };
  for (int i = 2; 1LL*i*i <= s; i++) {
    if (s%i == 0) check(i);
  }
  if (s > 1) check(s);
  cout << ans << '\n';
}