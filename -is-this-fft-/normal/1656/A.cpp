#include <iostream>

using namespace std;

void solve () {
  int n;
  cin >> n;

  pair<int, int> mx = {-1, -1};
  pair<int, int> mn = {1e9 + 5, -1};

  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;

    mx = max(mx, {x, i});
    mn = min(mn, {x, i});
  }

  cout << 1 + mx.second << " " << 1 + mn.second << '\n';
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