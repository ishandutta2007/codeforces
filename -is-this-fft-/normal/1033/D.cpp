#include <iostream>
#include <set>
#include <vector>
#include <map>

using namespace std;

typedef long long ll;

int blog (ll num) {
  int ans = 0;
  while (num != 0) {
    ans++;
    num /= 2;
  }
  return ans;
}

pair<bool, ll> dpow (ll num, int exp) {
  ll ans = 1;
  for (int i = 0; i < exp; i++) {
    if (blog(ans) + blog(num) > 62) {
      return make_pair(false, 0);
    }
    ans *= num;
  }

  return make_pair(true, ans);
}

ll root (ll x, int base) {
  ll ans = 0;
  for (ll k = 1LL << 31; k != 0; k /= 2) {
    ll cur = ans + k;
    pair<bool, ll> cpow = dpow(cur, base);
    if (cpow.first && cpow.second <= x) {
      ans += k;
    }
  }
  return ans;
}

bool eqr (ll x, ll base) {
  return dpow(root(x, base), base).second == x;
}

ll gcd (ll p, ll q) {
  if (q == 0) {
    return p;
  }
  return gcd(q, p % q);
}

const int mod = 998244353;

int main () {
  int numc;
  cin >> numc;

  vector<ll> all_nums;
  set<ll> primes;
  vector<ll> paireds;
  for (int i = 0; i < numc; i++) {
    ll num;
    cin >> num;

    if (eqr(num, 4)) {
      primes.insert(root(num, 4));
    } else if (eqr(num, 3)) {
      primes.insert(root(num, 3));
    } else if (eqr(num, 2)) {
      primes.insert(root(num, 2));
    } else {
      paireds.push_back(num);
    }

    all_nums.push_back(num);
  }

  for (ll u : paireds) {
    for (ll v : paireds) {
      ll gc = gcd(u, v);
      if (gc != u && gc != 1) {
        primes.insert(gc);
        primes.insert(u / gc);
        primes.insert(v / gc);
      }
    }
  }

  for (ll u : paireds) {
    for (ll p : primes) {
      if (u % p == 0) {
        primes.insert(u / p);
      }
    }
  }

  map<ll, int> atoms;
  for (int i = 0; i < numc; i++) {
    for (ll p : primes) {
      while (all_nums[i] % p == 0) {
        all_nums[i] /= p;
        if (atoms.count(p) == 0) {
          atoms[p] = 0;
        }
        atoms[p]++;
      }
    }

    if (all_nums[i] != 1) {
      if (atoms.count(all_nums[i]) == 0) {
        atoms[all_nums[i]] = 0;
      }
      atoms[all_nums[i]]++;
    }
  }

  ll ans = 1;
  for (pair<ll, int> pr : atoms) {
    if (primes.count(pr.first) != 0) {
      ans *= pr.second + 1;
      ans %= mod;
    } else {
      ans *= pr.second + 1;
      ans %= mod;
      ans *= pr.second + 1;
      ans %= mod;
    }
  }

  cout << ans << endl;
}