#include <bits/stdc++.h>
using namespace std;

#define ldb long double

vector<vector<ldb>> mul(vector<vector<ldb>> a, vector<vector<ldb>> b) {
  vector<vector<ldb>> c(a.size(), vector<ldb> (b[0].size()));
  for (int i = 0; i < (int) a.size(); i++) {
    for (int j = 0; j < (int) a[0].size(); j++) {
      for (int k = 0; k < (int) b[0].size(); k++) {
        c[i][k] += a[i][j] * b[j][k];
      }
    }
  }
  return c;
}

vector<vector<ldb>> powm(vector<vector<ldb>> a, int n) {
  if (n == 1) {
    return a;
  }
  if (n % 2 == 0) {
    return powm(mul(a, a), n / 2);
  }
  return mul(powm(a, n - 1), a);
}

void solve() {
  int n, x;
  cin >> n >> x;
  vector<ldb> p(x + 1);
  for (int i = 0; i <= x; i++) {
    cin >> p[i];
  }
  x = 128;
  while ((int) p.size() < x) {
    p.push_back(0);
  }
  if (0 && n == 1) {
    cout << 1 - p[0] << endl;
    return;
  }
  vector<vector<ldb>> mat(x, vector<ldb> (x));
  for (int i = 0; i < x; i++) {
    for (int j = 0; j < x; j++) {
      mat[i][i ^ j] += p[j];
    }
  }
  mat = powm(mat, n);
  cout.precision(20);
  cout << 1 - mat[0][0] << endl;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  t = 1;
  while (t--)
    solve();
}