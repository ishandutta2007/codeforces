#include <iostream>
#define rank ___rank
#include <vector>
 
using namespace std;
 
typedef long long ll;

/* resubmit for diagnostics */
 
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
 
const int MAX_N = 2e5 + 5;
const int BITS = 40;
 
ll compr (ll mask, ll filter) {
  ll ans = 0;
  for (int i = 0; i < BITS; i++) {
    if (filter & 1LL << i) {
      ans *= 2;
      if (mask & 1LL << i) {
        ans++;
      }
    }
  }
  return ans;
}
 
ll arr [MAX_N];
ll basis [BITS];
int used [MAX_N];
 
ll pans [BITS];
Modint ans [BITS];
 
Modint dp [1 << 15][40];
 
int main () {
  ios::sync_with_stdio(false);
 
  int n, m;
  cin >> n >> m;
 
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
 
  for (int i = 0; i < m; i++) {
    int pivot = -1;
    for (int j = 0; j < n; j++) {
      if (!used[j] && (arr[j] & 1LL << i)) {
        pivot = j;
        break;
      }
    }
 
    if (pivot == -1) {
      basis[i] = -1;
    } else {
      used[pivot] = 1;
      basis[i] = arr[pivot];
      for (int j = 0; j < n; j++) {
        if (!used[j] && (arr[j] & 1LL << i)) {
          arr[j] ^= basis[i];
        }
      }
    }
  }
 
  int rank = 0;
  for (int i = m - 1; i >= 0; i--) {
    if (basis[i] != -1) {
      rank++;
      for (int j = i - 1; j >= 0; j--) {
        if (basis[j] != -1 && (basis[j] & 1LL << i)) {
          basis[j] ^= basis[i];
        }
      }
    }
  }
 
  int mul = m - rank;
  if (rank <= 20) {
    vector<ll> bvs;
    for (int i = 0; i < m; i++) {
      if (basis[i] != -1) {
        bvs.push_back(basis[i]);
      }
    }
 
    int k = bvs.size();
    for (int i = 0; i < 1 << k; i++) {
      ll cur = 0;
      for (int j = 0; j < k; j++) {
        if (i & 1 << j) {
          cur ^= bvs[j];
        }
      }
 
      pans[__builtin_popcountll(cur)]++;
    }
 
    for (int i = 0; i <= m; i++) {
      ans[i] = Modint(pans[i]);
    }
  } else {
    ll depb = 0;
    for (int j = 0; j < m; j++) {
      if (basis[j] == -1) {
        depb |= 1LL << j;
      }
    }
 
    vector<ll> frees;
    for (int i = 0; i < m; i++) {
      if (basis[i] != -1) {
        frees.push_back(compr(basis[i] & depb, depb));
      }
    }
 
    dp[0][0] = Modint(1);
    for (int i = 0; i < rank; i++) {
      vector<pair<pair<ll, int>, Modint>> upds;
      for (int j = 0; j < 1 << mul; j++) {
        for (int k = 0; k < rank; k++) {
          if (dp[j][k] != Modint(0)) {
            upds.push_back(make_pair(make_pair(j ^ frees[i], k + 1), dp[j][k]));
          }
        }
      }
 
      for (auto pr : upds) {
        dp[pr.first.first][pr.first.second] += pr.second;
      }
    }
 
    for (int j = 0; j < 1 << mul; j++) {
      for (int k = 0; k <= rank; k++) {
        ans[__builtin_popcountll(j) + k] += dp[j][k];
      }
    }
  }
 
  Modint tk = exp(Modint(2), n - rank);
  for (int i = 0; i <= m; i++) {
    cout << ans[i] * tk << " ";
  }
  cout << endl;
}