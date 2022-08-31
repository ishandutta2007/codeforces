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
const ll   mod   =  1e9 + 7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll n, p, a[N], f[N], pre[N];
map <int, int> m;

ll calc(int x) {
	int l = log2(x);
	if (l > p) return 0;
	while (x) {
		if (x&1) x /= 2;
		else if (x % 4 == 0) x /= 4;
		else break;
		if (m.find(x) != m.end()) return 0;
	}
	return pre[p - l];
}

void solve() {
	cin >> n >> p;
	for (int i = 1; i <= n; i++) cin >> a[i], m[a[i]]++;
	
	f[1] = f[2] = 1;
	pre[1] = 1, pre[2] = 2;
	for (int i = 3; i <= p + 5; i++) {
		f[i] = (f[i - 1] + f[i - 2]) % mod;
		pre[i] = (pre[i - 1] + f[i]) % mod;
	}
		
	ll ans = 0;
	for (int i = 1; i <= n; i++) ans = (ans + calc(a[i])) % mod;
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