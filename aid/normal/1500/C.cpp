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

const int mod = (int) 1e9 + 7;

int mul(int a, int b) {
  return (long long) a * b % mod;
}

void add(int &a, int b) {
  a += b;
  if (a >= mod) {
    a -= mod;
  }
}

int p;

void precalc() {
  p = rnd(mod);
}

const int maxn = 1505;
int n, m;
int a[maxn][maxn], b[maxn][maxn];

bool read() {
  if (!(cin >> n >> m)) {
    return false;
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> a[i][j];
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> b[i][j];
    }
  }
  return true;
}

int cnt[maxn];
int used[maxn];
int good[maxn];
vector<int> ans;
map<int, int> mp;

void solve() {
  for (int i = 0; i + 1 < n; ++i) {
    good[i] = false;
  }
  ans.clear();
  for (int j = 0; j < m; ++j) {
    cnt[j] = 0;
    used[j] = false;
    for (int i = 0; i + 1 < n; ++i) {
      if (b[i][j] > b[i + 1][j]) {
        ++cnt[j];
      }
    }
  }
  while (true) {
    int col = -1;
    for (int j = 0; j < m; ++j) {
      if (!used[j] && !cnt[j]) {
        col = j;
        break;
      }
    }
    if (col == -1) {
      break;
    }
    ans.push_back(col);
    used[col] = true;
    for (int i = 0; i + 1 < n; ++i) {
      if (!good[i] && b[i][col] != b[i + 1][col]) {
        good[i] = true;
        for (int j = 0; j < m; ++j) {
          if (b[i][j] > b[i + 1][j]) {
            --cnt[j];
          }
        }
      }
    }
  }
  mp.clear();
  for (int i = 0; i < n; ++i) {
    if (i && !good[i - 1]) {
      continue;
    }
    int h = 0;
    for (int j = 0; j < sz(ans); ++j) {
      int col = ans[j];
      h = mul(h, p);
      add(h, b[i][col]);
    }
    mp[h] = i;
  }
  for (int i = 0; i < n; ++i) {
    int h = 0;
    for (int j = 0; j < sz(ans); ++j) {
      int col = ans[j];
      h = mul(h, p);
      add(h, a[i][col]);
    }
    if (!mp.count(h)) {
      printf("-1\n");
      return;
    }
    auto &ii = mp[h];
    if (ii >= n) {
      printf("-1\n");
      return;
    }
    for (int j = 0; j < m; ++j) {
      if (a[i][j] != b[ii][j]) {
        printf("-1\n");
        return;
      }
    }
    ++ii;
  }
  cout << sz(ans) << "\n";
  for (int i = sz(ans) - 1; i >= 0; --i) {
    cout << ans[i] + 1 << " ";
  }
  cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
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