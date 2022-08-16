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
const int  LEVEL =  log2(N) + 1;

int n, a[N], d[N * 30], vis[N * 30];
vector <int> adj[N * 30], v[N];
map <int, int> idx;

void dfs(int x, int p) {
	d[x] = d[p] + 1;
	for (auto it : adj[x]) {
		if (d[it] != -1) continue;
		dfs(it, x);
	}
}

void solve() {
	cin >> n;

	vector <int> pts;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		idx[a[i]] = i;
		v[i].pb(a[i]);
		while (a[i]) {
			int l = ceil(log2(a[i]));
			a[i] = (1 << l) - a[i];
			v[i].pb(a[i]);
		}
		for (auto it : v[i]) pts.pb(it);
	}

	sort(all(pts));
	uniq(pts);

	auto ind = [&](int i) -> int {
		return lower_bound(all(pts), i) - pts.begin();
	};

	for (int i = 1; i <= n; i++) {
		for (auto &it : v[i]) it = ind(it);
		for (int j = 1; j < v[i].size(); j++) {
			adj[v[i][j]].pb(v[i][j - 1]);
			adj[v[i][j - 1]].pb(v[i][j]);
		}
	}

	for (int i = 0; i < pts.size(); i++) {
		if (idx.find(pts[i]) != idx.end()) vis[i] = 1;
		sort(all(adj[i]));
		uniq(adj[i]);
	}

	int root = 0;

	mset(d, -1);
	d[pts.size()] = 0;
	dfs(root, pts.size());

	for (int i = 0; i < pts.size(); i++) {
		if (d[i] > d[root] && vis[i]) {
			root = i;
		}
	}

	mset(d, -1);
	d[pts.size()] = 0;
	dfs(root, pts.size());

	int far = root;

	for (int i = 0; i < pts.size(); i++) {
		if (d[i] > d[far] && vis[i]) {
			far = i;
		}
	}

	deb3(idx[pts[root]], idx[pts[far]], d[far] - 1)
}

int main() {
	GODSPEED;
	int test = 1;
	// cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}