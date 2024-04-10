#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve () {
  int n, a, b;
  cin >> n >> a >> b;

  if (a + b > n - 2) {
    cout << -1 << '\n';
    return;
  }

  if (a != b - 1 && a != b && a != b + 1) {
    cout << -1 << '\n';
    return;
  }

  if (a == 0 && b == 0) {
    for (int i = 1; i <= n; i++) {
      cout << i << " ";
    }
    cout << '\n';
    return;
  }

  vector<int> smalls;
  vector<int> oths;
  for (int i = 1; i <= n; i++) {
    if (i <= b) {
      smalls.push_back(i);
    } else {
      oths.push_back(i);
    }
  }

  vector<int> bigs;
  while ((int) bigs.size() < a) {
    bigs.push_back(oths.back());
    oths.pop_back();
  }

  int fin = oths.back();
  oths.pop_back();
  
  bool afirst = a == b || a == b + 1;
  if (!afirst) {
    reverse(oths.begin(), oths.end());
  }

  for (int u : oths) {
    cout << u << " ";
  }
 
  while (!bigs.empty() || !smalls.empty()) {
    if (afirst) {
      if (!bigs.empty()) {
        cout << bigs.back() << " ";
        bigs.pop_back();
      }
    }

    if (!smalls.empty()) {
      cout << smalls.back() << " ";
      smalls.pop_back();
    }

    if (!afirst) {
      if (!bigs.empty()) {
        cout << bigs.back() << " ";
        bigs.pop_back();
      }
    }
  }

  cout << fin << '\n';
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