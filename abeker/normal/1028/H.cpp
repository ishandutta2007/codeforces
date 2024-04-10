#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> pii;

const int MAXN = 2e5 + 5;
const int MAXV = 6e6 + 5;
const int offset = 1 << 18;
const int INF = 0x3f3f3f3f;
const int MAXP = 8;

struct tournament {
	pii t[2 * offset];
	
	tournament() {
		for (int i = 0; i < 2 * offset; i++)
			t[i] = {-1, INF};
	}
	
	pii merge(pii l, pii r) {
		return {max(l.first, r.first), min(l.second, r.second)};
	}
	
	void update(int x, int v1, int v2) {
		x += offset;
		t[x] = {v1, v2};
		for (x /= 2; x; x /= 2)
			t[x] = merge(t[2 * x], t[2 * x + 1]);
	}
	
	pii query(int x, int lo, int hi, int from, int to) {
		if (lo >= to || hi <= from)
			return {-1, INF};
		if (lo >= from && hi <= to)
			return t[x];
		int mid = (lo + hi) / 2;
		return merge(query(2 * x, lo, mid, from, to), query(2 * x + 1, mid, hi, from, to));
	}
};

int N, Q;
int a[MAXN];
int p[MAXV];
int sz[MAXN];
vector <int> f[MAXN];
vector <pii> v[MAXN];
int lst[MAXV][MAXP];
int lft[MAXN][2 * MAXP], rig[MAXN][2 * MAXP];
tournament T[2 * MAXP];

void load() {
	scanf("%d%d", &N, &Q);
	for (int i = 1; i <= N; i++)
		scanf("%d", a + i);
}

inline void mx(int &x, int y) {
	if (x < y)
		x = y;
}

inline void mn(int &x, int y) {
	if (x > y)
		x = y;
}

void solve() {
	for (int i = 2; i < MAXV; i++) 
		if (!p[i])
			for (int j = i; j < MAXV; j += i)
				if (!p[j])
					p[j] = i;
	
	for (int i = 1; i <= N; i++) {
		int x = a[i];
		while (x > 1) {
			int tmp = p[x], ex = 0;
			for (; !(x % tmp); x /= tmp)
				ex ^= 1;
			if (ex) 
				f[i].push_back(tmp);
		}
			
		sz[i] = f[i].size();
		for (int j = 0; j < 1 << sz[i]; j++) {
			int prod = 1;
			for (int k = 0; k < sz[i]; k++) 
				if (j >> k & 1)
					prod *= f[i][k];
			v[i].push_back({prod, __builtin_popcount(j)});
		}
	}
	
	for (int i = 1; i <= N; i++) 
		for (auto it : v[i]) {
			for (int j = 0; j < MAXP; j++) 
				if (sz[i] + j >= 2 * it.second)
					mx(lft[i][sz[i] + j - 2 * it.second], lst[it.first][j]);
			lst[it.first][sz[i]] = i;
		}
	
	memset(rig, INF, sizeof rig);
	memset(lst, INF, sizeof lst);
	
	for (int i = N; i; i--)
		for (auto it : v[i]) {
			for (int j = 0; j < MAXP; j++)
				if (sz[i] + j >= 2 * it.second)
					mn(rig[i][sz[i] + j - 2 * it.second], lst[it.first][j]);
			lst[it.first][sz[i]] = i;
		}
		
	for (int i = 1; i <= N; i++)
		for (int j = 0; j < 2 * MAXP; j++) {
			if (j) {
				mx(lft[i][j], lft[i][j - 1]);
				mn(rig[i][j], rig[i][j - 1]);
			}
			T[j].update(i, lft[i][j], rig[i][j]);
		}
	
	while (Q--) {
		int l, r;
		scanf("%d%d", &l, &r);
		
		int lo = 0, hi = 2 * MAXP;
		while (lo < hi) {
			int mid = (lo + hi) / 2;
			pii tmp = T[mid].query(1, 0, offset, l, r + 1);
			if (tmp.first >= l || tmp.second <= r)
				hi = mid;
			else
				lo = mid + 1;
		}
		
		printf("%d\n", lo);
	}
}

int main() {
	load();
	solve();
	return 0;
}