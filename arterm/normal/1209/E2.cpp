#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
typedef long double ld;
typedef long long ll;

const int N = 13;
const int M = 2019;
const int P = 1 << N;

int n, m;

int a[M][N];
int mx[M];
pair<int, int> ord[M];
int d[P];
int h[P];

bool bit(int mask, int i) {
  return (mask >> i) & 1;
}

int shift(int mask) {
  int bit = mask & 1;
  mask >>= 1;
  mask |= bit << (n - 1);
  return mask;
}

void read() {
  cin >> n >> m;

  fill(mx, mx + M, -1);
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) {
      cin >> a[j][i];
      mx[j] = max(mx[j], a[j][i]);
    }
}

void uax(int &x, int y) {
  x = max(x, y);
}

void rec(int *col, int i, int up, int down, int sum) {
  assert((up & down) == 0);
  if (i == n) {
    uax(h[up | down], sum + d[down]);
    return;
  }

  rec(col, i + 1, up, down, sum);
  rec(col, i + 1, up | (1 << i), down, sum + col[i]);
  rec(col, i + 1, up, down | (1 << i), sum);
}

void add(int *col) {
  fill(h, h + (1 << n), 0);
  rec(col, 0, 0, 0, 0);
  
  for (int mask = 0; mask < (1 << n); ++mask) {
    assert(h[mask] >= d[mask]);
    int cur = mask;
    for (int i = 0; i < n; ++i) {
      uax(d[mask], h[cur]);
      cur = shift(cur);
    }
  }
}

void kill() {
  for (int j = 0; j < m; ++j)
    ord[j] = make_pair(-mx[j], j);
  sort(ord, ord + m);

  for (int mask = 0; mask < (1 << n); ++mask)
    d[mask] = 0;

  for (int k = 0; k < min(n, m); ++k) {
    add(a[ord[k].second]);
  }

  cout << d[(1 << n) - 1] << "\n";
}


int main() {
#ifdef LOCAL
  assert(freopen("e.in", "r", stdin));
#endif

  ios_base::sync_with_stdio(false);

  int t;
  cin >> t;
  while (t--) {
    read();
    kill();
  }

}