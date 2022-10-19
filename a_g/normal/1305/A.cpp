#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int& x: a) cin >> x;
    for (int& x: b) cin >> x;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    for (int x: a) cout << x << ' ';
    cout << '\n';
    for (int x: b) cout << x << ' ';
    cout << '\n';
  }
}