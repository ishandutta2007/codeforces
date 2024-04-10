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

#ifdef DEBUG
mt19937 mrand(300); 
#else
mt19937 mrand(chrono::steady_clock::now().time_since_epoch().count()); 
#endif

int rnd(int x) {
  return mrand() % x;
}

void precalc() {
}

const int maxn = (int) 4e5 + 5;
int n;
int a[maxn];

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  return true;
}

int cnt[maxn];
pair<int, int> ps[maxn];
vector<vector<int>> ans;

void solve() {
  sort(a, a + n);
  int k = 0;
  for (int i = 0; i < n; i++) {
    if (!k || a[i] != a[k - 1]) {
      a[k] = a[i];
      cnt[k] = 1;
      k++;
    } else {
      cnt[k - 1]++;
    }
  }
  for (int i = 0; i < k; i++) {
    ps[i] = make_pair(cnt[i], a[i]);
  }
  sort(ps, ps + k);
  int val = 0, h = -1;
  for (int i = 1, pos = 0, sum = 0; i * i <= n; i++) {
    while (pos < k && ps[pos].first < i) {
      sum += ps[pos].first;
      pos++;
    }
    int cur = sum + (k - pos) * i;
    cur -= cur % i;
    if (cur >= i * i && cur > val) {
      val = cur;
      h = i;
    }
  }
  int w = val / h;
  ans.clear();
  ans.resize(h, vector<int>(w));
  for (int i = 0; i < k; i++) {
    a[i] = ps[k - 1 - i].second;
    cnt[i] = min(h, ps[k - 1 - i].first);
  }
  int pos = 0;
  for (int i = 0; i < w; i++) {
    for (int j = 0; j < h; j++) {
      int x = j, y = (i + j) % w;
      while (!cnt[pos]) {
        pos++;
      }
      ans[x][y] = a[pos];
      cnt[pos]--;
    }
  }
  printf("%d\n", val);
  printf("%d %d\n", h, w);
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      printf("%d ", ans[i][j]);
    }
    printf("\n");
  }
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