#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int log(ll m, ll q) {
  // return floor(loq_q m)
  assert(q > 1);
  ll ans = 0;
  while (m > 1) m /= q, ans++;
  return ans;
}

ll expmod(ll a, ll b, ll m) {
  __int128_t res = 1;
  a = a % m; 
  if (a == 0) return 0;
  while (b > 0) {
    if (b & 1) {
      res = (res*a) % m;
    }
    b = b>>1;
    a = ((__int128_t)a*a) % m;
  }
  return res;
}

bool is_prime(ll n) {
  // Miller-Rabin
  if (n == 2 || n == 3) return 1;
  if (n % 2 == 0) return 0;
  assert(n > 3 && n&1);
  int r = 0;
  ll d = n-1;
  while (d % 2 == 0) {
    d /= 2;
    r++;
  }

  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  int trials = 20;
  while (trials--) {
    ll a = ((ll)(rng())<<30 ^ rng());
    ll x = expmod(a, d, n);
    if (x == 1 || x == n-1 || x == 0) continue;
    bool good = 0;
    for (int i = 0; i < r-1; i++) {
      x = expmod(x, 2, n);
      if (x == n-1) good = 1;
    }
    if (!good) return 0;
  }
  return 1;
}

pair<ll, int> ppowerfact (ll m) {
  // find q, e such that m = q^e
  for (int i = 2; i < 100; i++) {
    if (m % i == 0) {
      return {i, log(m, i)};
    }
  }
  for (int k = 11; k > 1; k--) {
    ll near = pow(m, 1.0/k);
    for (int i = -1; i < 2; i++) {
      if (m % (near + i) == 0 && near + i > 1) {
        ll q = near + i;
        return {q, log(m, q)};
      }
    }
  }
  return {m, 1};
}

ll find_factor(ll n) {
  ll q = ppowerfact(n).first;
  if (1 < q && q < n) return q;
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  ll x = rng();
  ll a = rng();
  ll y = x;
  ll d = 1;
  while (d == 1) {
    x = expmod(x, 2, n) + 1;
    y = expmod(y, 2, n) + 1;
    y = expmod(y, 2, n) + 1;
    d = __gcd(abs(x-y), n);
  }
  if (d > 1 && d < n) return d;
  return 0;
}

vector<ll> factorize(ll n) {
  // Pollard-Rho
  if (n == 1) return {};
  if (is_prime(n)) {
    return {n};
  }
  if (n % 2 == 0) {
    vector<ll> ans = factorize(n/2);
    ans.push_back(2);
    return ans;
  }
  int iters = 0;
  while (iters < 500) {
    ll d = find_factor(n);
    if (d) {
      assert(n%d == 0);
      vector<ll> ans = factorize(d);
      for (ll p: factorize(n/d)) {
        ans.push_back(p);
      }
      return ans;
    }
    iters++;
  }
  assert(0);
  return {};
}

ll prod(vector<ll> terms) {
  ll ans = 1;
  for (ll p: terms) ans *= p;
  return ans;
}

ll order(vector<ll> factorization, ll base, ll mod) {
  set<ll> primes(factorization.begin(), factorization.end());
  ll exp = prod(factorization);
  for (ll p: primes) {
    if (expmod(base, exp/p, mod) == 1) {
      vector<ll> newfact;
      bool taken = 0;
      for (ll q: factorization) {
        if (q != p || taken) newfact.push_back(q);
        else if (q == p) taken = 1;
      }
      return order(newfact, base, mod);
    }
  }
  return exp;
}

int main () {
  ll n, m, p;
  cin >> n >> m >> p;
  // m = q^e
  pair<ll, int> mfact = ppowerfact(m);
  ll q = mfact.first;
  int e = mfact.second;

  ll phim = pow(q, e-1)*(q-1);
  // first case: q divides p
  if (p % q == 0) {
    if (phim-1 >= n) {
      int count = 0;
      ll i = 2;
      while (count < n) {
        if (i % q != 0) {
          cout << i << " ";
          count++;
        }
        i++;
      }
      cout << endl;
    }
    else {
      cout << -1 << endl;
    }
    return 0;
  }

  // find the order of p modulo m
  vector<ll> orderfact = factorize(q-1);
  for (int i = 0; i < e-1; i++) orderfact.push_back(q);
  sort(orderfact.begin(), orderfact.end());

  ll order_of_p = order(orderfact, p, m);
  if (phim - order_of_p < n) {
    cout << -1 << endl;
    return 0;
  }

  if (m <= 5e6) {
    vector<bool> valid(m, 1);
    for (int i = 0; i < m; i += q) valid[i] = 0;
    ll u = 1;
    for (int i = 0; i < order_of_p; i++) {
      valid[u] = 0;
      u = (u*p) % m;
    }
    int count = 0;
    for (int i = 0; i < m; i++) {
      if (count == n) break;
      if (valid[i]) {
        cout << i << ' ';
        count++;
      }
    }
    cout << endl;
    return 0;
  }

  if (q != 2) {
    // find primitive root
    int prim;
    for (int i = 1; i < m; i++) {
      if (i % q != 0 && order(orderfact, i, m) == prod(orderfact)) {
        prim = i;
        break;
      }
    }
    ll val = 1;
    ll power = 0;
    ll bad = prod(orderfact)/order_of_p;
    vector<ll> answers;
    while (answers.size() < n) {
      val = (__int128_t)(val)*prim % m;
      power++;
      if (power % bad != 0) answers.push_back(val);
    }
    for (ll x: answers) cout << x << ' ';
    cout << endl;
    return 0;
  }

  // m is at least 5*10^6 and we can just use mod 8 to pick good stuff
  int count = 0;
  int i = 1;
  while (count < n) {
    if (i % 8 != 1 && (i % 8) != (p % 8)) {
      cout << i << ' ';
      count++;
    }
    i += 2;
  }
  cout << endl;
}