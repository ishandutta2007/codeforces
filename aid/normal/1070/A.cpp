#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

#ifdef DEBUG
#define eprintf(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#else
#define eprintf(...) ;
#endif

#define sz(x) ((int) (x).size())
#define TASK "text"

const int inf = (int) 1.01e9;
const long long infll = (long long) 1.01e18;
const ld eps = 1e-9;
const ld pi = acos((ld) -1);

mt19937 mrand(random_device{} ()); 

int rnd(int x) {
  return mrand() % x;
}

void precalc() {
}

const int maxd = 505, maxs = 5005;
int d, s;

int read() {
  if (scanf("%d%d", &d, &s) < 2) {
    return false;
  }
  return true;
}

vector<int> g[maxd];
int dist[maxd][maxs];
int p[maxd][maxs];

void solve() {
  for (int i = 0; i < d; i++) {
    g[i].clear();
  }
  for (int i = 0; i < d; i++) {
    int ni = (i * 10) % d;
    g[ni].push_back(i);
  }
  for (int i = 0; i < d; i++) {
    for (int j = 0; j <= s; j++) {
      dist[i][j] = inf;
    }
  }
  vector<pair<int, int>> q;
  dist[0][s] = 0;
  q.push_back(make_pair(0, s));
  for (int l = 0; l < sz(q); l++) {
    int x = q[l].first, sum = q[l].second;
    int curd = dist[x][sum];
    for (int dig = 0; dig < 10 && dig <= sum; dig++) {
      int y = ((x - dig) % d + d) % d;
      for (int i = 0; i < sz(g[y]); i++) {
        int z = g[y][i];
        if (curd + 1 < dist[z][sum - dig]) {
          dist[z][sum - dig] = curd + 1;
          p[z][sum - dig] = dig;
          q.push_back(make_pair(z, sum - dig));
        } else if (curd + 1 == dist[z][sum - dig] && dig < p[z][sum - dig]) {
          p[z][sum - dig] = dig;
        }
      }
    }
  }
  if (dist[0][0] >= inf) {
    printf("-1\n");
    return;
  }
  int x = 0, sum = 0;
  while (x != 0 || sum != s) {
    int dig = p[x][sum];
    printf("%d", dig);
    x = (x * 10 + dig) % d;
    sum += dig;
  }
  printf("\n");
}

int main() {
  precalc();
#ifdef DEBUG
  assert(freopen(TASK ".in", "r", stdin));
  assert(freopen(TASK ".out", "w", stdout));
#endif
  while (read()) {
    solve();
#ifdef DEBUG
    eprintf("Time %.2f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}