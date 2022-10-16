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

mt19937 mrand(random_device{} ()); 

int rnd(int x) {
  return mrand() % x;
}

void precalc() {
}

const int maxn = (int) 4e5 + 5;
int n, q;
string s;
char tmp[maxn];
int ls[maxn], rs[maxn];

int read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  scanf("%s", tmp);
  s = tmp;
  scanf("%d", &q);
  for (int i = 0; i < q; i++) {
    scanf("%d%d", &ls[i], &rs[i]);
    ls[i]--;
  }
  return true;
}

map<char, int> go[maxn];
int len[maxn], link[maxn];
int vs;
int ps[maxn];

int newNode(int l) {
  go[vs].clear();
  len[vs] = l;
  link[vs] = -1;
  return vs++;
}

int addChar(int v, char c) {
  int u = newNode(len[v] + 1);
  while (v != -1 && !go[v].count(c)) {
    go[v][c] = u;
    v = link[v];
  }
  if (v == -1) {
    link[u] = 0;
    return u;
  }
  int w = go[v][c];
  if (len[w] == len[v] + 1) {
    link[u] = w;
    return u;
  }
  int nw = newNode(len[v] + 1);
  go[nw] = go[w];
  link[nw] = link[w];
  link[w] = nw;
  link[u] = nw;
  while (v != -1 && go[v][c] == w) {
    go[v][c] = nw;
    v = link[v];
  }
  return u;
}

vector<int> g[maxn];
int ts[maxn], heavy[maxn];

void dfs(int v) {
  ts[v] = 1;
  heavy[v] = -1;
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i];
    dfs(u);
    ts[v] += ts[u];
    if (heavy[v] == -1 || ts[u] > ts[heavy[v]]) {
      heavy[v] = u;
    }
  }
}

int pos[maxn], root[maxn], rpos[maxn];

pair<int, int> st[4 * maxn][2];
priority_queue<pair<int, int>> pq[maxn][2];
vector<int> qs[maxn];
int pi[maxn];

void buildst(int v, int tl, int tr) {
  st[v][0] = make_pair(-inf, -inf);
  st[v][1] = make_pair(-inf, -inf);
  if (tl == tr - 1) {
    while (!pq[tl][0].empty()) {
      pq[tl][0].pop();
    }
    while (!pq[tl][1].empty()) {
      pq[tl][1].pop();
    }
    return;
  }
  int tm = (tl + tr) / 2;
  buildst(2 * v, tl, tm);
  buildst(2 * v + 1, tm, tr);
}

void add(int v, int tl, int tr, int pos, pair<int, int> val0, pair<int, int> val1) {
  if (tl == tr - 1) {
    pq[tl][0].push(val0);
    pq[tl][1].push(val1);
    st[v][0] = make_pair(pq[tl][0].top().first, tl);
    st[v][1] = make_pair(pq[tl][1].top().first, tl);
    return;
  }
  int tm = (tl + tr) / 2;
  if (pos < tm) {
    add(2 * v, tl, tm, pos, val0, val1);
  } else {
    add(2 * v + 1, tm, tr, pos, val0, val1);
  }
  st[v][0] = max(st[2 * v][0], st[2 * v + 1][0]);
  st[v][1] = max(st[2 * v][1], st[2 * v + 1][1]);
}

pair<int, int> get(int v, int tl, int tr, int l, int r, int t) {
  if (l == tl && r == tr) {
    return st[v][t];
  }
  int tm = (tl + tr) / 2;
  pair<int, int> res = make_pair(-inf, -inf);
  if (l < tm) {
    res = max(res, get(2 * v, tl, tm, l, min(r, tm), t));
  }
  if (r > tm) {
    res = max(res, get(2 * v + 1, tm, tr, max(l, tm), r, t));
  }
  return res;
}

void del(int v, int tl, int tr, int pos, int t, int i) {
  if (tl == tr - 1) {
    int id = pq[tl][t].top().second;
    pq[tl][t].pop();
    if (pi[id] == -1) {
      pi[id] = i - ls[id];
    }
    st[v][0] = (pq[tl][0].empty() ? make_pair(-inf, -inf) : make_pair(pq[tl][0].top().first, tl));
    st[v][1] = (pq[tl][1].empty() ? make_pair(-inf, -inf) : make_pair(pq[tl][1].top().first, tl));
    return;
  }
  int tm = (tl + tr) / 2;
  if (pos < tm) {
    del(2 * v, tl, tm, pos, t, i);
  } else {
    del(2 * v + 1, tm, tr, pos, t, i);
  }
  st[v][0] = max(st[2 * v][0], st[2 * v + 1][0]);
  st[v][1] = max(st[2 * v][1], st[2 * v + 1][1]);
}

void addQuery(int v, int id) {
  while (v != -1) {
    add(1, 0, vs, pos[v], make_pair(ls[id], id), make_pair(ls[id] + len[v], id));
    v = link[root[v]];
  }
}

void addPref(int i, int v) {
  while (v != -1) {
    while (true) {
      pair<int, int> val = get(1, 0, vs, pos[v], rpos[root[v]], 0);
      if (i - len[v] <= val.first) {
        del(1, 0, vs, val.second, 0, i);
      } else {
        break;
      }
    }
    if (v != root[v]) {
      while (true) {
        pair<int, int> val = get(1, 0, vs, pos[root[v]], pos[v], 1);
        if (i <= val.first) {
          del(1, 0, vs, val.second, 1, i);
        } else {
          break;
        }
      }
    }
    v = link[root[v]];
  }
}

int pid[maxn];
int lt[maxn], rt[maxn];

void addTandem(int l, int d) {
  rt[l] = min(rt[l], 2 * d);
  int r = l + 2 * d;
  lt[r] = min(lt[r], 2 * d);
}

set<int> getTandems(int v) {
  set<int> st;
  if (pid[v] != -1) {
    st.insert(pid[v]);
  }
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i];
    auto stu = getTandems(u);
    if (sz(stu) > sz(st)) {
      swap(stu, st);
    }
    for (auto it = stu.begin(); it != stu.end(); it++) {
      auto itv = st.lower_bound(*it);
      if (itv != st.end() && *itv - *it <= len[v]) {
        int d = *itv - *it;
        addTandem(*it - d, d);
      }
      if (itv != st.begin()) {
        auto itv1 = itv;
        itv1--;
        int d = *it - *itv1;
        if (d <= len[v]) {
          addTandem(*itv1 - d, d);
        }
      }
      st.insert(itv, *it);
    }
  }
  return st;
}

const int sigma = 26;
int po[maxn];
vector<int> os[sigma];

int isTan[maxn];

void solve() {
  vs = 0;
  ps[0] = newNode(0);
  for (int i = 0; i < n; i++) {
    ps[i + 1] = addChar(ps[i], s[i]);
  }
  for (int i = 0; i < vs; i++) {
    g[i].clear();
  }
  for (int i = 1; i < vs; i++) {
    g[link[i]].push_back(i);
  }
  dfs(0);
  for (int v = 0, cur = 0; v < vs; v++) {
    if (link[v] != -1 && heavy[link[v]] == v) {
      continue;
    }
    for (int u = v; u != -1; u = heavy[u]) {
      pos[u] = cur++;
      root[u] = v;
    }
    rpos[v] = cur;
  }
  buildst(1, 0, vs);
  for (int i = 0; i <= n; i++) {
    qs[i].clear();
  }
  for (int i = 0; i < q; i++) {
    qs[rs[i]].push_back(i);
    pi[i] = -1;
  }
  for (int i = n; i >= 0; i--) {
    addPref(i, ps[i]);
    for (int j = 0; j < sz(qs[i]); j++) {
      int id = qs[i][j];
      addQuery(ps[i], id);
    }
  }
  for (int i = 0; i < vs; i++) {
    pid[i] = -1;
  }
  for (int i = 0; i <= n; i++) {
    pid[ps[i]] = i;
    lt[i] = inf;
    rt[i] = inf;
  }
  getTandems(0);
  for (int i = 0; i < sigma; i++) {
    os[i].clear();
  }
  for (int i = 0; i < n; i++) {
    po[i] = sz(os[s[i] - 'a']);
    os[s[i] - 'a'].push_back(i);
  }
  {
    for (int i = 0; i < q; i++) {
      isTan[i] = false;
    }
    priority_queue<pair<int, int>> pq;
    for (int i = n; i >= 0; i--) {
      for (int j = 0; j < sz(qs[i]); j++) {
        int id = qs[i][j];
        pq.push(make_pair(i, id));
      }
      while (!pq.empty() && i + rt[i] <= pq.top().first) {
        int id = pq.top().second;
        pq.pop();
        if (ls[id] <= i) {
          isTan[id] = true;
        }
      }
    }
  }
  for (int id = 0; id < q; id++) {
    int l = ls[id], r = rs[id];
    if (r - l <= sigma) {
      int msk = 0;
      bool ok = false;
      for (int i = l; i < r; i++) {
        int bit = (1 << (s[i] - 'a'));
        if (msk & bit) {
          ok = true;
          break;
        }
        msk |= bit;
      }
      if (!ok) {
        printf("-1\n");
        continue;
      }
    }
    if (pi[id] && !((r - l) % (r - l - pi[id]))) {
      printf("1\n");
      continue;
    }
    if (pi[id] || rt[l] <= r - l || lt[r] <= r - l) {
      printf("2\n");
      continue;
    }
    int nxta = (po[l] + 1 < sz(os[s[l] - 'a']) ? os[s[l] - 'a'][po[l] + 1] : n);
    int prvc = (po[r - 1] ? os[s[r - 1] - 'a'][po[r - 1] - 1] : -1);
    if (nxta < r || prvc >= l || isTan[id]) {
      printf("3\n");
      continue;
    }
    printf("4\n");
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