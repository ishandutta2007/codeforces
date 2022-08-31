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

const ll   N     =  2e5 + 5;
const ll   mod   =  998244353;
const ll   INF   =  1e18;
const int  INFi  =  0x7f7f7f7f;
const ll   LEVEL =  log2(N) + 1;

ll n, a[N], b[N], ans[N];
vector <int> ind[N];

void solve() {
	vector <int> v;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i], b[i] = a[i], v.pb(a[i]);
	sort(b, b + n);
	sort(all(v));
	uniq(v);
	for (int i = 0; i < n; i++) {
		a[i] = lower_bound(all(v), a[i]) - v.begin();
		b[i] = lower_bound(all(v), b[i]) - v.begin();
		ind[b[i]].pb(i);
	}
	for (int i = 0; i <= n; i++) {
		reverse(all(ind[i]));
	}
	set <int> s;
	int mex = -1, ans = 0;
	for (int i = 0; i < n; i++) {
		s.insert(ind[a[i]].back());
		ind[a[i]].pop_back();
		while(s.find(mex + 1) != s.end()) mex++;
		if (mex == i) ans++;
	}
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