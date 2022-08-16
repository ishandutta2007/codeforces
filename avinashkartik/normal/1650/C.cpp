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

ll n, m, x[N], w[N];

void solve() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) cin >> x[i] >> w[i];
	vector <int> ind(m), pts;
	iota(all(ind), 1);
	sort(all(ind), [&](int i, int j) {
		return w[i] < w[j];
	});
	ll ans = 0;
	for (int i = 0; i < 2 * n; i++) {
		ans += w[ind[i]];
		pts.pb(ind[i]);
	}
	sort(all(pts), [&](int i, int j) {
		return x[i] < x[j];
	});
	
	deb1(ans)
	for (int i = 0; i < n; i++) deb2(pts[i], pts[2 * n - i - 1])
}

int main() {
	GODSPEED;
	int test = 1;
	cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}