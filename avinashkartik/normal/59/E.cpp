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

const ll   N     =  3e5 + 5;
const ll   mod   =  1e9 + 7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const ll   LEVEL =  log2(N) + 1;

ll n, m, k, a[N];
vector <int> adj[N];
map <tuple<int, int, int>, bool> K;

void bfs() {
    vector <vector <int>> d(n + 1, vector <int>(n + 1, INFi)), p(n + 1, vector <int>(n + 1, INFi));
    d[0][1] = 0;
    queue <pll> q; q.push({0, 1});
    while (!q.empty()) {
        auto [u, v] = q.front();
        q.pop();
        for (auto to : adj[v]) {
        	if (K.find({u, v, to}) != K.end()) continue;
            if (d[u][v] + 1 < d[v][to]) {
            	p[v][to] = u;
            	d[v][to] = d[u][v] + 1;
                q.push({v, to});
            }
        }
    }
    int ans = INFi, ind  = -1;
    for (int i = 1; i <= n; i++) {
    	if (d[i][n] < ans) {
    		ans = d[i][n];
    		ind = i;
    	}
    }
    if (ans == INFi) {
    	deb1(-1)
    	return;
    } else {
    	deb1(ans)
    	int par = ind, cur = n;
    	vector <int> v;
    	v.pb(n);
    	while (par) {
    		v.pb(par);
    		int nxt = p[par][cur];
    		cur = par;
    		par = nxt;
    	}
    	reverse(all(v));
    	debv(v)
    }
    
}

void solve() {
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		int x, y; cin >> x >> y;
		adj[x].pb(y);
		adj[y].pb(x);
	}
	for (int i = 1; i <= k; i++) {
		int u, v, w; cin >> u >> v >> w;
		K[{u, v, w}] = 1;
	}
	bfs();
}

int main() {
	GODSPEED;
	int test = 1;
	// cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}