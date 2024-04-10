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

const ll   N     =  3e5 + 5;
const ll   mod   =  1e9 + 7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll n, q, a[N], b[N];

void solve() {
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 2; i <= n; i++) b[i] = a[i] != a[i - 1];
	ll ans = n * (n + 1) / 2;
	for (int i = 2; i <= n; i++) ans += b[i] * (i - 1) * (n - i + 1);
	for (int i = 1; i <= q; i++) {
		ll ind, x; cin >> ind >> x;
		if (ind != 1) {
			ans -= b[ind] * (ind - 1) * (n - ind + 1);
			b[ind] = x != a[ind - 1];
			ans += b[ind] * (ind - 1) * (n - ind + 1);
		}
		if (ind != n) {
			ans -= b[ind + 1] * (ind) * (n - ind);
			b[ind + 1] = a[ind + 1] != x;
			ans += b[ind + 1] * (ind) * (n - ind);
		}
		a[ind] = x;
		deb1(ans)
	}
}

int main() {
	GODSPEED;
	int test = 1;
	// cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}