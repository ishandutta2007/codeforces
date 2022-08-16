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

int n, m, ans[N], val[N];

void solve() {
	cin >> n >> m;
	graph g(n);
	for (int i = 1; i <= m; i++) {
		int u, v, w; cin >> u >> v >> w;
		g.add_edge(u, v, w);
		g.add_edge(v, u, w);
		val[u] += w;
		val[v] += w;
	}
	
	mset(ans, -1);
	queue <int> q;
	q.push(1);
	while (q.size()) {
		int x = q.front();
		q.pop();
		for (auto i : g.adj[x]) {
			if (ans[i / 2] == -1) {
				ans[i / 2] = i % 2;
				val[g.v[i]] -= 2 * g.w[i];
				if (val[g.v[i]] == 0 && g.v[i] != n) q.push(g.v[i]);
			}
		}
	}
	for (int i = 0; i < m; i++) deb1(ans[i])
}

int main() {
	GODSPEED;
	int test = 1;
	// cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}