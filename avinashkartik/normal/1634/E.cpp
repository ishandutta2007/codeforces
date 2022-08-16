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
const ll   mod   =  998244353;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

struct graph {
    int n, m;
    vector <int> v, w;
    vector <set <int>> adj;

    graph() {}
    graph(int n) : n(n), m(0) {
        adj.resize(n + 1, set <int>());
    }

    void add_edge(int ui, int vi, int wi = 0) {
        v.push_back(vi);
        w.push_back(wi);
        adj[ui].insert(m++);
    }
};

ll n;
multiset <pair <int, int>> m;

void recurse(graph &g, int x, int f = 0) {
	for (auto i : g.adj[x]) {
		if (g.adj[g.v[i]].size() >= 2) {
			if (!f) m.insert({x, g.v[i]});
			g.adj[x].erase(i);
			g.adj[g.v[i]].erase(i ^ 1);
			recurse(g, g.v[i], 1 - f);
			break;
		}
	}
}

void solve() {
	cin >> n;
	vector <vector <int>> a(n + 1);
	vector <int> pts;
	set <int> s;
	for (int i = 1; i <= n; i++) {
		int sz, x; cin >> sz;
		for (int j = 1; j <= sz; j++) {
			cin >> x;
			a[i].pb(x);
			pts.pb(x);
			if (s.find(x) != s.end()) s.erase(x);
			else s.insert(x);
		}
	}
	
	if (s.size()) {
		deb1("NO")
		return;
	}
	
	sort(all(pts));
	uniq(pts);
	
	graph g(n + pts.size() + 1);
	for (int i = 1; i <= n; i++) {
		for (auto it : a[i]) {
			g.add_edge(i, n + 1 + lower_bound(all(pts), it) - pts.begin());
			g.add_edge(n + 1 + lower_bound(all(pts), it) - pts.begin(), i);
		}
	}
	
	for (int i = 1; i <= n; i++) {
		if (g.adj[i].size()) recurse(g, i);
	}
	
	deb1("YES")
	for (int i = 1; i <= n; i++) {
		for (auto it : a[i]) {
			int j = n + 1 + lower_bound(all(pts), it) - pts.begin();
			if (m.find({i, j}) != m.end()) {
				cout << "L";
				m.erase(m.find({i, j}));
			} else cout << "R";
		}
		newl;
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