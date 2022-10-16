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

const string s0 = "What are you doing at the end of the world? Are you busy? Will you save us?";
const string sl = "What are you doing while sending \"";
const string sm = "\"? Are you busy? Will you send \"";
const string sr = "\"?";

const int maxn = (int) 1e5 + 5;
long long len[maxn];

void precalc() {
  len[0] = sz(s0);
  for (int i = 1; i < maxn; i++) {
    len[i] = min(infll, 2 * len[i - 1] + sz(sl) + sz(sm) + sz(sr));
  }
}

int n;
long long pos;

int read() {
  if (scanf("%d%lld", &n, &pos) < 2) {
    return false;
  }
  pos--;
  return true;
}


void solve() {
  if (len[n] <= pos) {
    printf(".");
    return;
  }
  while (n) {
    if (pos < sz(sl)) {
      printf("%c", sl[pos]);
      return;
    }
    pos -= sz(sl);
    if (pos < len[n - 1]) {
      n--;
      continue;
    }
    pos -= len[n - 1];
    if (pos < sz(sm)) {
      printf("%c", sm[pos]);
      return;
    }
    pos -= sz(sm);
    if (pos < len[n - 1]) {
      n--;
      continue;
    }
    pos -= len[n - 1];
    assert(pos < sz(sr));
    printf("%c", sr[pos]);
    return;
  }
  assert(pos < sz(s0));
  printf("%c", s0[pos]);
}

int main() {
  precalc();
#ifdef DEBUG
  assert(freopen(TASK ".in", "r", stdin));
  assert(freopen(TASK ".out", "w", stdout));
#endif
  int t;
  scanf("%d", &t);
  while (read()) {
    solve();
#ifdef DEBUG
    eprintf("Time %.2f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  }
  printf("\n");
  return 0;
}