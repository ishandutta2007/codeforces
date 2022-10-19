#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, k, b;
    long long s;
    cin >> n >> k >> b >> s;
    if (s < 1LL*b*k) {
      cout << "-1\n";
      continue;
    }
    if (s > 1LL*b*k+1LL*n*(k-1)) {
      cout << "-1\n";
      continue;
    }
    vector<long long> ans(n);
    ans[0] = 1LL*b*k;
    long long t = ans[0];
    for (int i = 0; i < n; i++) {
      long long d = min<long long>(s-t, k-1);
      ans[i] += d;
      t += d;
      cout << ans[i] << ' ';
    }
    cout << '\n';
  }
}