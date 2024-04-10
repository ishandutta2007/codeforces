#include <iostream>

using namespace std;

int ask (int x) {
  cout << x << endl;

  int ans;
  cin >> ans;

  if (ans == 0) exit(0);
  if (ans == -2) exit(0);
  return ans;
}

const int MAX_N = 35;

int inv [MAX_N];

int main () {
  int m, n;
  cin >> m >> n;

  for (int i = 0; i < n; i++) {
    inv[i] = -ask(m);
  }

  int cur = 0;
  int ans = 0;
  for (int k = 1 << 30; k != 0; k /= 2) {
    if (ans + k <= m) {
      if (inv[cur] * ask(ans + k) == 1) {
        ans += k;
      }
      cur++;
      cur %= n;
    }
  }

  ask(ans + 1);
}