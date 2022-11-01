#include <bits/stdc++.h> 

using namespace std;

const long long INF = 1e9 + 10;

set <long long> s;
long long b, q, l, m;

int main (int argc, char const *argv[]) {
  scanf("%lld %lld %lld %lld", &b, &q, &l, &m);
  while (m--) {
    long long x;
    scanf("%lld", &x);
    s.insert(x);
  }
  if (abs(b) > l) {
    puts("0");
    return 0;
  }
  if (b == 0) {
    if (s.count(0)) puts("0");
    else puts("inf");
    return 0;
  }
  if (q == 0) {
    if (s.count(0)) {
      if (s.count(b)) puts("0");
      else puts("1");
    } else {
      puts("inf");
    }
    return 0;
  }
  if (q == 1) {
    if (s.count(b)) puts("0");
    else puts("inf");
    return 0;
  }
  if (q == -1) {
    if (s.count(b) and s.count(-b)) puts("0");
    else puts("inf");
    return 0;
  }
  int tot = 0;
  while (abs(b) <= l) {
    if (!s.count(b)) {
      ++tot;
    }
    b *= q;
  }
  printf("%d\n", tot);
  return 0;
}