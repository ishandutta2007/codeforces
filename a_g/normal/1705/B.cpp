#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int& x: a) cin >> x;
    int s = 0;
    while (s < n && a[s] == 0) s++;
    long long ans = accumulate(a.begin(), a.end(), 0LL)-a.back();
    for (int i = s+1; i < n-1; i++) {
      if (a[i] == 0) ans++;
    }
    cout << ans << '\n';
  }
}