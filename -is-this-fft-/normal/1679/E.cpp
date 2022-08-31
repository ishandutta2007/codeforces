#include <iostream>

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

const int MAX_C = 17;

Modint dp [1 << MAX_C][MAX_C];

void add (int mask, int ex) {
  for (int i = 0; i < MAX_C; i++) {
    dp[mask][i] += exp(Modint(i + 1), ex);
  }
}

void precalc (const string &s, int l, int r, int tot_qms) {
  int n = s.size();
  int e = tot_qms, mask = 0;
  
  while (true) {
    if (s[l] == '?') e--;
    if (l != r && s[r] == '?') e--;
    
    if (s[l] == '?' && s[r] == '?') {
      e++;
    } else if (s[l] == '?') {
      mask |= 1 << (s[r] - 'a');
    } else if (s[r] == '?') {
      mask |= 1 << (s[l] - 'a');
    } else if (s[l] != s[r]) {
      break;
    }

    add(mask, e);
    
    l--;
    r++;
    if (l < 0 || n <= r)
      break;
  }
}

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  int n;
  cin >> n;

  string s;
  cin >> s;

  int tot_qms = 0;
  for (char c : s) {
    if (c == '?')
      tot_qms++;
  }
  
  // even middles
  for (int i = 0; i < n - 1; i++) {
    precalc(s, i, i + 1, tot_qms);
  }

  for (int i = 0; i < n; i++) {
    precalc(s, i, i, tot_qms);
  }

  for (int k = 0; k < MAX_C; k++) {
    for (int mask = 0; mask < 1 << MAX_C; mask++) {
      if (mask & 1 << k) {
        for (int i = 0; i < MAX_C; i++) {
          dp[mask][i] += dp[mask - (1 << k)][i];
        }
      }
    }
  }

  int qc;
  cin >> qc;
  
  for (int i = 0; i < qc; i++) {
    string q;
    cin >> q;

    int mask = 0;
    for (char c : q) {
      mask |= 1 << (c - 'a');
    }

    cout << dp[mask][(int) q.size() - 1] << '\n';
  }
}