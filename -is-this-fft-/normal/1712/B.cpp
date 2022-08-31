#include <iostream>
#include <vector>

using namespace std;

void solve () {
  int n;
  cin >> n;

  vector<int> perm;
  for (int i = 1; i <= n; i++) {
    perm.push_back(i);
  }

  for (int i = n - 2; i >= 0; i -= 2) {
    swap(perm[i], perm[i + 1]);
  }

  for (int u : perm) {
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