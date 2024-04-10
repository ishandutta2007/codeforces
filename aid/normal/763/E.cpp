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

const int maxn = (int) 1e5 + 5, maxk = 6;
int n, k, m;
int g[maxn][maxk];

int read() {
  if (scanf("%d%d%d", &n, &k, &m) < 3) {
    return false;
  }
  for (int i = 0; i < n; i++) {
  	for (int j = 0; j <= k; j++) {
  		g[i][j] = false;
  	}
  }
  for (int i = 0; i < m; i++) {
  	int v, u;
  	scanf("%d%d", &v, &u);
  	v--;
  	u--;
  	if (v > u) {
  		swap(v, u);
  	}
  	g[v][u - v] = true;
  }
  return true;
}

struct T {
	vector<int> l, r;
	int tl, tr;
	int cnt, c;
	
	T() {}
	
	T(int pos) {
		l = vector<int>(1, 0);
		r = vector<int>(1, 0);
		tl = pos;
		tr = pos + 1;
		cnt = 0;
		c = 1;
	}
};

void getC(T &t) {
	int maxc = 0;
	for (int i = 0; i < sz(t.l); i++) {
		maxc = max(maxc, t.l[i]);
	}
	for (int i = 0; i < sz(t.r); i++) {
		maxc = max(maxc, t.r[i]);
	}
	maxc++;
	vector<int> used(maxc, 0);
	for (int i = 0; i < sz(t.l); i++) {
		used[t.l[i]] = true;
	}
	for (int i = 0; i < sz(t.r); i++) {
		used[t.r[i]] = true;
	}
	int id = 0;
	for (int i = 0; i < sz(used); i++) {
		if (!used[i]) {
			used[i] = -1;
		} else {
			used[i] = id++;
		}
	}
	for (int i = 0; i < sz(t.l); i++) {
		t.l[i] = used[t.l[i]];
	}
	for (int i = 0; i < sz(t.r); i++) {
		t.r[i] = used[t.r[i]];
	}
	t.c = id;
}

T tmerge(T l, T r) {
	assert(l.tr == r.tl);
	for (int i = 0; i < sz(r.l); i++) {
		r.l[i] += l.c;
	}
	for (int i = 0; i < sz(r.r); i++) {
		r.r[i] += l.c;
	}
	for (int i = 0; i < sz(l.r); i++) {
		int v = l.tr - i - 1;
		int ci = l.r[i];
		for (int j = 1; j <= k; j++) {
			if (!g[v][j]) {
				continue;
			}
			int u = v + j;
			int ii = u - r.tl;
			if (ii < 0) {
				continue;
			}
			if (ii >= sz(r.l)) {
				break;
			}
			int cii = r.l[ii];
			if (ci == cii) {
				continue;
			}
			for (int jj = 0; jj < sz(l.l); jj++) {
				if (l.l[jj] == cii) {
					l.l[jj] = ci;
				}
			}
			for (int jj = 0; jj < sz(l.r); jj++) {
				if (l.r[jj] == cii) {
					l.r[jj] = ci;
				}
			}
			for (int jj = 0; jj < sz(r.l); jj++) {
				if (r.l[jj] == cii) {
					r.l[jj] = ci;
				}
			}
			for (int jj = 0; jj < sz(r.r); jj++) {
				if (r.r[jj] == cii) {
					r.r[jj] = ci;
				}
			}
		}
	}
	vector<int> used(l.c + r.c, 0);
	for (int i = 0; i < sz(l.l); i++) {
		used[l.l[i]] = true;
	}
	for (int i = 0; i < sz(l.r); i++) {
		used[l.r[i]] = true;
	}
	for (int i = 0; i < sz(r.l); i++) {
		used[r.l[i]] = true;
	}
	for (int i = 0; i < sz(r.r); i++) {
		used[r.r[i]] = true;
	}
	int cnt = 0;
	for (int i = 0; i < sz(used); i++) {
		cnt += used[i];
	}
	T res;
	res.l = l.l;
	for (int i = 0; i < sz(r.l) && sz(res.l) < k; i++) {
		res.l.push_back(r.l[i]);
	}
	res.r = r.r;
	for (int i = 0; i < sz(l.r) && sz(res.r) < k; i++) {
		res.r.push_back(l.r[i]);
	}
	res.tl = l.tl;
	res.tr = r.tr;
	res.cnt = l.cnt + r.cnt;
	getC(res);
	res.cnt += cnt - res.c;
	return res;
}

T st[4 * maxn];

void buildst(int v, int tl, int tr) {
	if (tl == tr - 1) {
		st[v] = T(tl);
		return;
	}
	int tm = (tl + tr) / 2;
	buildst(2 * v, tl, tm);
	buildst(2 * v + 1, tm, tr);
	st[v] = tmerge(st[2 * v], st[2 * v + 1]);
}

T get(int v, int tl, int tr, int l, int r) {
	if (l == tl && r == tr) {
		return st[v];
	}
	int tm = (tl + tr) / 2;
	if (r <= tm) {
		return get(2 * v, tl, tm, l, r);
	}
	if (l >= tm) {
		return get(2 * v + 1, tm, tr, l, r);	
	}
	return tmerge(get(2 * v, tl, tm, l, tm), get(2 * v + 1, tm, tr, tm, r));
}

void solve() {
	buildst(1, 0, n);
	int q;
	scanf("%d", &q);
	for (int i = 0; i < q; i++) {
		int l, r;
		scanf("%d%d", &l, &r);
		l--;
		r = min(r, n);
		if (l >= r) {
			printf("0\n");
			continue;
		}
		T t = get(1, 0, n, l, r);
		printf("%d\n", t.cnt + t.c);
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