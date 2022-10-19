#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> pii;

const int MAXN = 1e5 + 5;
const int MOD = 1e9 + 7;

int N;
vector <int> E[MAXN];
int a[MAXN], b[MAXN], w[MAXN], c[MAXN];
int sz[MAXN], mx[MAXN];
vector <int> tmp;
int prod[MAXN];
bool bio[MAXN];
pii cnt[MAXN];
int expo[MAXN];
vector <int> todo;
vector <int> nodes[MAXN];
int f[4 * MAXN];
int sol = 1;

void load() {
	scanf("%d", &N);
	for (int i = 1; i < N; i++) {
		scanf("%d%d%d%d", a + i, b + i, w + i, c + i);
		E[a[i]].push_back(i);
		E[b[i]].push_back(i);
	}
}

inline int add(int x, int y) {
	x += y;
	if (x >= MOD)
		x -= MOD;
	return x;
}

inline int mul(int x, int y) {
	return (long long)x * y % MOD;
}

int pot(int x, int y) {
	int res = 1;
	for (; y; y /= 2) {
		if (y % 2)
			res = mul(res, x);
		x = mul(x, x);
	}
	return res;
}

pii operator +(const pii &l, const pii &r) {
	return {l.first + r.first, l.second + r.second};
}

void dfs(int x, int p) {
	tmp.push_back(x);
	mx[x] = 0;
	sz[x] = 1;
	expo[x] = 0;
	for (auto it : E[x]) {
		int nxt = a[it] + b[it] - x;
		if (!bio[nxt] && nxt != p) {
			dfs(nxt, x);
			sz[x] += sz[nxt];
			mx[x] = max(mx[x], sz[nxt]);
		}
	}
}

void go(int x, int p, int d, pii curr, int ch) {
	nodes[ch].push_back(x);
	todo.push_back(ch);
	prod[x] = d;
	cnt[x] = curr;
	for (auto it : E[x]) {
		int nxt = a[it] + b[it] - x;
		if (!bio[nxt] && nxt != p) 
			go(nxt, x, mul(d, w[it]), curr + (c[it] ? pii(-2, 1) : pii(1, -2)), ch ? ch : nxt);
	}
}

bool cmp(const int &lhs, const int &rhs) {
	return cnt[lhs] < cnt[rhs];
}

void update(int x, int val) {
	for (x += 2 * MAXN; x < 4 * MAXN; x += x & -x)
		f[x] += val;
}

int get(int x) {
	int res = 0;
	for (x += 2 * MAXN; x; x -= x & -x)
		res += f[x];
	return res;
}

void work(vector <int> &v, int coef) {
	sort(v.begin(), v.end(), cmp);
	
	int ptr = 0;
	vector <int> rem;
	for (int i = (int)v.size() - 1; i >= 0; i--) {
		for (; ptr < v.size() && cnt[v[ptr]].first + cnt[v[i]].first <= 0; ptr++) {
			update(cnt[v[ptr]].second, 1);
			rem.push_back(cnt[v[ptr]].second);
		}
		expo[v[i]] += coef * get(-cnt[v[i]].second);
	}
	
	for (auto it : rem)
		update(it, -1);
	
	v.clear();
}

void decompose(int x, int p) {
	dfs(x, p);
	
	int centroid = 0;
	for (auto it : tmp) {
		mx[it] = max(mx[it], sz[x] - sz[it]);
		if (mx[it] < mx[centroid])
			centroid = it; 
	}
	x = centroid;
	
	go(x, p, 1, {0, 0}, 0);
	
	sort(todo.begin(), todo.end());
	todo.resize(unique(todo.begin(), todo.end()) - todo.begin());
	
	vector <int> t = tmp;
	work(tmp, 1);
	for (auto it : todo) 
		work(nodes[it], -1);
	todo.clear();
	
	for (auto it : t) 
		sol = mul(sol, pot(prod[it], expo[it]));
		
	bio[x] = true;
	for (auto it : E[x]) {
		int nxt = a[it] + b[it] - x;
		if (!bio[nxt])
			decompose(nxt, x);
	}
}

int main() {
	load();
	mx[0] = MAXN;
	decompose(1, 0);
	printf("%d\n", sol);
	return 0;
}