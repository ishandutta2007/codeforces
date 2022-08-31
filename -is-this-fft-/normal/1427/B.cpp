#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void solve () {
  int n, K;
  cin >> n >> K;

  string s;
  cin >> s;

  int lc = 0, score = 0;

  vector<int> blocks (1, 0); // LWLWLWLWL..
  char last = 'L';
  for (char c : s) {
    if (c == 'W') {
      score++;
      if (last != 'L') {
        score++;
      }
    } else {
      lc++;
    }

    if (c != last) {
      blocks.push_back(0);
    }
    blocks.back()++;
    last = c;
  }

  if (lc == n) {
    cout << max(0, 2 * K - 1) << '\n';
    return;
  }
  
  K = min(K, lc);
  score += 2 * K;

  vector<int> mgables;
  for (int i = 2; i < (int) blocks.size() - 1; i += 2) {
    mgables.push_back(blocks[i]);
  }
  sort(mgables.begin(), mgables.end());

  for (int b : mgables) {
    if (K >= b) {
      score++;
      K -= b;
    }
  }

  cout << score << '\n';
}

int main () {
  ios::sync_with_stdio(false);

  int testc;
  cin >> testc;

  for (int t = 0; t < testc; t++) {
    solve();
  }
}