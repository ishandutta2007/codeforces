#include <bits/stdc++.h>
using namespace std;

/*
vector<pair<int, int>> solve(int n, int k) {
  if (n == 4) {
    assert(k <= 2);
    if (k == 0) return {{0, 3}, {1, 2}};
    if (k == 1) return {{0, 2}, {1, 3}};
    if (k == 2) return {{0, 1}, {2, 3}};
  }
  int m = k/2;
  vector<pair<int, int>> ans;
  for (pair<int, int> p: solve(n, m)) {
    if (p.first < n/2) p.first += n/2;
    if (p.first < n/2) p.first += n/2;
  }
}
*/

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    if (n == 4 && k == 3) {
      cout << "-1\n";
      continue;
    }
    if (n == 4 && k == 1) {
      cout << "0 2\n1 3\n";
      continue;
    }
    vector<int> partner(n/2+1);
    for (int i = 0; i < n/2+1; i++) {
      partner[i] = n-1-i;
    }

    int b = __builtin_ctz(n);
    vector<int> x(1);
    for (int i = 0; i < b; i++) {
      if (k&(1<<i)) x.push_back(1<<i);
    }
    int m = x.size();
    for (int i = 0; i < m; i++) {
      partner[x[i]] = n-1-(x[(i+1)%m]);
    }
    for (int i = 0; i < n/2+1; i++) {
      if (i == n/2-1) continue;
      cout << i << " " << partner[i] << '\n';
    }
  }
}