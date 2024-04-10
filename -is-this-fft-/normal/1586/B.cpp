#include <iostream>
#include <set>

using namespace std;

void solve () {
  int n, m;
  cin >> n >> m;

  set<int> ctrs;
  for (int i = 1; i <= n; i++) {
    ctrs.insert(i);
  }

  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    ctrs.erase(b);
  }

  int u = *ctrs.begin();
  for (int i = 1; i <= n; i++) {
    if (i == u) continue;
    cout << i << " " << u << '\n';
  }
}

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int testc;
  cin >> testc;

  for (int i = 0; i < testc; i++) {
    solve();
  }
}