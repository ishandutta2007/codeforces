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

const int MAX_N = 1e5 + 5;

int arr [MAX_N];
vector<int> divs [MAX_N]; // divisors of i

int add [MAX_N];

int cur_age;
int _age [MAX_N];
int _cnt [MAX_N];
int &cnt (int pos) {
  if (_age[pos] != cur_age) {
    _age[pos] = cur_age;
    _cnt[pos] = 0;
  }
  return _cnt[pos];
}

int main () {
  for (int i = 1; i < MAX_N; i++) {
    for (int d = 1; d * d <= i; d++) {
      if (i % d == 0) {
        divs[i].push_back(d);
        if (d * d != i) {
          divs[i].push_back(i / d);
        }
      }
    }
  }

  add[1] = 1;
  for (int i = 2; i < MAX_N; i++) {
    int cur = 0;
    for (int d : divs[i]) {
      if (d == i) continue;
      cur += add[d];
    }
    add[i] = i - cur;
  }
  
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
  }

  Modint ans (0);
  for (int k = 1; k <= n; k++) {
    cur_age++;
    Modint cur (0);
    Modint sum (0);
    for (int i = k; i <= n; i += k) {
      sum += arr[i];
      for (int d : divs[arr[i]]) {
        cur += Modint(cnt(d)) * Modint(add[d]);
        cnt(d)++;
      }
    }

    cur *= Modint(2);
    cur += sum;
    ans += Modint(add[k]) * cur;
  }

  cout << ans << endl;
}