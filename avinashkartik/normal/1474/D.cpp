#pragma optimization_level 3
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")

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

const ll   N     =  2e5 + 2;
const ll   mod   =  1e9 + 7;
const ll   INF   =  1e18;
const int  INFi  =  0x7f7f7f7f;
const ll   LEVEL =  log2(N) + 1;

ll n, a[N], p[N], s[N], pf[N], sf[N];

void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	pf[0] = sf[n + 1] = 1;
	p[0] = s[n + 1] = 0;
	for (int i = 1; i <= n; i++) {
		p[i] = a[i] - p[i - 1];
		pf[i] = pf[i - 1] & (p[i] >= 0);
	}
	for (int i = n; i >= 1; i--) {
		s[i] = a[i] - s[i + 1];
		sf[i] = sf[i + 1] & (s[i] >= 0);
	}
	if ((p[n] == 0 && pf[n] == 1) || (s[1] == 0 && sf[1] == 1)) {
		deb1("YES")
		return;
	}
	for (int i = 1; i < n; i++) {
		if (p[i] == s[i + 1] && pf[i] == 1 && sf[i + 1] == 1) {
			deb1("YES")
			return;
		}
	}
	for (int i = 1; i < n; i++) {
		ll a1 = a[i + 1] - p[i - 1];
		ll a2 = a[i] - s[i + 2];
		if (pf[i - 1] == 0 || sf[i + 2] == 0) continue;
		if (a1 == a2 && a1 >= 0) {
			deb1("YES")
			return;
		}
	}
	deb1("NO")
}

int main() {
	GODSPEED;
	int test = 1;
	cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}