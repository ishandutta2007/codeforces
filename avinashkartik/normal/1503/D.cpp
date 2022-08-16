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

const ll   N     =  4e5 + 5;
const ll   mod   =  1e9 + 7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const ll   LEVEL =  log2(N) + 1;

int n, a[N], vis[N], b[N];
vpll v;

void solve() {
	cin >> n;
	vpll v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i].f >> v[i].s;
		a[v[i].f] = v[i].s;
		b[v[i].f] = 0;
		a[v[i].s] = v[i].f;
		b[v[i].s] = 1;
	}
	sort(all(v));
	int mx = 2 * n + 1, mn = -1, m = n, f = 0, mn1 = -1, mx1 = 2 * n;
	vector <int> front;
	for (int i = 1; i <= 2 * n; i++) {
		if (vis[i] == 1) continue;
		if (a[i] == 2 * n - i + 1) { m--; continue; }
		mn = i;
		if (a[i] > mx || a[i] < mn1 || i > mx1) {
			deb1(-1)
			return;
		}
		mx = a[i];
		//deb2(i, mx)
		vis[i] = vis[a[i]] = 1;
		f += b[i];
		for (int i = mx1; i > mx; i--) {
			if (vis[i] == 1) continue;
			if (a[i] == 2 * n - i + 1) { m--; continue; }
			mx1 = i;
			if (mn1 > a[i] || i < mn || a[i] > mx) {
				deb1(-1)
				return;
			}
			mn1 = a[i];
			//deb2(i, a[i])
			vis[i] = vis[a[i]] = 1;
			f += b[i];
		}
	}
	deb1(min(f, m - f))
}

int main() {
	GODSPEED;
	int test = 1;
	//cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}