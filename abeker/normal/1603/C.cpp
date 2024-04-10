#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 5;
const int MOD = 998244353;

inline void add(int &x, int y) {
  x += y;
  if (x >= MOD)
    x -= MOD;
}

inline int mul(int x, int y) {
  return (long long)x * y % MOD;
}

int subtree[MAX][2];

int solve() {
  int N;
  scanf("%d", &N);
  vector <int> a(N + 1);
  a[0] = 1;
  for (int i = 1; i <= N; i++)
    scanf("%d", &a[i]);
  int sol = 0, curr = 0;
  vector <int> non_zero, nxt;
  for (int i = N; i; i--) {
    nxt.clear();
    subtree[a[i]][curr]++;
    non_zero.push_back(a[i]);
    int prev = 0;
    for (auto it : non_zero) {
      if (it == prev)
        continue;
      int k = (a[i - 1] - 1) / it + 1;
      subtree[a[i - 1] / k][curr ^ 1] += subtree[it][curr];
      add(sol, mul(mul(i - 1, subtree[it][curr]), k - 1));
      nxt.push_back(a[i - 1] / k);
      subtree[it][curr] = 0;
      prev = it;
    }
    non_zero = nxt;
    curr ^= 1;
  }
  for (auto it : non_zero)
    subtree[it][curr] = 0;
  return sol;
}

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--)
    printf("%d\n", solve());
  return 0;
}