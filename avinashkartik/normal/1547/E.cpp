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

const ll   N     =  5e5 + 5;
const ll   mod   =  1e9 + 7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const ll   LEVEL =  log2(N) + 1;

ll n, k, a[N], x[N];

void solve() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) a[i] = INFi;
	set <pll> s;
	for (int i = 1; i <= k; i++) {
		cin >> x[i];
	}
	for (int i = 1; i <= k; i++) {
		int t; cin >> t;
		a[x[i]] = t;
		s.insert({a[x[i]], x[i]});
	}
	while (s.size()) {
		int x = s.begin()->s;
		s.erase(s.begin());
		for (int j = x - 1; j <= x + 1; j++) {
			if (j == 0 || j == n + 1) continue;
			if (a[j] > a[x] + 1) {
				s.erase({a[j], j});
				a[j] = a[x] + 1;
				s.insert({a[j], j});
			}
		}
	}
	for (int i = 1; i <= n; i++) cout << a[i] << " ";
	newl;
}

int main() {
	GODSPEED;
	int test = 1;
	cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}