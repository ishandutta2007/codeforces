#include <iostream>

using namespace std;

const int MAX_N = 105;

int n, m, K;
int grid [MAX_N][MAX_N];

const int BIG = 12;

namespace big {
  int count_mistakes (int a, int b) {
    int ans = 0;
    for (int j = 0; j < m; j++) {
      ans += grid[a][j] != grid[b][j];
    }
    return ans;
  }
  
  int solve () {
    int ans = K + 1;
    for (int t = 0; t < n; t++) {
      int cur = 0;
      for (int i = 0; i < n; i++) {
        int mis = count_mistakes(i, t);
        cur += min(mis, m - mis);
      }
      ans = min(ans, cur);
    }

    if (ans > K) {
      return -1;
    } else {
      return ans;
    }
  }
}

namespace small {
  int count_mistakes (int col, int mask) {
    int ans = 0;
    for (int i = 0; i < n; i++) {
      if (!!(mask & 1 << i) ^ grid[i][col]) {
        ans++;
      }
    }
    return ans;
  }
  
  int solve () {
    int ans = K + 1;
    for (int mask = 0; mask < 1 << n; mask++) {
      int cur = 0;
      for (int j = 0; j < m; j++) {
        int mis = count_mistakes(j, mask);
        cur += min(mis, n - mis);
      }
      ans = min(ans, cur);
    }

    if (ans > K) {
      return -1;
    } else {
      return ans;
    }
  }
}

int main () {
  ios::sync_with_stdio(false);

  cin >> n >> m >> K;

  bool trans = 0;
  if (n < m) {
    trans = 1;
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (trans) {
        cin >> grid[j][i];
      } else {
        cin >> grid[i][j];
      }
    }
  }

  if (trans) {
    swap(n, m);
  }

  // WLOG now n >= m

  if (n > BIG) {
    cout << big::solve() << endl;
  } else {
    cout << small::solve() << endl;
  }
}