#include <iostream>
#include <string>

using namespace std;

typedef long long ll;

const int MOD = 1e9 + 2017;

struct Modint {
  ll val;
  
  Modint (ll _val = 0)
    : val(_val % MOD) {}

  Modint operator+ (Modint other) {
    return Modint(val + other.val);
  }

  void operator+= (Modint other) {
    val += other.val;
    val %= MOD;
  }

  Modint operator- () {
    return Modint(MOD - val);
  }

  Modint operator- (Modint other) {
    return Modint(val + MOD - other.val);
  }

  void operator-= (Modint other) {
    val += MOD - other.val;
    val %= MOD;
  }

  Modint operator* (Modint other) {
    return Modint(val * other.val);
  }

  void operator*= (Modint other) {
    val *= other.val;
    val %= MOD;
  }

  bool operator== (Modint other) {
    return val == other.val;
  }

  bool operator!= (Modint other) {
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

Modint BASE (3);
const int MAX_N = 5e5 + 5;

Modint pref_hsh [MAX_N];
Modint suff_hsh [MAX_N];

int arr [MAX_N];

int main () {
  ios::sync_with_stdio(false);

  string s, t;
  cin >> s >> t;

  int c0 = 0, c1 = 0;
  for (char c : s) {
    if (c == '0') c0++;
    else c1++;
  }

  int n = t.size();
  for (int i = 1; i <= n; i++) {
    arr[i] = t[i - 1] - '0';
  }

  for (int i = 1; i <= n; i++) {
    pref_hsh[i] = BASE * pref_hsh[i - 1] + Modint(arr[i] + 1);
  }

  Modint mul (1);
  for (int i = n; i >= 1; i--) {
    suff_hsh[i] = suff_hsh[i + 1] + mul * Modint(arr[i] + 1);
    mul *= BASE;
  }

  int suffs = 1;
  for (int i = 1; i < n; i++) {
    if (pref_hsh[i] == suff_hsh[n - i + 1]) {
      suffs = i + 1;
    }
  }

  int cost0 = 0, cost1 = 0;
  for (int i = suffs; i <= n; i++) {
    if (arr[i] == 0) cost0++;
    else cost1++;
  }

  int init0 = 0, init1 = 0;
  for (int i = 1; i <= n; i++) {
    if (arr[i] == 0) init0++;
    else init1++;
  }

  if (c0 < init0 || c1 < init1) {
    cout << s << endl;
    return 0;
  }

  c0 -= init0;
  c1 -= init1;
  cout << t;

  while (c0 >= cost0 && c1 >= cost1) {
    for (int i = suffs; i <= n; i++) {
      cout << arr[i];
    }
    
    c0 -= cost0;
    c1 -= cost1;
  }

  for (int i = 0; i < c0; i++) cout << 0;
  for (int j = 0; j < c1; j++) cout << 1;
  cout << endl;
}