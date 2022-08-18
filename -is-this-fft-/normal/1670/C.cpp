#include <iostream>

using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7; 

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

const int MAX_N = 1e5 + 5;

int A [MAX_N];
int B [MAX_N];
int D [MAX_N];

int nxt [MAX_N];
int choice [MAX_N];

bool vis [MAX_N];

int dfs (int u) {
  vis[u] = 1;

  int ans = choice[u];
  if (!vis[nxt[u]]) {
    ans |= dfs(nxt[u]);
  }
  return ans;
}

void solve () {
  int n;
  cin >> n;

  for (int i = 1; i <= n; i++) {
    cin >> A[i];
  }

  for (int i = 1; i <= n; i++) {
    cin >> B[i];
  }

  for (int i = 1; i <= n; i++) {
    cin >> D[i];
  }

  for (int i = 1; i <= n; i++) {
    nxt[A[i]] = B[i];
    vis[i] = 0;
    
    if (D[i] == A[i]) {
      choice[A[i]] = 1;
    } else if (D[i] == B[i]) {
      choice[A[i]] = 2;
    } else {
      choice[A[i]] = 0;
    }
  }

  Modint ans (1);
  for (int i = 1; i <= n; i++) {
    if (nxt[i] == i) {
      continue;
    }

    if (!vis[i]) {
      int ch = dfs(i);
      if (ch == 0) ans *= 2;
      if (ch == 3) ans *= 0;
    }
  }

  cout << ans << '\n';
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