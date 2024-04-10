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
    vector<int> as = a;
    vector<int> bs = b;
    sort(as.begin(), as.end());
    sort(bs.begin(), bs.end());
    vector<pair<int, int>> moves;
    for (int i = 0; i < n; i++) {
      if (as[i] != a[i] || bs[i] != b[i]) {
        for (int j = i+1; j < n; j++) {
          if (as[i] == a[j] && bs[i] == b[j]) {
            moves.emplace_back(i+1, j+1);
            swap(a[i], a[j]);
            swap(b[i], b[j]);
            break;
          }
        }
      }
    }

    bool win = 1;
    for (int i = 0; i < n; i++) {
      if (as[i] != a[i] || bs[i] != b[i]) {
        win = 0;
      }
    }
    if (!win) {
      cout << "-1\n";
      continue;
    }
    cout << moves.size() << '\n';
    for (pair<int, int>& p: moves) {
      cout << p.first << " " << p.second << '\n';
    }
  }
}