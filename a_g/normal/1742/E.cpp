#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    vector<long long> s(n+1);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      s[i+1] = s[i]+a[i];
    }
    for (int i = 1; i < n; i++) a[i] = max(a[i-1], a[i]);
    while (q--) {
      int x;
      cin >> x;
      int low = -1;
      int high = n;
      while (high-low > 1) {
        int mid = (low+high)/2;
        if (a[mid] > x) high = mid;
        else low = mid;
      }
      cout << s[high] << ' ';
    }
    cout << '\n';
  }
}