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

const ll   N     =  2e3 + 5;
const ll   mod   =  998244353;
const ll   INF   =  1e18;
const int  INFi  =  0x7f7f7f7f;
const ll   LEVEL =  log2(N) + 1;

ll n, m, w, a[N][N];

vector <vector <ll>> dijkstra(int x, int y) {
    vector <vector <ll>> d(n + 1, vector <ll>(m + 1, INF));
    d[x][y] = 0;
    queue <tuple<ll, int, int>> q; 
    q.push({0, x, y});
    while (!q.empty()) {
        auto t = q.front();
        q.pop();
        int x = get<1>(t), y = get<2>(t);
        if (a[x][y] == -1) continue;
        if (x != 1) {
        	if (d[x - 1][y] > d[x][y] + 1) {
        		d[x - 1][y] = d[x][y] + 1;
        		q.push({d[x - 1][y], x - 1, y});
        	}
        }
        if (x != n) {
        	if (d[x + 1][y] > d[x][y] + 1) {
        		d[x + 1][y] = d[x][y] + 1;
        		q.push({d[x + 1][y], x + 1, y});
        	}
        }
        if (y != 1) {
        	if (d[x][y - 1] > d[x][y] + 1) {
        		d[x][y - 1] = d[x][y] + 1;
        		q.push({d[x][y - 1], x, y - 1});
        	}
        }
        if (y != m) {
        	if (d[x][y + 1] > d[x][y] + 1) {
        		d[x][y + 1] = d[x][y] + 1;
        		q.push({d[x][y + 1], x, y + 1});
        	}
        }
    }
    return d;
}

void solve() {
	cin >> n >> m >> w;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
		}
	}
	vector <vector <ll>> d1 = dijkstra(1, 1);
	vector <vector <ll>> d2 = dijkstra(n, m);
	ll ans = d1[n][m];
	if (ans != INF) ans *= w;
	ll mn1 = INF, mn2 = INF;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (a[i][j] <= 0) continue;
			if (d1[i][j] != INF) {
				mn1 = min(mn1, w * d1[i][j] + a[i][j]);
			}
			if (d2[i][j] != INF) {
				mn2 = min(mn2, w * d2[i][j] + a[i][j]);
			}
		}
	}
	ans = min(ans, mn1 + mn2);
	if (ans == INF) ans = -1;
	deb1(ans)
}

int main() {
	GODSPEED;
	int test = 1;
	// cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}