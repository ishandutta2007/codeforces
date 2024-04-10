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
#define sz(x) ((int) (x).size())
#define TASK "text"

const int inf = (int) 1.01e9;
const ld eps = 1e-9;
const ld pi = acos((ld) -1);

mt19937 mrand(random_device{} ()); 

int rnd(int x) {
  return mrand() % x;
}

const int mod[2] = {(int) 1e9 + 7, (int) 1e9 + 9};

struct Hash {
	const static int n = 2;
	int a[n];
	
	Hash(int x = 0) {
		for (int i = 0; i < n; i++) {
			a[i] = x % mod[i];
		}
	}
	
	Hash(int x[]) {
		for (int i = 0; i < n; i++) {
			a[i] = x[i] % mod[i];
		}
	}
	
	Hash operator + (const Hash &h) const {
		Hash res;
		for (int i = 0; i < n; i++) {
			res.a[i] = a[i] + h.a[i];
			if (res.a[i] > mod[i]) {
				res.a[i] -= mod[i];
			}
		}
		return res;
	}
	
	Hash operator - (const Hash &h) const {
		Hash res;
		for (int i = 0; i < n; i++) {
			res.a[i] = a[i] - h.a[i];
			if (res.a[i] < 0) {
				res.a[i] += mod[i];
			}
		}
		return res;
	}
	
	Hash operator * (const Hash &h) const {
		Hash res;
		for (int i = 0; i < n; i++) {
			res.a[i] = (long long) a[i] * h.a[i] % mod[i];
		}
		return res;
	}
	
	bool operator < (const Hash &h) const {
		for (int i = 0; i < n; i++) {
			if (a[i] != h.a[i]) {
				return a[i] < h.a[i];
			}
		}
		return false;
	}
};

const int maxn = (int) 1e5 + 5;
Hash p;
Hash ps[2 * maxn];

void precalc() {
	p = 239017 + rnd(1000);
	ps[0] = 1;
	for (int i = 1; i < 2 * maxn; i++) {
		ps[i] = ps[i - 1] * p;
	}
}

struct T {
	Hash h;
	int len;
	
	T(): h(0), len(0) {}
	
	T(const Hash &_h, int _len): h(_h), len(_len) {}
	
	T operator + (const T &t) const {
		return T(h * ps[t.len] + t.h, len + t.len);
	}
	
	bool operator < (const T &t) const {
		return len < t.len || (len == t.len && h < t.h);
	}
};

int n;
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
  return true;
}

T dp[maxn];
vector< pair<T, int> > cdp[maxn];

void getDp(int v, int p) {
	cdp[v].clear();
	for (int i = 0; i < sz(g[v]); i++) {
		int u = g[v][i];
		if (u == p) {
			continue;
		}
		getDp(u, v);
		cdp[v].push_back(make_pair(dp[u], u));
	}
	sort(cdp[v].begin(), cdp[v].end());
	dp[v] = T(Hash('('), 1);
	for (int i = 0; i < sz(cdp[v]); i++) {
		dp[v] = dp[v] + cdp[v][i].first;
	}
	dp[v] = dp[v] + T(Hash(')'), 1);
}

int res, ans;
map<T, int> mp;

void del(const T &t) {
	mp[t]--;
	if (!mp[t]) {
		mp.erase(t);
	}
}

void addp(int v, int p) {
	auto it = lower_bound(cdp[v].begin(), cdp[v].end(), make_pair(dp[p], p));
	cdp[v].insert(it, make_pair(dp[p], p));
	del(dp[v]);
	dp[v] = T(Hash('('), 1);
	for (int i = 0; i < sz(cdp[v]); i++) {
		dp[v] = dp[v] + cdp[v][i].first;
	}
	dp[v] = dp[v] + T(Hash(')'), 1);
	mp[dp[v]]++;
}

void delp(int v, int p) {
	auto it = lower_bound(cdp[v].begin(), cdp[v].end(), make_pair(dp[p], p));
	cdp[v].erase(it);
	del(dp[v]);
	dp[v] = T(Hash('('), 1);
	for (int i = 0; i < sz(cdp[v]); i++) {
		dp[v] = dp[v] + cdp[v][i].first;
	}
	dp[v] = dp[v] + T(Hash(')'), 1);
	mp[dp[v]]++;
}

void dfs(int v, int p) {
	vector<T> pref(sz(cdp[v]) + 1), suff(sz(cdp[v]) + 1);
	pref[0] = T(Hash('('), 1);
	for (int i = 0; i < sz(cdp[v]); i++) {
		pref[i + 1] = pref[i] + cdp[v][i].first;
	}
	suff[sz(cdp[v])] = T(Hash(')'), 1);
	for (int i = sz(cdp[v]) - 1; i >= 0; i--) {
		suff[i] = cdp[v][i].first + suff[i + 1];
	}
	//eprintf("%d: %d ", v, dp[v].h.a[0]);
	//eprintf("%d\n", sz(mp));
	del(dp[v]);
	for (int i = 0; i < sz(cdp[v]); i++) {
		int u = cdp[v][i].second;
		if (u == p) {
			continue;
		}
		dp[v] = pref[i] + suff[i + 1];
		mp[dp[v]]++;
		addp(u, v);
		if (sz(mp) > res) {
			res = sz(mp);
			ans = u;
		}
		dfs(u, v);
		delp(u, v);
		del(dp[v]);
	}
	dp[v] = pref[0] + suff[0];
	mp[dp[v]]++;
}

void solve() {
	getDp(0, -1);
	mp.clear();
	for (int i = 0; i < n; i++) {
		mp[dp[i]]++;
	}
	res = sz(mp);
	ans = 0;
	dfs(0, -1);
	printf("%d\n", ans + 1);
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