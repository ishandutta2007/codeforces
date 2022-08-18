#include <iostream>
#include <map>
#include <vector>

using namespace std;

typedef long long ll;

const int MOD = 998244353; // change if needed
// const int MOD = 1e9 + 7; 

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

class Fenwick {
  vector<Modint> tree;

public:
  Fenwick (int n) : tree(n, Modint(0)) {
  }

  void add (int pos, Modint val) {
    for (int i = pos; i < (int) tree.size(); i += i & -i) {
      tree[i] += val;
    }
  }

  Modint get (int pos) {
    Modint ans (0);
    for (int i = pos; i > 0; i -= i & -i) {
      ans += tree[i];
    }
    return ans;
  }

  Modint range (int l, int r) {
    if (l > r) return Modint(0);
    return get(r) - get(l - 1);
  }

  Modint at (int pos) {
    return range(pos, pos);
  }
};

const int MAX_N = 2e5 + 5;

struct Portal {
  int from, to, init;
} arr [MAX_N];

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  map<int, int> mp;
  for (int i = 1; i <= n; i++) {
    cin >> arr[i].from >> arr[i].to >> arr[i].init;
    mp[arr[i].from] = i;
  }

  Fenwick fen (n + 5);
  for (int i = 1; i <= n; i++) {
    Modint cost = Modint(arr[i].from - arr[i].to);
    auto ub = mp.upper_bound(arr[i].to)->second;
    cost += fen.range(ub, i - 1);

    fen.add(i, cost);
  }

  Modint ans (arr[n].from + 1);
  for (int i = 1; i <= n; i++) {
    if (arr[i].init) {
      ans += fen.at(i);
    }
  }

  cout << ans << endl;
}