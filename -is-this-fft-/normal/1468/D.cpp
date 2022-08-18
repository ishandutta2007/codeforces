#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_N = 1 << 18;

int fuse [MAX_N];

bool can (int diff, int fc, int to_end) {
    if(diff <= fc)
        return false;
  if (to_end - fc <= 0) return false;

  for (int i = 0; i < fc; i++) {
    int cur = fuse[fc - i - 1];
    if (i + cur >= to_end) {
      return false;
    }
  }
  return true;
}

void solve () {
  int n, m, a, b;
  cin >> n >> m >> a >> b;

  int to_end = b - 1;
  int diff = abs(a-b);
  if (a > b) {
    to_end = n - b;
  }

  for (int i = 0; i < m; i++) {
    cin >> fuse[i];
  }
  sort(fuse, fuse + m);

  int ans = 0;
  for (int k = MAX_N; k != 0; k /= 2) {
    if (ans + k <= m && can(diff, ans + k, to_end)) {
      ans += k;
    }
  }
  cout << ans << '\n';
}

int main () {
  ios::sync_with_stdio(false);

  int testc;
  cin >> testc;

  for (int i = 0; i < testc; i++) {
    solve();
  }
}