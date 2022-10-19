#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  int k = (2*n+1)/3;
  cout << k << '\n';
  //if (n % 3 == 2) n--;
  vector<pair<int, int>> queens;
  auto place = [&] (int x, int y) {
    queens.emplace_back(x, y);
    cout << x << " " << y << '\n';
  };
  int pairs = (k-1)/2;
  int d = 1;
  int ex = k-1-2*pairs;
  int maxd = (n-k)-1;
  //cout << k << " " << maxd << '\n';
  if (maxd == -1) {
    place(1, 1);
    return 0;
  }
  int even = maxd - (maxd%2);
  set<int> coords;
  for (int i = 0; i <= even/2; i++) {
    coords.insert(i+1);
    coords.insert(even+1-i);
    if (i == even/2) {
      place(i+1, even+1-i);
    }
    else {
      place(i+1, even+1-i);
      place(even+1-i, i+1);
    }
  }
  int odd = even + (even < maxd ? 1 : -1);
  if (odd != -1) {
    for (int i = 0; i <= odd/2; i++) {
      coords.insert(even+i+2);
      coords.insert(even+odd+2-i);
      place(even+i+2, even+odd+2-i);
      place(even+odd+2-i, even+i+2);
    }
  }
  for (int i = 1; i <= k; i++) {
    if (!coords.count(i)) {
      place(i, i);
    }
  }

  /*
  vector<vector<char>> grid(n, vector<char>(n, '.'));
  for (pair<int, int>& p: queens) {
    grid[p.first-1][p.second-1] = 'X';
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << grid[i][j];
    }
    cout << '\n';
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      bool valid = false;
      for (pair<int, int>& p: queens) {
        if (p.first == i || p.second == j || p.second-p.first == j-i) {
          valid = true;
          break;
        }
      }
      if (!valid) {
        cout << "FAIL: ";
        cout << i << " " << j << '\n';
      }
    }
  }
  */
}