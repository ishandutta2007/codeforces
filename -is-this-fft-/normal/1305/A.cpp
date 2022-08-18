#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve () {
  int n;
  cin >> n;

  vector<int> a (n);
  for (int i = 0; i < n; i++) cin >> a[i];
  vector<int> b (n);
  for (int i = 0; i < n; i++) cin >> b[i];

  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  for (int u : a) {
    cout << u << " ";
  }
  cout << '\n';
  for (int u : b) {
    cout << u << " ";
  }
  cout << '\n';
}

int main () {
  ios::sync_with_stdio(false);

  int testc;
  cin >> testc;

  for (int t = 0; t < testc; t++) {
    solve();
  }
}