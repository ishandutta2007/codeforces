#include <iostream>
#include <vector>

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

const int MAX_N = 1e3 + 5;

bool is_ok (const vector<int> &nxt) {
  int K = nxt.size();
  for (int i = 0; i < K; i++) {
    bool ok = false;
    int cur = i;
    for (int j = 0; j < K; j++) {
      cur = nxt[cur];
      if (cur == 0) {
        ok = true;
        break;
      }
    }

    if (!ok) {
      return false;
    }
  }
  return true;
}

void dfs (vector<int> &cur, int K, int &ans) {
  if ((int) cur.size() == K) {
    if (is_ok(cur)) {
      ans++;
    }
  } else {
    for (int i = 0; i < K; i++) {
      cur.push_back(i);
      dfs(cur, K, ans);
      cur.pop_back();
    }
  }
}

int main () {
  int n, K;
  cin >> n >> K;

  vector<int> stk;
  int cnt_left = 0;
  dfs(stk, K, cnt_left);

  Modint ans = exp(Modint(n - K), n - K) * Modint(cnt_left);
  cout << ans << endl;
}