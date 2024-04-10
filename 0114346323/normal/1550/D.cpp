#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <numeric>
#include <vector>
constexpr int kMod = 1e9 + 7;
char Gc() {
  static char now[1 << 20], *S, *T;
  if (T == S) {
    T = (S = now) + std::fread(now, 1, 1 << 20, stdin);
    if (T == S) return EOF;
  }
  return *S++;
}
template <typename T>
void Read(T &x) {
  x = 0;
  int f = 1;
  char c;
  while ((c = Gc()) < '0' || c > '9')
    if (c == '-') f = -1;
  x = c - '0';
  while ((c = Gc()) >= '0' && c <= '9') x = x * 10 + (c - '0');
  x *= f;
}
template <typename T, typename... Args>
void Read(T &x, Args &... args) {
  Read(x);
  Read(args...);
}
template <typename T>
void checkmax(T &x, T y) {
  if (x < y) x = y;
}
template <typename T>
void checkmin(T &x, T y) {
  if (x > y) x = y;
}
template <typename T>
T add(T a, T b) {
  return (a + b) % kMod;
}
template <typename T, typename... Args>
T add(T a, T b, Args... args) {
  return add(add(a, b), args...);
}
template <typename T>
T sub(T a, T b) {
  return (a + kMod - b) % kMod;
}
template <typename T>
T mul(T a, T b) {
  return a * static_cast<long long>(b) % kMod;
}
template <typename T, typename... Args>
T mul(T a, T b, Args... args) {
  return mul(mul(a, b), args...);
}
template <typename T>
void Add(T &a, T b) {
  a = add(a, b);
}
template <typename T, typename... Args>
void Add(T &a, T b, Args... args) {
  Add(a, add(b, args...));
}
template <typename T>
void Sub(T &a, T b) {
  a = sub(a, b);
}
template <typename T>
void Mul(T &a, T b) {
  a = mul(a, b);
}
template <typename T, typename... Args>
void Mul(T &a, T b, Args... args) {
  Mul(a, mul(b, args...));
}
int Ksm(int a, int b) {
  int s = 1;
  while (b) {
    if (b & 1) Mul(s, a);
    Mul(a, a);
    b >>= 1;
  }
  return s;
}
int t, n, l, r, fac[200001], inv[200001];
int C(int x, int y) {
  if (x < y || y < 0) return 0;
  return mul(fac[x], inv[x - y], inv[y]);
}
int Calc1(int x) {
  if (x <= 0) return 0;
  int a = std::max(x + l - 1, 0), b = std::max(n - r + x, 0);
  if (a + b > n) return 0;
  return n & 1 ? add(C(n - a - b, n / 2 - a), C(n - a - b, n / 2 - a + 1))
               : C(n - a - b, n / 2 - a);
}
int Calc2() { return n & 1 ? add(C(n, n / 2), C(n, n / 2 + 1)) : C(n, n / 2); }
int main(int argc, char const *argv[]) {
  fac[0] = 1;
  for (int i = 1; i <= 200000; i++) fac[i] = mul(fac[i - 1], i);
  inv[200000] = Ksm(fac[200000], kMod - 2);
  for (int i = 199999; i >= 0; i--) inv[i] = mul(inv[i + 1], i + 1);
  Read(t);
  while (t--) {
    Read(n, l, r);
    int ans = 0;
    for (int i = std::min(-l, r - n); i <= std::min(n - l, r); i++)
      Add(ans, Calc1(i));
    Add(ans, mul(std::max((std::min(-l, r - n) - 1), 0), Calc2()));
    std::printf("%d\n", ans);
  }
  return 0;
}