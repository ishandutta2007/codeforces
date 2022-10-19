#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  long long ans = 1e18;
  for (int i = 0; i < n; i++) {
    long long steps = 0;
    long long target = 0;
    for (int j = i-1; j >= 0; j--) {
      long long k = (target/a[j]-1);
      target = k * a[j];
      steps += abs(k);
    }
    target = 0;
    for (int j = i+1; j < n; j++) {
      long long k = (target/a[j]+1);
      target = k * a[j];
      steps += k;
    }
    ans = min(ans, steps);
  }
  cout << ans << '\n';
}