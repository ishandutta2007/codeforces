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


// # of splits, new leftmost
pair<int, int> split (int cur, int nxt) {
  int splits = (cur + nxt - 1) / nxt;
  int lft = cur / splits;
  return make_pair(splits - 1, lft);
}

const int MAX_N = 1e5 + 5;

int arr [MAX_N];

int _cur_age;
int _age [MAX_N];
int _cnt [MAX_N];

vector<int> active;

void reset () {
  _cur_age++;
  active.clear();
}

int &cnt (int pos) {
  if (_age[pos] != _cur_age) {
    _cnt[pos] = 0;
    _age[pos] = _cur_age;
    active.push_back(pos);
  }

  return _cnt[pos];
}

void solve () {
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  vector<pair<int, int>> to_check; // leftmost, #
  Modint sum = 0, ans = 0;
  for (int i = n - 1; i >= 0; i--) {
    to_check.push_back(make_pair(MAX_N, 1));

    reset();
    for (auto pr : to_check) {
      auto s = split(arr[i], pr.first);
      cnt(s.second) += pr.second;
      sum += Modint(pr.second) * Modint(s.first);
    }

    ans += sum;

    to_check.clear();
    for (auto u : active) {
      to_check.push_back(make_pair(u, cnt(u)));
    }
  }

  cout << ans << '\n';
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