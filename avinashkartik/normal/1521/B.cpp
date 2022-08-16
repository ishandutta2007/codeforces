#include<bits/stdc++.h>

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

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
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

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

ll n, a[N];

void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (n == 1) {
		deb1(0)
		return;
	}
	if (n == 2) {
		deb1(1)
		deb4(1, 2, min(a[1], a[2]), mod)
		return;
	}
	deb1(n)
	for (int i = 2; i <= n; i++) {
		ll x = min(a[i], a[i - 1]), y = mod + i;
		a[i - 1] = y;
		a[i] = x;
		deb4(i - 1, i, y, x);
	}
	for (ll j = a[n - 1]; ; j++) {
		if (__gcd(j, a[n]) == 1 && __gcd(j, a[n - 2]) == 1) {
			deb4(n - 1, n, j, a[n])
			break;
		}
	}
}

int main() {
	GODSPEED;
	int test = 1;
	cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}