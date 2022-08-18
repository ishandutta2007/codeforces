#include <iostream>

using namespace std;

#include <bits/extc++.h>
using namespace __gnu_pbds;

template <typename T>
using ordered_set = tree<T, null_type, less<T>,
  rb_tree_tag, tree_order_statistics_node_update>;

// cur.order_of_key(2)
// the number of elements in the set less than 2
// *cur.find_by_order(1)
// the 1-st smallest number in the set(0-based)

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

Modint fact [MAX_N];
int perm [MAX_N];

const Modint i2 = inv(2);

Modint pairc (int n) {
  return Modint(n) * Modint(n - 1) * i2;
}

Modint invsum (int K) {
  return fact[K] * pairc(K) * i2;
}

int main () {
  fact[0] = Modint(1);
  for (int i = 1; i < MAX_N; i++) {
    fact[i] = fact[i - 1] * Modint(i);
  }
  
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  for (int i = 1; i <= n; i++) {
    cin >> perm[i];
  }

  ordered_set<int> seen;
  Modint inev (0);
  Modint ans (0);
  for (int i = 1; i <= n; i++) {
    int smallerc = seen.order_of_key(perm[i]); // # of smaller things to the left
    int missing = perm[i] - 1 - smallerc;
    int sfx = n - i; // # of things strictly to the right

    ans += Modint(missing) * inev * fact[sfx];
    ans += Modint(missing) * invsum(sfx);
    ans += fact[sfx] * Modint(missing) * Modint(missing - 1) * i2;

    inev += Modint(missing); // those inversions are inevitable now
    seen.insert(perm[i]);
  }

  ans += inev;
  cout << ans << endl;
}