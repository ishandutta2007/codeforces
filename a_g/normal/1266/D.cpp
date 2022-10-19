#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+2;
long long a[N];

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  while (m--) {
    int u, v, d;
    cin >> u >> v >> d;
    a[u] += d;
    a[v] -= d;
  }
  vector<int> pos, neg;
  for (int i = 1; i <= n; i++) {
    if (a[i] > 0) pos.push_back(i);
    else if (a[i] < 0) neg.push_back(i);
  }

  vector<tuple<int, int, long long>> ans;
  while (pos.size()) {
    assert(neg.size());
    long long z = min(a[pos.back()], -a[neg.back()]);
    assert(z > 0);
    ans.emplace_back(pos.back(), neg.back(), z);
    a[pos.back()] -= z;
    a[neg.back()] += z;
    if (a[pos.back()] == 0) pos.pop_back();
    if (a[neg.back()] == 0) neg.pop_back();
  }

  assert(ans.size() <= 3e5);
  cout << ans.size() << '\n';
  for (auto& [u, v, d]: ans) {
    assert(u != v);
    cout << u << " " << v << " " << d << '\n';
  }
}