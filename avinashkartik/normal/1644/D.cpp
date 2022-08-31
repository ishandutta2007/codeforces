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

const ll   N     =  2e5 + 5;
const ll   mod   =  998244353;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll n, m, k, q, x[N], y[N];
int vx[N], vy[N];

void solve() {
	cin >> n >> m >> k >> q;
	int ctx = 0, cty = 0;
	for (int i = 1; i <= q; i++) cin >> x[i] >> y[i];
	ll ans = 1;
	for (int i = q; i >= 1; i--) {
		if (vx[x[i]] && vy[y[i]]) continue;
		if (ctx == n || cty == m) continue;
		
		ctx -= vx[x[i]];
		cty -= vy[y[i]];
		vx[x[i]] = 1;
		vy[y[i]] = 1;
		ctx += vx[x[i]];
		cty += vy[y[i]];
		
		ans = (ans * k) % mod;
	}
	deb1(ans)
	
	for (int i = 1; i <= q; i++) vx[x[i]] = 0, vy[y[i]] = 0;
}

int main() {
	GODSPEED;
	int test = 1;
	cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}