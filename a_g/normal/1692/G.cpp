#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int& x: a) cin >> x;
    vector<int> p(n);
    for (int i = 0; i < n-1; i++) {
      p[i+1] = p[i] + (a[i] < 2*a[i+1]);
    }
    int ans = 0;
    for (int i = 0; i+k < n; i++) {
      ans += (p[i+k]-p[i] == k);
    }
    cout << ans << '\n';
  }
}