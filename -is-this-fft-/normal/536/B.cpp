#include <iostream>

using namespace std;

typedef long long ll;

const ll MOD = 3006703054056749LL;

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

ostream& operator<< (ostream& out, Modint p) {
  out << p.val;
  return out;
}

void failure () {
  cout << 0 << endl;
  exit(0);
}

const Modint BASE (31);

const int MAX_N = 1e6 + 5;

Modint pref [MAX_N];
Modint suff [MAX_N];
int occs [MAX_N];

int cnt_cov [MAX_N];

int main () {
  ios::sync_with_stdio(false);

  int n, m;
  cin >> n >> m;
  
  string P;
  cin >> P;

  for (int i = 0; i < m; i++) {
    cin >> occs[i];
  }

  int K = P.size();
  for (int i = 1; i <= K; i++) {
    pref[i] = pref[i - 1] * BASE + Modint(P[i - 1] - 'a');
  }

  Modint bpow (1);
  for (int i = K - 1; i >= 0; i--) {
    suff[i] = suff[i + 1] + Modint(P[i] - 'a') * bpow;
    bpow *= BASE;
  }

  for (int i = 0; i < m - 1; i++) {
    int len = K - (occs[i + 1] - occs[i]);
    if (len > 0) {
      if (pref[len] != suff[occs[i + 1] - occs[i]]) {
        failure();
      }
    }
  }

  for (int i = 0; i < m; i++) {
    cnt_cov[occs[i]]++;
    cnt_cov[occs[i] + K]--;
  }

  for (int i = 1; i <= n; i++) {
    cnt_cov[i] += cnt_cov[i - 1];
  }
  
  ll ans = 1;
  for (int i = 1; i <= n; i++) {
    if (cnt_cov[i] == 0) {
      ans *= 26;
      ans %= 1000000007;
    }
  }

  cout << ans << endl;
}