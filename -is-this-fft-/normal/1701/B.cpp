#include <iostream>
#include <set>

using namespace std;

void solve () {
  int n;
  cin >> n;

  set<int> unused;
  for (int i = 1; i <= n; i++) {
    unused.insert(i);
  }

  cout << 2 << '\n';
  while (!unused.empty()) {
    int cur = *unused.begin();
    while (cur <= n) {
      unused.erase(cur);
      cout << cur << " ";
      cur *= 2;
    }
  }

  cout << '\n';
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