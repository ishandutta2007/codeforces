#ifdef ONLINE_JUDGE
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops, no-stack-protector")
#pragma GCC target("avx,avx2,fma")
#define NDEBUG
#endif

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

const ll   N     =  3e5 + 5;
const ll   mod   =  998244353;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const ll   LEVEL =  log2(N) + 1;

int n, m, l, r, q;

void solve() {
	cin >> n >> m;
	vector <int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(all(a));
	for (int i = 1; i <= n; i++) {
		if (a[i] == a[i - 1]) a[i] = a[i - 1] = 0;
	}
	sort(all(a));
	cin >> q;
	for (int i = 0; i < q; i++) {
		cin >> l >> r;
		int lb = lower_bound(all(a), l) - a.begin();
		int rb = upper_bound(all(a), r) - a.begin();
		int ans = 0;
		for (int i = lb; i < rb; i++) ans ^= (a[i] - l);
		cout << "AB"[ans == 0];
	}
	newl;
}

int main() {
	GODSPEED;
	int test = 1;
	// cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}