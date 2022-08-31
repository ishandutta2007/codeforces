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

ll n;
vector <int> adj[N];

void solve() {
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    
    vector <int> bfs(n), ind(n + 1), BFS, vis(n + 1, 0);
    for (int i = 0; i < n; i++) cin >> bfs[i], ind[bfs[i]] = i;
    
    for (int i = 1; i <= n; i++) {
        sort (all(adj[i]), [&](int i, int j) {
            return ind[i] < ind[j];
        });
    }
    
    queue <int> q;
    q.push(1);
    vis[1] = 1;
    
    while (q.size()) {
        int x = q.front();
        q.pop();
        BFS.pb(x);
        for (auto it : adj[x]) {
            if (vis[it]) continue;
            vis[it] = 1;
            q.push(it);
        }
    }
    
    if (bfs == BFS) deb1("Yes")
    else deb1("No")
}

int main() {
	GODSPEED;
	int test = 1;
    // 	cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}