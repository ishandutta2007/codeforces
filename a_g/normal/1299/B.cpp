#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  if (n&1) {
    cout << "NO\n";
    return 0;
  }
  int k = n/2;
  vector<pair<int, int>> vtxs(n);
  for (int i = 0; i < n; i++) {
    cin >> vtxs[i].first >> vtxs[i].second;
  }
  int x = vtxs[0].first + vtxs[k].first;
  int y = vtxs[0].second + vtxs[k].second;
  for (int i = 1; i < k; i++) {
    if (vtxs[i].first + vtxs[i+k].first != x || vtxs[i].second + vtxs[i+k].second != y) {
      cout << "NO\n";
      return 0;
    }
  }
  cout << "YES\n";
}