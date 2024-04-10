#include <iostream>

using namespace std;

typedef long long ll;

const int MAX_T = 505;

int qs [MAX_T];

// p must be prime
pair<ll, ll> sumtil (int p) {
  return make_pair(p - 2, 2 * p);
}

bool is_prime (int x) {
  for (int i = 2; i * i <= x; i++) {
    if (x % i == 0) return false;
  }
  return true;
}

int prev_prime (int x) {
  for (int i = x; true; i--) {
    if (is_prime(i)) {
      return i;
    }
  }
}

int nxt_prime (int x) {
  for (int i = x + 1; true; i++) {
    if (is_prime(i)) {
      return i;
    }
  }
}

ll gcd (ll p, ll q) {
  if (q == 0) return p;
  return gcd(q, p % q);
}

pair<ll, ll> solve (int x) {
  if (x == 2) {
    return make_pair(1, 6);
  }

  int p = prev_prime(x);
  int q = nxt_prime(x);

  auto ans = sumtil(p);
  ans.first *= (ll) q;
  ans.second *= (ll) q;
  ans.first += 2 * (ll) (x - p + 1);
  ll gc = gcd(ans.first, ans.second);
  ans.first /= gc;
  ans.second /= gc;
  return ans;
}

int main () {
  ios::sync_with_stdio(false);

  int testc;
  cin >> testc;

  for (int i = 0; i < testc; i++) {
    int x;
    cin >> x;

    auto ans = solve(x);
    cout << ans.first << "/" << ans.second << '\n';
  }
}