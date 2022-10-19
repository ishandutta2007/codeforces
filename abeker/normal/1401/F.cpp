#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int LOG = 19;

int N, Q;
vector <ll> tour[LOG];
int change[LOG];

ll& get(int lvl, int idx) {
  return tour[lvl][idx ^ change[lvl]];
}

void replace(int x, int val) {
  get(N, x) = val;
  for (int lvl = N - 1; lvl >= 0; lvl--) {
    x /= 2;
    get(lvl, x) = get(lvl + 1, 2 * x) + get(lvl + 1, 2 * x + 1);
  }
}

void load() {
  scanf("%d%d", &N, &Q);
  for (int i = 0; i <= N; i++)
    tour[i].resize(1 << i);
  for (int i = 0; i < 1 << N; i++) {
    int x;
    scanf("%d", &x);
    replace(i, x);
  }
}

void rev(int k) {
  for (int i = 0; i < k; i++)
    change[N - i] ^= (1 << k - i) - 1;
}

ll query(int lvl, int idx, int lo, int hi, int from, int to) {
  if (lo >= to || hi <= from)
    return 0;
  if (lo >= from && hi <= to)
    return get(lvl, idx);
  int mid = (lo + hi) / 2;
  return query(lvl + 1, 2 * idx, lo, mid, from, to) + query(lvl + 1, 2 * idx + 1, mid, hi, from, to);
}

void solve() {
  while (Q--) {
    int type, k;
    scanf("%d", &type);
    if (type == 1) {
      int x, v;
      scanf("%d%d", &x, &v);
      replace(x - 1, v);
    }
    else if (type == 2) {
      scanf("%d", &k);
      rev(k);
    }
    else if (type == 3) {
      scanf("%d", &k);
      rev(k + 1);
      rev(k);
    }
    else {
      int l, r;
      scanf("%d%d", &l, &r);
      printf("%lld\n", query(0, 0, 0, 1 << N, l - 1, r));
    }
  }
}

int main() {
  load();
  solve();
  return 0;
}