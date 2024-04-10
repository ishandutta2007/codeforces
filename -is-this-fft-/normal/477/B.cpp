#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> solve (int n) {
  vector<vector<int>> sol;
  for (int k = 0; k < n; k++) {
    sol.push_back({6 * k + 1, 6 * k + 3, 6 * k + 5, 6 * k + 2});
  }
  return sol;
}

int main () {
  ios::sync_with_stdio(false);

  int n, K;
  cin >> n >> K;

  auto vec = solve(n);
  int mx = 0;
  for (auto &v : vec) {
    for (auto &u : v) {
      u *= K;
      mx = max(mx, u);
    }
  }

  cout << mx << endl;
  for (auto &v : vec) {
    for (int u : v) {
      cout << u << " ";
    }
    cout << '\n';
  }
}