#include <iostream>
#include <vector>

using namespace std;

void solve () {
  int n, m;
  cin >> n >> m;

  if (n > m) {
    cout << "No" << '\n';
    return;
  }

  if (n % 2 == 0 && m % 2 == 1) {
    cout << "nO" << '\n';
    return;
  }

  vector<int> ans (n, 1);
  m -= n;

  if (n % 2 == 0) {
    ans[0] += m / 2;
    ans[1] += m / 2;
  } else {
    ans[0] += m;
  }

  cout << "Yes" << '\n';
  for (int u : ans) {
    cout << u << " ";
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