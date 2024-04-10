#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int mod = 1000000007;

ll expmod(ll a, ll b, int m) {
  int res = 1;
  a = a % m; 
  if (a == 0) return 0;
  while (b > 0) {
    if (b & 1) {
      res = (res*a) % m;
    }
    b = b>>1;
    a = (a*a) % m;
  }
  return res;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  ll n, q;
  cin >> n >> q;

  const int pow = 3*n+3;
  vector<ll> fact(pow+1), invfact(pow+1);
  fact[0] = fact[1] = 1;
  invfact[0] = invfact[1] = 1;
  for (int i = 2; i < pow+1; i++) {
    fact[i] = (i*fact[i-1]) % mod;
  }
  invfact[pow] = expmod(fact[pow], mod-2, mod);
  for (int i = pow-1; i > 1; i--) {
    invfact[i] = invfact[i+1] * (i+1) % mod;
  }
  vector<ll> numer(pow, fact[pow]);
  for (int i = 0; i < pow; i++) {
    numer[i] = numer[i] * ((invfact[i+1] * invfact[pow-i-1]) % mod) % mod;
  }

  const ll third = expmod(3, mod-2, mod);
  vector<ll> answers(pow);
  answers[0] = numer[0]*third % mod;
  answers[1] = ((numer[1] - 3*answers[0])*third) % mod;
  for (int i = 2; i < pow; i++) {
    answers[i] = third*(numer[i] - 3*answers[i-1] - answers[i-2]) % mod;
  }

  while (q--) {
    int x;
    cin >> x;
    cout << (answers[x]+mod)%mod << '\n';
  }
}