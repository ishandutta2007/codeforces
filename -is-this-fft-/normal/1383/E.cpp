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

const int MAX_N = 1e6 + 5;

int nxt [MAX_N];
Modint dp [MAX_N];
Modint pass [MAX_N];

int main () {
  ios::sync_with_stdio(false);

  string s;
  cin >> s;

  vector<pair<int, int>> blocks;
  for (int i = 0; i < (int) s.size(); i++) {
    if (i == 0 || s[i] != s[i - 1]) {
      blocks.push_back(make_pair(s[i] - '0', 0));
    }
    blocks.back().second++;
  }

  if (blocks.size() == 1) {
    cout << blocks[0].second << endl;
    return 0;
  }

  int n = blocks.size();
  vector<pair<int, int>> stk; // <idx, len>
  for (int i = n - 1; i >= 0; i--) {
    if (blocks[i].first == 0) {
      while (!stk.empty() && stk.back().second < blocks[i].second) {
        stk.pop_back();
      }

      if (stk.empty()) {
        nxt[i] = -1;
      } else {
        nxt[i] = stk.back().first;
      }
      stk.push_back(make_pair(i, blocks[i].second));
    }
  }

  Modint pfx (1);
  if (blocks[0].first == 0) {
    // pass[0] = Modint(1);
    dp[0] = Modint(blocks[0].second);
  }
      
  for (int i = 0; i < n; i++) {
    int len = blocks[i].second;
    if (blocks[i].first == 0) {
      pfx += dp[i];
      if (nxt[i] != -1) {
        pass[nxt[i]] += pass[i];
        dp[nxt[i]] += Modint(blocks[nxt[i]].second - len) * pass[i];
      }
    } else {
      dp[i] += Modint(len) * pfx;
      if (i + 1 < n) {
        pass[i + 1] += dp[i];
        dp[i + 1] += Modint(blocks[i + 1].second) * dp[i];
      }
    }
  }

  Modint ans (0);
  for (int i = 0; i < n; i++) {
    if (blocks[i].first == 1) {
      ans += dp[i];
    }
  }

  // if you want to end with a 0, add it separately
  if (blocks.back().first == 0) {
    ans *= Modint(1 + blocks.back().second);
  }
  
  cout << ans << endl;
}