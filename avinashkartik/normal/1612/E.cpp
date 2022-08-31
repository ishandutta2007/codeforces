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

const ll   N     =  2e5 + 5;
const ll   mod   =  998244353;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const ll   LEVEL =  log2(N) + 1;

int n, m[N], a[N];

void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> m[i] >> a[i];
	ld ans = 0;
	vector <int> v;
	for (int i = 1; i <= 20; i++) {
		vector <pll> k(N);
		for (int j = 0; j < N; j++) {
			k[j].s = j;
		}
		for (int j = 1; j <= n; j++) {
			k[m[j]].f += min(i, a[j]);
		}
		sort(all(k), greater<>());
		ld res = 0;
		for (int j = 0; j < i; j++) {
			res += k[j].f;
		}
		res = (ld) res / i;
		if (res > ans) {
			ans = res;
			v.clear();
			for (int j = 0; j < i; j++) {
				v.pb(k[j].s);
			}
		}
	}
	vector <pll> k(N);
	for (int j = 0; j < N; j++) {
		k[j].s = j;
	}
	for (int j = 1; j <= n; j++) {
		k[m[j]].f += a[j];
	}
	sort(all(k), greater<>());
	ld res = 0;
	for (int j = 0; j < 20; j++) {
		res += k[j].f;
	}
	for (int i = 20; i < N; i++) {
		res += k[i].f;
		if (res > ans * (i + 1)) {
			ans = (ld) res / (i + 1);
			if (v.size() <= 20) {
				v.clear();
				for (int j = 0; j < i; j++) {
					v.pb(k[j].s);
				}
			} else {
				for (int j = v.size(); j < i; j++) {
					v.pb(k[j].s);
				}
			}
		}
	}
	deb1(v.size())
	debv(v)
}

int main() {
	GODSPEED;
	int test = 1;
	// cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}