#include <iostream>
#include <vector>

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

struct Segments {
  int n;
  vector<int> pre;
  Modint post;
  bool ispost;

  Segments (int _n = 0, int a = 0) : n(_n), pre(_n) {
    for (int i = 0; i < min(n, a); i++) {
      pre[i] = 1;
    }

    post = Modint(max(0, a - n));
    ispost = a > n;
  }

  void merge (const Segments& oth) {
    int res = 0;
    for (int i = 1; i < n; i++) {
      if (oth.pre[i - 1]) {
        res++;
      }

      if (!pre[i] && res) {
        res--;
        pre[i] = 1;
      }
    }

    if (res) {
      post += res;
      ispost = true;
    }
    
    post += oth.post;
    ispost |= oth.ispost;
    
    if (oth.pre[n - 1]) {
      post += 1;
      ispost = true;
    }
  }

  Modint time () {
    if (ispost) {
      return post + n;
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
      if (pre[i]) {
        ans = i + 1;
      }
    }
    return Modint(ans);
  }
};

const int MAX_N = 1e3 + 5;

vector<int> in [MAX_N];
int outc [MAX_N];
Segments dp [MAX_N];
bool vis [MAX_N];

void process (int u) {
  for (int prv : in[u]) {
    if (!vis[prv]) {
      process(prv);
    }
    dp[u].merge(dp[prv]);
  }
  vis[u] = 1;
}

void solve () {
  int n, m;
  cin >> n >> m;

  for (int i = 1; i <= n; i++) {
    in[i].clear();
    vis[i] = false;
    outc[i] = 0;
  }

  for (int i = 1; i <= n; i++) {
    int a;
    cin >> a;
    dp[i] = Segments(n + 5, a);
  }

  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;

    in[v].push_back(u);
    outc[u]++;
  }

  int sink = -1;
  for (int i = 1; i <= n; i++) {
    if (outc[i] == 0) {
      sink = i;
    }
  }

  process(sink);
  cout << dp[sink].time() << '\n';
}

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int testc;
  cin >> testc;

  for (int i = 0; i < testc; i++) {
    solve();
  }
}