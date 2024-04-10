#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
typedef long double ld;
typedef long long ll;

const int M = 200100;
const int N = 4 * M;
const int inf = 1e9;

int n, q, s[M];
string t;
const int S[] = {0, +1, -1, 0};

struct Node {
  int d[4][4];

  int* operator[](int x) {
    return d[x];
  }

} tree[N];
int bon[N];

void uax(int &x, int y) {
  x = max(x, y);
}


Node nodeByVal(int value) {
  Node node;
  for (int i = 0; i < 4; ++i)
    for (int j = i; j < 4; ++j) {
      node[i][j] = (S[j] - S[i]) * value;
    }
  return node;
}

void push(int v, int l, int r) {
  for (int i = 0; i < 4; ++i)
    for (int j = i; j < 4; ++j)
      tree[v][i][j] += (S[j] - S[i]) * bon[v];

  if (r - l > 1) {
    bon[2 * v] += bon[v];
    bon[2 * v + 1] += bon[v];
  }

  bon[v] = 0;
}

void upd(int v, int l, int r) {
  assert(r - l > 1);

  for (int i = 0; i < 4; ++i)
    for (int j = i; j < 4; ++j)
      tree[v][i][j] = -inf;

  int m = (l + r) / 2;
  push(2 * v, l, m);
  push(2 * v + 1, m, r);
  
  for (int i = 0; i < 4; ++i)
    for (int k = i; k < 4; ++k)
      for (int j = k; j < 4; ++j)
        uax(tree[v][i][j], tree[2 * v][i][k] + tree[2 * v + 1][k][j]);
}

void build(int v, int l, int r) {
  if (l + 1 == r) {
    tree[v] = nodeByVal(s[l]);
    return;
  }

  int m = (l + r) / 2;
  build(2 * v, l, m);
  build(2 * v + 1, m, r);

  upd(v, l, r);
}

void add(int v, int l, int r, int le, int re, int val) {
  push(v, l, r);
  if (l == le && r == re) {
    bon[v] += val;
    return;
  }

  int m = (l + r) / 2;
  if (le < m)
    add(2 * v, l, m, le, min(re, m), val);
  if (m < re)
    add(2 * v + 1, m, r, max(m, le), re, val);
  upd(v, l, r);
}

int get() {
  push(1, 0, n + 1);
  return tree[1][0][3];
}

void read() {
  cin >> n >> q;
  cin >> t;
  n = t.length();
}

int naive() {
  s[0] = 0;

  for (int i = 0; i < n; ++i) {
    char c = t[i];

    s[i + 1] = s[i];

    if (c == '(')
      s[i + 1]++;
    else
      s[i + 1]--;
  }

  int ans = 0;
  for (int l = 0; l <= n; ++l)
    for (int m = l; m <= n; ++m)
      for (int r = m; r <= n; ++r)
        ans = max(ans, s[l] + s[r] - 2 * s[m]);
  return ans;
}

void kill() {
  for (int i = 0; i < n; ++i) {
    char c = t[i];

    s[i + 1] = s[i];

    if (c == '(')
      s[i + 1]++;
    else
      s[i + 1]--;
  }

  build(1, 0, n + 1);
  cout << get() << "\n";
  //cerr << naive() << "!\n";
  while (q--) {
    int x, y;
    cin >> x >> y;
    --x, --y;

    if (x > y)
      swap(x, y);

    if (t[x] != t[y]) {
      int val = 0;
      if (t[x] == '(') {
        val = -2;
      } else {
        val = +2;
      }
      add(1, 0, n + 1, x + 1, y + 1, val);
      swap(t[x], t[y]);
    }

    cout << get() << "\n";
    //cerr << naive() << "!\n";
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