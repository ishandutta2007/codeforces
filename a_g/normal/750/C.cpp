#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  int low = -INF;
  int high = INF;
  int delta = 0;
  for (int i = 0; i < n; i++) {
    int c, d;
    cin >> c >> d;
    if (d == 1) {
      low = max(low, 1900-delta);
    }
    else {
      high = min(high, 1899-delta);
    }
    delta += c;
  }
  if (low > high) {
    cout << "Impossible\n";
  }
  else if (high == INF) {
    cout << "Infinity\n";
  }
  else {
    cout << high+delta << '\n';
  }
}