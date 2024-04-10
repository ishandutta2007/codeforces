#include <iostream>

using namespace std;

const int INF = 1e9 + 5;

void solve () {
  int n;
  cin >> n;

  pair<int, int> mn = {INF, 0};
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;

    mn = min(mn, {x, i});
  }

  if (n % 2 == 0) {
    cout << (mn.second % 2 == 0 ? "Joe" : "Mike") << '\n';
  } else {
    cout << "Mike" << '\n';
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