#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, x;
    cin >> n >> x;
    vector<int> a(2*n);
    for (int& x: a) cin >> x;
    sort(a.begin(), a.end());
    bool good = 1;
    for (int i = 0; i < n; i++) {
      if (a[i+n]-a[i] < x) good = 0;
    }
    cout << (good ? "YES" : "NO") << '\n';
  }
}