#include <iostream>
#include <algorithm>

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

const int MAX_D = 10;

Modint endp [MAX_D];
Modint endpl [MAX_D];

pair<Modint, Modint> calc (string s) {
  Modint cur (0);
  Modint exp (1);
  
  reverse(s.begin(), s.end());
  for (char c : s) {
    int dig = c - '0';
    cur += exp * endp[dig];
    exp *= endpl[dig];
  }
  return make_pair(cur, exp);
}

const int MAX_Q = 1e5 + 5;

pair<int, string> prods [MAX_Q];

int main () {
  string s;
  cin >> s;

  for (int i = 0; i < MAX_D; i++) {
    endp[i] = i;
    endpl[i] = Modint(10);
  }
  
  int qc;
  cin >> qc;
  for (int i = 0; i < qc; i++) {
    string q;
    cin >> q;

    prods[i].first = q[0] - '0';
    prods[i].second = q.substr(3, string::npos);
  }

  for (int i = qc - 1; i >= 0; i--) {
    auto pr = calc(prods[i].second);
    endp[prods[i].first] = pr.first;
    endpl[prods[i].first] = pr.second;
  }

  auto ans = calc(s);
  cout << ans.first << endl;
}