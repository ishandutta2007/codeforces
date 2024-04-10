#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define sz(s) ((int) ((s).size()))
#define eprintf(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)

#ifdef _WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

typedef long long ll;
typedef long double ld;

const int inf = (int) 1e9 + 100;
const ld eps = 1e-11;
const ld pi = acos(-1.0L);

mt19937 mrand(random_device{} ());
int rnd(int x) {
  return mrand() % x;
}

void precalc() {
}

const int maxx = (1 << 20);
int n;
int cnt[maxx];
char cc[100];

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  return true;
}

int get(long long a) {
  int res = 0, pos = 0;
  while(a) {
    int d = a % 10;
    if (d & 1) {
      res ^= (1 << pos);
    }
    a /= 10;
    pos++;
  }
  return res;
}

void solve() {
  for (int i = 0; i < maxx; i++) {
    cnt[i] = 0;
  }
  set< pair<long long, int> > st;
  for (int i = 0; i < n; i++) {
    long long a;
    scanf("%s%I64d", cc, &a);
    if (cc[0] == '+') {
      st.insert(make_pair(a, i));
      int x = get(a);
      cnt[x]++;
    }
    else if (cc[0] == '-') {
      st.erase(st.lower_bound(make_pair(a, -1)));
      int x = get(a);
      cnt[x]--;
    }
    else {
      int x = get(a);
      printf("%d\n", cnt[x]);
    }
  }
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