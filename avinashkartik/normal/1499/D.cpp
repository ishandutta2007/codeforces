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

const ll   N     =  2e7 + 5;
const ll   mod   =  998244353;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const ll   LEVEL =  log2(N) + 1;

ll c, d, x, p[N];

ll comp(ll g){
	ll l = (x + d * g) / c;
	if((x + d * g) % c != 0 || l % g != 0) return 0;
	return (1 << p[l / g]);
}

void solve() {
	cin >> c >> d >> x;
	ll ans = 0;
	for(ll i = 1; i * i <= x; i++) {
		if(x % i != 0) continue;
		ans += comp(i);
		if(i * i != x) ans += comp(x / i);
	}
	deb1(ans)
}

int main() {
	GODSPEED;
	mset(p, 0);
	for (int i = 2; i < N; i++) {
		if (p[i]) continue;
		for (int j = 2 * i; j < N; j += i) {
			p[j]++;
		}
	}
	for (int i = 2; i < N; i++) if (p[i] == 0) p[i] = 1;
	int test = 1;
	cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}