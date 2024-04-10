#include <iostream>
#include <vector>
#include <map>

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

const int MAX_N = 2e5 + 5;

int factor [MAX_N];

typedef map<int, int> Factorized;

Factorized factorize (int x) {
  Factorized ans;
  while (x != 1) {
    ans[factor[x]]++;
    x /= factor[x];
  }
  return ans;
}

Factorized operator- (Factorized p, Factorized q) {
  Factorized ans = p;
  for (auto kv : q) {
    ans[kv.first] -= kv.second;
  }
  return ans;
}

vector<pair<int, pair<Modint, Factorized>>> adj [MAX_N];
Modint mul [MAX_N];

void dfs (int u, int p, Factorized &cur, Factorized &mn) {
  for (auto e : adj[u]) {
    if (e.first == p) continue;
    mul[e.first] = mul[u] * e.second.first;

    for (auto kv : e.second.second) {
      cur[kv.first] += kv.second;
      mn[kv.first] = min(mn[kv.first], cur[kv.first]);
    }
    
    dfs(e.first, u, cur, mn);

    for (auto kv : e.second.second) {
      cur[kv.first] -= kv.second;
    }
  }
}

void solve () {
  int n;
  cin >> n;

  for (int i = 1; i <= n; i++) {
    adj[i].clear();
  }

  for (int i = 0; i < n - 1; i++) {
    int u, v, p, q;
    cin >> u >> v >> p >> q;

    auto pf = factorize(p);
    auto qf = factorize(q);

    adj[u].push_back({v, {Modint(q) * inv(Modint(p)), qf - pf}});
    adj[v].push_back({u, {Modint(p) * inv(Modint(q)), pf - qf}});
  }

  mul[1] = Modint(1);
  Factorized cur, mn;
  dfs(1, 0, cur, mn);

  Modint sum (0);
  for (int i = 1; i <= n; i++) {
    sum += mul[i];
  }

  Modint lcm (1);
  for (auto kv : mn) {
    if (kv.second < 0) {
      lcm *= exp(Modint(kv.first), -kv.second);
    }
  }
  
  cout << sum * lcm << '\n';
}

int main () {
  for (int i = 2; i < MAX_N; i++) {
    if (factor[i] == 0) {
      for (int j = i; j < MAX_N; j += i) {
        factor[j] = i;
      }
    }
  }
  
  ios::sync_with_stdio(false);
  cin.tie(0);

  int testc;
  cin >> testc;

  for (int i = 0; i < testc; i++) {
    solve();
  }
}