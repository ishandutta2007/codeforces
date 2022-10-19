#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
typedef long double ld;
typedef long long ll;

const int M = 88;
const int N = 13;
const int ITER = 100000;
const int inf = 1e9 + 1e7;

int n, k;
int a[M][M];
int d[N][M];
vector<int> c[2];
mt19937 rng;

int rnd() {
  return (rng()%2 + 1)%2;
}

void gen() {
  n = 80;
  k = 10;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      if (i != j)
        a[i][j] = rng() % (int(1e8));
      else
        a[i][j] = 0;
}

void read() {
  cin >> n >> k;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      cin >> a[i][j];
}

int solve() {
  for (int i = 0; i <= k; ++i)
    fill(d[i], d[i] + n, inf);

  d[0][0] = 0;
  for (int i = 0; i < k; ++i)
    for (int u : c[i % 2])
      if (d[i][u] < inf)
        for (int v : c[(i + 1) % 2])
          d[i + 1][v] = min(d[i + 1][v], d[i][u] + a[u][v]);

  return d[k][0];
}

int main() {
#ifdef LOCAL
  assert(freopen("d.in", "r", stdin));
#endif

  ios_base::sync_with_stdio(false);

  read();
  //gen();
  int ans = inf;
  for (int i = 0; i < ITER; ++i) {
    c[0].clear();
    c[1].clear();

    c[0].push_back(0);
    for (int i = 1; i < n; ++i)
      c[rnd()].push_back(i);

    ans = min(ans, solve());
  }

  cout << ans << "\n";
}