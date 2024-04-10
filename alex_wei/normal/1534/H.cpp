#include <bits/stdc++.h>
using namespace std;

#define pii pair <int, int>
#define fi first
#define se second
const int N = 1e5 + 5;

vector <int> e[N];
int n, x, f[N], ans[N];
int query(int x) {
	cout << "? " << x << endl;
	int ret; cin >> ret; return ret;
}
void dfs(int id, int fa) {
	f[id] = 1;
	for(int it : e[id]) {if(it == fa) continue; dfs(it, id);}
	sort(e[id].begin(), e[id].end(), [&](int x, int y) {return f[x] > f[y];});
	int tot = 0;
	for(int it : e[id]) {
		if(it == fa) continue;
		f[id] = max(f[id], tot + f[it]), tot++;
	} if(!fa) for(int i = 1; i < e[id].size(); i++)
		f[id] = max(f[id], i - 1 + f[e[id][0]] + f[e[id][i]]);
}


void dfs2(int id, int fa) {
	multiset <int> x;
	sort(e[id].begin(), e[id].end(), [&](int x, int y) {return f[x] > f[y];});
	int tot = 0;
	for(int it : e[id]) ans[id] = max(ans[id], tot + f[it]), tot++;
	for(int i = 1; i < e[id].size(); i++)
		ans[id] = max(ans[id], i - 1 + f[e[id][0]] + f[e[id][i]]);
	for(int i = 1; i < e[id].size(); i++) x.insert(f[e[id][i]] + i - 1);
	for(int i = 0; i < e[id].size(); i++) {
		int it = e[id][i], origin = f[id];
		if(it != fa) {
			if(x.empty()) f[id] = 1; 
			else f[id] = *--x.end();
			dfs2(it, id), f[id] = origin;
		} if(i + 1 < e[id].size()) {
			x.insert(f[e[id][i]] + i);
			x.erase(x.find(f[e[id][i + 1]] + i));
		}
	}
}

int calc(int id, int f) {
	bool isleaf = 1;
	for(int it : e[id]) {
		if(it == f) continue;
		isleaf = 0;
		int res = calc(it, id);
		if(res != id) return res;
	} if(isleaf) return query(id);
	return id;
}


int main() {
	cin >> n;
	for(int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		e[u].push_back(v), e[v].push_back(u);
	} dfs(1, 0), dfs2(1, 0);
	for(int i = 1, mx = 0; i <= n; i++) {
		mx = max(mx, ans[i]);
		if(i == n) cout << mx << endl;
	} cin >> x, dfs(x, 0);
	vector <int> ans;
	for(auto it : e[x]) {
		int res = calc(it, x);
		if(res != x) ans.push_back(res);
		if(ans.size() == 2) break;
	} while(ans.size() < 2) ans.push_back(x);
	cout << "! " << ans[0] << " " << ans[1] << endl;
}

///