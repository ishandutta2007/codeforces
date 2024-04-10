#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n), w(k);
    for (int& x: a) cin >> x;
    for (int& x: w) cin >> x;
    sort(a.begin(), a.end());
    sort(w.begin(), w.end(), greater<int>());
    long long ans = 0;
    while (w.size() && w.back() == 1) {
      ans += 2*a.back();
      w.pop_back();
      a.pop_back();
      k--;
    }
    ans += accumulate(a.end()-k, a.end(), 0LL);
    for (int i = 0, j = 0; j < k; i += w[j]-1, j++) {
      ans += a[i];
    }
    cout << ans << '\n';
  }
}