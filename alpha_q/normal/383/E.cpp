#include <bits/stdc++.h>

using namespace std;

#pragma GCC diagnostic warning "-std=c++11"

const int N = 24;
const int MASK = (1 << N) + 5;

char s[69];
int n, f[MASK];

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%s", s);
    int now = 0;
    now |= 1 << (s[0] - 'a');
    now |= 1 << (s[1] - 'a');
    now |= 1 << (s[2] - 'a');
    ++f[now];
  }
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < 1 << N; ++j) {
      if (j & 1 << i) f[j] += f[j ^ 1 << i];
    }
  }
  long long ans = 0;
  for (int i = 0; i < 1 << N; ++i) {
    long long now = n - f[i];
    ans ^= (now * now);
  }
  printf("%lld\n", ans);
  return 0;
}