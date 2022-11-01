#include <bits/stdc++.h>

using namespace std;

const int N = 18;
const int MASK = (1 << 14) + 69;

int n, g[N][N], id[69];
long long ans[MASK], cnt[2][MASK][70][17];

void backtrack (int who, int target) {
  for (int taken = 0; taken < 1 << n; ++taken) {
    if (__builtin_popcount(taken) == target) {
      int sz = 0;
      for (int i = 0; i < n; ++i) if (taken & 1 << i) id[sz++] = i;
      do {
        int cur = 0;
        for (int j = 0; j + 1 < target; ++j) cur |= g[id[j]][id[j + 1]] << j;
        if (n & 1) !who ? ++cnt[0][taken][cur][id[sz - 1]] : ++cnt[1][taken][cur][id[0]];
        else ++cnt[0][taken][cur][id[sz - 1]], ++cnt[1][taken][cur][id[0]];
      } while (next_permutation(id, id + sz));
    }
  }
}

int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    string s; cin >> s;
    for (int j = 0; j < n; ++j) g[i][j] = s[j] - '0';
  }
  if (n <= 8) {
    vector <int> id;
    for (int i = 0; i < n; ++i) id.emplace_back(i);
    do {
      int cur = 0;
      for (int i = 0; i + 1 < n; ++i) {
        int u = id[i], v = id[i + 1];
        cur |= g[u][v] << i;
      }
      ++ans[cur];
    } while (next_permutation(id.begin(), id.end()));
    for (int i = 0; i < 1 << (n - 1); ++i) {
      printf("%lld ", ans[i]);
    }
    puts(""); return 0;
  }
  int one = n / 2, two = n - one;
  backtrack(0, one);
  if (n & 1) backtrack(1, two);
  int its = 0;
  for (int mask = 0; mask < 1 << n; ++mask) {
    if (__builtin_popcount(mask) != one) continue;
    int offset = ((1 << n) - 1) ^ mask;
    vector <int> lt, rt;
    for (int i = 0; i < n; ++i) {
      if (mask & 1 << i) lt.emplace_back(i);
      else rt.emplace_back(i);
    }
    for (int m1 = 0; m1 < 1 << (one - 1); ++m1) for (int lastEl : lt) {
      if (!cnt[0][mask][m1][lastEl]) continue;
      for (int m2 = 0; m2 < 1 << (two - 1); ++m2) for (int firstEl : rt) {
        if (!cnt[1][offset][m2][firstEl]) continue;
        long long tot = cnt[0][mask][m1][lastEl] * cnt[1][offset][m2][firstEl];
        int cur = m1 | (g[lastEl][firstEl] << (one - 1)) | (m2 << one);
        ans[cur] += tot;
      }
    }
  }
  for (int i = 0; i < 1 << (n - 1); ++i) {
    printf("%lld ", ans[i]); 
  }
  puts("");
  return 0;
}