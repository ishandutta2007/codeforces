#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    vector<tuple<int, int, int>> x(m);
    for (int i = 0; i < m; i++) {
      cin >> get<1>(x[i])>> get<0>(x[i]);
      get<2>(x[i]) = i+1;
    }
    sort(x.begin(), x.end());
    x.resize(2*n);
    int weight = 0;
    for (int i = 0; i < 2*n; i++) {
      weight += get<0>(x[i]);
      swap(get<0>(x[i]), get<1>(x[i]));
    }
    sort(x.begin(), x.end());
    cout << weight << '\n';
    for (int i = 0; i < n; i++) {
      cout << get<2>(x[i]) << " " << get<2>(x[2*n-1-i]) << '\n';
    }
  }
}