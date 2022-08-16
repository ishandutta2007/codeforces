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
    vector <int> v, w, d;
    vector <vector <int>> adj;

    graph() {}
    graph(int n) : n(n), m(0) {
        adj.resize(n + 1, vector <int>());
        d.assign(n + 1, 0);
    }

    void add_edge(int ui, int vi, int wi = 0) {
    	d[vi]++;
        v.push_back(vi);
        w.push_back(wi);
        adj[ui].push_back(m++);
    }
};

ll n, m, t[N], u[N], v[N], ori[N], ans[N];

void dfs(graph &g, int x, int p = 0, int d = 0) {
	ori[x] = d;
	for (auto i : g.adj[x]) {
		if (g.v[i] == p) continue;
		if (ori[g.v[i]] != -1) {
			if (ori[g.v[i]] == ori[x]) {
				deb1("NO")
				exit(0);
			}
		} else {
			dfs(g, g.v[i], x, 1 - d);
		}
	}
}

void solve() {
	cin >> n >> m;
	mset(ori, -1);
	graph g(n);
		
	for (int i = 1; i <= m; i++) {
		cin >> t[i] >> u[i] >> v[i];
		g.add_edge(u[i], v[i]);
		g.add_edge(v[i], u[i]);
	}
	
	for (int i = 1; i <= n; i++) {
		if (ori[i] == -1) dfs(g, i);
	}
	
	graph g1(n);
	for (int i = 1; i <= m; i++) {
		if (t[i] == 1) {
			if (ori[u[i]] == 1) g1.add_edge(u[i], v[i]);
			else g1.add_edge(v[i], u[i]);
		} else {
			if (ori[u[i]] == 0) g1.add_edge(u[i], v[i]);
			else g1.add_edge(v[i], u[i]);
		}
	}
	
	queue <int> q;
	for (int i = 1; i <= n; i++) {
		if (g1.d[i] == 0) q.push(i);
	}
	
	int ct = 0;
	while (q.size()) {
		int x = q.front();
		q.pop();
		ans[x] = ct++;
		for (auto i : g1.adj[x]) {
			g1.d[g1.v[i]]--;
			if (g1.d[g1.v[i]] == 0) q.push(g1.v[i]);
		}
	}
	
	if (ct == n) {
		deb1("YES")
		for (int i = 1; i <= n; i++) {
			if (ori[i] == 1) cout << "L ";
			else cout << "R ";
			deb1(ans[i])
		}
	} else {
		deb1("NO")
	}
}

int main() {
	GODSPEED;
	int test = 1;
	// cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}