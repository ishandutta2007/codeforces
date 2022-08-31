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

const ll   N     =  1e6 + 5;
const ll   mod   =  1e9 + 7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const ll   LEVEL =  log2(N) + 1;

ll n, m;
string s[N];

void solve() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> s[i];
	set <pll> o, e;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (s[i][j] == '0') continue;
			if ((i + j) % 2 == 0) {
				e.insert({i + j, i});
			} else {
				o.insert({i + j, i});
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (s[i][j] == '0') continue;
			ans++;
			if ((i + j) % 2 == 1) {
				for (int x = i, y = j; x < n; x++) {
					if (s[x][y] == '1') {
						s[x][y] = '0';
						o.erase({x + y, x});
					}
					auto it = o.lower_bound({x + y, x});
					if (it == o.end()) {
						if (y < m - 1) y++;
						else y--;
					} else {
						if (it->f == x + y && y != 0) y--;
						else y++;
					}
				}
			} else {
				for (int x = i, y = j; x < n; x++) {
					if (s[x][y] == '1') {
						s[x][y] = '0';
						e.erase({x + y, x});
					}
					auto it = e.lower_bound({x + y, x});
					if (it == e.end()) {
						if (y < m - 1) y++;
						else y--;
					} else {
						if (it->f == x + y && y != 0) y--;
						else y++;
					}
				}
			}
		}
	}
	deb1(ans)
}

int main() {
	GODSPEED;
	int test = 1;
	cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}