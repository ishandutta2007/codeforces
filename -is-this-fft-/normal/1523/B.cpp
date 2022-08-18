#include <iostream>
#include <vector>

using namespace std;

vector<int> ops = {2, 1, 2, 1, 2, 1};

void solve () {
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
  }

  cout << (int) ops.size() * (n / 2) << '\n';
  for (int i = 1; i <= n; i += 2) {
    for (auto u : ops) {
      cout << u << " " << i << " " << i + 1 << '\n';
    }
  }
}

int main () {
  ios::sync_with_stdio(false);

  int testc;
  cin >> testc;

  for (int i = 0; i < testc; i++) {
    solve();
  }
}