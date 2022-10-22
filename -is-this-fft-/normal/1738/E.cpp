#include <iostream>
#include <vector>
#include <algorithm>

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

const int MAX_N = 1e5 + 5;

Modint fact [MAX_N];
Modint ifact [MAX_N];

Modint choose (int n, int k) {
  return fact[n] * ifact[k] * ifact[n - k];
}

vector<pair<ll, int>> runs (const vector<ll> &vec) {
  vector<pair<ll, int>> ans;
  for (ll u : vec) {
    if (ans.empty() || ans.back().first != u) {
      ans.push_back(make_pair(u, 0));
    }

    ans.back().second++;
  }

  return ans;
}

void solve () {
  int n;
  cin >> n;

  vector<ll> arr (n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  vector<ll> pref = arr;
  for (int i = 1; i < n; i++) {
    pref[i] += pref[i - 1];
  }

  vector<ll> suff = arr;
  reverse(suff.begin(), suff.end());
  for (int i = 1; i < n; i++) {
    suff[i] += suff[i - 1];
  }

  ll tot = pref.back();
  
  auto prun = runs(pref);
  auto srun = runs(suff);

  Modint ans (1);
  int pptr = 0, sptr = 0;
  int pcnt = 0, scnt = 0;
  while (pptr < (int) prun.size() && sptr < (int) srun.size()) {
    if (prun[pptr].first < srun[sptr].first) {
      pcnt += prun[pptr].second;
      pptr++;
    } else if (srun[sptr].first < prun[pptr].first) {
      scnt += srun[sptr].second;
      sptr++;
    } else {
      ll csum = prun[pptr].first + srun[sptr].first;
      int nsum = pcnt + scnt + prun[pptr].second + srun[sptr].second;
      int pl = prun[pptr].second, sl = srun[sptr].second;
      if (csum == tot && nsum > n) {
        if (csum == 0) {
          ans *= exp(2, pl - 1);
        } else {
          ans *= exp(2, pl);
        }
      } else if (csum > tot) {
        break;
      } else {
        Modint ways (0);
        for (int i = 0; i <= min(pl, sl); i++) {
          ways += choose(pl, i) * choose(sl, i);
        }

        ans *= ways;
      }

      pcnt += prun[pptr].second;
      pptr++;
      scnt += srun[sptr].second;
      sptr++;
    }
  }

  cout << ans << '\n';
}

int main () {
  fact[0] = 1;
  for (int i = 1; i < MAX_N; i++) {
    fact[i] = fact[i - 1] * i;
  }

  for (int i = 0; i < MAX_N; i++) {
    ifact[i] = inv(fact[i]);
  }
  
  ios::sync_with_stdio(false);
  cin.tie(0);

  int testc;
  cin >> testc;

  for (int i = 0; i < testc; i++) {
    solve();
  }
}