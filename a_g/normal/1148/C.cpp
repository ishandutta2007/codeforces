#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<int> p(n+1), q(n+1);
  for (int i = 1; i <= n; i++) {
    cin >> p[i];
    q[p[i]] = i;
  }

  vector<pair<int, int>> ops;
  auto operate = [&] (int i, int j) {
    //if (i == j) return;
    ops.emplace_back(i, j);
    swap(p[i], p[j]);
    swap(q[p[i]], q[p[j]]);
  };
  for (int i = 1; i <= n; i++) {
    if (p[i] == i) continue;
    int z = q[i];
    int a = (2*(n-i) >= n ? n : 1);
    int b = (2*(n-z) >= n ? n : 1);
    if (i == b) {
      operate(z, b);
      continue;
    }
    if (z == a) {
      operate(i, a);
      continue;
    }
    if (a == b) {
      operate(z, a);
      operate(i, a);
      operate(z, a);
    }
    else {
      operate(i, a);
      operate(z, b);
      operate(a, b);
      operate(i, a);
      operate(z, b);
    }
  }
  cout << ops.size() << '\n';
  for (pair<int, int>& op: ops) {
    cout << op.first << " " << op.second << '\n';
  }
}