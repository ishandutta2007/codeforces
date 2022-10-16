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

const int maxn = (int) 1e5 + 5, k = 100, maxb = (maxn + k - 1) / k;
int n, m;
int a[maxn];
pair<int, pair<int, int> > qs[maxn];

int read() {
  if (scanf("%d%d", &n, &m) < 2) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    a[i]--;
  }
  for (int i = 0; i < m; i++) {
    scanf("%d%d%d", &qs[i].first, &qs[i].second.first, &qs[i].second.second);
    if (qs[i].first == 1) {
      qs[i].second.first--;
      qs[i].second.second--;
    } else {
      qs[i].second.first--;
    }
  }
  return true;
}

set<int> st[maxn];
int p[maxn];
vector< pair<int, int> > b[maxb];
vector<int> s[maxb];
bool flag;

void update(int pos, int x) {
  p[pos] = x;
  int id = pos / k;
  {
    int i = 0;
    int y = flag ? n - pos - 1 : pos;
    while (b[id][i].second != y) {
      i++;
    }
    b[id][i].first = x;
    while (i && b[id][i - 1] > b[id][i]) {
      swap(b[id][i - 1], b[id][i]);
      i--;
    }
    while (i + 1 < sz(b[id]) && b[id][i] > b[id][i + 1]) {
      swap(b[id][i], b[id][i + 1]);
      i++;
    }
  }
  s[id][0] = 0;
  for (int i = 0; i < sz(b[id]); i++) {
    s[id][i + 1] = s[id][i] + b[id][i].second;
  }
}

int get(int id, int l) {
  int pos = lower_bound(b[id].begin(), b[id].end(), make_pair(l, -inf)) - b[id].begin();
  return s[id][pos];
}

int getStupid(int id, int l, int r) {
  int res = 0;
  for (int i = 0; i < sz(b[id]); i++) {
    int pos = flag ? n - b[id][i].second - 1 : b[id][i].second;
    if (l <= pos && pos < r && b[id][i].first < l) {
      res += b[id][i].second;
    }
  }
  return res;
}

void solve1(long long ans[maxn]) {
  for (int i = 0; i < n; i++) {
    st[i].clear();
  }
  for (int i = n - 1; i >= 0; i--) {
    if (!st[a[i]].empty()) {
      int j = *st[a[i]].begin();
      p[j] = i;
    }
    st[a[i]].insert(i);
    p[i] = -1;
  }
  int bs = (n + k - 1) / k;
  for (int i = 0; i < bs; i++) {
    int bl = i * k, br = min(bl + k, n);
    b[i].resize(br - bl);
    for (int j = bl; j < br; j++) {
      b[i][j - bl] = make_pair(p[j], flag ? n - j - 1 : j);
    }
    sort(b[i].begin(), b[i].end());
    s[i].resize(br - bl + 1);
    s[i][0] = 0;
    for (int j = 0; j < br - bl; j++) {
      s[i][j + 1] = s[i][j] + b[i][j].second;
    }
  }
  for (int q = 0; q < m; q++) {
    int t = qs[q].first;
    if (t == 1) {
      int pos = qs[q].second.first, nx = qs[q].second.second;
      int px = a[pos];
      st[px].erase(pos);
      {
        auto it = st[px].upper_bound(pos);
        if (it != st[px].end()) {
          int npos = *it;
          if (it == st[px].begin()) {
            update(npos, -1);
          } else {
            it--;
            update(npos, *it);
          }
        }
      }
      {
        auto it = st[nx].upper_bound(pos);
        if (it != st[nx].end()) {
          update(*it, pos);
        }
      }
      {
        auto it = st[nx].insert(pos).first;
        if (it == st[nx].begin()) {
          update(pos, -1);
        } else {
          it--;
          update(pos, *it);
        }
      }
      a[pos] = nx;
    } else {
      int l = qs[q].second.first, r = qs[q].second.second;
      int lb = l / k, rb = (r - 1) / k;
      ans[q] = 0;
      for (int i = lb; i <= rb; i++) {
        int bl = i * k, br = min(bl + k, n);
        if (l <= bl && r >= br) {
          ans[q] += get(i, l);
        } else {
          ans[q] += getStupid(i, l, r);
        }
      }
    }
  }
}

int a0[maxn];
long long ans[2][maxn];

void solve() {
  for (int i = 0; i < n; i++) {
    a0[i] = a[i];
  }
  flag = false;
  solve1(ans[0]);
  for (int i = 0; i < n; i++) {
    a[i] = a0[i];
  }
  reverse(a, a + n);
  for (int i = 0; i < m; i++) {
    if (qs[i].first == 1) {
      auto &pos = qs[i].second.first;
      pos = n - pos - 1;
    } else {
      auto &l = qs[i].second.first, &r = qs[i].second.second;
      r--;
      swap(l, r);
      l = n - l - 1;
      r = n - r - 1;
      r++;
    }
  }
  flag = true;
  solve1(ans[1]);
  for (int i = 0; i < m; i++) {
    if (qs[i].first == 1) {
      continue;
    }
    printf("%lld\n", ans[1][i] - ans[0][i]);
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