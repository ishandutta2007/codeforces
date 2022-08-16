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
typedef  pair<ll, ll>           pll;
typedef  vector<ll>            vll;
typedef  vector<pll>           vpll;

const ll   N     =  5e5 + 5;
const ll   mod   =  1e9 + 7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const ll   LEVEL =  log2(N) + 1;

int n, m, f1, f2;
vector <int> adj[N], rev[N];
vector <int> order, component, used, ans, loop;

void dfs1(int v) {
    used[v] = true;

    for (auto u : adj[v])
        if (!used[u])
            dfs1(u);

    order.push_back(v);
}

void dfs2(int v) {
	if (v == 1) f1 = 1;
    used[v] = true;
    component.push_back(v);

    for (auto u : rev[v])
        if (!used[u])
        	dfs2(u);
}
      

void solve() {
	cin >> n >> m;
	loop.assign(n + 1, 0);
	for (int i = 1; i <= m; i++) {
		int u, v; cin >> u >> v;
		if (u == v) loop[u] = 1;
		adj[u].pb(v);
		rev[v].pb(u);
	}
	ans.assign(n + 1, -2);

	used.assign(n + 1, false);
    for (int i = 1; i <= n; i++)
        if (!used[i])
            dfs1(i);

    used.assign(n + 1, false);
    reverse(order.begin(), order.end());
    for (auto v : order) {
        if (!used[v]) {
        	f1 = 0;
            dfs2(v);
            // debv(component)
            int f = f1;
            for (auto it : rev[v]) {
            	if (ans[it] == -2) continue;
            	if (ans[it] == -1) f = -1;
            	if (f != -1) f += ans[it];
            }
            f = min(f, 2);
            if (f && (component.size() > 1 || loop[component[0]])) f = -1;
            for (auto it : component) {
            	ans[it] = f;
            }
            component.clear();
        }
    }
    order.clear();
    component.clear();
    for (int i = 1; i <= n; i++) {
    	cout << ans[i] << " ";
    	adj[i].clear();
    	rev[i].clear();
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