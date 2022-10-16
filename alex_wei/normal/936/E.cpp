#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
char buf[1 << 22], *p1 = buf, *p2 = buf, obuf[1 << 22], *O = obuf;
#define gc (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 22, stdin), p1 == p2) ? EOF : *p1++)
#define pc(x) (*O++ = x)
#define flush() fwrite(obuf, 1, O - obuf, stdout)
inline int read() {
	int x = 0;
	char s = gc;
	while(!isdigit(s)) s = gc;
	while(isdigit(s)) x = x * 10 + s - '0', s = gc;
	return x;
}
inline void print(int x) {
	if(x < 0) return pc('-'), print(-x);
	if(x >= 10) print(x / 10);
	pc(x % 10 + '0');
}

const int N = 3e5 + 5;
const int inf = 1e9 + 7;
const int dx[4] = {0, -1, 1, 0};
const int dy[4] = {-1, 0, 0, 1};

// general variables
int l[N], r[N], bel[N];
pair <int, int> p[N];
vector <int> e[N], g[N];
map <pair <int, int>, int> mp;
int pn, n, q;

// centroid decomposition tree
int vis[N], mx[N], sz[N], R;
void findroot(int id, int fa, int tot) {
	sz[id] = 1, mx[id] = 0;
	for(int it : e[id]) {
		if(it == fa || vis[it]) continue;
		findroot(it, id, tot), sz[id] += sz[it];
		mx[id] = max(mx[id], sz[it]);
	}
	mx[id] = max(mx[id], tot - sz[id]);
	if(mx[id] < mx[R]) R = id;
}

int dep[N], f[N], cover[N], cnt;
int ind[30][N], bfs_vis[N];
vector <int> pre[N], suf[N];
vector <pair <int, int>> dat[N]; // dat : {from which position, distance}
queue <pair <int, pair <int, int>>> que;
void findpoint(int id, int fa) {
	for(int j = l[id]; j <= r[id]; j++) cover[++cnt] = j;
	for(int it : e[id]) if(it != fa && !vis[it]) findpoint(it, id);
}
void divide(int id, int fa) {
	dep[id] = dep[fa] + 1;
    assert(dep[id] <= 20);
	f[id] = fa, vis[id] = 1;
	cnt = 0, findpoint(id, 0);
	dat[id].resize(cnt + 1);
	pre[id].resize(cnt + 1, inf);
	suf[id].resize(cnt + 1, inf);
	for(int i = 1; i <= cnt; i++) ind[dep[id]][cover[i]] = i, bfs_vis[cover[i]] = 0; // i -> cover[i]
	for(int j = l[id]; j <= r[id]; j++) que.push({j, {j - l[id] + 1, 0}}), bfs_vis[j] = 1;
	while(!que.empty()) {
		auto t = que.front(); que.pop();
		pair <int, int> dt = t.second;
		int pid = t.first;
		dat[id][ind[dep[id]][pid]] = dt, dt.second++;
		// cerr << "inside " << id << " " << pid << " " << ind[dep[id]][pid] << " " << dt.first << " " << dt.second << endl;
		for(int it : g[pid]) if(!bfs_vis[it]) que.push({it, dt}), bfs_vis[it] = 1;
	}
	// cerr << ind[1][5] << " " << dat[3][1].first << endl;
	for(int it : e[id]) {
		if(vis[it]) continue;
		R = 0, findroot(it, id, sz[it]), divide(R, id);
	}
}

// BIT
void add_pre(vector <int> &c, int p, int v) {while(p < c.size()) c[p] = min(c[p], v), p += p & -p;}
int query_pre(vector <int> &c, int p) {
	int ans = inf;
	while(p) ans = min(ans, c[p]), p -= p & -p;
	return ans;
}
void add_suf(vector <int> &c, int p, int v) {while(p) c[p] = min(c[p], v), p -= p & -p;}
int query_suf(vector <int> &c, int p) {
	int ans = inf;
	while(p < c.size()) ans = min(ans, c[p]), p += p & -p;
	return ans;
}
void add_point(int x, int y) {
	// cerr << ind[1][5] << " " << dat[3][1].first << " " << dat[3][1].second << endl;
	int pid = mp[{x, y}], id = bel[pid];
	while(id) {
		pair <int, int> dt = dat[id][ind[dep[id]][pid]];
		// cerr << "dep " << dep[id] << " " << id << " " << pid << " " << ind[dep[id]][pid] << " " << dt.first << " " << dt.second << endl;
		// assert(dt.first);
		add_pre(pre[id], dt.first, dt.second - dt.first);
		add_suf(suf[id], dt.first, dt.second + dt.first);
		id = f[id];
	}
}
int query_point(int x, int y) {
	int ans = inf, pid = mp[{x, y}], id = bel[pid];
	while(id) {
		pair <int, int> dt = dat[id][ind[dep[id]][pid]];
		// cerr << "dep " << dep[id] << " " << id << " " << pid << " " << ind[dep[id]][pid] << " " << dt.first << " " << dt.second << endl;
		// assert(dt.first);
		ans = min(ans, query_pre(pre[id], dt.first) + dt.second + dt.first);
		ans = min(ans, query_suf(suf[id], dt.first) + dt.second - dt.first);
		id = f[id];
	}
	return ans > N ? -1 : ans;
}

int main() {
	// freopen("1.in", "r", stdin);
	memset(bfs_vis, 0x3f, sizeof(bfs_vis));
	cin >> pn, mx[0] = N;
	for(int i = 1, x, y; i <= pn; i++) p[i] = {x = read(), y = read()};
	sort(p + 1, p + pn + 1);
	for(int i = 1; i <= pn; ) {
		l[++n] = i, r[n] = i;
		while(r[n] < pn && p[r[n] + 1].second == p[r[n]].second + 1) r[n]++;
		// cerr << i << " " << r[n] << endl;
		for(int j = i; j < r[n]; j++) g[j].push_back(j + 1), g[j + 1].push_back(j);
		for(int j = i, lst = 0; j <= r[n]; j++) {
			mp[p[j]] = j, bel[j] = n;
			auto it = mp.find({p[j].first - 1, p[j].second});
			if(it == mp.end()) continue;
			g[j].push_back(it -> second), g[it -> second].push_back(j);
			if(bel[it -> second] == lst) continue;
			e[n].push_back(lst = bel[it -> second]), e[lst].push_back(n);
			// cerr << "add " << n << " " << lst << endl;
		}
		i = r[n] + 1;
	}
	findroot(1, 0, n), divide(R, 0);
	// if(pn >= 1e5) assert(0);
	// if(pn > 1e5) exit(0);
	q = read();
	for(int i = 1, op, x, y; i <= q; i++) {
		op = read(), x = read(), y = read();
		if(op == 1) add_point(x, y);
		else print(query_point(x, y)), pc('\n');
	}
	return flush(), 0;
}

/*
2022/5/2
start thinking at 17:43

.
 city  city , .
.

.
abs(x - x_i) + abs(y - y_i)
 x_i, y_i  x , .
?
.
.
.
, .
.
, .

.

, .
? ?
, .
, .
. .

start coding at 18:51

.
, T .
.
19:37 .
????
, .
CF .

, ,  MLE .
.
, TLE .
, ,  1.
? ?
,  gp_hash_table .

, .

finish debugging at 21:01
*/