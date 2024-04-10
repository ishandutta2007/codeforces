#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long ll;

const int M = 1010;

int n, m, w;
int a[M], b[M];
int p[M];
int d[M];
vector<int> s[M];

void ini() {
  iota(p, p + M, 0);
}

int get(int x) {
  return p[x] = p[x] == x ? x : get(p[x]);
}

void uni(int x, int y) {
  x = get(x);
  y = get(y);
  if (x < y)
    swap(x, y);
  p[x] = y;
}

void read() {
  cin >> n >> m >> w;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
  }
  for (int i = 0; i < m; ++i) {
    int x, y;
    cin >> x >> y;
    --x, --y;
    uni(x, y);
  }
}

void uax(int &x, int y) {
  x = max(x, y);
}

void kill() {
  for (int i = 0; i < n; ++i)
    s[get(i)].push_back(i);

  fill(d, d + M, 0);

  for (int i = 0; i < n; ++i)
    if (!s[i].empty()) {
      int ta = 0, tb = 0;
      for (int j : s[i]) {
        ta += a[j];
        tb += b[j];
      }

      for (int x = w; x >= 0; --x) {
        if (x >= ta)
          uax(d[x], d[x - ta] + tb);
        for (int j : s[i])
          if (x >= a[j])
            uax(d[x], d[x - a[j]] + b[j]);
      }
    }

  int ans = *max_element(d, d + (w + 1));
  cout << ans << endl;
}

int main() {
#ifdef LOCAL
  assert(freopen("b.in", "r", stdin));
#endif

  ios_base::sync_with_stdio(false);

  ini();
  read();
  kill();
}