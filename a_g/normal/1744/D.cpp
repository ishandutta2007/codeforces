#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    int k = 0;
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      k += __builtin_ctz(x);
      b[i] = __builtin_ctz(i+1);
    }
    sort(b.begin(), b.end(), greater<int>());
    int ans = 0;
    for (int x: b) {
      if (k >= n) break;
      ans++;
      k += x;
    }
    cout << (k >= n ? ans : -1) << '\n';
  }
}