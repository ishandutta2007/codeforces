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

int n;

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  return true;
}

char tmp[10];

bool ask(int x, int y, bool b) {
  if (x >= n || y >= n || x < 0 || y < 0) {
    return false;
  }
  if (!b) {
    printf("? %d %d %d %d\n", x + 1, y + 1, n, n);
  } else {
    printf("? %d %d %d %d\n", 1, 1, x + 1, y + 1);
  }
  fflush(stdout);
  scanf("%s", tmp);
  if (tmp[0] == 'B') {
    exit(0);
  }
  return tmp[0] == 'Y';
}

void solve() {
  int x = 0, y = 0;
  string ans;
  while (x + y < n - 1) {
    if (ask(x, y + 1, 0)) {
      ans += "R";
      y++;
    } else {
      ans += "D";
      x++;
    }
  }
  string rans;
  x = n - 1;
  y = n - 1;
  while (x + y > n - 1) {
    if (ask(x - 1, y, 1)) {
      rans += "D";
      x--;
    } else {
      rans += "R";
      y--;
    }
  }
  reverse(rans.begin(), rans.end());
  ans += rans;
  printf("! %s\n", ans.c_str());
  fflush(stdout);
}

int main() {
	read();
  solve();
  eprintf("Time %.2f\n", (double) clock() / CLOCKS_PER_SEC);
	return 0;
}