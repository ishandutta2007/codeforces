#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <map>
#include <deque>
#include <set>
#include <algorithm>

using namespace std;

void failure () {
  cout << -1 << endl;
  exit(0);
}

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

const int MAX_N = 1505;

Modint base;

int hsh (const vector<int> &vec) {
  Modint h (0);
  for (int u : vec) {
    h *= base;
    h += Modint(u);
  }

  return h.val;
}

vector<int> A [MAX_N];
vector<int> B [MAX_N];

vector<int> cols_by_brk [MAX_N];
int brkc [MAX_N];

set<int> avail;

void allow_brk (int row) {
  for (int col : cols_by_brk[row]) {
    brkc[col]--;
    if (brkc[col] == 0) {
      avail.insert(col);
    }
  }
  cols_by_brk[row].clear();
}

int main () {
  mt19937 rng (chrono::steady_clock::now().time_since_epoch().count());
  int ba = MAX_N + rng() % MAX_N;
  base = Modint(ba);

  ios::sync_with_stdio(false);
  
  int n, m;
  cin >> n >> m;

  map<int, deque<int>> ids_by_hash;
  for (int i = 0; i < n; i++) {
    A[i] = vector<int> (m);
    for (int j = 0; j < m; j++) {
      cin >> A[i][j];
    }

    ids_by_hash[hsh(A[i])].push_back(i);
  }

  for (int i = 0; i < n; i++) {
    B[i] = vector<int> (m);
    for (int j = 0; j < m; j++) {
      cin >> B[i][j];
    }

    if (ids_by_hash[hsh(B[i])].empty()) {
      failure();
    }
    int bk = ids_by_hash[hsh(B[i])].front();
    ids_by_hash[hsh(B[i])].pop_front();
    B[i].push_back(bk);
  }

  m++;

  for (int j = 0; j < m; j++) {
    for (int i = 0; i < n - 1; i++) {
      if (B[i][j] > B[i + 1][j]) {
        brkc[j]++;
        cols_by_brk[i].push_back(j);
      }
    }
  }

  for (int j = 0; j < m; j++) {
    if (brkc[j] == 0) {
      avail.insert(j);
    }
  }

  vector<int> cols;
  while (!avail.empty()) {
    auto cur = *avail.rbegin();
    avail.erase(cur);

    if (cur == m - 1) {
      reverse(cols.begin(), cols.end());
      cout << (int) cols.size() << '\n';
      for (int u : cols) {
        cout << u + 1 << " ";
      }
      cout << '\n';
      return 0;
    }

    for (int i = 0; i < n - 1; i++) {
      if (B[i][cur] != B[i + 1][cur]) {
        allow_brk(i);
      }
    }
    cols.push_back(cur);
  }

  failure();
}