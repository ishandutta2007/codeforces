#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef unsigned char uchar;

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

const int MAX_N = 2e5 + 5;
const int ALPHA = 256;

Modint fact [MAX_N];
Modint ifact [MAX_N];

Modint dp [MAX_N];

void add (int u, int target) {
  if (u == 0) return;
  
  for (int i = target - 1; i >= 0; i--) {
    dp[i + u] += dp[i];
  }
}

void del (int u, int target) {
  if (u == 0) return;
  
  for (int i = 0; i < target; i++) {
    dp[i + u] -= dp[i];
  }
}

int n;
int cnt [ALPHA];
bool memo [ALPHA][ALPHA];
Modint ans [ALPHA][ALPHA];

Modint calc (uchar a, uchar b) {
  int cur_cnt = cnt[a];
  if (a != b) {
    cur_cnt += cnt[b];
  }
  
  if (cur_cnt > n / 2) {
    return 0;
  }
  
  del(cnt[a], n / 2);
  if (b != a) {
    del(cnt[b], n / 2);
  }

  Modint ways = dp[n / 2 - cur_cnt];
  
  add(cnt[a], n / 2);
  if (b != a) {
    add(cnt[b], n / 2);
  }
  return ways;
}

Modint solve (uchar a, uchar b) {
  if (a > b) {
    swap(a, b);
  }
  
  if (memo[a][b]) {
    return ans[a][b];
  }

  auto ways = calc(a, b);

  memo[a][b] = true;
  ans[a][b] = ways;
  return ways;
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

  string s;
  cin >> s;

  n = s.size();
  
  for (uchar c : s) {
    cnt[c]++;
  }

  dp[0] = 1;
  for (int i = 0; i < ALPHA; i++) {
    add(cnt[i], n / 2);
  }
  
  Modint ipf = 1;
  for (int i = 0; i < 256; i++) {
    ipf *= ifact[cnt[i]];
  }
  
  int qc;
  cin >> qc;

  for (int i = 0; i < qc; i++) {
    int x, y;
    cin >> x >> y;
    x--; y--;
    
    auto ways = solve(s[x], s[y]);
    cout << ways * ipf * fact[n / 2] * fact[n / 2] * 2 << '\n';
  }
}