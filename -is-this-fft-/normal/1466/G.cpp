#include <iostream>
#include <vector>

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
const int ALPH = 26;

Modint pref [ALPH][MAX_N];
Modint tpow [MAX_N];
Modint itpow [MAX_N];

string T;

Modint solve (const string &s, int pos, int jmp, int lvl, int maxl) {
  int n = s.size();
  if (lvl > maxl) {
    return Modint(0);
  }

  if (pos >= n) {
    return Modint(0);
  }

  if (pos + jmp >= n) {
    int cha = s[pos] - 'a';
    Modint cur = pref[cha][maxl];
    if (lvl != 0) {
      cur -= pref[cha][lvl - 1];
    }
    cur *= tpow[maxl];
    return cur;
  }

  Modint ans (0);
  for (int add = 0; add < 2; add++) {
    bool ok = true;
    for (int i = pos + add * jmp; i < n; i += 2 * jmp) {
      if (s[i] != T[lvl]) {
        ok = false;
        break;
      }
    }

    if (ok) {
      ans += solve(s, pos + (1 - add) * jmp, 2 * jmp, lvl + 1, maxl);
    }
  }

  return ans;
}

string S;
const int MAX_S = 105;

const Modint BASE [2] = {277, 331};
Modint S_hsh [2][MAX_S];

const int MAX_L = 1e6 + 5;

Modint hsh [2][MAX_L];
bool match (int wL, int wR, int m) {
  int sL = 0, sR = (int) S.size() - 1;

  if (wR >= m) {
    sR -= wR - m + 1;
    wR = m - 1;
  }

  if (wL < 0) {
    sL -= wL;
    wL = 0;
  }

  int len = sR - sL + 1;
  if (len <= 0) {
    return true;
  }

  for (int i = 0; i < 2; i++) {
    auto sH = S_hsh[i][sR];
    if (sL != 0) {
      sH -= S_hsh[i][sL - 1] * exp(BASE[i], len);
    }

    auto wH = hsh[i][wR];
    if (wL != 0) {
      wH -= hsh[i][wL - 1] * exp(BASE[i], len);
    }

    if (sH != wH) {
      return false;
    }
  }
  return true;
}

Modint solve (string &W, int maxl) {
  int m = W.size();

  for (int a = 0; a < 2; a++) {
    hsh[a][0] = Modint(W[0]);
    for (int i = 1; i < m; i++) {
      hsh[a][i] = BASE[a] * hsh[a][i - 1] + Modint(W[i]);
    }
  }
  
  Modint ans (0);
  int K = S.size();
  for (int t = 0; t <= K; t++) {
    bool can = true;
    for (int i = t - (K + 1); i < m; i += K + 1) {
      if (!match(i + 1, i + K, m)) {
        can = false;
      }
    }
    
    if (!can) {
      continue;
    }
    
    string cur;
    for (int i = t; i < (int) W.size(); i += K + 1) {
      cur += W[i];
    }
    
    if (cur.empty()) {
      ans += tpow[maxl + 1];
    } else {
      ans += solve(cur, 0, 1, 0, maxl);
    }
  }
  return ans;
}

int main () {
  tpow[0] = Modint(1);
  for (int i = 1; i < MAX_N; i++) {
    tpow[i] = Modint(2) * tpow[i - 1];
  }

  Modint i2 = inv(Modint(2));
  itpow[0] = Modint(1);
  for (int i = 1; i < MAX_N; i++) {
    itpow[i] = i2 * itpow[i - 1];
  }
  
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, qc;
  cin >> n >> qc;
  cin >> S >> T;

  for (int a = 0; a < 2; a++) {
    S_hsh[a][0] = Modint(S[0]);
    for (int i = 1; i < (int) S.size(); i++) {
      S_hsh[a][i] = S_hsh[a][i - 1] * BASE[a] + Modint(S[i]);
    }
  }
  
  for (int i = 0; i < (int) T.size(); i++) {
    pref[T[i] - 'a'][i] += itpow[i];
  }

  for (int a = 0; a < ALPH; a++) {
    for (int i = 1; i < (int) T.size(); i++) {
      pref[a][i] += pref[a][i - 1];
    }
  }
  
  for (int i = 0; i < qc; i++) {
    int maxl;
    string W;
    cin >> maxl >> W;
    maxl--;

    cout << solve(W, maxl) << '\n';
  }
}