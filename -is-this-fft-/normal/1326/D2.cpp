#include <iostream>
#include <string>

using namespace std;

typedef long long ll;
 
const int MOD = 998244353; // change if needed
 
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

const int BASE = 301;
const int MAX_S = 1e6 + 5;

Modint hsh [MAX_S];
Modint rhsh [MAX_S];
Modint bpow [MAX_S];

void solve () {
  string s;
  cin >> s;

  int n = s.size();
  int lptr = 0, rptr = n - 1;

  while (lptr < rptr && s[lptr] == s[rptr]) {
    lptr++;
    rptr--;
  }

  if (lptr > rptr) {
    cout << s << '\n';
    return;
  }

  if (lptr == rptr) {
    cout << s << '\n';
    return;
  }

  Modint cur_hsh (0);
  for (int i = lptr; i <= rptr; i++) {
    cur_hsh *= BASE;
    cur_hsh += Modint(s[i]);
    hsh[i] = cur_hsh;
  }

  Modint cur_rev (0);
  for (int i = rptr; i >= lptr; i--) {
    cur_rev *= BASE;
    cur_rev += Modint(s[i]);
    rhsh[i] = cur_rev;
  }

  int ans1 = 0;
  for (int i = lptr; i < rptr; i++) {
    Modint ltr = hsh[i];
    Modint rtl = rhsh[lptr] - rhsh[i + 1] * bpow[i + 1 - lptr];

    if (ltr == rtl) {
      ans1 = i - lptr + 1;
    }
  }

  int ans2 = 0;
  for (int i = rptr; i > lptr; i--) {
    Modint rtl = rhsh[i];
    Modint ltr = hsh[rptr] - hsh[i - 1] * bpow[rptr - (i - 1)];

    if (ltr == rtl) {
      ans2 = rptr - i + 1;
    }
  }

  for (int i = 0; i < lptr; i++) {
    cout << s[i];
  }
  // cout << "|";
  if (ans1 > ans2) {
    for (int i = lptr; i < lptr + ans1; i++) {
      cout << s[i];
    }
  } else {
    for (int i = rptr - ans2 + 1; i <= rptr; i++) {
      cout << s[i];
    }
  }
  // cout << "|";
  for (int i = rptr + 1; i < n; i++) {
    cout << s[i];
  }
  cout << '\n';
}

int main () {
  ios::sync_with_stdio(false);

  bpow[0] = Modint(1);
  for (int i = 1; i < MAX_S; i++) {
    bpow[i] = bpow[i - 1] * BASE;
  }
  
  int testc;
  cin >> testc;

  for (int t = 0; t < testc; t++) {
    solve();
  }
}