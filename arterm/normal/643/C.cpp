#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int M = 200200;
const int N = 53;

int n, k, a[M];
ld s[M], t[M];
ld d[N][M];

void read() {
  cin >> n >> k;
  for (int i = 0; i < n; ++i)
    cin >> a[i];
}

void pre() {
  s[0] = 0;
  t[0] = 0;
  for (int i = 0; i < n; ++i) {
    s[i + 1] = s[i] + a[i];
    t[i + 1] = t[i] + 1.0 / a[i];
  }
}

void ini() {
  for (int i = 1; i <= n; ++i)
    d[1][i] = 0;
}

void solve(int k, int l, int r, int le, int re) {
  int pos = le;
  int m = (l + r) / 2;
  
  d[k][m] = -1.0;

  for (int i = max(le, k - 1); i <= re && i < m; ++i) {
    ld nw = d[k - 1][i] + s[i] * (t[m] - t[i]);
    if (nw >= d[k][m]) {
      pos = i;
      d[k][m] = nw;
    }
  }

  if (l <= m - 1)
    solve(k, l, m - 1, le, pos);
  if (m + 1 <= r)
    solve(k, m + 1, r, pos, re);
}

void kill() {
  ini();
  for (int i = 2; i <= k; ++i)
    solve(i, 1, n, 1, n);

  ld sum = 0.0;
  for (int i = 0; i < n; ++i)
    sum += a[i] * (t[n] - t[i]);

  //for (int i = 1; i <= n; ++i)
    //cout << d[k][i] << " ";
  //cout << endl;

  //cout << d[k][n] << "\n";
  cout << sum - d[k][n] << "\n";
}

int main() {
  cout.precision(20);
  cout << fixed;
  ios_base::sync_with_stdio(false);
  read();
  pre();
  kill();
}