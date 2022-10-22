#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()

using li = long long;

vector<vector<int>> m;

void fill(int i0, int j0, int i1, int j1) {
  int n = (i1 - i0 + 1);

  if (n == 2) {
    m[i0][j0] = m[i0][j0 + 1] = 1;
    return;
  }

  if (n == 4) {
    m[i0][j0 + 1] = m[i0][j0 + 2] = 1;
    m[i0 + 2][j0] = m[i0 + 3][j0] = 1;
    m[i0 + 2][j0 + 3] = m[i0 + 3][j0 + 3] = 1;
    return;
  }

  fill(i0 + 2, j0 + 2, i1 - 2, j1 - 2);

  if (n % 4 == 2) {
    for (int i = i0; i <= i1; ++i) {
      m[i][j0] = ((i - i0) % 4 == 0 || (i - i0) % 4 == 3);
      m[i][j1] = ((i - i0) % 4 == 0 || (i - i0) % 4 == 3);
    }
    for (int j = j0; j <= j1; ++j) {
      m[i0][j] = ((j - j0) % 4 == 0 || (j - j0) % 4 == 1);
      m[i1][j] = ((j - j0) % 4 == 2 || (j - j0) % 4 == 3);
    }
  } else {
    for (int i = i0; i <= i1; ++i) {
      m[i][j0] = ((i - i0) % 4 == 2 || (i - i0) % 4 == 3);
      m[i][j1] = ((i - i0) % 4 == 2 || (i - i0) % 4 == 3);
    }
    for (int j = j0; j <= j1; ++j) {
      m[i0][j] = ((j - j0) % 4 == 1 || (j - j0) % 4 == 2);
      m[i1][j] = ((j - j0) % 4 == 0 || (j - j0) % 4 == 3);
    }
  }
}

void solve(bool read = true) {
  int n;
  cin >> n;

  m.assign(n, vector<int>(n));

  fill(0, 0, n - 1, n - 1);

  /*for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cout << m[i][j];
    }
    cout << "\n";
  }
  cout.flush();*/

  li ans = 0;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      int w = (i ? m[i - 1][j] : 0) + (j ? m[i][j - 1] : 0) + (i + 1 != n ? m[i + 1][j] : 0) + (j + 1 != n ? m[i][j + 1] : 0);
      w %= 2;
      assert(w == 1);

      li x;
      cin >> x;
      if (m[i][j]) {
        ans ^= x;
      }
    }
  }

  cout << ans << "\n";

  /*for (int i = 0; i < n; ++i) {
  }*/
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int nt = 1;
  cin >> nt;

  for (int i = 0; i < nt; ++i) {
    solve(true);
  }

  return 0;
}