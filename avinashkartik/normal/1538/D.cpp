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

const ll   N     =  5e4 + 5;
const ll   mod   = 	1e9 + 7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const ll   LEVEL =  log2(N) + 1;

ll a, b, k, p[N];
vector <int> pr;

void solve() {
	cin >> a >> b >> k;
	if (a > b) swap(a, b);
	ll l = a, r = b;
	int ctl = 0, ctr = 0;
	for (auto i : pr) {
		while (l % i == 0) {
			l /= i;
			ctl++;
		}
	}
	if (l > 1) ctl++;
	for (auto i : pr) {
		while (r % i == 0) {
			r /= i;
			ctr++;
		}
	}
	if (r > 1) ctr++;
	if (k == 1) {
		if (a == b) {
			deb1("NO")
		} else if (b % a == 0) {
			deb1("YES")
		} else {
			deb1("NO")
		}
	} else if (k > ctl + ctr) deb1("NO")
	else deb1("YES")
}

int main() {
	GODSPEED;
	int test = 1;
	for (int i = 2; i * i < N; i++) {
		if (p[i]) continue;
		for (int j = i * i; j < N; j += i) p[j] = 1;
	}
	for (int i = 2; i < N; i++) {
		if (p[i]) continue;
		pr.pb(i);
	}
	cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}