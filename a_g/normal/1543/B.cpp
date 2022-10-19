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
    for (int& x: a) cin >> x;
    long long tot = accumulate(a.begin(), a.end(), 0LL);
    int m = tot % n;
    cout << 1LL * m * (n-m) << '\n';
  }
}