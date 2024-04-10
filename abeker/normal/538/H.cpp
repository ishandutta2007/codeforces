#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

typedef pair <int, int> pii;
#define lo first
#define hi second

const int MAXN = 200005;
const int INF = 0x3f3f3f3f;
const pii ALL = {0, INF};

int t, T;
int N, M;
pii p[MAXN];
vector <int> E[MAXN];
int color[MAXN];
pii range[2];
int mat[MAXN][2];
vector <pii> sweep;
multiset <int> L, R;
vector <int> comp;
int n[2];

void load() {
	scanf("%d%d", &t, &T); 
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= N; i++) {
		scanf("%d%d", &p[i].lo, &p[i].hi);
		p[i].hi++;
	}
	while (M--) {
		int a, b;
		scanf("%d%d", &a, &b);
		E[a].push_back(b);
		E[b].push_back(a);
	}
	T++;
}

void bye() {
	puts("IMPOSSIBLE");
	exit(0);
}

pii intersect(pii P, pii Q) {
	return {max(P.lo, Q.lo), min(P.hi, Q.hi)};
}

void reduce(pii &P, pii Q) {
	P = intersect(P, Q);
}

bool contain(pii P, pii Q) {
	return intersect(P, Q) == Q;
}

bool empty(pii P) {
	return P.lo >= P.hi;
}

bool cmp(const pii &lhs, const pii &rhs) {
	if (mat[lhs.lo][lhs.hi] != mat[rhs.lo][rhs.hi])
		return mat[lhs.lo][lhs.hi] < mat[rhs.lo][rhs.hi];
	if (lhs.hi != rhs.hi)
		return lhs.hi < rhs.hi; 
	return lhs.lo < rhs.lo;
}

bool dfs(int x, int c) {
	if (color[x] != -1)
		return color[x] == c;
	color[x] = c;
	reduce(range[c], p[x]);
	for (auto it : E[x])
		if (!dfs(it, c ^ 1))
			return false;
	return true;
}

bool check(int x, int c) {
	if (color[x] != -1)
		return true;
	if (p[x].lo > n[c] || p[x].hi <= n[c])
		return false;
	color[x] = c;
	comp.push_back(x);
	for (auto it : E[x])
		if (!check(it, c ^ 1))
			return false;
	return true;
}

void output(pii P) {
	printf("[%d, %d>\n", P.lo, P.hi);
}

void finish(pii P, pii Q) {
	if (empty(P) || empty(Q))
		return;
	pii sol = intersect({t, T}, {P.lo + Q.lo, P.hi + Q.hi - 1});
	if (empty(sol))
		return;
	
	pii tmp = intersect(P, {sol.lo - Q.hi + 1, sol.lo - Q.lo + 1});
	assert(!empty(tmp));
	n[0] = tmp.lo;
	n[1] = sol.lo - n[0];
	
	memset(color, -1, sizeof color);
	for (int i = 1; i <= N; i++)
		if (color[i] == -1) {
			comp.clear();
			for (int j = 0; j < 2; j++) {
				for (auto it : comp)
					color[it] = -1;
				if (check(i, j))
					break;
			}	
		}
	
	puts("POSSIBLE");
	printf("%d %d\n", n[0], n[1]);
	for (int i = 1; i <= N; i++)
		printf("%d", ++color[i]);
	puts("");
	exit(0);
}

pii get() {
	return {*L.rbegin(), *R.begin()}; 
}

void solve() {
	memset(color, -1, sizeof color);
	pii one = ALL, two = ALL;
	int sz = 0; 
	for (int i = 1; i <= N; i++)
		if (color[i] == -1) {
			range[0] = range[1] = ALL;
			if (!dfs(i, 0))
				bye();
			if (empty(range[0]) || empty(range[1]))
				bye();
			if (range[0].lo > range[1].lo)
				swap(range[0], range[1]);
			reduce(one, range[0]);
			if (range[0].hi < range[1].hi)
				swap(range[0], range[1]);
			reduce(two, range[0]);
			if (contain(range[0], range[1])) {
				L.insert(range[1].lo);
				R.insert(range[1].hi);
				mat[sz][1] = range[1].lo;
				mat[sz][0] = range[1].hi;
				sweep.push_back({sz, 1});
				sweep.push_back({sz, 0});
				sz++;
			}
		}
	
	if (sweep.empty()) 
		finish(one, two);
	
	sort(sweep.begin(), sweep.end(), cmp);
	int last = -1;
	L.insert(0);
	R.insert(INF);
	for (auto it : sweep) {
		int curr = mat[it.lo][it.hi];
		if (last != -1 && !L.empty()) {
			pii p1 = intersect({last, curr}, one);
			pii p2 = intersect(get(), two);
			finish(p1, p2);
		}
		if (it.hi == 1) {
			L.erase(L.find(mat[it.lo][1]));
			R.erase(R.find(mat[it.lo][0]));
		}
		else {
			L.insert(mat[it.lo][1]);
			R.insert(mat[it.lo][0]);
		}
		last = curr;
	}
	
	bye();
}

int main() {
	load();
	solve();
	return 0;
}