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

struct Fenwick {
  vector<int> tree;

public:
  Fenwick (int n) : tree(n, 0) {}
  
  void add (int idx, int val) {
    for (int i = idx; i < (int) tree.size(); i += i & -i) {
      tree[i] += val;
    }
  }

  int get (int idx) {
    int ans = 0;
    for (int i = idx; i > 0; i -= i & -i) {
      ans += tree[i];
    }
    return ans;
  }
};

const int MAX_N = 2e5 + 5;

Modint fact [MAX_N];
Modint ifact [MAX_N];

int cnt [MAX_N];
int T [MAX_N];

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
  
  int n, m;
  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;

    cnt[x]++;
  }

  for (int i = 0; i < m; i++) {
    cin >> T[i];
  }

  Fenwick cntf (MAX_N);
  Modint mult = fact[n];
  for (int i = 1; i < MAX_N; i++) {
    cntf.add(i, cnt[i]);
    mult *= inv(fact[cnt[i]]);
  }

  Modint ans = 0;
  for (int k = 0; k < m && k <= n; k++) { // len common prefix
    if (k == n) {
      ans += 1;
      break;
    }
    
    mult *= inv(n - k);
    ans += mult * cntf.get(T[k] - 1);

    if (cnt[T[k]] == 0) {
      break;
    }

    mult *= cnt[T[k]];
    cnt[T[k]]--;
    cntf.add(T[k], -1);
  }

  cout << ans << '\n';
}