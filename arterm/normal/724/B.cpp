#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int M = 107;

int n, m, a[M][M], b[M][M];

void read() {
  cin >> n >> m;
  for (int j = 0; j < n; ++j) {
    for (int i = 0; i < m; ++i) {
      int x;
      cin >> x;
      --x;
      a[j][i] = x;
    }
  }
}

bool can() {
  for (int i = 0; i < n; ++i) {
    int cnt = 0;
    for (int j = 0; j < m; ++j)
      if (b[i][j] != j)
        ++cnt;
    if (cnt > 2)
      return false;
  }
  return true;
}

void yes() {
  cout << "YES\n";
  exit(0);
}

void kill() {
  for (int i = 0; i < n; ++i)
    copy(a[i], a[i] + m, b[i]);

  if (can())
    yes();

  for (int l = 0; l < m; ++l)
    for (int r = l + 1; r < m; ++r) {
      for (int i = 0; i < n; ++i) {
        copy(a[i], a[i] + m, b[i]);
        swap(b[i][l], b[i][r]);
      }
      if (can())
        yes();
    }
  
  cout << "NO\n";
}
      

int main() {
  cout.precision(20);
  cout << fixed;
  ios_base::sync_with_stdio(false);
  read();
  kill();
}