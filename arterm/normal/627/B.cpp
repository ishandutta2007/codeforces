#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int M = 2e5 + 10;

int n, k, a, b, q;

struct Fenw {
  int f[M];

  Fenw() {
    fill(f, f + M, 0);
  }

  void add(int at, int x) {
    for (int i = at; i < M; i |= (i + 1))
      f[i] += x;
  }

  int get(int r) {
    int ans = 0;
    for (int i = r; i >= 0; i = (i & (i + 1)) - 1)
      ans += f[i];
    return ans;
  }

  int get(int l, int r) {
    return get(r) - get(l - 1);
  }
};

int cur[M];
Fenw l, r;

void add(int at, int x) {
  l.add(at, -min(cur[at], b));
  r.add(at, -min(cur[at], a));

  cur[at] += x;

  l.add(at, min(cur[at], b));
  r.add(at, min(cur[at], a));
}

void read() {
  cin >> n >> k >> a >> b >> q;

  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      int at, x;
      cin >> at >> x;
      add(at, x);
    } else {
      int p;
      cin >> p;
      int ans = l.get(0, p - 1) + r.get(p + k, n);
      cout << ans << endl;
    }
  }
}


int main() {
  cout.precision(20);
  cout << fixed;
  ios_base::sync_with_stdio(false);
  read();
}