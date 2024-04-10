#include <iostream>
#include <set>

using namespace std;

void solve () {
  int n;
  cin >> n;

  set<int> arr;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;

    arr.insert(x);
  }

  bool adj = false;
  for (int u : arr) {
    if (arr.count(u + 1)) {
      adj = true;
    }
  }

  if (adj && arr.count(1)) {
    cout << "NO" << '\n';
  } else {
    cout << "YES" << '\n';
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