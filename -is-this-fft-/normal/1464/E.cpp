#include <iostream>
#include <vector>
#include <set>

using namespace std;

typedef long long ll;

const int MOD = 998244353;

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
}

const int MAX_N = 1e5 + 5;
const int MAX_B = 9;

vector<int> out_adj [MAX_N];
int vis [MAX_N];
int grundy [MAX_N];

void build (int u) {
  vis[u] = 1;
  
  for (int nxt : out_adj[u]) {
    if (!vis[nxt]) {
      build(nxt);
    }
  }

  set<int> mexb;
  for (int i = 0; i < (int) out_adj[u].size() + 1; i++) {
    mexb.insert(i);
  }

  for (int nxt : out_adj[u]) {
    mexb.erase(grundy[nxt]);
  }
  grundy[u] = *mexb.begin();
}

int cnt [1 << MAX_B];

int main () {
  ios::sync_with_stdio(false);

  int n, m;
  cin >> n >> m;

  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;

    out_adj[u].push_back(v);
  }

  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      build(i);
    }

    cnt[grundy[i]]++;
  }

  Modint ip = inv(Modint(n + 1));

  vector<vector<Modint>> A (0);
  for (int i = 0; i < 1 << MAX_B; i++) {
    vector<Modint> row (1 << MAX_B, 0);
    row[i] = Modint(-1);

    for (int j = 0; j < 1 << MAX_B; j++) {
      row[i ^ j] += Modint(cnt[j]) * ip; 
    }

    if (i == 0) {
      row.push_back(Modint(0));
    } else {
      row.push_back(ip);
    }

    A.push_back(row);
  }

  vector<Modint> ans;
  gauss(A, ans);

  cout << -ans[0] << endl;
}