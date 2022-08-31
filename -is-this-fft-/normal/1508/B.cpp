#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

bool smaller (ll x, int m) {
  if (x == 0) return true;
  // returns true if x < (1 << m)
  return 63 - __builtin_clzll(x) < m;
}

void solve () {
  int n;
  ll K;
  cin >> n >> K;
  K--;

  if (!smaller(K, n - 1)) {
    cout << -1 << '\n';
    return;
  }

  vector<int> blocks (1, 1);
  int left = n - 1;
  while (left > 0) {
    if (!smaller(K, left - 1)) {
      K -= 1LL << (left - 1);
      blocks.back()++;
    } else {
      blocks.push_back(1);
    }
    left--;
  }

  int tot = 0;
  for (int u : blocks) {
    tot += u;
    for (int i = 0; i < u; i++) {
      cout << tot - i << " ";
    }
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