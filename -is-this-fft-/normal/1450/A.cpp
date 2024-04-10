#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve () {
  int n;
  cin >> n;

  vector<char> v (n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }

  sort(v.begin(), v.end());

  for (char c : v) {
    cout << c;
  }
  cout << '\n';
}

int main () {
  ios::sync_with_stdio(false);

  int testc;
  cin >> testc;

  for (int i = 0; i < testc; i++) {
    solve();
  }
}