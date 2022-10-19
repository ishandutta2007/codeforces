#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    if (accumulate(a.begin(), a.end(), 0) == x) {
      cout << "NO\n";
      continue;
    }
    sort(a.begin(), a.end());
    int sum = 0;
    for (int i = 0; i < n-1; i++) {
      sum += a[i];
      if (sum == x) {
        swap(a[i], a[i+1]);
        break;
      }
    }
    cout << "YES\n";
    for (int w: a) {
      cout << w << ' ';
    }
    cout << '\n';
  }
}