#include <bits/stdc++.h>
using namespace std;

const int N = 2005;
int a[N];
int n;
vector<pair<int, int>> ops;
multiset<int> m;

bool check() {
  if (m.size() == 1) return 1;
  int mx = *m.rbegin();
  m.erase(m.find(mx));
  int n = *m.rbegin();
  int d = mx - n;
  auto it = m.find(d);
  if (it == m.end()) {
    m.insert(mx);
    return 0;
  }
  m.erase(it);
  if (d == n && !m.count(d)) {
    m.insert(mx);
    m.insert(d);
    return 0;
  }
  ops.push_back({n, d});
  bool ans = check();
  m.insert(mx);
  m.insert(d);
  return ans;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    m.clear();
    for (int i = 1; i <= 2*n; i++) {
      cin >> a[i];
      m.insert(a[i]);
    }
    bool win = 0;
    int mx = *m.rbegin();
    for (int x = 1; x <= 2*n; x++) {
      ops.clear();
      if (a[x] == mx && m.count(mx) == 1) continue;
      m.erase(m.find(a[x]));
      if (check()) {
        win = 1;
        ops.insert(ops.begin(), make_pair(a[x], mx));
        break;
      }
      m.insert(a[x]);
    }
    if (win) {
      cout << "YES\n";
      cout << ops[0].first + ops[0].second << '\n';
      for (pair<int, int> p: ops) {
        cout << p.first << " " << p.second << '\n';
      }
    }
    else {
      cout << "NO\n";
    }
  }
}