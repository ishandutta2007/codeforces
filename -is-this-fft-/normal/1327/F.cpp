#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
 
const int MOD = 998244353; // change if needed
 
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

struct Req {
  int l, r, x;
};

const int MAX_N = 5e5 + 5;

vector<Req> reqs;

int n;
int fadds [MAX_N];
int fends [MAX_N];
vector<int> kends [MAX_N];
int real_id [MAX_N];
int bal_at [MAX_N];

Modint dp [MAX_N];
Modint cdp [MAX_N];
Modint proc_bit (int k) {
  for (int i = 1; i <= n + 1; i++) {
    fadds[i] = 0;
    fends[i] = 0;
    kends[i].clear();
  }
  
  for (Req req : reqs) {
    if (req.x & 1 << k) {
      fadds[req.l]++;
      fends[req.r]++;
    }
  }

  int bal = 0, cur = 0;
  for (int i = 1; i <= n; i++) {
    bal += fadds[i];
    bal -= fends[i];
    if (bal == 0) {
      cur++;
    }
    real_id[i] = cur;
    bal_at[i] = bal;
  }
  real_id[n + 1] = cur + 1;

  for (Req req : reqs) {
    if (!(req.x & 1 << k)) {
      int l = req.l;
      int r = req.r;
      if (bal_at[l] != 0) l = real_id[l] + 1;
      else l = real_id[l];
      if (bal_at[r] != 0) r = real_id[r] + 1;
      else r = real_id[r];
      
      if (l == r) return Modint(0);
      kends[r].push_back(l);
    }
  }

  int cmin = 0;
  dp[0] = 1;
  cdp[0] = 1;
  for (int i = 1; i <= cur; i++) {
    for (int l : kends[i]) {
      cmin = max(cmin, l);
    }

    dp[i] = cdp[i - 1] - (cmin == 0 ? Modint(0) : cdp[cmin - 1]);
    cdp[i] = cdp[i - 1] + dp[i];
  }
  for (int l : kends[cur + 1]) {
    cmin = max(cmin, l);
  }
  
  return cdp[cur] - (cmin == 0 ? Modint(0) : cdp[cmin - 1]);
}

int main () {
  ios::sync_with_stdio(false);

  int k, m;
  cin >> n >> k >> m;

  reqs = vector<Req> (m);
  for (int i = 0; i < m; i++) {
    cin >> reqs[i].l >> reqs[i].r >> reqs[i].x;
    reqs[i].r++;
  }

  Modint ans (1);
  for (int i = 0; i < k; i++) {
    ans *= proc_bit(i);
  }
  cout << ans << endl;
}