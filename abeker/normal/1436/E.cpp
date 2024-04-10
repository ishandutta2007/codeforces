#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
const int offset = 1 << 17;

int N;
int a[MAXN];
int last[MAXN];
int mini[2 * offset];

void load() {
  scanf("%d", &N);
  for (int i = 1; i <= N; i++)
    scanf("%d", a + i);
}

void update(int x, int val) {
  x += offset;
  mini[x] = val;
  for (x /= 2; x; x /= 2)
    mini[x] = min(mini[2 * x], mini[2 * x + 1]);
}

int query(int x, int lo, int hi, int from, int to) {
  if (lo >= to || hi <= from)
    return MAXN;
  if (lo >= from && hi <= to)
    return mini[x];
  int mid = (lo + hi) / 2;
  return min(query(2 * x, lo, mid, from, to), query(2 * x + 1, mid, hi, from, to));
}

int solve() {
  set <int> other;
  for (int i = 1; i <= N + 2; i++)
    other.insert(i);
  auto check = [&](int val, int pos) {
    if (pos > last[val] + 1 && query(1, 0, offset, 1, val) > last[val])
      other.erase(val);
    if (pos == N + 1)
      return;
    update(val, pos);
    last[val] = pos;
  };
  for (int i = 1; i <= N; i++) 
    check(a[i], i);
  for (int i = 1; i <= N + 1; i++)
    check(i, N + 1);
  return *other.begin();
}

int main() {
  load();
  printf("%d\n", solve());
  return 0;
}