#include <iostream>

using namespace std;

const int MAX_LG = 22;

int cnt [MAX_LG]; // # of 2^i

int blog (int x) {
  return 31 - __builtin_clz(x);
}

void solve () {
  int n, W;
  cin >> n >> W;

  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;

    cnt[blog(x)]++;
  }

  int ans = 0;
  while (true) {
    bool allz = true;
    for (int i = 0; i < MAX_LG; i++) {
      if (cnt[i] != 0) {
        allz = false;
      }
    }

    if (allz) {
      break;
    }
    ans++;

    int cur = W;
    for (int i = MAX_LG - 1; i >= 0; i--) {
      while (cnt[i] > 0 && cur >= (1 << i)) {
        cnt[i]--;
        cur -= (1 << i);
      }
    }
  }

  cout << ans << endl;
}

int main () {
  ios::sync_with_stdio(false);

  int testc;
  cin >> testc;

  for (int i = 0; i < testc; i++) {
    solve();
  }
}