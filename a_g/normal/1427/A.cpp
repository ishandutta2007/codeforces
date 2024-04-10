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
    int s = accumulate(a.begin(), a.end(), 0);
    if (s == 0) {
      cout << "NO\n";
      continue;
    }
    sort(a.begin(), a.end());
    if (s > 0) reverse(a.begin(), a.end());
    cout << "YES\n";
    for (int x: a) cout << x << ' ';
    cout << '\n';
  }
}