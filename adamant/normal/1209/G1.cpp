#include<bits/stdc++.h>
 
using namespace std;

#define int int64_t
#define all(x) begin(x),end(x)

const int maxn = 2e5 + 42;
int par[maxn], mx[maxn], sz[maxn];
int get(int v) {
	return v == par[v] ? v : par[v] = get(par[v]);
}
int uni(int a, int b) {
	a = get(a);
	b = get(b);
	if(a != b) {
		par[a] = b;
		sz[b] += sz[a];
		mx[b] = max(mx[b], mx[a]);
		return 1;
	} else {
		return 0;
	}
}

vector<int> occs[maxn], open[maxn], clos[maxn];
void solve() {
	iota(par, par + maxn, 0);
	int n, q;
	cin >> n >> q;
	int a[n];
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		occs[a[i]].push_back(i);
		mx[a[i]]++;
		sz[a[i]]++;
	}
	for(int i = 0; i < maxn; i++) {
		if(!occs[i].empty()) {
			open[occs[i][0]].push_back(i);
			clos[occs[i].back()].push_back(i);
		}
	}
	set<int> cur;
	int ans = 0;
	for(int i = 0; i < maxn; i++) {
		for(auto it: open[i]) {
			if(!cur.empty()) {
				uni(it, *begin(cur));
			}
			cur.insert(it);
		}
		for(auto it: clos[i]) {
			cur.erase(it);
		}
	}
	for(int i = 0; i < maxn; i++) {
		if(i == par[i]) {
			ans += sz[i] - mx[i];
		}
	}
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