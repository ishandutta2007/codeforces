#include <bits/stdc++.h>
using namespace std;

const int N = 105;
pair<int, int> c[N];

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
      cin >> c[i].first;
    }
    for (int i = 0; i < n; i++) {
      cin >> c[i].second;
    }
    sort(c, c+n);
    for (int i = 0; i < n; i++) {
      if (k >= c[i].first) {
        k += c[i].second;
      }
      else {
        break;
      }
    }

    cout << k << '\n';
  }
}