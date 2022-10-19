#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int& x: a) cin >> x;
    map<int, pair<int, int>> last;
    map<int, pair<int, int>> lo, hi;
    for (int& x: a) {
      last[x] = {-1, 0};
      lo[x] = {INF, 0};
      hi[x] = {-INF, 0};
    }
    int d = 0;
    int b = 0;
    int l = 0;
    int r = 0;
    for (int i = 0; i < n; i++) {
      int z = a[i];
      int cur = last[z].second;
      int m = cur-(i-last[z].first-1)+1;
      lo[z] = min(lo[z], {m-1, i});
      hi[z] = max(hi[z], {m, i});
      last[z] = {i, m};
      if (m-lo[z].first > d) {
        d = m-lo[z].first;
        b = z;
        l = lo[z].second+1;
        r = i+1;
      }
    }
    
    cout << b << " " << l << " " << r << '\n';
  }
}