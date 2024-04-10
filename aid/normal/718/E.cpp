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

const int maxn = (int) 1e5 + 5, sigma = 8, pows = (1 << sigma);
const int K = 15;
int n;
string s;
char tmp[maxn];

int read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  scanf("%s", tmp);
  s = tmp;
  return true;
}

int d[sigma][maxn], dc[sigma][sigma], msk[maxn];
int cnt[sigma][pows];

void solve() {
  for (int c = 0; c < sigma; c++) {
    vector<int> q;
    for (int i = 0; i < n; i++) {
      if (s[i] == 'a' + c) {
        d[c][i] = 0;
        q.push_back(i);
      } else {
        d[c][i] = inf;
      }
    }
    int used = (1 << c);
    for (int l = 0; l < sz(q); l++) {
      int v = q[l];
      for (int go = -1; go <= 1; go += 2) {
        int u = v + go;
        if (0 <= u && u < n && d[c][u] >= inf) {
          d[c][u] = d[c][v] + 1;
          q.push_back(u);
        }
      }
      if (!(used & (1 << (s[v] - 'a')))) {
        for (int u = 0; u < n; u++) {
          if (s[u] == s[v] && d[c][u] >= inf) {
            d[c][u] = d[c][v] + 1;
            q.push_back(u);
          }
        }
        used |= (1 << (s[v] - 'a'));
      }
    }
  }
  for (int c = 0; c < sigma; c++) {
    for (int i = 0; i < sigma; i++) {
      dc[c][i] = inf;
    }
    for (int i = 0; i < n; i++) {
      dc[c][s[i] - 'a'] = min(dc[c][s[i] - 'a'], d[c][i]);
    }
  }
  for (int i = 0; i < n; i++) {
    auto &cur = msk[i];
    cur = 0;
    for (int c = 0; c < sigma; c++) {
      cur |= ((d[c][i] - dc[c][s[i] - 'a']) << c);
    }
  }
  memset(cnt, 0, sizeof(cnt));
  int ansd = -1;
  long long ansc = 0;
  for (int i = K + 1; i < n; i++) {
    cnt[s[i] - 'a'][msk[i]]++;
  }
  for (int i = 0; i < n; i++) {
    for (int j = max(i - K, 0); j <= min(i + K, n - 1); j++) {
      int dist = abs(j - i);
      for (int c = 0; c < sigma; c++) {
        dist = min(dist, d[c][i] + 1 + d[c][j]);
      }
      if (dist > ansd) {
        ansd = dist;
        ansc = 0;
      }
      if (dist == ansd) {
        ansc++;
      }
    }
    for (int cj = 0; cj < sigma; cj++) {
      for (int msk = 0; msk < pows; msk++) {
        auto cur = cnt[cj][msk];
        if (!cur) {
          continue;
        }
        int dist = inf;
        for (int c = 0; c < sigma; c++) {
          dist = min(dist, d[c][i] + 1 + dc[c][cj] + ((msk >> c) & 1));
        }
        if (dist > ansd) {
          ansd = dist;
          ansc = 0;
        }
        if (dist == ansd) {
          ansc += cur;
        }
      }
    }
    if (i + K + 1 < n) {
      cnt[s[i + K + 1] - 'a'][msk[i + K + 1]]--;
    }
    if (i - K >= 0) {
      cnt[s[i - K] - 'a'][msk[i - K]]++;
    }
  }
  assert(!(ansc & 1));
  ansc /= 2;
  printf("%d %lld\n", ansd, ansc);
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