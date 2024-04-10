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

void precalc() {
}

int gcd(int a, int b) {
  return (b ? gcd(b, a % b) : a);
}

const int maxn = (int) 2e5 + 5;
int n;
pair<int, int> ps[maxn];

int read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf(" ");
    int a, b, c;
    scanf("%*c%d%*c%d%*c%*c%d", &a, &b, &c);
    a += b;
    int g = gcd(a, c);
    a /= g;
    c /= g;
    ps[i] = make_pair(a, c);
  }
  return true;
}

int ans[maxn];
pair<pair<int, int>, int> tosort[maxn];

void solve() {
  for (int i = 0; i < n; i++) {
    tosort[i] = make_pair(ps[i], i);
  }
  sort(tosort, tosort + n);
  for (int j = 0; j < n;) {
    int i = j;
    while (j < n && tosort[j].first == tosort[i].first) {
      j++;
    }
    for (int k = i; k < j; k++) {
      ans[tosort[k].second] = j - i;
    }
  }
  for (int i = 0; i < n; i++) {
    printf("%d ", ans[i]);
  }
  printf("\n");
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