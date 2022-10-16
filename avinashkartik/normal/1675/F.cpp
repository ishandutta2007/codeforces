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

const ll   N     =  3e5 + 5;
const ll   mod   =  1e9 + 7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

struct graph {
    int n, m;
    vector <int> v, w;
    vector <vector <int>> adj;

    graph() {}
    graph(int n) : n(n), m(0) {
        adj.resize(n + 1, vector <int>());
    }

    void add_edge(int ui, int vi, int wi = 0) {
        v.push_back(vi);
        w.push_back(wi);
        adj[ui].push_back(m++);
    }
};

int n, k, x, y, a[N];

void solve() {
	cin >> n >> k;
	cin >> x >> y;
	vector <int> mark(n + 1, 0), vis(n + 1, 0), d(n + 1, 0);
	for (int i = 1; i <= k; i++) cin >> a[i], mark[a[i]] = 1;
	mark[y] = 1;
	graph g(n);
	for (int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		g.add_edge(u, v);
		g.add_edge(v, u);
	}
	function<void(int)> dfs = [&](int x) {
		vis[x] = 1;
		for (auto i : g.adj[x]) {
			if (!vis[g.v[i]]) {
				dfs(g.v[i]);
				if (mark[g.v[i]]) mark[x] = 1;
			}
		}
	};
	dfs(x);
	
	vis.assign(n + 1, 0);
	function<void(int)> bfs = [&](int x) {
		queue <int> q;
		q.push(x);
		vis[x] = 1;
		while (q.size()) {
			int x = q.front();
			q.pop();
			for (auto i : g.adj[x]) {
				if (!vis[g.v[i]]) {
					q.push(g.v[i]);
					vis[g.v[i]] = 1;
					d[g.v[i]] = d[x] + 1;
				}
			}
		}
	};
	bfs(x);
	
	int ans = 2 * accumulate(all(mark), 0) - 2 - d[y];
	deb1(ans)
}

int main() {
	GODSPEED;
	int test = 1;
	cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}