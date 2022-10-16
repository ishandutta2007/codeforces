#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

mt19937 mrand(random_device{} ());

int rnd(int x) {
  return mrand() % x;
}

typedef long double ld;

#ifdef DEBUG
#define eprintf(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#else
#define eprintf(...) ;
#endif

#define sz(x) ((int) (x).size())

const int inf = (int) 1.01e9;
const ld eps = 1e-9;
const ld pi = acos((ld) -1);

const int maxn = (int) 2e5 + 5;
int n;
char tmp[maxn];
string s;

bool read() {
  if (scanf("%s", tmp) < 1) {
    return false;
  }
  s = tmp;
  n = sz(s);
  return true;
}

int p[maxn];

void solve() {
  s = s + s;
  p[2 * n - 1] = 1;
  int res = 1;
  for (int i = 2 * n - 2; i >= 0; i--) {
    p[i] = (s[i] == s[i + 1] ? 1 : 1 + p[i + 1]);
    res = max(res, p[i]);
  }
  res = min(res, n);
  printf("%d\n", res);
}

int main() {
#ifdef DEBUG
	assert(freopen("text.in", "r", stdin));
	assert(freopen("text.out", "w", stdout));
#endif
	while (read()) {
		solve();
    eprintf("Time %.2f\n", (double) clock() / CLOCKS_PER_SEC);
	}
	return 0;
}