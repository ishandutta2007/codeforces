#include "bits/stdc++.h"

using namespace std;

vector<string> ans;
int cnt;

void rem(int x, int y) {
  assert(ans[x][y] == 'o');
  assert(ans[y][x] == 'o');

  ans[x][y] = '.';
  ans[y][x] = '.';

  if (x == y) {
    cnt -= 1;
  } else {
    cnt -= 2;
  }
}

int main() {
  int n, m = 1;
  cin >> n;

  if (n == 2) {
    cout << "-1\n";
    return 0;
  }

  while (n > m * m) {
    m++;
  }

  bool special = false;

  if (n == m * m - 2) {
    ++m;
    special = true;
  }

  ans = vector<string>(m, string(m, 'o'));
  cnt = m * m;

  if (special) {
    rem(m - 2, m - 2);
    rem(m - 3, m - 3);
  }


  while (cnt > n) {
    if (ans[m - 1][m - 1] == 'o') {
      rem(m - 1, m - 1);
    } else if (ans[m - 1][m - 2] == 'o') {
      rem(m - 1, m - 2);
    } else if (cnt % 2 != n % 2) {
      rem(m - 2, m - 2);
    } else {
      bool ok = false;
      for (int j = m - 1; j >= 0 && !ok; --j) {
        for (int i = min(m - 3, j - 1); i >= 1 && !ok; --i) {
          if (ans[j][i] == 'o') {
            rem(j, i);
            ok = true;
          }
        }
      }
    }
  }

  cout << m << "\n";
  for (int i = m - 1; i >= 0; --i)
    cout << ans[i] << "\n";
  return 0;
}