#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 3005;

int N;
int a[MAXN], b[MAXN], c[MAXN];
int x[MAXN];
int dad[MAXN], sz[MAXN];
int cap[MAXN];

void load() {
  scanf("%d", &N);
  for (int i = 1; i < N; i++)
    scanf("%d%d%d", a + i, b + i, c + i);
  for (int i = 1; i <= N; i++)
    scanf("%d", x + i);
}

int find(int x) {
  return dad[x] == x ? x : dad[x] = find(dad[x]);
}

void join(int x, int y) {
  x = find(x);
  y = find(y);
  if (sz[x] > sz[y])
    swap(x, y);
  dad[x] = y;
  sz[y] += sz[x];
  cap[y] += cap[x];
}

bool check(int val) {
  int sum = 0;
  for (int i = 1; i <= N; i++) {
    dad[i] = i;
    sz[i] = 1;
    cap[i] = x[i];
    sum += x[i];
  }
  
  for (int i = 1; i < N; i++)
    if (c[i] < val)
      join(a[i], b[i]);
  
  for (int i = 1; i <= N; i++) {
    int tmp = find(i);
    if (sz[tmp] + cap[tmp] > sum)
      return false;
  }
  
  return true;
}

int solve() {
  int lo = 0, hi = 10000;
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