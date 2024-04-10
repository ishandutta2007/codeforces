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
int n;
int c[maxn];
vector<int> g[maxn];

int read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
  	g[i].clear();
  }
  for (int i = 0; i < n - 1; i++) {
  	int v, u;
  	scanf("%d%d", &v, &u);
  	v--;
  	u--;
  	g[v].push_back(u);
  	g[u].push_back(v);
  }
  for (int i = 0; i < n; i++) {
  	scanf("%d", &c[i]);
  }
  return true;
}

int tc[maxn];

void gettc(int v, int p) {
	tc[v] = c[v];
	for (int i = 0; i < sz(g[v]); i++) {
		int u = g[v][i];
		if (u == p) {
			continue;
		}
		gettc(u, v);
		if (tc[u] != c[v]) {
			tc[v] = -1;
		}
	}
}

int dfs(int v, int p) {
	bool ok = true;
	int cnt = 0;
	int w = -1;
	for (int i = 0; i < sz(g[v]); i++) {
		int u = g[v][i];
		if (u == p) {
			continue;
		}
		if (tc[u] == -1) {
			ok = false;
			cnt++;
			w = u;
		}
	}
	if (ok) {
		return v;
	}
	if (cnt > 1) {
		return -1;
	}
	if (p != -1 && c[p] != c[v]) {
		return -1;
	}
	for (int i = 0; i < sz(g[v]); i++) {
		int u = g[v][i];
		if (u == p || u == w) {
			continue;
		}
		if (tc[u] != c[v]) {
			return -1;
		}
	}
	return dfs(w, v);
}

void solve() {
	gettc(0, -1);
	int res = dfs(0, -1);
	if (res == -1) {
		printf("NO\n");
		return;
	}
	printf("YES\n");
	printf("%d\n", res + 1);
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