#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

ll gcd (ll p, ll q) {
  if (q == 0) return p;
  return gcd(q, p % q);
}

const int MAX_N = 1e5 + 5;

int sieve [MAX_N];
vector<int> smallp;

ll phi (ll m) {
  ll ans = 1;
  for (int p : smallp) {
    if (m % p == 0) {
      ans *= p - 1;
      m /= p;
      while (m % p == 0) {
        ans *= p;
        m /= p;
      }
    }
  }

  if (m != 1) {
    ans *= m - 1;
  }

  return ans;
}

void solve () {
  ll a, m;
  cin >> a >> m;
  
  ll g = gcd(a, m);
  a /= g;
  m /= g;

  cout << phi(m) << '\n';
}

int main () {
  ios::sync_with_stdio(false);

  for (int i = 2; i < MAX_N; i++) {
    if (!sieve[i]) {
      smallp.push_back(i);
      for (int j = i; j < MAX_N; j += i) {
        sieve[j] = 1;
      }
    }
  }
  
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    solve();
  }
}