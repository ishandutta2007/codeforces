#include <iostream>
#include <vector>
#include <set>
 
using namespace std;
 
typedef long long ll;
 
const int MOD = 3;
 
struct Modint {
  ll val;
  
  Modint (ll _val = 0)
    : val(_val % MOD) {}
 
  Modint operator+ (Modint other) const {
    return Modint(val + other.val);
  }
 
  void operator+= (Modint other) {
    val += other.val;
    val %= MOD;
  }
 
  Modint operator- () const {
    return Modint(MOD - val);
  }
 
  Modint operator- (Modint other) const {
    return Modint(val + MOD - other.val);
  }
 
  void operator-= (Modint other) {
    val += MOD - other.val;
    val %= MOD;
  }
 
  Modint operator* (Modint other) const {
    return Modint(val * other.val);
  }
 
  void operator*= (Modint other) {
    val *= other.val;
    val %= MOD;
  }
 
  bool operator== (Modint other) const {
    return val == other.val;
  }
 
  bool operator!= (Modint other) const {
    return val != other.val;
  }
};
 
Modint exp (Modint a, int k) {
  if (k == 0) {
    return Modint(1);
  } else if (k % 2 == 0) {
    Modint half = exp(a, k / 2);
    return half * half;
  } else {
    return a * exp(a, k - 1);
  }
}
 
Modint inv (Modint a) {
  return exp(a, MOD - 2);
}
 
ostream& operator<< (ostream& out, Modint p) {
  out << p.val;
  return out;
}
 
// Source: https://cp-algorithms.com/linear_algebra/linear-system-gauss.html
void gauss (vector<vector<Modint>> a, vector<Modint> &ans) {
  int n = (int) a.size();
  int m = (int) a[0].size() - 1;
 
  vector<int> where (m, -1);
  for (int col=0, row=0; col<m && row<n; ++col) {
    int sel = row;
    for (int i=row; i<n; ++i)
      if (a[i][col].val > a[sel][col].val)
        sel = i;
    if (a[sel][col] == Modint(0))
      continue;
    for (int i=col; i<=m; ++i)
      swap (a[sel][i], a[row][i]);
    where[col] = row;
 
    for (int i=0; i<n; ++i)
      if (i != row) {
        Modint c = a[i][col] * inv(a[row][col]);
        for (int j=col; j<=m; ++j)
          a[i][j] -= a[row][j] * c;
      }
    ++row;
  }
 
  ans.assign (m, 0);
  for (int i=0; i<m; ++i)
    if (where[i] != -1)
      ans[i] = a[where[i]][m] * inv(a[where[i]][i]);

  for (int i=0; i<n; ++i) {
    Modint sum = 0;
    for (int j=0; j<m; ++j)
      sum += ans[j] * a[i][j];
    if (sum != a[i][m]) {
      ans.clear();
    }
  }
}

const int MAX_N = 64;

int conn [MAX_N][MAX_N];

void solve () {
  int n, m;
  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      conn[i][j] = -1;
    }
  }

  vector<vector<Modint>> A (0);
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    u--; v--;

    conn[u][v] = i;
    conn[v][u] = i;
    if (w != -1) {
      w--;
      A.emplace_back(m + 1, Modint(0));
      A.back()[i] = Modint(1);
      A.back().back() = Modint(w);
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (conn[i][j] == -1) continue;
      for (int k = j + 1; k < n; k++) {
        if (conn[i][k] == -1) continue;
        if (conn[j][k] == -1) continue;

        A.emplace_back(m + 1, Modint(0));
        A.back()[conn[i][j]] = Modint(1);
        A.back()[conn[i][k]] = Modint(1);
        A.back()[conn[j][k]] = Modint(1);
      }
    }
  }

  if (A.empty()) {
    // special case
    for (int i = 0; i < m; i++) {
      cout << 1 << " ";
    }
    cout << '\n';
    return;
  }
  
  vector<Modint> ans;
  gauss(A, ans);
  if (ans.empty()) {
    cout << -1 << '\n';
    return;
  }

  for (int i = 0; i < m; i++) {
    cout << ans[i].val + 1 << " ";
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