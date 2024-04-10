#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 5;
const int M = 1e7 + 5;

int n, sp[M], d[2][N];

int main() {
  for (int i = 2; i * i < M; ++i) if (!sp[i]) {
    sp[i] = i;
    for (int j = i * i; j < M; j += i) if (!sp[j]) {
      sp[j] = i;
    }
  }
  for (int i = 2; i < M; ++i) if (!sp[i]) sp[i] = i;
  cin >> n;
  for (int i = 1, x; i <= n; ++i) {
    scanf("%d", &x);
    d[0][i] = d[1][i] = -1;
    int pwr = 1, p = sp[x];
    while (x % p == 0) x /= p, pwr *= p;
    if (x == 1) continue;
    d[0][i] = pwr, d[1][i] = x;
  }
  for (int i = 1; i <= n; ++i) printf("%d ", d[0][i]); puts("");
  for (int i = 1; i <= n; ++i) printf("%d ", d[1][i]); puts("");
  return 0;
}