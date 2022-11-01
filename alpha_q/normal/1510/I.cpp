#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

mt19937 rng(58);

inline ld getRand (ld l, ld r) {
  return uniform_real_distribution<ld>(l, r)(rng);
}

const int N = 1010;

char s[N], rep[5];
int n, m, score[N];

int main() {
  srand(time(0));
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) score[i] = 1;
  for (int i = 1; i <= m; ++i) {
    scanf("%s", s + 1);
    long double cnt[2] = {0, 0};
    for (int j = 1; j <= n; ++j) {
      cnt[s[j] - '0'] += expl(-score[j] / 10.0);
    }
    int me = getRand(0, cnt[0] + cnt[1]) > cnt[0];
    printf("%d\n", me); fflush(stdout);
    scanf("%s", rep);
    for (int j = 1; j <= n; ++j) {
      if (s[j] != rep[0]) ++score[j];
    }
  }
  return 0;
}