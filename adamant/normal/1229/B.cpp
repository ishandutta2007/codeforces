#include<bits/stdc++.h>
 
using namespace std;

#define int int64_t
#define all(x) begin(x),end(x)

const int maxn = 1e5 + 42, mod = 1e9 + 7;
vector<int> st;
vector<map<int, int, greater<int>>> gc;
int x[maxn];
vector<int> g[maxn];

int ans = 0;

void dfs(int v = 0, int p = 0) {
	for(auto u: g[v]) {
		if(u != p) {
			st.push_back(u);
			map<int, int, greater<int>> ngc = {{x[u], 1}};
			for(auto it: gc.back()) {
				int t = __gcd(it.first, x[u]);
				ngc[t] = max(ngc[t], it.second + 1);
			}
			gc.push_back(ngc);
			dfs(u, v);
			st.pop_back();
			gc.pop_back();
		}
	}
	int pr = gc.back()[0];
	for(auto it: gc.back()) {
		ans += (it.second - pr) * it.first;
		pr = it.second;
		ans %= mod;
	}
}

void solve() {
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> x[i];
	}
	for(int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	st.push_back(0);
	gc.push_back({{x[0], 1}});
	dfs();
	cout << ans << endl;
}

signed main() {
	//freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0); 
    cin.tie(0);
    int t;
    t = 1;//cin >> t;
    while(t--) {
		solve();
	}
}