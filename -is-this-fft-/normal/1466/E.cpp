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

const int MAX_N = 5e5 + 5;
const int MAX_LG = 60;

ll arr [MAX_N];
int cnt [MAX_LG];
Modint tpow [MAX_LG];

void solve () {
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  for (int i = 0; i < MAX_LG; i++) {
    cnt[i] = 0;
  }

  for (int i = 0; i < n; i++) {
    for (int b = 0; b < MAX_LG; b++) {
      if (arr[i] & 1LL << b) {
        cnt[b]++;
      }
    }
  }

  Modint ans (0);
  for (int j = 0; j < n; j++) {
    Modint oths (0);
    for (int b = 0; b < MAX_LG; b++) {
      if (!(arr[j] & 1LL << b)) {
        oths += tpow[b] * Modint(cnt[b]);
      }
    }

    for (int a = 0; a < MAX_LG; a++) {
      if (arr[j] & 1LL << a) {
        Modint cur = Modint(arr[j]) * Modint(n) + oths;
        cur *= Modint(cnt[a]) * tpow[a];
        ans += cur;
      }
    }
  }

  cout << ans << '\n';
}

int main () {
  for (int i = 0; i < MAX_LG; i++) {
    tpow[i] = Modint(1LL << i);
  }
  
  ios::sync_with_stdio(false);
  cin.tie(0);

  int testc;
  cin >> testc;

  for (int i = 0; i < testc; i++) {
    solve();
  }
}