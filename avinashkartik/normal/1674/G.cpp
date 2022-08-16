#include<bits/stdc++.h>

using namespace std;

#define  GODSPEED       ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(15);
#define  f              first
#define  s              second
#define  newl           cout<<"\n";
#define  pb             push_back
#define  mset(a,x)      memset(a,x,sizeof(a))
#define  debv(a)        for(auto it: a)cout<<it<<" ";newl;
#define  deb1(a)        cout<<a<<"\n";
#define  deb2(a,b)      cout<<a<<" "<<b<<"\n";
#define  deb3(a,b,c)    cout<<a<<" "<<b<<" "<<c<<"\n";
#define  deb4(a,b,c,d)  cout<<a<<" "<<b<<" "<<c<<" "<<d<<"\n";
#define  uniq(a)        a.resize(unique(a.begin(), a.end()) - a.begin());
#define  all(a)         a.begin(),a.end()

typedef  long long             ll;
typedef  long double           ld;

const ll   N     =  2e5 + 5;
const ll   mod   =  1e9 + 7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

struct graph {
    int n, m;
    vector <int> v, w, in, out;
    vector <vector <int>> adj;

    graph() {}
    graph(int n) : n(n), m(0) {
        adj.resize(n + 1, vector <int>());
        in.resize(n + 1, 0);
        out.resize(n + 1, 0);
    }

    void add_edge(int ui, int vi, int wi = 0) {
        v.push_back(vi);
        w.push_back(wi);
        adj[ui].push_back(m++);
        in[vi]++;
        out[ui]++;
    }
};

int n, m, vis[N], dp[N];

void dfs(graph &g, int x) {
	if (vis[x]) return;
	vis[x] = 1;
	
	for (auto i : g.adj[x]) {
		dfs(g, g.v[i]);
		if (g.in[g.v[i]] > 1 && g.out[x] > 1) dp[x] = max(dp[x], dp[g.v[i]]);
	}
	dp[x]++;
}

void solve() {
	cin >> n >> m;
	graph g(n);
	for (int i = 1; i <= m; i++) {
		int u, v; cin >> u >> v;
		g.add_edge(u, v);
	}
	
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		dfs(g, i);
		ans = max(ans, dp[i]);
	}
	deb1(ans)
}

int main() {
	GODSPEED;
	int test = 1;
	// cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}