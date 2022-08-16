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
typedef  pair<ll, ll>          pll;
typedef  vector<ll>            vll;
typedef  vector<pll>           vpll;

const ll   N     =  6e5 + 5;
const ll   mod   =  1e9 + 7;
const ll   INF   =  1e16;
const int  INFi  =  0x7f7f7f7f;
const ll   LEVEL =  log2(N) + 1;

int n, in[N];
vector <int> adj[N];

void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int k, x; cin >> k;
		for (int j = 1; j <= k; j++) {
			cin >> x;
			adj[x].pb(i);
			in[i]++;
		}
	}
	int ans = 1, c = 0, p = 0;
	set <int> q;
	for (int i = 1; i <= n; i++) {
		if (in[i] == 0) q.insert(i);
	}
	while (q.size()) {
		auto y = q.lower_bound(p);
		if (y == q.end()) {
			y = q.begin();
			ans++;
		}
		int x = *y;
		q.erase(y);
		c++;
		p = x;

		for (auto it : adj[x]) {
			in[it]--;
			if (in[it] == 0) q.insert(it);
		}
	}

	if (c != n) deb1(-1)
	else deb1(ans)

	for (int i = 1; i <= n; i++) {
		adj[i].clear();
		in[i] = 0;
	}
}

int main() {
	int test = 1;
	cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}