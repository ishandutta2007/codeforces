#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7; // change if needed

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

ll gcd (ll p, ll q) {
  if (q == 0) return p;
  return gcd(q, p % q);
}

const int MAX_N = 1e6 + 5;

ll arr [MAX_N];
int par [MAX_N];
vector<int> adj [MAX_N];

void dfs (int u) {
  for (int nxt : adj[u]) {
    dfs(nxt);
    arr[u] += arr[nxt];
  }
}

int cnt [MAX_N];
int cntsm [MAX_N];

int exists [MAX_N];
Modint dp [MAX_N];

int main () {
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
  }
  
  for (int i = 2; i <= n; i++) {
    cin >> par[i];
    adj[par[i]].push_back(i);
  }

  dfs(1);
  
  ll S = arr[1];
  for (int i = 1; i <= n; i++) {
    ll gc = gcd(arr[i], S);
    ll b = S / gc;
    
    if (b <= n) {
      cnt[b]++;
    }
  }

  // propagate the b-s over all multiples
  for (int i = 1; i <= n; i++) {
    for (int j = i; j <= n; j += i) {
      cntsm[j] += cnt[i];
    }
  }

  for (int i = 1; i <= n; i++) {
    if (cntsm[i] == i) {
      exists[i] = 1;
    }
  }

  Modint ans (0);
  dp[1] = Modint(1);
  for (int i = 1; i <= n; i++) {
    if (exists[i]) {
      for (int j = 2 * i; j <= n; j += i) {
        if (exists[j]) {
          dp[j] += dp[i];
        }
      }
      ans += dp[i];
    }
  }
  cout << ans << endl;
}