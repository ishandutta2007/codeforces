#include <bits/stdc++.h>
using namespace std;
const int K = 374;
const int N = 1e5 + 5;
const int mod = 1e9 + 7;
void add(int &x, int y) {x += y, x >= mod && (x -= mod);}
struct lb {
	int w[5];
	lb() {memset(w, 0, sizeof(w));}
	bool chk(int v) {
		for(int i = 4; ~i; i--)
			if(v >> i & 1) {
				if(w[i]) v ^= w[i];
				else return 1; // won't form 0
			}
		return 0;
	}
	void insert(int v) {
		for(int i = 4; ~i; i--)
			if(v >> i & 1) {
				if(w[i]) v ^= w[i];
				else {
					for(int j = i - 1; ~j; j--) if(v >> j & 1) v ^= w[j];
					for(int j = 4; j > i; j--) if(w[j] >> i & 1) w[j] ^= v;
					return w[i] = v, void();
				}
			}
	}
	friend bool operator == (const lb &x, const lb &y) {
		for(int i = 0; i < 5; i++) if(x.w[i] ^ y.w[i]) return 0;
		return 1;
	}
	int get() {
		int hsh = 0;
		for(int i = 0; i < 5; i++) hsh = (hsh << 5) | w[i];
		return hsh;
	}
} LB[K], cur;
int n, m, tot, hsh[1 << 25];
int f[K], g[K], E, ban;
int val[N], comb[N];
int mer[K][K], vis[N];
vector <pair <int, int>> e[N];
void dfs(int id, int fa) { // !!!!
	vis[id] = 1;
	for(auto it : e[id]) {
		int to = it.first, v = it.second ^ val[id] ^ val[to];
		// cerr << id << " " << to << " " << v << endl;
		if(to == fa) continue;
		if(!vis[to]) val[to] = v, dfs(to, id);
		else if(to == comb[id]) E = v;
		else if(id > to) ban |= !cur.chk(v), cur.insert(v);
		// !!!!!  id > to!!!!
	}
}
int main() {
	// freopen("1.in", "r", stdin);
	cin >> n >> m, f[0] = 1;
	for(int i = 1, u, v, w; i <= m; i++) {
		cin >> u >> v >> w;
		e[u].push_back(make_pair(v, w));
		e[v].push_back(make_pair(u, w));
	}
	for(int i = 0; i < 2; i++)
		for(int j = 0; j < 4; j++)
			for(int k = 0; k < 8; k++)
				for(int l = 0; l < 16; l++)
					for(int m = 0; m < 32; m++) {
						lb cur;
						cur.insert(i), cur.insert(j), cur.insert(k), cur.insert(l), cur.insert(m);
						bool same = 0;
						for(int p = 0; p < tot && !same; p++) same |= cur == LB[p];
						if(!same) LB[tot++] = cur;
					}
	for(int i = 0; i < tot; i++) hsh[LB[i].get()] = i;
	for(int i = 0; i < tot; i++)
		for(int j = 0; j < tot; j++) {
			mer[i][j] = 0, cur = LB[i];
			for(int k = 0; k < 5; k++)
				if(LB[j].w[k]) {
					if(!cur.chk(LB[j].w[k])) mer[i][j] = -1; // LB[i] -> cur
					cur.insert(LB[j].w[k]);
				}
			if(!mer[i][j]) mer[i][j] = hsh[cur.get()];
		}
	for(auto it : e[1]) vis[it.first] = 1, val[it.first] = it.second;
	for(auto id : e[1]) for(auto it : e[id.first]) if(vis[it.first]) comb[id.first] = it.first;
	vis[1] = 1; //  vis[1] = 1  comb 
	for(auto it : e[1]) {
		int id = it.first;
		if(comb[id] && id > comb[id]) continue;
		memset(cur.w, ban = 0, sizeof(cur.w));
		dfs(id, 1);
		if(comb[id]) dfs(comb[id], 1); // add this line
		if(ban) continue; // remember to ban
		static int g[374];
		int idcur = hsh[cur.get()];
		memcpy(g, f, sizeof(f));
		// cerr << id << " " << idcur << endl;
		if(!comb[id]) {
			for(int i = 0; i < 374; i++) {
				if(!f[i]) continue;
				int res = mer[i][idcur];
				if(res != -1) add(g[res], f[i]);
			}
		}
		else {
			int ban2 = !cur.chk(E);
			cur.insert(E);
			int idcur2 = hsh[cur.get()];
			// cerr << "chk " << idcur2 << " " << E << endl;
			for(int i = 0; i < 374; i++) {
				if(!f[i]) continue;
				// cerr << i << " " << f[i] << endl;
				int res = mer[i][idcur];
				// cerr << "res " << res << endl;
				if(res != -1) add(g[res], f[i]), add(g[res], f[i]);
				if(ban2) continue; // remember to ban
				res = mer[i][idcur2];
				// cerr << "res " << res << endl;
				if(res != -1) add(g[res], f[i]);
			}
		}
		swap(f, g);
	}
	int ans = 0;
	for(int i = 0; i < tot; i++) add(ans, f[i]);
	cout << ans << endl;
	return 0;
}

/*
2022/4/28
start thinking at 15:00

 > 3  1 .
 1 ,  1 .
 374 ,  DP .

.

start coding at 16:00
finish debugging at 17:56
*/