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

const int maxn = 2005, h = 9, k = 4;
int n;
int a[maxn], b[maxn];

int read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d%d", &a[i], &b[i]);
    a[i]--;
    b[i]--;
  }
  return true;
}

const int maxv = maxn * h * (h + 1) * (h + 1) * (h + 1) * (h + 1);
bitset<maxv> used;
vector<pair<int, int>> q;

int getId(int cur, int pos, int to[k]) {
  int id = cur;
  id = id * h + pos;
  for (int i = 0; i < k; i++) {
    id = id * (h + 1) + to[i];
  }
  return id;
}

void getAll(int id, int &cur, int &pos, int to[k]) {
  for (int i = k - 1; i >= 0; i--) {
    to[i] = id % (h + 1);
    id /= h + 1;
  }
  pos = id % h;
  id /= h;
  cur = id;
}

void mySort(int a[k], int i) {
  while (i && a[i] < a[i - 1]) {
    swap(a[i - 1], a[i]);
    i--;
  }
  while (i + 1 < k && a[i] > a[i + 1]) {
    swap(a[i], a[i + 1]);
    i++;
  }
}

void solve() {
  used.reset();
  q.clear();
  {
    int to[k] = {h, h, h, h};
    int s = getId(0, 0, to);
    q.push_back(make_pair(s, 0));
    used[s] = true;
  }
  for (int l = 0; l < sz(q); l++) {
    int v = q[l].first, d = q[l].second;
    int cur, pos, to[k];
    getAll(v, cur, pos, to);
    for (int dh = -1; dh <= 1; dh += 2) {
      int npos = pos + dh;
      if (npos < 0 || npos >= h) {
        continue;
      }
      int nv = getId(cur, npos, to);
      if (!used[nv]) {
        q.push_back(make_pair(nv, d + 1));
        used[nv] = true;
      }
    }
    for (int i = 0; i < k; i++) {
      if (to[i] == pos) {
        int nto[k];
        for (int j = 0; j < k; j++) {
          nto[j] = to[j];
        }
        nto[i] = h;
        mySort(nto, i);
        int nv = getId(cur, pos, nto);
        if (!used[nv]) {
          bool ok = (cur == n);
          for (int j = 0; j < k && ok; j++) {
            if (nto[j] != h) {
              ok = false;
            }
          }
          if (ok) {
            printf("%d\n", d + 1);
            return;
          }
          q.push_back(make_pair(nv, d + 1));
          used[nv] = true;
        }
      }
    }
    if (cur < n && a[cur] == pos && to[k - 1] == h) {
      int nto[k];
      for (int i = 0; i < k; i++) {
        nto[i] = to[i];
      }
      nto[k - 1] = b[cur];
      mySort(nto, k - 1);
      int nv = getId(cur + 1, pos, nto);
      if (!used[nv]) {
        q.push_back(make_pair(nv, d + 1));
        used[nv] = true;
      }
    }
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