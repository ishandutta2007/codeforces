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

const int maxn = (int) 5e5 + 5;
char tmp[maxn];
int n;
string s;

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  scanf("%s", tmp);
  s = tmp;
  return true;
}

int a[maxn];
long long val[maxn];
vector<int> st;

void solve() {
  for (int i = 0; i < n; ++i) {
    a[i] = (s[i] == '0' ? 0 : (i ? a[i - 1] : 0) + 1);
  }
  long long res = 0;
  for (int i = n - 1; i >= 0 && s[i] == '1'; --i) {
    int k = n - i;
    res += (long long) k * (k + 1) / 2;
  }
  st.clear();
  for (int i = n - 1; i >= 0; --i) {
    if (s[i] == '1') {
      if (st.empty()) {
        val[i] = (long long) (n - i) * a[i];
      } else {
        val[i] = (long long) (st.back() - i) * a[i] + val[st.back()];
      }
      st.push_back(i);
      continue;
    }
    int j = i;
    while (j >= 0 && (j == i || s[j] == '1')) {
      int k = i - j;
      while (!st.empty() && a[st.back()] < k) {
        st.pop_back();
      }
      res += (long long) k * (k + 1) / 2;
      int pos = (st.empty() ? n : st.back());
      res += (long long) (pos - i) * k;
      if (!st.empty()) {
        res += val[pos];
      }
      --j;
    }
  }
  printf("%lld\n", res);
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