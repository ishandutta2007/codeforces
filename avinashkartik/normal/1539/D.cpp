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

const ll   N     =  1e6 + 5;
const ll   mod   =  1e9 + 7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const ll   LEVEL =  log2(N) + 1;

ll n, a[N], b[N];

void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i] >> b[i];
	vector <int> ind(n);
	iota(all(ind), 1);
	sort(all(ind), [&](int i, int j) {
		return b[i] > b[j];
	});
	ll cur = 0, ans = 0;
	for (int ii = 0, jj = n - 1; ii <= jj;) {
		int i = ind[ii], j = ind[jj];
		if (cur + a[i] <= b[j]) {
			ans += 2 * a[i];
			cur += a[i];
			ii++;
		} else if (cur < b[j]) {
			ll buy = b[j] - cur;
			ans += 2 * buy;
			cur += buy;
			a[i] -= buy;
		} else {
			ans += a[j];
			cur += a[j];
			jj--;
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