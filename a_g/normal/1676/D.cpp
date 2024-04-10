#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>>a(n, vector<int>(m));
    for (int i =0; i < n; i++) {
      for (int&x: a[i]) cin >> x;
    }
    map<int, long long> s1;
    map<int, long long> s2;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        s1[i+j] += a[i][j];
        s2[i-j] += a[i][j];
      }
    }
    long long best = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        best = max(best, s1[i+j]+s2[i-j]-a[i][j]);
      }
    }
    cout << best << '\n';
  }
}