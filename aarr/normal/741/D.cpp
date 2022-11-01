#include <iostream>
#include <vector>
using namespace std;


const int N = 500 * 1000 + 5, C = 22;
int tm = 1;


vector <int> chld[N];
int sz[N];
int cnt[N];
int h[N];
int st[N];
int ft[N];
int rl[N];
int chng[N];
int par[N];
int ans[N];
//int pl[N];
char c[N];
vector <pair <int, int> > vec;
int mx[(1 << C) + 7];


void pdfs(int v) {
	sz[v] = 1;
	for (auto u : chld[v]) {
		par[u] = v;
		h[u] = h[v] + 1;
		pdfs(u);
		sz[v] += sz[u];
	}
}

void kfs(int v, int xr) {
//	cout << "49 " << v << endl;
	for (auto u : chld[v]) {
		kfs(u, xr ^ (1 << (c[u] - 'a')));
	}
	vec.push_back({xr, h[v]});
}
void dfs(int v) {
	int bg = 0;
	for (auto u : chld[v]) {
		if (sz[u] > sz[bg]) {
			bg = u;
		}
	}
	for (auto u : chld[v]) {
		if (u != bg) {
			dfs(u);
			ans[v] = max(ans[v], ans[u]);
			vec.clear();
			kfs(u, 0);
			for (auto p : vec) {
				mx[p.first ^ chng[u]] = -N;
			}
		}
	}
	if (bg) {
		dfs(bg);
		ans[v] = max(ans[v], ans[bg]);
		chng[v] = chng[bg] ^ (1 << (c[bg] - 'a'));
		ans[v] = max(ans[v], mx[chng[v]] - h[v]);
		for (int i = 0; i < C; i++) {
			ans[v] = max(ans[v], mx[chng[v] ^ (1 << i)] - h[v]);
		}
		//pl[v] = pl[bg] + 1;
	//	cout << v << " " << mx[0] << " " << mx[1] << " " << mx[262144] << " " << mx[262145] << endl;
	}
	mx[chng[v]] = max(mx[chng[v]], h[v]);
	for (auto u : chld[v]) {
		if (u != bg) {
			vec.clear();
			kfs(u, 1 << (c[u] - 'a'));
			for (auto p : vec) {
				int mask = p.first;
				ans[v] = max(ans[v], mx[mask ^ chng[v]] + p.second - 2 * h[v]);
				for (int i = 0; i < C; i++) {
					ans[v] = max(ans[v], mx[mask ^ chng[v] ^ (1 << i)] + p.second - 2 * h[v]);
				}
			}
			for (auto p : vec) {
				mx[p.first ^ chng[v]] = max(mx[p.first ^ chng[v]], p.second);
			}
		}
	}
}
int main() {
	ios :: sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 2; i <= n; i++) {
		int u;
		cin >> u >> c[i];
		chld[u].push_back(i);
	}
	pdfs(1);
	fill(mx, mx + (1 << C), -N);
	dfs(1);
/*	for (int i = 1; i <= n; i++) {
		cout << "31 " << i << " " << h[i] << " " << chng[i] << endl;
	}*/
	for (int i = 1; i <= n; i++) {
		cout << ans[i] << " ";
	}
	return 0;
}