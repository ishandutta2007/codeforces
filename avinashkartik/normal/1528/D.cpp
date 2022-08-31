#include<bits/stdc++.h>

using namespace std;

#define  GODSPEED       ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(12);
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

const ll   N     =  6e5 + 5;
const ll   mod   =  998244353;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const ll   LEVEL =  log2(N) + 1;

ll n, m, dist[605][605];

void dijkstra(int s) {
    vll d(n, INF);
    d[s] = 0;
    set<pll> q; q.insert({0, s});
    ll ct = 0;
    while (!q.empty()) {
        int v = q.begin()->s;
        q.erase(q.begin());
        int st = 0;
        vll d1(n + 1, INF);
        for (int i = 0; i < n; i++) if (dist[v][i] < dist[v][st]) st = i;
        ll cur = dist[v][st];
    	st = (st + d[v]) % n;
        for (int i = 0; i < n; i++) {
        	if (dist[v][(st + n - d[v] % n) % n] < cur) cur = dist[v][(st + n - d[v] % n) % n];
        	d1[st] = cur;
        	// if (v == 0) deb2(st, cur)
        	st = (st + 1) % n;
        	cur++;
        }
        for (int i = 0; i < n; i++){
            ll to = i;
            ll len = d1[i];
            if (d[v] + len < d[to]) {
                q.erase({d[to], to});
            	d[to] = d[v] + len;
                q.insert({d[to], to});
            }
        }
    }
    debv(d)
}

void solve() {
	cin >> n >> m;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			dist[i][j] = INF;
		}
	}
	for (int i = 1; i <= m; i++) {
		ll a, b, c; cin >> a >> b >> c;
		dist[a][b] = c;
	}
	for (int i = 0; i < n; i++) dijkstra(i);
}

int main() {
	GODSPEED;
	int test = 1;
	// cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}