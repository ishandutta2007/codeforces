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

const int maxn = (int) 3e5 + 5;
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

int m;
int p[maxn], ts[maxn];

int get(int x) {
  return (p[x] == x ? x : p[x] = get(p[x]));
}

void unite(int x, int y) {
  x = get(x);
  y = get(y);
  if (x == y) {
    return;
  }
  if (ts[x] < ts[y]) {
    swap(x, y);
  }
  p[y] = x;
  ts[x] += ts[y];
}

set<pair<int, int>, greater<pair<int, int>>> st;
deque<int> vs[maxn];

void merge(int x, int y, int k) {
  if (k < sz(vs[y]) - 2) {
    int tmp = vs[x].front();
    vs[x].pop_front();
    vs[x].push_back(tmp);
  }
  int curk = sz(vs[y]);
  int lst = vs[x].back();
  unite(vs[x].back(), vs[y].back());
  vs[x].pop_back();
  vs[y].pop_back();
  int pr = lst;
  while (curk > k) {
    pr = vs[x].back();
    unite(vs[x].back(), vs[y].back());
    vs[x].pop_back();
    vs[y].pop_back();
    curk -= 2;
  }
  vs[x].push_back(pr);
  while (!vs[y].empty()) {
    vs[x].push_back(vs[y].back());
    vs[y].pop_back();
  }
  vs[x].push_back(lst);
}

int ids[maxn];

void printAns() {
  int curid = 0;
  for (int i = 0; i < m; i++) {
    if (p[i] == i) {
      ids[i] = curid++;
    }
  }
  printf("%d\n", curid);
  int cur = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < a[i]; j++) {
      printf("%d ", ids[get(cur++)] + 1);
    }
    printf("\n");
  }
}

void solve() {
  m = 0;
  st.clear();
  for (int i = 0; i < n; i++) {
    st.insert(make_pair(a[i], i));
    vs[i].clear();
    for (int j = 0; j < a[i]; j++) {
      vs[i].push_back(m++);
    }
  }
  for (int i = 0; i < m; i++) {
    p[i] = i;
    ts[i] = 1;
  }
  long long s = 0;
  for (int i = 0; i < n; i++) {
    s += a[i] - 2;
  }
  if (2 * (st.begin()->first - 2) - s >= 3) {
    auto it = st.begin();
    it++;
    while (it != st.end()) {
      merge(st.begin()->second, it->second, -it->first + 2);
      it++;
    }
    printAns();
    return;
  }
  while (sz(st) > 1) {
    int x = st.begin()->second;
    st.erase(st.begin());
    int y = st.begin()->second;
    st.erase(st.begin());
    bool found = false;
    for (int k = -sz(vs[y]) + 2; k <= sz(vs[y]) - 2; k += 2) {
      int na = sz(vs[x]) - 2 + k;
      if (!na) {
        continue;
      }
      long long ns = s;
      ns -= sz(vs[y]) - 2;
      ns += k;
      if (2 * na - ns >= 3) {
        continue;
      }
      if (!st.empty()) {
        int aa = st.begin()->first - 2;
        if (2 * aa - ns >= 3) {
          continue;
        }
      }
      found = true;
      merge(x, y, k);
      s = ns;
      break;
    }
    assert(found);
    st.insert(make_pair(sz(vs[x]), x));
  }
  printAns();
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