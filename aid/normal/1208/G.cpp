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

const int maxn = (int) 1e6 + 5;
int lDiv[maxn], phi[maxn];
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
  phi[1] = 1;
  for (int i = 2; i < maxn; i++) {
    int p = lDiv[i];
    int j = i / p;
    if (lDiv[j] == lDiv[i]) {
      phi[i] = phi[j] * p;
    } else {
      phi[i] = phi[j] * (p - 1);
    }
  }
}

int n, k;

bool read() {
  if (scanf("%d%d", &n, &k) < 2) {
    return false;
  }
  return true;
}

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

void solve() {
  while (!pq.empty()) {
    pq.pop();
  }
  for (int i = 3; i <= n; i++) {
    if (i == 4) {
      pq.push(make_pair(3, 4));
      continue;
    }
    if (i == 6) {
      continue;
    }
    pq.push(make_pair(phi[i], i));
  }
  long long res = 1;
  while (k) {
    int x = pq.top().second;
    res += pq.top().first;
    pq.pop();
    if (x == 4) {
      pq.push(make_pair(2, 6));
    }
    k--;
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