#include <iostream>

using namespace std;

const int MAX_N = 2e5 + 5;

int l [MAX_N], r [MAX_N];

bool can (int len, int n) {
  int cur = 0;
  for (int i = 0; i < n; i++) {
    if (l[i] >= cur && r[i] >= len - 1 - cur) {
      cur++;
    }
  }

  return cur >= len;
}

void solve () {
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> r[i] >> l[i];
  }

  int ans = 0;
  for (int k = 1 << 17; k != 0; k /= 2) {
    if (ans + k <= n && can(ans + k, n)) {
      ans += k;
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