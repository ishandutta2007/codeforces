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
    bool win = 1;
    vector<long long> pref(n+1);
    for (int i = 0; i < n; i++) {
      pref[i+1] = pref[i] + a[i];
    }
    int p = n+1;
    while (p > 0 && pref[p-1] == 0) p--;
    if (p == n+1) win = 0;
    for (int i = 1; i < p; i++) {
      if (pref[i] <= 0) win = 0;
    }
    cout << (win ? "Yes" : "No") << '\n';
  }
}