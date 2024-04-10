#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long ll;

const int M = 100100;

int t[8 * M];
int s[8 * M];

void push(int v) {
  t[v] = t[v] + s[v];
  s[2 * v] += s[v];
  s[2 * v + 1] += s[v];
  s[v] = 0;
}

int val(int v) {
  return t[v] + s[v];
}

void add(int v, int l, int r, int le, int re, int by) {
  push(v);

  if (l == le && r == re) {
    s[v] += by;
    return;
  }

  int m = (l + r) / 2;
  if (le < m)
    add(2 * v, l, m, le, min(m, re), by);

  if (m < re)
    add(2 * v + 1, m, r, max(m, le), re, by);

  t[v] = max(val(2 * v), val(2 * v + 1));
}

int get(int v, int l, int r, int to) {
  push(v);

  if (l + 1 == r) {
    if (val(v) < to)
      return -1;
    else
      return l;
  }

  int m = (l + r) / 2;

  if (val(2 * v + 1) >= to)
    return get(2 * v + 1, m, r, to);
  
  return get(2 * v, l, m, to);
}

int n;
int a[M];

void read() {
  cin >> n;
}

void kill() {
  for (int i = 0; i < n; ++i) {
    int at;
    cin >> at;
    --at;

    int type;
    cin >> type;
    if (type == 1)
      cin >> a[at];

    if (type == 0)
      add(1, 0, n, 0, at + 1, -1);
    else
      add(1, 0, n, 0, at + 1, 1);
    
    int pos = get(1, 0, n, 1);

    if (pos == -1)
      cout << "-1\n";
    else {
      assert(a[pos] > 0);
      cout << a[pos] << "\n";
    }
  }
}

int main() {
#ifdef LOCAL
  assert(freopen("c.in", "r", stdin));
#endif

  ios_base::sync_with_stdio(false);

  read();
  kill();
}