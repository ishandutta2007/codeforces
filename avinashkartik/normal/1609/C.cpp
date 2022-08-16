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

const ll   N     =  2e6 + 5;
const ll   mod   =  1e9 + 7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const ll   LEVEL =  log2(N) + 1;

int n, e, a[N], p[N];

void solve() {
	cin >> n >> e;
	for (int i = 1; i <= n; i++) cin >> a[i];
	ll ans = 0;
	for (int i = 1; i <= e; i++) {
		vector <int> v;
		v.pb(0);
		for (int j = i, f = 0; j <= n; j += e) {
			if (a[j] == 1) {
				if (f == 0) v.pb(1), f = 1;
				else if (f == 2) {
					int x = v.back();
					v.pop_back();
					ans += v.back() + 1;
					v.pb(x + 1);
				} else {
					int x = v.back();
					v.pop_back();
					v.pb(x + 1);
				}
			} else if (p[a[j]] == 0) {
				ans += v.back();
				v.pb(0);
				f = 2;
			} else {
				v.clear();
				v.pb(0);
				f = 0;
			}
		}
	}
	deb1(ans)
}

int main() {
	GODSPEED;
	for (int i = 2; i * i < N; i++) {
		if (p[i]) continue;
		for (int j = i * i; j < N; j += i) p[j] = 1;
	}
	int test = 1;
	cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}