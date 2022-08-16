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

const ll   N     =  2e6 + 5;
const ll   mod   =  998244353 ;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const int  LEVEL =  log2(N) + 1;

int n, k, a[N];

void solve() {
	cin >> n >> k;
	vector <int> pos, neg;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] < 0) neg.pb(-a[i]);
		else pos.pb(a[i]);
	}
	sort(all(pos));
	sort(all(neg));
	ll ans = 0;
	for (int i = pos.size() - 1; i >= 0; i -= k) ans += 2 * pos[i];
	for (int i = neg.size() - 1; i >= 0; i -= k) ans += 2 * neg[i];
	if (pos.size() && neg.size()) ans -= max(pos.back(), neg.back());
	else if (pos.size()) ans -= pos.back();
	else ans -= neg.back();
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