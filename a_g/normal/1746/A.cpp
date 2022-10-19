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
    if (count(a.begin(), a.end(), 1) == 0) {
      cout << "NO\n";
      continue;
    }
    cout << "YES\n";
  }
}