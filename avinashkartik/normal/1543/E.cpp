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

const int   N    =  5e5 + 1;
const ll   mod   =  1e9 + 7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll n, a[N], p[N], vis[N];
vector <int> adj[N], e[N];

void recurse(int no, int i, int j, int sum) {
	if (no == n) {
		int x = sum + (1 << j), y = sum + (1 << i);
		// deb3(x, y, (x & y) + (x ^ y))
		e[sum + (1 << j)].pb(sum + (1 << i));
		return;
	}
	if (no == i || no == j) {
		recurse(no + 1, i, j, sum);
	} else {
		recurse(no + 1, i, j, sum);
		recurse(no + 1, i, j, sum + (1 << no));
	}
}

void bfs() {
	p[0] = 0;
	vis[0] = 0;
	for (int i = 0; i < n; i++) {
		int x = adj[0][i];
		p[1 << i] = x;
		vis[x] = (1 << i);
	}
	for (int x = 1; x < (1 << n); x++) {
		for (auto it : e[x]) {
			if (p[it] == -1) continue;
			for (int i = 0, j = 0; i < n && j < n;) {
				int u = adj[p[x]][i], v = adj[p[it]][j];
				if (u < v) i++;
				else if (u > v) j++;
				else if (vis[u] != -1) i++, j++;
				else {
					p[(it & x) + (it ^ x)] = u;
					vis[u] = (it & x) + (it ^ x);
					i++, j++;
				}
			}
		}
	}
}

void solve() {
	cin >> n;
	for (int i = 0; i < (1 << n); i++) adj[i].clear(), p[i] = -1, e[i].clear(), vis[i] = -1;
	for (int i = 0; i < n * (1 << (n - 1)); i++) {
		int u, v; cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			recurse(0, i, j, 0);
		}
	}

	for (int i = 0; i < (1 << n); i++) sort(all(adj[i])), sort(all(e[i]));

	bfs();

	for (int i = 0; i < (1 << n); i++) cout << p[i] << " ";
	newl;

	if (__builtin_popcount(n) == 1) {
		vector <int> v(1 << n, 0);
		for (int i = 0; i < (1 << n); i++) {
			int c = 0;
			for (int j = 0; j < n; j++) {
				c ^= ((i >> j)&1) * j;
			}
			v[i] = c;
		}
		for (int i = 0; i < v.size(); i++) cout << v[vis[i]] << " ";
		newl;
	} else {
		deb1(-1)
	}
}

int main() {
	GODSPEED;
	int test = 1;
	cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}