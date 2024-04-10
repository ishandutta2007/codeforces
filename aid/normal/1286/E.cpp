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

const int inf = (int) 1.1e9;
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

const int P = (int) 1e9, L = 9;

struct BigInt {
  vector<int> a;

  BigInt(long long x) {
    while (x) {
      a.push_back(x % P);
      x /= P;
    }
  }

  BigInt operator + (const BigInt &b) const {
    BigInt res(0);
    res.a.resize(max(sz(a), sz(b.a)));
    int carry = 0;
    for (int i = 0; i < sz(res.a); i++) {
      if (i < sz(a)) {
        res.a[i] += a[i];
      }
      if (i < sz(b.a)) {
        res.a[i] += b.a[i];
      }
      res.a[i] += carry;
      carry = 0;
      if (res.a[i] >= P) {
        carry = 1;
        res.a[i] -= P;
      }
    }
    if (carry) {
      res.a.push_back(carry);
    }
    return res;
  }

  int operator % (int k) const {
    int res = 0;
    for (int i = sz(a) - 1; i >= 0; i--) {
      res = ((long long) res * P + a[i]) % k;
    }
    return res;
  }

  string toStr() const {
    if (a.empty()) {
      return "0";
    }
    stringstream ss;
    ss << a.back();
    for (int i = sz(a) - 2; i >= 0; i--) {
      ss << setfill('0') << setw(L) << a[i];
    }
    return ss.str();
  }
};

const int maxn = (int) 6e5 + 5;
int q;

bool read() {
  if (scanf("%d", &q) < 1) {
    return false;
  }
  return true;
}

struct node {
  int cnt, val;
  long long sum;
};

node st[4 * maxn];

void buildst(int v, int tl, int tr) {
  st[v].cnt = 0;
  st[v].val = inf;
  st[v].sum = 0;
  if (tl == tr - 1) {
    return;
  }
  int tm = (tl + tr) / 2;
  buildst(2 * v, tl, tm);
  buildst(2 * v + 1, tm, tr);
}

void push(int v) {
  if (st[v].val >= inf) {
    return;
  }
  for (int i = 0; i < 2; i++) {
    int u = 2 * v + i;
    st[u].val = st[v].val;
    st[u].sum = (long long) st[u].val * st[u].cnt;
  }
  st[v].val = inf;
}

void update(int v, int tl, int tr, int pos, int x) {
  if (tl == tr - 1) {
    st[v].cnt = x;
    st[v].sum = st[v].val * x;
    return;
  }
  push(v);
  int tm = (tl + tr) / 2;
  if (pos < tm) {
    update(2 * v, tl, tm, pos, x);
  } else {
    update(2 * v + 1, tm, tr, pos, x);
  }
  st[v].sum = st[2 * v].sum + st[2 * v + 1].sum;
  st[v].cnt = st[2 * v].cnt + st[2 * v + 1].cnt;
}

void update1(int v, int tl, int tr, int l, int r, int x) {
  if (l == tl && r == tr) {
    st[v].val = x;
    st[v].sum = (long long) st[v].val * st[v].cnt;
    return;
  }
  push(v);
  int tm = (tl + tr) / 2;
  if (l < tm) {
    update1(2 * v, tl, tm, l, min(r, tm), x);
  }
  if (r > tm) {
    update1(2 * v + 1, tm, tr, max(l, tm), r, x);
  }
  st[v].sum = st[2 * v].sum + st[2 * v + 1].sum;
  st[v].cnt = st[2 * v].cnt + st[2 * v + 1].cnt;
}

int n;
int w[maxn];
string s;
set<int> ps;

const int sigma = 26;
char tmp[10];

bool check(int i) {
  return s[n - 1] == s[n - 1 - i];
}

void solve() {
  int res0 = 0;
  BigInt res(0);
  n = 0;
  s = "";
  ps.clear();
  buildst(1, 0, q);
  vector<pair<int, int>> st;
  for (int qq = 0; qq < q; qq++) {
    int curw;
    scanf("%s%d", tmp, &curw);
    char c = tmp[0];
    long long cc = c - 'a';
    cc = (BigInt(cc) + res) % sigma;
    c = (char) ('a' + cc);
    curw = (curw ^ res0);
    w[n++] = curw;
    s += c;
    ps.insert(n - 1);
    update(1, 0, q, n - 1, 1);
    int pr = 0;
    auto it = ps.begin();
    while (true) {
      it++;
      if (it == ps.end()) {
        break;
      }
      int i = *it;
      if (!check(i)) {
        update(1, 0, q, i, 0);
        auto del = it;
        it--;
        ps.erase(del);
        continue;
      }
      int k = (n - pr + 2 * (i - pr) - 1) / (2 * (i - pr)) - 1;
      if (k <= 1) {
        pr = i;
        continue;
      }
      it = ps.lower_bound(pr + (i - pr) * k - 1);
      if (*it == i) {
        pr = i;
        continue;
      }
      it--;
      pr = *it;
    }
    while (!st.empty() && st.back().first > curw) {
      st.pop_back();
    }
    update1(1, 0, q, (st.empty() ? 0 : st.back().second + 1), n, curw);
    st.push_back(make_pair(curw, n - 1));
    long long val = ::st[1].sum;
    res = res + BigInt(val);
    res0 = ((res0 + val) & ((1ll << 30) - 1));
    printf("%s\n", res.toStr().c_str());
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