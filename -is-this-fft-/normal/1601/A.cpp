#include <iostream>
#include <vector>

using namespace std;

const int MAX_B = 30;

void solve () {
  vector<int> cnt (MAX_B, 0);

  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;

    for (int j = 0; j < MAX_B; j++) {
      if (x & 1 << j) {
        cnt[j]++;
      }
    }
  }

  for (int k = 1; k <= n; k++) {
    bool ok = true;
    for (int j = 0; j < MAX_B; j++) {
      if (cnt[j] % k != 0) {
        ok = false;
        break;
      }
    }

    if (ok) {
      cout << k << " ";
    }
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