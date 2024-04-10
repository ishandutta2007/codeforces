#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;

int N, M;
int a[MAXN];
int l[MAXN], r[MAXN];

void load() {
  scanf("%d%d", &N, &M);
  for (int i = 1; i <= N; i++)
    scanf("%d", a + i);
  for (int i = 0; i < M; i++)
    scanf("%d%d", l + i, r + i);
}

int get_first(vector <int> &v, int x) {
  return lower_bound(v.begin(), v.end(), x) - v.begin();
}

int solve() {
  vector <int> mini_left(N + 2, N + 1);
  for (int i = 0; i < M; i++)
    mini_left[r[i]] = min(mini_left[r[i]], l[i]);
  unordered_map <int, vector <int>> pos;
  for (int i = 1; i <= N; i++)
    pos[a[i]].push_back(i);
  int lo = N + 1, hi = 1;
  vector <int> mini_sofar(N + 2, N + 1);
  for (int i = N; i; i--) {
    mini_left[i] = min(mini_left[i], mini_left[i + 1]);
    vector <int> &ref = pos[a[i]];
    int curr = get_first(ref, i);
    if (curr + 1 < ref.size()) {
      int sec = get_first(ref, mini_left[ref[curr + 1]]) + 1;
      if (sec <= curr) {
        lo = min(lo, ref[sec]);
        hi = max(hi, i);
      }
    }
    if (mini_left[i] <= N) {
      int fst = get_first(ref, mini_left[i]);
      mini_sofar[i] = min(mini_sofar[i], ref[fst]);
      if (fst + 1 == curr) {
        mini_sofar[N + 1] = min(mini_sofar[N + 1], i);
        hi = max(hi, ref[fst]);
      }
    }
  }
  int sol = N;
  for (int i = N; i >= hi; i--) {
    sol = min(sol, max(i - min(mini_sofar[i + 1], lo) + 1, 0));
    mini_sofar[i] = min(mini_sofar[i], mini_sofar[i + 1]);
  }
  return sol;
}

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    load();
    printf("%d\n", solve());
  }
  return 0;
}