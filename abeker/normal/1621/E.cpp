#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 5;
const int offset = 1 << 17;

struct Node {
  int mini, lazy;
};

int N, M;
int a[MAXN];
int k[MAXN];
ll sum[MAXN], avg[MAXN];
vector <int> b[MAXN];
Node tour[2 * offset];

void prop(int x) {
  tour[x].mini += tour[x].lazy;
  if (x < offset) {
    tour[2 * x].lazy += tour[x].lazy;
    tour[2 * x + 1].lazy += tour[x].lazy;
  }
  tour[x].lazy = 0;
}

Node merge(Node lft, Node rig) {
  return {min(lft.mini, rig.mini), 0};
}

void update(int x, int lo, int hi, int from, int to, int val) {
  prop(x);
  if (lo >= to || hi <= from)
    return;
  if (lo >= from && hi <= to) {
    tour[x].lazy += val;
    prop(x);
    return;
  }
  int mid = (lo + hi) / 2;
  update(2 * x, lo, mid, from, to, val);
  update(2 * x + 1, mid, hi, from, to, val);
  tour[x] = merge(tour[2 * x], tour[2 * x + 1]);
}

void update(int from, int val) {
  update(1, 0, offset, from, offset, val);
}

ll query() {
  prop(1);
  return tour[1].mini;
}

void load() {
  scanf("%d%d", &N, &M);
  for (int i = 0; i < N; i++)
    scanf("%d", a + i);
  for (int i = 0; i < M; i++) {
    scanf("%d", k + i);
    b[i].resize(k[i]);
    for (auto &it : b[i])
      scanf("%d", &it);
  }
}

void solve() {
  sort(a, a + N, greater <int> ());
  for (int i = 0; i < M; i++) {
    update(a[i], -1);
    sum[i] = accumulate(b[i].begin(), b[i].end(), 0ll);
    avg[i] = (sum[i] - 1) / k[i] + 1;
    update(avg[i], 1);
  }
  for (int i = 0; i < M; i++) {
    update(avg[i], -1);
    for (auto it : b[i]) {
      ll curr = (sum[i] - it - 1) / (k[i] - 1) + 1;
      update(curr, 1);
      printf("%d", query() >= 0);
      update(curr, -1);
    }
    update(avg[i], 1);
  }
  for (int i = 0; i < M; i++) {
    update(a[i], 1);
    update(avg[i], -1);
  }
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