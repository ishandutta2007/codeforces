#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define sz(s) ((int) ((s).size()))
#define eprintf(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)

typedef long long ll;
typedef long double ld;

const int inf = (int) 1e9 + 100;
const ld eps = 1e-11;
const ld pi = acos(-1.0L);

mt19937 mrand(random_device{} ());
int rnd(int x) {
  return mrand() % x;
}

const int maxn = (int)1e6 + 5;
int n, k;
int c[maxn], a[maxn];
int lDiv[maxn];
vector<int> pr;

void precalc() {
  for (int i = 2; i < maxn; i++) {
    if (!lDiv[i]) {
      lDiv[i] = i;
      pr.push_back(i);
    }
    for (int j = 0; j < sz(pr) && pr[j] <= lDiv[i]; j++) {
      int p = pr[j] * i;
      if (p >= maxn) {
        break;
      }
      lDiv[p] = pr[j];
    }
  }
}

bool read() {
  if (scanf("%d%d", &n, &k) < 2) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &c[i]);
  }
  return true;
}

void solve() {
  for (int i = 0; i < maxn; i++) {
    a[i] = 0;
  }
  for (int i = 0; i < n; i++) {
    int x = c[i];
    while (x > 1) {
      int p = lDiv[x], q = 0;
      while(!(x % p)) {
        x /= p;
        q++;
      }
      a[p] = max(a[p], q);
    }
  }
  int x = k;
  while (x > 1) {
    int p = lDiv[x], q = 0;
    while(!(x % p)) {
      x /= p;
      q++;
    }
    if (a[p] < q) {
      printf("No\n");
      return;
    }
  }
  printf("Yes\n");
}

int main() {
  precalc();
#ifdef DEBUG
  assert(freopen("text.in", "r", stdin));
  assert(freopen("text.out", "w", stdout));
#endif

  while (true) {
    if (!read()) {
      break;
    }
    solve();
#ifdef DEBUG
    eprintf("Time: %.18f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}