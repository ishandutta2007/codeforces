#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 2e3 + 5;

bool can [MAX_N];

void solve () {
  int n;
  cin >> n;

  vector<int> blocks;
  int prem = -1;
  for (int i = 0; i < 2 * n; i++) {
    int x;
    cin >> x;

    if (x > prem) {
      blocks.push_back(0);
      prem = x;
    }

    blocks.back()++;
  }

  for (int i = 0; i <= n; i++) {
    can[i] = 0;
  }
  can[0] = 1;

  for (int b : blocks) {
    for (int j = n - b; j >= 0; j--) {
      if (can[j]) can[j + b] = 1;
    }
  }

  if (can[n]) {
    cout << "YES" << '\n';
  } else {
    cout << "NO" << '\n';
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