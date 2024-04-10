#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

const int N = 2;

template<ll mod>
struct matrix {
  ll arr [N][N];

  matrix () {
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        arr[i][j] = 0;
      }
    }
  }

  ll& at (int i, int j) {
    return arr[i][j];
  }
};

template<ll mod>
matrix<mod> mul (matrix<mod> p, matrix<mod> q) {
  matrix<mod> ans;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      for (int k = 0; k < N; k++) {
        ans.at(i, j) += (p.at(i, k) * q.at(k, j)) % mod;
        ans.at(i, j) %= mod;
      }
    }
  }
  return ans;
}

template<ll mod>
matrix<mod> fibbase () {
  matrix<mod> ans;
  ans.at(0, 0) = 1;
  ans.at(1, 0) = 1;
  ans.at(0, 1) = 1;
  return ans;
}

template<ll mod>
matrix<mod> id () {
  matrix<mod> ans;
  ans.at(0, 0) = 1;
  ans.at(1, 1) = 1;
  return ans;
}

template<ll mod>
matrix<mod> matexp (matrix<mod> a, ll k) {
  if (k == 0) {
    return id<mod> ();
  } else if (k % 2 == 0) {
    matrix<mod> half = matexp(a, k / 2);
    return mul<mod>(half, half);
  } else {
    return mul<mod>(a, matexp<mod>(a, k - 1));
  }
}

template<ll mod>
ll fib (ll idx) {
  return matexp<mod> (fibbase<mod> (), idx).at(1, 0);
}

ll exp (ll a, ll k, ll mod) {
  if (k == 0) {
    return 1;
  } else if (k % 2 == 0) {
    ll half = exp(a, k / 2, mod);
    return (half * half) % mod;
  } else {
    return (a * exp(a, k - 1, mod)) % mod;
  }
}

const int MAX_POW = 13;

ll phi (ll mod) {
  if (mod == 12288) return 4096;
  ll cur = 2;
  ll last = 1;
  for (int i = 1; i <= MAX_POW; i++) {
    if (mod == cur) return cur - last;
    cur *= 2;
    last *= 2;
  }

  cur = 5;
  last = 1;
  for (int i = 1; i <= MAX_POW; i++) {
    if (mod == cur) return cur - last;
    cur *= 5;
    last *= 5;
  }
  return 0;
}

ll inv (ll a, ll mod) {
  return exp(a, phi(mod) - 1, mod);
}

ll crt (vector<ll> vals, vector<ll> mods) {
  ll mod = 1;
  for (ll n : mods) {
    mod *= n;
  }

  vector<ll> ms;
  for (ll n : mods) {
    ms.push_back(mod / n);
  }

  ll ans = 0;
  for (int i = 0; i < (int) vals.size(); i++) {
    ans += (((vals[i] * inv(ms[i], mods[i])) % mod) * ms[i]) % mod;
    ans %= mod;
  }
  return ans;
}

const ll mod2 = 1 << 13;
const ll mod57 = 78125;
const ll mod56 = 15625;
const ll mod513 = 1220703125LL;
const ll cycl57 = 312500;
const ll cycl2 = 12288;
const ll cycl = 1e13 + 5e12;

vector<ll> occs57 [mod57];
vector<ll> occs2 [mod2];

int main () {
  ll last = 0;
  ll cur = 1;
  occs2[0].push_back(0);
  for (int i = 1; i < cycl2; i++) {
    occs2[cur].push_back(i);
    ll nxt = (last + cur) % mod2;
    last = cur;
    cur = nxt;
  }

  last = 0;
  cur = 1;
  occs57[0].push_back(0);
  for (int i = 1; i < cycl57; i++) {
    occs57[cur].push_back(i);
    ll nxt = (last + cur) % mod57;
    last = cur;
    cur = nxt;
  }

  ll input;
  cin >> input;

  vector<ll> mod2poss = occs2[input % mod2];
  if (mod2poss.empty()) {
    cout << -1 << endl;
    return 0;
  }

  vector<ll> mod57poss = occs57[input % mod57];
  if (mod57poss.empty()) {
    cout << -1 << endl;
    return 0;
  }

  vector<ll> mod513poss;
  for (ll u : mod57poss) {
    for (ll i = u; i < 4 * mod513; i += cycl57) {
      if (fib<mod513>(i) == input % mod513) {
        mod513poss.push_back(i);
      }
    }
  }

  ll ans = 100 * mod513 * mod2 + 5;
  for (ll u : mod2poss) {
    for (ll v : mod513poss) {
      if (u % 4 == v % 4) {
      // cout << u << " " << v << " " << crt({u, v % mod513}, {(mod2 / 2) * 3, mod513}) << endl;
        ans = min(ans, crt({u, v % mod513}, {(mod2 / 2) * 3, mod513}));
      }
    }
  }

  if (ans == 100 * mod513 * mod2 + 5) {
    cout << -1 << endl;
  } else {
    cout << ans << endl;
  }
}