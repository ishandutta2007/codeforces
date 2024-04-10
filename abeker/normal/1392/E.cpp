#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 25;

int N, Q;
ll a[MAXN][MAXN];

ll rec(int, int);
ll smallest(int, int);
ll largest(int, int);
 
ll smallest(int x, int y) {
  ll res = 0;
  for (int i = y + 1; i < N; i++)
    res += rec(x, i);
  for (int i = x + 1; i < N; i++)
    res += rec(i, N - 1);
  return res;
}

ll largest(int x, int y) {
  ll res = 0;
  for (int i = x + 1; i < N; i++)
    res += rec(i, y);
  for (int i = y + 1; i < N; i++)
    res += rec(N - 1, i);
  return res;
}

ll rec(int x, int y) {
  ll &ref = a[x][y];
  if (ref != -1)
    return ref;
  if (x == 0 || y == N - 1)
    return ref = 0;
  return ref = largest(x - 2, y + 1) - smallest(x, y) + 1;
}

void load() {
  scanf("%d", &N);
}

void construct() {
  memset(a, -1, sizeof a);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++)
      printf("%lld ", rec(i, j));
    puts("");
    fflush(stdout);
  }
}

void find_path(ll target) {
  int x = 0, y = 0;
  for (int i = 1; i < 2 * N; i++) {
    printf("%d %d\n", x + 1, y + 1);
    fflush(stdout);
    target -= rec(x, y);
    if (x == N - 1 || smallest(x + 1, y - 1) > target) {
      y++; continue;
    }
    if (y == N - 1 || largest(x - 1, y + 1) < target) {
      x++; continue;
    }
    assert(false);
  }
}

void solve() {
  scanf("%d", &Q);
  while (Q--) {
    ll k;
    scanf("%lld", &k);
    find_path(k);
  }
}

int main() {
  load();
  construct();
  solve();
  return 0;
}