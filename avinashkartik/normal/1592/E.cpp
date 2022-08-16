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
const ll   mod   =  998244353;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const ll   LEVEL =  log2(N) + 1;

ll n, a[N], b[N];

void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	int ans = 0;
	for (int j = 19; j >= 0; j--) {
		int x = 0;
		vector <int> me(N, -1), mo(N, -1), ve, vo;
		me[0] = 0, ve.pb(0);
		for (int i = 1, st = 1; i <= n; i++) {
			if ((a[i] >> j)&1) {
				x ^= b[i];
				if (i % 2 == 0) {
					if (me[x] == -1) me[x] = i, ve.pb(x);
					else ans = max(ans, i - me[x]);
				} else {
					if (mo[x] == -1) mo[x] = i, vo.pb(x);
					else ans = max(ans, i - mo[x]);
				}
			} else {
				st = i + 1;
				x = 0;
				for (auto it : ve) me[it] = -1;
				for (auto it : vo) mo[it] = -1;
				ve.clear();
				vo.clear();
				if (i&1) mo[0] = i, vo.pb(0);
				else me[0] = i, ve.pb(0);
			}
		}
		for (int i = 1; i <= n; i++) {
			if ((a[i] >> j)&1) b[i] |= (1 << j);
		}
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