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

const int maxn = (int) 1e5 + 5;
int n;

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  return n != -1;
}

char tmp[maxn];

string ask(const vector<pair<int, int>> &q) {
  if (q.empty()) {
    return "";
  }
  printf("Q %d ", sz(q));
  for (int i = 0; i < sz(q); i++) {
    printf("%d %d ", q[i].first + 1, q[i].second + 1);
  }
  printf("\n");
  fflush(stdout);
  scanf("%s", tmp);
  string s = tmp;
  if (s == "-1") {
    exit(0);
  }
  return s;
}

int eq[maxn];
int nxt[maxn];
int eqb[maxn];
vector<int> ans[3];

int getMex(int a, int b) {
  int c = 0;
  while (c == a || c == b) {
    c++;
  }
  return c;
}

void solve() {
  for (int t = 0; t < 2; t++) {
    vector<pair<int, int>> q;
    for (int i = t; i + 1 < n; i += 2) {
      q.push_back(make_pair(i, i + 1));
    }
    string s = ask(q);
    for (int i = 0; i < sz(q); i++) {
      eq[q[i].first] = s[i] - '0';
    }
  }
  nxt[n - 1] = n;
  for (int i = n - 2; i >= 0; i--) {
    nxt[i] = (eq[i] ? nxt[i + 1] : i + 1);
  }
  for (int t = 0; t < 2; t++) {
    int p = 0;
    if (t) {
      p = nxt[p];
      if (p < n) {
        p = nxt[p];
      }
    }
    vector<pair<int, int>> q;
    while (p < n) {
      int np = nxt[p];
      if (np >= n) {
        break;
      }
      int nnp = nxt[np];
      if (nnp >= n) {
        break;
      }
      q.push_back(make_pair(p, nnp));
      int nnnp = nxt[nnp];
      if (nnnp >= n) {
        break;
      }
      q.push_back(make_pair(np, nnnp));
      p = nxt[nnnp];
    }
    string s = ask(q);
    for (int i = 0; i < sz(q); i++) {
      eqb[q[i].second] = s[i] - '0';
    }
  }
  for (int t = 0; t < 3; t++) {
    ans[t].clear();
  }
  int p = 0, cur = 0, prv = -1;
  while (p < n) {
    int np = nxt[p];
    for (int i = p; i < np; i++) {
      ans[cur].push_back(i);
    }
    if (np >= n) {
      break;
    }
    int nxt = (prv == -1 ? 1 : (eqb[np] ? prv : getMex(cur, prv)));
    p = np;
    prv = cur;
    cur = nxt;
  }
  printf("A %d %d %d\n", sz(ans[0]), sz(ans[1]), sz(ans[2]));
  for (int t = 0; t < 3; t++) {
    for (int i = 0; i < sz(ans[t]); i++) {
      printf("%d ", ans[t][i] + 1);
    }
    printf("\n");
  }
  fflush(stdout);
}

int main() {
  precalc();
  int t;
  scanf("%d", &t);
  for (int tt = 0; tt < t; tt++) {
    if (!read()) {
      break;
    }
    solve();
#ifdef DEBUG
    eprintf("Time %.2f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}