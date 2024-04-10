#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9+2;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, q;
    cin >> n >> q;
    vector<int> a(n), start_win(n+1, INF), end_win(n+1, INF);
    for (int& x: a) cin >> x;
    int cur = (a[0] > a[1] ? 0 : 1);
    start_win[cur] = 1;
    for (int i = 2; i < n; i++) {
      if (a[i] > a[cur]) {
        end_win[cur] = i;
        start_win[i] = i;
        cur = i;
      }
    }
    while (q--) {
      int i, k;
      cin >> i >> k;
      i--;
      if (k < start_win[i]) {
        cout << "0\n";
        continue;
      }
      cout << min(k+1, end_win[i])-start_win[i] << '\n';
    }
  }
}