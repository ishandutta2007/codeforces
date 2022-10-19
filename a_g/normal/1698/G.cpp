#include <bits/stdc++.h>
using namespace std;

const int N = 75;
using poly = bitset<N>;
poly MOD;
poly p2[N];

long long lcm(long long a, long long b) {
  return a*(b/__gcd(a, b));
}

int deg(poly a) {
  for (int i = N-1; i >= 0; i--) {
    if (a[i]) return i;
  }
  return -1;
}

const poly operator % (poly a, poly b) {
  assert(b != 0);
  while (deg(a) >= deg(b)) {
    a ^= b<<(deg(a)-deg(b));
  }
  return a;
}

const poly operator * (poly a, poly b) {
  poly ans;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (a[i] && b[j]) {
        assert(i+j < N);
        ans[i+j] = !ans[i+j];
      }
    }
  }
  return ans%MOD;
}

const poly operator / (poly a, poly b) {
  assert(a%b == 0);
  poly ans;
  while (a != 0) {
    ans[deg(a)-deg(b)] = 1;
    a ^= b<<(deg(a)-deg(b));
  }
  return ans;
}

poly gcd(poly a, poly b) {
  if (deg(a) < deg(b)) swap(a, b);
  if (b == 0) return a;
  return gcd(b, a%b);
}

bool nonconst(poly a) {
  return (a != 0 && a != 1);
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  string s;
  cin >> s;
  if (count(s.begin(), s.end(), '1') == 0) {
    cout << "-1\n";
    return 0;
  }

  int b = 1;
  while (s[0] == '0') {
    b++;
    s = s.substr(1);
  }
  while (s.back() == '0') s.pop_back();
  int n = s.size();

  for (int i = 0; i < n; i++) {
    if (s[i] == '1') MOD[i] = 1;
  }

  p2[0][1] = 1;
  for (int i = 1; i < N; i++) {
    p2[i] = p2[i-1]*p2[i-1];
  }

  long long deg = 1<<7;
  for (int i = 1; i < 60; i++) {
    poly z = p2[i];
    z[1] = !z[1];
    for (int i = 0; i < 6; i++) {
      z = z*z;
    }
    poly g = gcd(z, MOD);
    if (nonconst(g)) {
      deg = lcm(deg, (1LL<<i)-1);
      MOD = MOD/gcd(z, MOD);
    }
  }

  for (int i = 0; i < n; i++) {
    if (s[i] == '1') MOD[i] = 1;
  }
  auto check = [&] (long long d) {
    poly z = 1;
    for (int i = 0; i < 64; i++) {
      if ((d>>i)&1) {
        z = z * p2[i];
      }
    }
    return z.count() == 1 && z[0] == 1;
  };

  if (s != "1") assert(check(deg));

  for (int i = 2; 1LL*i*i <= deg; i++) {
    if (deg%i == 0 && check(i)) {
      deg = i;
    }
    while (deg%i == 0 && check(deg/i)) {
      deg /= i;
    }
  }
  if (s == "1") deg = 1;
  cout << b << " " << b+deg << '\n';

}