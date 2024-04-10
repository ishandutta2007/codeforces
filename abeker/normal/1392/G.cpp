#include <bits/stdc++.h>
using namespace std;

const int MAXK = 21;

int N, M, K;
char s[MAXK], t[MAXK];
int mini[1 << MAXK], maks[1 << MAXK];

int get_mask(char *str, const vector <int> &p) {
  int res = 0;
  for (int i = 0; i < K; i++)
    if (str[i] == '1')
      res |= 1 << p[i];
  return res;
}

void load() {
  scanf("%d%d%d%s%s", &N, &M, &K, s, t);
  vector <int> perm(K);
  iota(perm.begin(), perm.end(), 0);
  fill(mini, mini + (1 << K), N + 1);
  for (int i = 1; i <= N; i++) {
    int pref = get_mask(s, perm); 
    mini[pref] = min(mini[pref], i);
    int a, b;
    scanf("%d%d", &a, &b);
    swap(perm[--a], perm[--b]);
    maks[get_mask(t, perm)] = i;
  }
}

void solve() {
  int lft = 0, rig = 0, least = K + 1;
  for (int i = 0; i < 1 << K; i++) {
    for (int j = 0; j < K; j++)
      if (i >> j & 1) {
        mini[i] = min(mini[i], mini[i ^ 1 << j]);
        maks[i] = max(maks[i], maks[i ^ 1 << j]);
      }
    if (mini[i] && maks[i] - mini[i] + 1 >= M) {
      int cand = __builtin_popcount(i);
      if (cand < least) {
        least = cand;
        lft = mini[i];
        rig = maks[i];
      }
    }
  }
  printf("%d\n%d %d\n", count(s, s + K, '1') + count(t, t + K, '1') - 2 * least + K, lft, rig);
}

int main() {
  load();
  solve();
  return 0;
}