#include <iostream>
#include <iomanip>

using namespace std;

int calc_pot (int x, int y) {
  int ans = 0;
  for (int k = 4; k >= 0; k--) {
    bool fx = !!(x & 1 << k);
    bool fy = !!(y & 1 << k);

    if (fx) {
      x -= 1 << k;
      x = (1 << k) - x - 1;
      ans += 1 << (2 * k);
    }

    if (fy) {
      y -= 1 << k;
      y = (1 << k) - y - 1;
      ans += 1 << (2 * k + 1);
    }
  }

  return ans;
}

const int MAX_N = 32;

int pot [MAX_N][MAX_N];
pair<int, int> bypot [MAX_N * MAX_N];

int main () {
  for (int i = 0; i < MAX_N; i++) {
    for (int j = 0; j < MAX_N; j++) {
      pot[i][j] = calc_pot(i, j);
      bypot[pot[i][j]] = make_pair(i, j);
    }
  }

  int n, qc;
  cin >> n >> qc;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n - 1; j++) {
      cout << (pot[i][j] ^ pot[i][j + 1]) << " ";
    }
    cout << endl;
  }

  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n; j++) {
      cout << (pot[i + 1][j] ^ pot[i][j]) << " ";
    }
    cout << endl;
  }

  int cur = 0;
  for (int i = 0; i < qc; i++) {
    int x;
    cin >> x;

    cur ^= x;
    auto pr = bypot[cur];
    cout << 1 + pr.first << " " << 1 + pr.second << endl;
  }
}