#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
const bool testing = 0;
int p[N];
int ans[N];
int n;
int test_n = 20;
vector<int> z[N];

int query(int a, int b, int c) {
  cout << "? " << a << " " << b << " " << c << endl;
  if (testing) {
    int u = abs(p[a]-p[b]);
    int v = abs(p[b]-p[c]);
    int w = abs(p[c]-p[a]);
    return u+v+w - min({u, v, w}) - max({u, v, w});
  }
  int m;
  cin >> m;
  if (m == -1) {
    exit(0);
  }
  return m;
}

int myrandom(int i) {
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  return rng()%i;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

  int T;
  cin >> T;
  while (T--) {
    if (testing) {
      n = test_n;
      for (int i = 1; i <= n; i++) {
        p[i] = n+1-i;
      }
      while (p[1] > p[2]) random_shuffle(p+1, p+n+1, myrandom);
    }
    else cin >> n;

    int a, b, c;
    int d = N;
    while (6*d + 4 > n) {
      a = rng()%n+1;
      b = rng()%n+1;
      c = rng()%n+1;
      if (a == b || b == c || c == a) continue;
      d = query(a, b, c);
    }

    int mx = 0;
    for (int i = 1; i <= n; i++) {
      if (i == a || i == b) continue;
      int m = query(a, b, i);
      z[m].push_back(i);
      mx = max(mx, m);
    }

    int u = z[mx][0];
    int v = z[mx-1][0];
    if (z[mx-1].size() != 1) {
      int w = z[mx-1][1];
      if (query(u, w, a) < query(u, v, a)) swap(v, w);
    }
    ans[u] = 1;
    ans[v] = 2;
    for (int i = 1; i <= n; i++) {
      if (i == u || i == v) continue;
      ans[i] = 2+query(u, v, i);
    }

    if (ans[1] > ans[2]) {
      for (int i = 1; i <= n; i++) {
        ans[i] = n+1-ans[i];
      }
    }
    cout << "! ";
    for (int i = 1; i <= n; i++) {
      cout << ans[i] << ' ';
    }
    cout << endl;

    int verdict;
    cin >> verdict;
    if (verdict == -1) return 0;

    for (int i = 1; i <= n; i++) z[i].clear();
  }
}