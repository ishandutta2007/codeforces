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

const int maxn = (int) 1e5 + 5;
int n, m;
vector< pair<int, pair<long long, long long> > > allp[maxn];

int read() {
  if (scanf("%d%d", &n, &m) < 2) {
    return false;
  }
  for (int i = 0; i < m; i++) {
    allp[i].clear();
  }
  for (int i = 0; i < n; i++) {
    int k;
    scanf("%d", &k);
    for (int j = 0; j < k; j++) {
      int x;
      scanf("%d", &x);
      x--;
      allp[x].push_back(make_pair(i, make_pair(k, j)));
    }
  }
  return true;
}

long long gcd(long long a, long long b) {
  return b ? gcd(b, a % b) : a;
}

long long lcm(long long a, long long b) {
  return a * (b / gcd(a, b));
}

pair<long long, long long> extgcd(long long a, long long b) {
  if (!b) {
    return make_pair(1ll, 0ll);
  }
  pair<long long, long long> p = extgcd(b, a % b);
  return make_pair(p.second, p.first - (a / b) * p.second);
}

long long mul(long long a, long long b, long long mod) {
  if (abs((ld) a * b) < 1e18) {
    return a * b % mod;
  }
  long long d = (long long) ((ld) a * b / mod);
  long long res = a * b - d * mod;
  return res % mod;
}

bool intersect(long long &a, long long &b, long long c, long long d) {
  long long g = gcd(a, c);
  if (abs(d - b) % g) {
    return false;
  }
  long long na = lcm(a, c);
  b = mul(mul(a, ((d - b) / g), na), extgcd(a, c).first, na) + b;
  a = na;
  b = (b % a + a) % a;
  return true;
}

const int maxk = 45;
int cnt[maxk];

int solve(const vector< pair<int, pair<long long, long long> > > &p) {
  for (int i = 0; i < maxk; i++) {
    cnt[i] = 0;
  }
  int res = 0;
  long long a = 1, b = 0;
  for (int i = 0, j = 0; i < sz(p); i++) {
    while (j < sz(p) && (j == i || p[j].first == p[j - 1].first + 1)) {
      long long c = p[j].second.first, d = p[j].second.second;
      if (!intersect(a, b, c, d)) {
        break;
      }
      cnt[c]++;
      j++;
    }
    res = max(res, j - i);
    cnt[p[i].second.first]--;
    if (!cnt[p[i].second.first]) {
      a = 1;
      for (int k = 1; k < maxk; k++) {
        if (cnt[k]) {
          a = lcm(a, k);
        }
      }
      b %= a;
    }
  }
  return res;
}

void solve() {
  for (int i = 0; i < m; i++) {
    printf("%d\n", solve(allp[i]));
  }
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