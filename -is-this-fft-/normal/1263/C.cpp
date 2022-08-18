#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

void solve () {
  int n;
  cin >> n;

  vector<int> ans (1, n);
  for (int i = 2; i <= n + 1; i++) {
    int x = n / i;
    if (x != ans.back()) {
      ans.push_back(x);
    }

    if (2 * n <= (ll) i * (ll) (i + 1)) {
      break;
    }
  }

  while (ans.back() != 0) {
    ans.push_back(ans.back() - 1);
  }

  reverse(ans.begin(), ans.end());
  cout << (int) ans.size() << '\n';
  for (int u : ans) {
    cout << u << " ";
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