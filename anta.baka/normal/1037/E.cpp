#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = double;
using pii = pair<int, int>;
using vi = vector<int>;

#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
#define x first
#define y second
#define pb push_back

const int maxn = 5e5;
const int inf = 1e9;
const int mod = 1e9 + 7;
const ll inf64 = 1e18;
const ld pi = acos(-1.0);
const ld eps = 1e-6;

int n, m, k, deg[maxn];
set<int> g[maxn];
int uu[maxn], vv[maxn];
int ans[maxn];
int del[maxn];
int cur;

void go(int v) {
	queue<int> q;
	q.push(v);
	while(!q.empty()) {
		v = q.front();
		q.pop();
		if(del[v]) continue;
		del[v] = 1;
		cur--;
		for(int to : g[v]) {
			g[to].erase(v);
			if(--deg[to] < k) q.push(to);
		}
	}
}

main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m >> k;
    for(int i = 0; i < m; i++) {
    	int u, v; cin >> u >> v; u--; v--;
    	g[u].insert(v); g[v].insert(u);
    	deg[u]++; deg[v]++;
    	uu[i] = u; vv[i] = v;
    }
    cur = n;
    for(int i = 0; i < n; i++) if(del[i] == 0 && deg[i] < k) {
    	go(i);
    }
    for(int i = m - 1; i >= 0; i--) {
    	ans[i] = cur;
    	if(del[uu[i]] == 0 && del[vv[i]] == 0) {
	    	deg[uu[i]]--;
	    	deg[vv[i]]--;
	    	g[uu[i]].erase(vv[i]);
	    	g[vv[i]].erase(uu[i]);
	    	if(deg[uu[i]] < k) go(uu[i]);
	    	if(deg[vv[i]] < k) go(vv[i]);
    	}
    }
    for(int i = 0; i < m; i++) cout << ans[i] << '\n';
}