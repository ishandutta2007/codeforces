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

int n, p[N];

void solve() {
	cin >> n;
	int root = 0;
	graph g(n);
	for (int i = 1; i <= n; i++) {
		cin >> p[i];
		if (p[i] == i) {
			root = i;
		} else {
			g.add_edge(p[i], i);
		}
	}
	
	vector <int> d;
	d.assign(n + 1, 0);
	function<void(int)> bfs = [&](int x) {
		queue <int> q;
		q.push(x);
		while (q.size()) {
			int x = q.front();
			q.pop();
			for (auto i : g.adj[x]) {
				if (!d[g.v[i]] && g.v[i] != x) {
					q.push(g.v[i]);
					d[g.v[i]] = d[x] + 1;
				}
			}
		}
	};
	bfs(root);
	
	vector <int> ind(n);
	iota(all(ind), 1);
	sort(all(ind), [&](int i, int j){
		return d[i] < d[j];
	});
	
	vector <int> vis(n + 1, 0);
	function<void(int, vector<int>&)> dfs = [&](int x, vector <int> &ans) {
		vis[x] = 1;
		ans.pb(x);
		for (auto i : g.adj[x]) {
			if (!vis[g.v[i]]) {
				dfs(g.v[i], ans);
				break;
			}
		}
	};
	
	vector <vector <int>> ans;
	for (auto it : ind) {
		if (vis[it]) continue;
		vector <int> res;
		dfs(it, res);
		ans.pb(res);
	}
	
	deb1(ans.size())
	for (auto it : ans) {
		deb1(it.size())
		debv(it)
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