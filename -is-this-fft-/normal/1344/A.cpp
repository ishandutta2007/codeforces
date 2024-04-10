#include <iostream>
#include <set>

using namespace std;

const int MAX_N = 2e5 + 5;

void solve () {
  set<int> seen;

  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int add;
    cin >> add;

    int cur = (i + add) % n;
    if (cur < 0) cur += n;
    seen.insert(cur);
  }

  if ((int) seen.size() == n) {
    cout << "YES" << '\n';
  } else {
    cout << "NO" << '\n';
  }
}

int main () {
  ios::sync_with_stdio(false);

  int testc;
  cin >> testc;

  for (int t = 0; t < testc; t++) {
    solve();
  }
}