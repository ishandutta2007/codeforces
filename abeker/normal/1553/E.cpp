#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3e5 + 5;

int N, M;
int perm[MAXN], inv[MAXN];

void load() {
  scanf("%d%d", &N, &M);
  for (int i = 0; i < N; i++) {
    scanf("%d", perm + i);
    inv[--perm[i]] = i;
  }
}

bool check(int k) {
  int cycles = 0;
  vector <bool> bio(N);
  rotate(inv, inv + (N - k) % N, inv + N);
  for (int i = 0; i < N; i++)
    if (!bio[i]) {
      for (int x = i; !bio[x]; x = inv[x])
        bio[x] = true;
      cycles++;
    }
  rotate(inv, inv + k, inv + N);
  return N - cycles <= M;
}

void solve() {
  vector <int> occ(N);
  for (int i = 0; i < N; i++)
    occ[(i - perm[i] + N) % N]++;
  vector <int> ans;
  for (int k = 0; k < N; k++)
    if (3 * occ[k] >= N && check(k))
      ans.push_back(k);
  printf("%d", ans.size());
  for (auto it : ans)
    printf(" %d", it);
  puts("");
}

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    load();
    solve();
  }
  return 0;
}