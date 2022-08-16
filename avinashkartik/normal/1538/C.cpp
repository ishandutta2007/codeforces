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

const ll   N     =  4e6 + 5;
const ll   mod   = 	1e9 + 7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const ll   LEVEL =  log2(N) + 1;

int n, l, r;

ll calc(vector <int> a, int l) {
	ll ans = 0;
	for (int i = 0, j = n - 1; i < n; i++) {
		while (j >= 0 and a[i] + a[j] > l) j--;
		ans += j + 1; 
	}
	return ans;
}

void solve() {
	cin >> n >> l >> r;
	vector <int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(all(a));
	ll ans = calc(a, r) - calc(a, l - 1);
	for (auto it : a) {
		if (2 * it >= l && 2 * it <= r) ans--;
	}
	deb1(ans / 2)
}

int main() {
	GODSPEED;
	int test = 1;
	cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}