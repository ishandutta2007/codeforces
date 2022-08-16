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

const ll   N     =  5e5 + 2;
const ll   mod   =  1e9 + 7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const int  LEVEL =  log2(N) + 1;

int n, a[N];

int calc(int o, int t, int x) {
	vector <int> possible;
	for (int i = 0; i <= o; i++) {
		for (int j = 0; j <= t; j++) {
			possible.pb(i + j * 2);
		}
	}
	int ans = INFi;
	for (auto it : possible) {
		if (it > x || (x - it) % 3 != 0) continue;
		ans = min(ans, (x - it) / 3);
	}
	return ans + o + t;
}

void solve() {
	cin >> n;
	int ans = INFi;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int o = 0; o <= 2; o++) {
		for (int t = 0; t <= 2; t++) {
			int mx = 0;
			for (int i = 1; i <= n; i++) {
				mx = max(mx, calc(o, t, a[i]));
			}
			ans = min(ans, mx);
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