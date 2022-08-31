#include <iostream>
#include <set>
#include <vector>

using namespace std;

int gcd (int p, int q) {
  if (q == 0) return p;
  return gcd(q, p % q);
}

const int MAX_N = 2e5 + 5;

int factor [MAX_N];
vector<int> ps;

vector<int> ideal [MAX_N];

int dp [MAX_N], last [MAX_N];

typedef long long ll;

int phi [MAX_N];

int exp (ll a, int k, int mod) {
  if (k == 0) return 1;
  if (k % 2 == 0) {
    ll half = exp(a, k / 2, mod);
    return (half * half) % mod;
  } else {
    return ((ll) exp(a, k - 1, mod) * a) % mod;
  }
}

int inv (ll a, int mod) {
  return exp(a, phi[mod] - 1, mod);
}

// go from f to t modulo mod
int inv (int from, int to, int mod) {
  return ((ll) to * (ll) inv(from, mod)) % mod;
}

int main () {
  ios::sync_with_stdio(false);

  int n, m;
  cin >> n >> m;

  for (int i = 2; i < MAX_N; i++) {
    if (factor[i] == 0) {
      if (m % i == 0) ps.push_back(i);
      for (int j = i; j < MAX_N; j += i) {
        factor[j] = i;
      }
    }
  }

  phi[1] = 1;
  for (int i = 2; i < MAX_N; i++) {
    if (factor[i / factor[i]] == factor[i]) {
      phi[i] = phi[i / factor[i]] * factor[i];
    } else {
      phi[i] = phi[i / factor[i]] * (factor[i] - 1);
    }
  }

  set<int> forb;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;

    forb.insert(x);
  }

  for (int i = 0; i < m; i++) {
    if (!forb.count(i)) {
      ideal[gcd(i, m)].push_back(i);
    }
  }

  for (int i = m; i >= 1; i--) {
    if (m % i == 0) {
      pair<int, int> add = make_pair(0, 0);
      for (int p : ps) {
        ll nxt = (ll) i * (ll) p;
        if (m % nxt == 0) {
          add = max(add, make_pair(dp[nxt], (int) nxt));
        }
      }
      dp[i] = add.first + (int) ideal[i].size();
      last[i] = add.second;
    }
  }

  vector<int> pref;
  for (int cur = 1; cur != 0; cur = last[cur]) {
    for (int u : ideal[cur]) {
      pref.push_back(u);
    }
  }

  vector<int> ans (1, pref[0]);
  for (int i = 1; i < (int) pref.size(); i++) {
    int prv = pref[i - 1];
    int cur = pref[i];

    if (cur == 0) {
      ans.push_back(0);
    } else {
      int gcp = gcd(m, prv);
      int gcc = gcd(m, cur);

      int mul = gcc / gcp;
      prv *= mul;
      int ad = inv(prv / gcc, cur / gcc, m / gcc);
      ans.push_back((mul * ad) % m);
    }
  }

  cout << (int) ans.size() << endl;
  for (int u : ans) {
    cout << u << " ";
  }
  cout << endl;
}