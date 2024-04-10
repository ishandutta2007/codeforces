#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e9 + 5;

int min3s (int u, int c1, int c2) {
  int ans = INF;
  for (int i = 0; i <= c1; i++) {
    for (int j = 0; j <= c2; j++) {
      int v = u - i - 2 * j;
      if (v >= 0 && v % 3 == 0) {
        ans = min(ans, v / 3);
      }
    }
  }
  return ans;
}

int min3s (const vector<int> &prices, int c1, int c2) {
  int ans = 0;
  for (int u : prices) {
    ans = max(ans, min3s(u, c1, c2));
  }
  return ans;
}

void solve () {
  int n;
  cin >> n;

  vector<int> prices (n);
  for (int i = 0; i < n; i++) {
    cin >> prices[i];
  }

  int ans = INF;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 4; j++) {
      ans = min(ans, i + j + min3s(prices, i, j));
    }
  }

  cout << ans << '\n';
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