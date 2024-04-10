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

const int maxn = (int) 5e5 + 5;
int k, n;
int t[maxn];

int read() {
  if (scanf("%d%d", &k, &n) < 2) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &t[i]);
  }
  return true;
}

int s[maxn];
int ls[maxn], rs[maxn];
int alive[maxn];
set<pair<int, int>> st;
set<int> segs;

int getVal(int l, int r) {
  if (l - 1 < 0 || r + 1 >= n) {
    return inf;
  }
  int cur = (s[r + 1] - s[l]) * ((l & 1) ? -1 : 1);
  int nxt = (s[r + 2] - s[l - 1]) * (((l - 1) & 1) ? -1 : 1);
  return nxt - cur;
}

void solve() {
  sort(t, t + n);
  s[0] = 0;
  for (int i = 0; i < n; i++) {
    s[i + 1] = s[i] + ((i & 1) ? 1 : -1) * t[i];
  }
  st.clear();
  segs.clear();
  for (int i = 0; i + 1 < n; i++) {
    alive[i] = false;
    st.insert(make_pair(t[i + 1] - t[i], i));
  }
  int res = 0;
  for (int iter = 0; iter < k; iter++) {
    int id = st.begin()->second;
    res += st.begin()->first;
    st.erase(st.begin());
    if (!alive[id]) {
      alive[id] = true;
      ls[id] = id;
      rs[id] = id + 1;
      segs.insert(id);
    } else {
      ls[id]--;
      rs[id]++;
    }
    if (ls[id]) {
      st.erase(make_pair(t[ls[id]] - t[ls[id] - 1], ls[id] - 1));
    }
    if (rs[id] + 1 < n) {
      st.erase(make_pair(t[rs[id] + 1] - t[rs[id]], rs[id]));
    }
    auto it = segs.find(id);
    if (it != segs.begin()) {
      auto it0 = it;
      it0--;
      int id0 = *it0;
      if (rs[id0] + 1 == ls[id]) {
        st.erase(make_pair(getVal(ls[id0], rs[id0]), id0));
        segs.erase(it0);
        ls[id] = ls[id0];
      }
    }
    {
      auto it0 = it;
      it0++;
      if (it0 != segs.end()) {
        int id0 = *it0;
        if (rs[id] + 1 == ls[id0]) {
          st.erase(make_pair(getVal(ls[id0], rs[id0]), id0));
          segs.erase(it0);
          rs[id] = rs[id0];
        }
      }
    }
    st.insert(make_pair(getVal(ls[id], rs[id]), id));
  }
  printf("%d\n", res);
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