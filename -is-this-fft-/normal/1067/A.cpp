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

const int MAX_N = 1e5 + 5;
const int MAX_K = 200; // TEMP

int arr [MAX_N];

int main () {
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  vector<Modint> gp;
  if (arr[0] == -1) {
    gp = vector<Modint> (MAX_K + 1, Modint(1));
  } else {
    gp = vector<Modint> (MAX_K + 1, Modint(0));
    gp[arr[0]] = Modint(1);
  }
  vector<Modint> ep (MAX_K + 1, Modint(0));
  vector<Modint> lp (MAX_K + 1, Modint(0));
  // gp[i] is the # of ways to put an i that's greater than the previous.
  // things that are greater than previous need to be <= the next
  for (int i = 1; i < n; i++) {
    vector<Modint> ngp (MAX_K + 1, Modint(0));
    vector<Modint> nep (MAX_K + 1, Modint(0));
    vector<Modint> nlp (MAX_K + 1, Modint(0));

    for (int j = 1; j <= MAX_K; j++) {
      nep[j] = gp[j] + ep[j] + lp[j];
    }

    Modint pref (0);
    for (int j = 1; j <= MAX_K; j++) {
      ngp[j] += pref;
      pref += gp[j] + ep[j] + lp[j];
    }

    Modint suff (0);
    for (int j = MAX_K; j >= 1; j--) {
      nlp[j] += suff;
      suff += ep[j] + lp[j];
    }
    
    gp = ngp;
    ep = nep;
    lp = nlp;
    if (arr[i] != -1) {
      for (int j = 1; j <= MAX_K; j++) {
        if (j != arr[i]) {
          gp[j] = Modint(0);
          ep[j] = Modint(0);
          lp[j] = Modint(0);
        }
      }
    }
  }

  Modint ans (0);
  for (int i = 1; i <= MAX_K; i++) {
    ans += lp[i] + ep[i];
  }
  cout << ans << endl;
}