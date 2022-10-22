#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int color (int r, int c) {
  return ((r % 2) << 1) ^ (c % 2); 
}

void solve () {
  int n;
  cin >> n;

  vector<pair<int, int>> pcs;
  int badc = 0 ^ 1 ^ 2 ^ 3;
  for (int i = 0; i < 3; i++) {
    int r, c;
    cin >> r >> c;
    pcs.push_back({r, c});
    
    badc ^= color(r, c);
  }

  sort(pcs.begin(), pcs.end());
  int gx = -1, gy = -1;
  if (pcs == vector<pair<int, int>> {{1, 1}, {1, 2}, {2, 1}}) {
    gx = 1;
    gy = 1;
  } else if (pcs == vector<pair<int, int>> {{1, n - 1}, {1, n}, {2, n}}) {
    gx = 1;
    gy = n;
  } else if (pcs == vector<pair<int, int>> {{n - 1, 1}, {n, 1}, {n, 2}}) {
    gx = n;
    gy = 1;
  } else if (pcs == vector<pair<int, int>> {{n - 1, n}, {n, n - 1}, {n, n}}) {
    gx = n;
    gy = n;
  }

  int x, y;
  cin >> x >> y;

  if (color(x, y) == badc) {
    cout << "NO" << '\n';
  } else {
    if (gx != -1) {
      if (x == gx || y == gy) {
        cout << "YES" << '\n';
      } else {
      	cout << "NO" << '\n';
      }
    } else {
      cout << "YES" << '\n';
    }
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