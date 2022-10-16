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
const ld eps = 1e-9;
const ld pi = acos((ld) -1);

mt19937 mrand(random_device{} ()); 

int rnd(int x) {
  return mrand() % x;
}

void precalc() {
}

const int maxn = 1005;
const int maxx = (int) 2e4 + 5;
const int sigma = 26;
int n;
int a[maxn][2];
int res[maxn];
int used[maxx];
char tmp[100];

int read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  memset(used, 0, sizeof(used));
  for (int i = 0; i < n; i++) {
    string s, t;
    scanf("%s", tmp);
    s = tmp;
    scanf("%s", tmp);
    t = tmp;
    for (int j = 0; j < 2; j++) {
      string cur;
      if (!j) {
        cur = s.substr(0, 3);
      } else {
        cur = s.substr(0, 2) + t.substr(0, 1);
      }
      int x = 0;
      for (int k = 0; k < 3; k++) {
        x = x * sigma + (cur[k] - 'A');
      }
      a[i][j] = x;
    }
    res[i] = -1;
  }
  return true;
}

void solve() {
  for (int i = 0; i < n; i++) {
    if (res[i] != -1) {
      continue;
    }
    vector<int> v;
    v.push_back(i);
    for (int j = i + 1; j < n; j++) {
      if (a[j][0] == a[i][0]) {
        v.push_back(j);
      }
    }
    if (sz(v) == 1) {
      continue;
    }
    for (int j = 0; j < sz(v); j++) {
      int id = v[j];
      if (used[a[id][1]]) {
        printf("NO\n");
        return;
      }
      res[id] = 1;
      used[a[id][1]] = true;
    }
  }
  while (true) {
    bool ch = false;
    for (int i = 0; i < n; i++) {
      if (res[i] != -1) {
        continue;
      }
      for (int j = 0; j < 2; j++) {
        if (used[a[i][j]]) {
          if (used[a[i][j ^ 1]]) {
            printf("NO\n");
            return;
          }
          res[i] = (j ^ 1);
          used[a[i][j ^ 1]] = true;
          ch = true;
          break;
        }
      }
    }
    if (!ch) {
      break;
    }
  }
  for (int i = 0; i < n; i++) {
    if (res[i] == -1) {
      res[i] = 0;
    }
  }
  printf("YES\n");
  for (int i = 0; i < n; i++) {
    int x = a[i][res[i]];
    string s;
    for (int j = 0; j < 3; j++) {
      s += (char) (x % sigma + 'A');
      x /= sigma;
    }
    reverse(s.begin(), s.end());
    printf("%s\n", s.c_str());
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