#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
typedef long double ld;
typedef long long ll;

const int M = 200200;
const int inf = 1e9;
const int N = 4 * M;

int n, m, q;
int p[M], a[M], b[M];
int c[M];
int pos[M];
int nx[M];
int t[N];

void build(int v, int l, int r) {
  if (l + 1 == r) {
    t[v] = b[l];
    return;
  }
  int m = (l + r) / 2;
  build(2 * v, l, m);
  build(2 * v + 1, m, r);
  t[v] = min(t[2 * v], t[2 * v + 1]);
}

int get(int v, int l, int r, int le, int re) {
  assert(l <= le && re <= r);
  if (l == le && r == re) {
    return t[v];
  }
  int m = (l + r) / 2;
  if (re <= m) {
    return get(2 * v, l, m, le, re);
  } else if (m <= le) {
    return get(2 * v + 1, m, r, le, re);
  } else {
    return min(
        get(2 * v, l, m, le, m),
        get(2 * v + 1, m, r, m, re)
        );
  }
}

void read() {
  cin >> n >> m >> q;
  for (int i = 0; i < n; ++i) {
    cin >> p[i];
    --p[i];
  }
  for (int i = 0; i < m; ++i) {
    cin >> a[i];
    --a[i];
  }
}

void pre() {
  p[n] = p[0];
  for (int i = 0; i < n; ++i) {
    nx[p[i]] = p[i + 1];
  }

  fill(pos, pos + n, m);
  c[m] = m;

  for (int i = m - 1; i >= 0; --i) {
    pos[a[i]] = i;
    c[i] = pos[nx[a[i]]];
  }

  for (int i = 0; i <= m; ++i) {
    b[i] = i;
  }

  int pw = n - 1;
  while (pw) {
    if (pw & 1) {
      for (int i = 0; i <= m; ++i) {
        b[i] = c[b[i]];
      }
    }

    for (int i = 0; i <= m; ++i) {
      c[i] = c[c[i]];
    }

    pw >>= 1;
  }

  //for (int i = 0; i < m; ++i) {
    //cerr << b[i] << " ";
  //}
  //cerr << "\n";

}

void kill() {
  build(1, 0, m);

  for (int i = 0; i < q; ++i) {
    int l, r;
    cin >> l >> r;
    --l;
    int mn = get(1, 0, m, l, r);
    //cerr << "mn = " << mn << "\n";

    if (mn < r) {
      cout << '1';
    } else {
      cout << '0';
    }
  }
  cout << "\n";
}

int main() {
#ifdef LOCAL
  assert(freopen("b.in", "r", stdin));
#endif

  ios_base::sync_with_stdio(false);

  read();
  pre();
  kill();
}