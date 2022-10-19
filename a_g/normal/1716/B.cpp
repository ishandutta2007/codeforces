#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    cout << n << '\n';
    vector<int> p(n);
    iota(p.begin(), p.end(), 1);
    for (int x: p) {
      cout << x << ' ';
    }
    cout << '\n';
    for (int i = 0; i < n-1; i++) {
      swap(p[i], p[i+1]);
      for (int x: p) {
        cout << x << ' ';
      }
      cout << '\n';
    }
  }
}