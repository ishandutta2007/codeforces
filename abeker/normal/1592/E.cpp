#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1 << 20;
const int LOG = 20;

int N;
int a[MAXN];
int pref[MAXN];
int pos[MAXN];

void load() {
  scanf("%d", &N);
  for (int i = 1; i <= N; i++)
    scanf("%d", a + i);
}

inline int get_bit(int x, int y) {
  return a[x] >> y & 1;
}

inline int get_pref(int x, int y) {
  return pref[x] | (1 << y) - 1;
}

int find_longest(int from, int to, int bit) {
  int res = 0;
  for (int i = from - 1; i <= to; i++)
    pos[get_pref(i, bit)] = -1; 
  for (int i = from - 1; i <= to; i++) {
    int tmp = get_pref(i, bit);
    if (pos[tmp] != -1) 
      res = max(res, i - pos[tmp]);
    else
      pos[tmp] = i;
  }
  return res;
}

int solve() {
  for (int i = 1; i <= N; i++)
    pref[i] = pref[i - 1] ^ a[i];
  int sol = 0;
  for (int j = 0; j < LOG; j++) {
    int st = 0;
    for (int i = 1; i <= N; i++) {
      if (get_bit(i, j) && !get_bit(i - 1, j))
        st = i;
      if (get_bit(i, j) && !get_bit(i + 1, j))
        sol = max(sol, find_longest(st, i, j));
    }
  }
  return sol;
}

int main() {
  load();
  printf("%d\n", solve());
  return 0;
}