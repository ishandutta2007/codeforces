#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a[2];
    while (n--) {
      int x;
      cin >> x;
      a[x&1].push_back(x);
    }
    for (int i = 0; i < 2; i++) {
      for (int x: a[i]) {
        cout << x << ' ';
      }
    }
    cout << '\n';
  }
}