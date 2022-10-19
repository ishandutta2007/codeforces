#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, q;
  cin >> n >> q;
  vector<vector<pair<int, int>>> constraints(n);
  vector<int> ans(n), bad(n);
  while (q--) {
    int i, j, x;
    cin >> i >> j >> x;
    i--, j--;
    if (i > j) swap(i, j);
    bad[i] |= ~x;
    bad[j] |= ~x;
    if (i == j) ans[i] = x;
    else constraints[i].emplace_back(j, x);
  }
  for (int i = 0; i < n; i++) {
    for (auto& [j, x]: constraints[i]) {
      ans[i] |= x&bad[j];
    }
    for (auto& [j, x]: constraints[i]) {
      ans[j] |= x&(~ans[i]);
    }
    cout << ans[i] << " \n"[i+1==n];
  }
}