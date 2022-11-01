#include <bits/stdc++.h>

using namespace std;

const int N = 100003;

int n, cnt;
bitset <N> vis;

int ask (char c, int x) {
  ++cnt;
  printf("%c %d\n", c, x);
  fflush(stdout);
  int ret; scanf("%d", &ret);
  return ret;
}

int main() {
  for (int i = 2; i * i < N; ++i) if (!vis[i]) {
    for (int j = i * i; j < N; j += i) vis[j] = 1;
  }
  cin >> n;
  long long ans = 1;
  for (int i = 2; i * i <= n; ++i) if (!vis[i]) {
    int rep = ask('B', i);
    long long pwr = i;
    while (pwr <= n) {
      int yo = ask('A', pwr);
      if (yo) ans *= i;
      else break;
      pwr *= i;
    }
  }
  vector <int> big;
  for (int i = 2; i <= n; ++i) if (!vis[i]) {
    if ((long long) i * i > n) {
      big.emplace_back(i);
    }
  }
  int curSz = ask('A', 1);
  if (!big.empty()) {
    int block = 100;
    for (int i = 0, j = block - 1; i < big.size(); i += block, j += block) {
      j = min(j, (int) big.size() - 1);
      bool found = 0;
      for (int k = i; k <= j; ++k) {
        int rep = ask('B', big[k]);
        if (rep > 1) {
          ans *= big[k];
          found = 1;
          break;
        }
        --curSz;
      }
      if (found) break;
      int sz = ask('A', 1);
      if (sz == curSz) continue;
      for (int k = i; k <= j; ++k) {
        int rep = ask('A', big[k]);
        if (rep) {
          ans *= big[k];
          break;
        }
      }
      break;
    }
  }
  printf("C %lld\n", ans);
  fflush(stdout); ++cnt;
  assert(cnt <= 10000);
  return 0;
}