#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <numeric>
#include <vector>
template <typename T>
void Read(T &x) {
  x = 0;
  int f = 1;
  char c;
  while ((c = std::getchar()) < '0' || c > '9')
    if (c == '-') f = -1;
  x = c - '0';
  while ((c = std::getchar()) >= '0' && c <= '9') x = x * 10 + (c - '0');
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
int t, n, a, b;
char s[101];
int main(int argc, char const *argv[]) {
  Read(t);
  while (t--) {
    Read(n, a, b);
    std::scanf("%s", s + 1);
    if (b >= 0) {
      std::printf("%d\n", a * n + b * n);
      continue;
    }
    int cnt = 1;
    for (int i = 2; i <= n; i++) cnt += s[i] != s[i - 1];
    std::printf("%d\n", a * n + (cnt + 2) / 2 * b);
  }
  return 0;
}