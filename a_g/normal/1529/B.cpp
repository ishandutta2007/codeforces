#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int c = 0;
    for (int val: a) {
      if (val <= 0) c++;
    }
    if (c < n) {
      sort(a.begin(), a.end());
      int d = 1e9;
      for (int i = 0; i < c-1; i++) {
        d = min(a[i+1]-a[i], d);
      }
      if (a[c] <= d) c++;
    }
    cout << c << '\n';
  }
}