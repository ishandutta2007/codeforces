#include <bits/stdc++.h>
using namespace std;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef pair <int, int> pii;

const int MAXN = 1e5 + 5;
const int MAXM = 5;
const int INF = 2e9 + 5;
const int MOD = 1e9 + 7;

int N, M;
int comp[MAXN][1 << MAXM];
vector <pair <pii, pii>> sorted;
int lo[MAXN], mid[MAXN], hi[MAXN];
int a[MAXN][MAXM], a_old[MAXN][MAXM];
int w[MAXN], w_old[MAXN];

void load() {
  scanf("%d%d", &N, &M);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++)
      scanf("%d", a[i] + j);
    scanf("%d", w + i);
  }
}

bool process() {
  bool ok = false;
  vector <vector <int>> queries(N);
  for (int i = 0; i < N; i++) 
    if (lo[i] < hi[i]) {
      mid[i] = (lo[i] + hi[i]) / 2;
      queries[mid[i]].push_back(i);
      ok = true;
    }
  vector <int> disjoint(N);
  vector <int> cnt(sorted.size() + 1);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < 1 << M; j++)
      cnt[comp[i][j]]++;
    for (auto it : queries[i])
      for (int j = 0; j < 1 << M; j++)
        disjoint[it] += __builtin_popcount(j) % 2 ? -cnt[comp[it][j]] : cnt[comp[it][j]];
  }
  for (int i = 0; i < N; i++)
    if (disjoint[i])
      hi[i] = mid[i];
    else if (lo[i] < hi[i])
      lo[i] = mid[i] + 1;
  return ok;
}

int get_base() {
  return uniform_int_distribution <int> (1, MOD - 1)(rng);
}

void append(int &hsh, int elem, int base) {
  hsh = ((long long)base * hsh + elem) % MOD;
}

int solve() {
  vector <int> idx(N);
  iota(idx.begin(), idx.end(), 0);
  sort(idx.begin(), idx.end(), [&](int x, int y) { return w[x] != w[y] ? w[x] < w[y] : x < y; });
  memcpy(a_old, a, sizeof a_old);
  memcpy(w_old, w, sizeof w_old);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++)
      a[i][j] = a_old[idx[i]][j];
    w[i] = w_old[idx[i]];
  }
  int base1 = get_base();
  int base2 = get_base();
  for (int i = 0; i < N; i++) {
    sort(a[i], a[i] + M);
    for (int j = 0; j < 1 << M; j++) {
      pii subset = {0, 0};
      for (int k = 0; k < M; k++)
        if (j >> k & 1) {
          append(subset.first, a[i][k], base1);
          append(subset.second, a[i][k], base2);
        }
      sorted.push_back({subset, {i, j}});
    }
  }
  int curr = 0;
  sort(sorted.begin(), sorted.end());
  for (int i = 0; i < sorted.size(); i++) {
    if (!i || sorted[i].first != sorted[i - 1].first) 
      curr++;
    comp[sorted[i].second.first][sorted[i].second.second] = curr;
  }
  for (int i = 0; i < N; i++)
    hi[i] = N;
  while (process());
  int sol = INF;
  for (int i = 0; i < N; i++)
    if (lo[i] < N)
      sol = min(sol, w[i] + w[lo[i]]);
  return sol == INF ? -1 : sol;
}

int main() {
  load();
  printf("%d\n", solve());
  return 0;
}