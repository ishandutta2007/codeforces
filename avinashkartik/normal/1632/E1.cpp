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

const ll   N     =  3002;
const ll   mod   =  1e9 + 7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

struct graph {
	int n, m;
	vector <int> v, w, p, d;
	vector <vector <int>> adj;

	graph() {}
	graph(int n) : n(n), m(0) {
		adj.resize(n + 1, vector <int>());
		p.assign(n + 1, 0);
        d.assign(n + 1, 0);
   	}
	
	void findpar(int x, int par) {
        p[x] = par;
        for (auto it : adj[x]) {
            if (v[it] == par) continue;
            d[v[it]] = d[x] + 1;
            findpar(v[it], x);
        }
    }

	void add_edge(int ui, int vi, int wi = 0) {
		v.push_back(vi);
		w.push_back(wi);
		adj[ui].push_back(m++);
	}
	
	int bfs(int node, int weight) {
		vector <int> d(n + 1, INFi);
		d[0] = 0;
		d[1] = 0;
		d[node] = weight;
		queue <int> q;
		q.push(1);
		int f = 0;
		while (q.size()) {
			auto u = q.front();
			q.pop();
			if (d[u] == weight && f == 0) {
				q.push(node);
				f = 1;
			}
			for (auto i : adj[u]) {
				if (d[v[i]] > d[u] + w[i]) {
					d[v[i]] = d[u] + w[i];
					q.push(v[i]);
				}
			}
		}
		return *max_element(all(d));
	}
};

int n;

void solve() {
	cin >> n;
	graph g(n);
	for (int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		g.add_edge(u, v, 1);
		g.add_edge(v, u, 1);
	}
	
	g.findpar(1, 0);
	int mx = 1;
	for (int i = 2; i <= n; i++) {
		if (g.d[i] > g.d[mx]) mx = i;
	}
	
	int st = mx;
	vector <int> path;
	while (st) {
		path.pb(st);
		st = g.p[st];
	}
	reverse(all(path));
	
	for (int x = 1, i = 1; x <= n; x++) {
		int ans = g.bfs(path[i], x);
		while (i < path.size() - 1) {
			int res = g.bfs(path[i + 1], x);
			if (res < ans) {
				ans = res;
				i++;
			} else {
				break;
			}
		}
		cout << ans << " ";
	}
	newl;
}

int main() {
	GODSPEED;
	int test = 1;
	cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}