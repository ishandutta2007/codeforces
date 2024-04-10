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
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    sort(a.begin(), a.end());
    int l = unique(a.begin(), a.end())-a.begin();
    for (int k = 1; k <= n; k++) {
      cout << max(k, l) << " \n"[k==n];
    }
  }
}