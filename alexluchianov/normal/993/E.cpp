#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>

using ll = long long;
using ld = long double;

ld const pi = acos(-1);

struct Complex{
  ld a;
  ld b;
  Complex(ld val = 0) {
    a = val;
    b = 0;
  }
  Complex(ld a_, ld b_) {
    a = a_;
    b = b_;
  }
  Complex operator + (Complex oth) {
    return {a + oth.a, b + oth.b};
  }
  Complex operator - (Complex oth) {
    return {a - oth.a, b - oth.b};
  }
  Complex operator * (Complex oth) {
    return {a * oth.a - b * oth.b, a * oth.b + b * oth.a};
  }
  Complex operator / (ld number) {
    return {a / number, b / number};
  }
};

int lg(int n) {
  return 31 - __builtin_clz(n);
}

int rev(int number, int n) {
  int result = 0;
  for(int i = 0; i < n; i++) 
    result |= ((0 < ((1 << i) & number)) << (n - 1 - i));
  return result;
}

void fft(std::vector<Complex> &v, int inverse) {
  int n = lg(v.size());
  assert((1 << n) == v.size());
  for(int i = 0; i < (1 << n); i++)
    if(i < rev(i, n))
      std::swap(v[i], v[rev(i, n)]);
  
  for(int jump = 2; jump <= (1 << n); jump *= 2) {
    ld angle = (inverse * 2 * pi / jump);
    Complex alpha = {cos(angle), sin(angle)};

    Complex omega;
    int halfjump = jump / 2;
    for(int i = 0; i < (1 << n); i += jump) {
      omega = 1;
      for(int j = i; j < i + halfjump; j++, omega = omega * alpha) {
        Complex a = v[j], b = omega * v[j + halfjump];
        v[j] = a + b;
        v[j + halfjump] = a - b;
      }
    }
  }
  if(inverse == -1)
    for(int i = 0; i < (1 << n); i++)
      v[i] = v[i] / (1 << n);
}

void multiply(std::vector<Complex> &a, std::vector<Complex> b) {
  int p = 0;
  while((1 << p) < a.size() + b.size()) 
    p++;
  a.resize(1 << p);
  b.resize(1 << p);
  fft(a, 1);
  fft(b, 1);
  for(int i = 0; i < a.size(); i++)
    a[i] = a[i] * b[i];
  fft(a, -1);
}


int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int n, x;
  std::cin >> n >> x;
  std::vector<Complex> pref(1 + n);
  int scount = 0;
  pref[0] = 1;
  for(int i = 0; i < n; i++) {
    int val;
    std::cin >> val;
    scount += (val < x); 
    pref[scount] = pref[scount] + 1;
  }
  std::vector<Complex> pref2;
  pref2 = pref;
  std::reverse(pref2.begin(), pref2.end());
  multiply(pref, pref2);
  
  std::vector<ll> sol(1 + n);
  sol[0] = 1LL * n * (n + 1) / 2;

  for(int i = n + 1;i <= n + n; i++) {
    sol[i - n] = (ll)(pref[i].a + 0.5);
    sol[0] -= sol[i - n];
  }

  for(int i = 0; i <= n; i++)
    std::cout << sol[i] << " " ;
  std::cout << '\n';
  return 0;
}