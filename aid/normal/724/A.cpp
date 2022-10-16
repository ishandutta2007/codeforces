#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long ll;

#ifdef DEBUG
#define eprintf(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#else
#define eprintf(...) ;
#endif

#define pb push_back
#define mp make_pair
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

int a, b;
char tmp[100];

int get(const string &s) {
  if (s[0] == 'm') {
    return 0;
  } else if (s[0] == 't' && s[1] == 'u') {
    return 1;
  } else if (s[0] == 'w') {
    return 2;
  } else if (s[0] == 't' && s[1] == 'h') {
    return 3;
  } else if (s[0] == 'f') {
    return 4;
  } else if (s[2] == 't') {
    return 5;
  } else {
    return 6;
  }
}

int read() {
  if (scanf("%s", tmp) < 1) {
    return false;
  }
  string sa = tmp;
  scanf("%s", tmp);
  string sb = tmp;
  a = get(sa);
  b = get(sb);
  return true;
}

int d[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

void solve() {
  for (int i = 0; i < 11; i++) {
    if ((a + d[i]) % 7 == b) {
      printf("YES\n");
      return;
    }
  }
  printf("NO\n");
}

int main() {
  precalc();
#ifdef LOCAL
  assert(freopen(TASK ".in", "r", stdin));
  assert(freopen(TASK ".out", "w", stdout));
#endif
  while (true) {
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