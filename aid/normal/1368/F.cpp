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

const int maxn = 1005;
int n;

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  return true;
}

void fin() {
  printf("0\n");
  fflush(stdout);
}

int a[maxn];

void solve() {
  if (n <= 3) {
    fin();
    return;
  }
  for (int i = 0; i < n; i++) {
    a[i] = 0;
  }
  int k = 2;
  int need = n / 2 - 1;
  for (int i = 3; i <= n; i++) {
    int cur = n - (n + i - 1) / i - (i - 1);
    if (cur > need) {
      k = i;
      need = cur;
    }
  }
  while (true) {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      cnt += a[i];
    }
    if (cnt >= need) {
      fin();
      return;
    }
    vector<int> take;
    for (int i = 0; i < n && sz(take) < k; i++) {
      if (!(i % k)) {
        continue;
      }
      if (a[i]) {
        continue;
      }
      take.push_back(i);
    }
    printf("%d ", k);
    for (int i = 0; i < k; i++) {
      printf("%d ", take[i] + 1);
      a[take[i]] = 1;
    }
    printf("\n");
    fflush(stdout);
    int z;
    scanf("%d", &z);
    if (z == -1) {
      assert(z != -1);
      return;
    }
    z--;
    for (int i = 0; i < k; i++) {
      int p = (z + i) % n;
      a[p] = 0;
    }
  }
}

int main() {
  precalc();
  read();
  solve();
#ifdef DEBUG
  eprintf("Time %.2f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  return 0;
}