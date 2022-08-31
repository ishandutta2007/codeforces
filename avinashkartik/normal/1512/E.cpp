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

const ll   N     =  1e7 + 5;
const ll   mod   =  998244353;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const ll   LEVEL =  log2(N) + 1;

ll n, l, r, s;
set <int, greater<>> t;

ll no(int s, int n) {
	ll low = n * (n - 1) / 2;
	for (auto i : t) {
		if(s - i >= low) {
			return i;
		}
	}
	return 0;
}

void solve() {
	cin >> n >> l >> r >> s;
	vll ans(n, 0);
	ll m = r - l + 1;
	ll low = m * (m + 1) / 2, high = 0;
	t.clear();
	for (int i = 1; i <= n; i++) t.insert(i);
	for (int i = n - m + 1; i <= n; i++) {
		high += i;
	}
	if(s < low || s > high) {
		deb1(-1)
		return;
	}
	for (int i = l - 1; i < r; i++) {
		ans[i] = no(s, m);
		s -= ans[i];
		t.erase(ans[i]);
		m--;
	}
	for (int i = 0; i < n; i++) {
		if(ans[i]) continue;
		ans[i] = *t.begin();
		t.erase(t.begin());
	}
	debv(ans)
}

int main() {
	GODSPEED;
	int test = 1;
	cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}