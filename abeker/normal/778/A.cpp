#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN = 200005;

int N, M;
char t[MAXN], p[MAXN];
int inv[MAXN];

void load() {
  scanf("%s%s", t, p);
  N = strlen(t);
  M = strlen(p);
  for (int i = 0; i < N; i++) {
    int x;
    scanf("%d", &x);
    inv[--x] = i;
  }
}

bool check(int len) {
  int pos = 0;
  for (int i = 0; i < N; i++)
    if (inv[i] >= len && t[i] == p[pos])
      pos++;
  return pos >= M;
}

int solve() {
  int lo = 0, hi = N;
  while (lo < hi) {
    int mid = (lo + hi + 1) / 2;
    if (check(mid))
      lo = mid;
    else
      hi = mid - 1;
  }
  return lo;
}

int main() {
  load();
  printf("%d\n", solve());
  return 0;
}