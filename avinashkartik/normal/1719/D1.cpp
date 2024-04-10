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

ll n, a[N], b[N];

void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		b[i] = a[i];
	}
	
	int l = n, r = n;
	map <int, int> pre, suf;
	pre[0] = suf[0] = 1;
	a[0] = b[n + 1] = 0;
	
	for (int i = 1; i <= n; i++) {
		a[i] ^= a[i - 1];
		if (pre[a[i]]) {
			l--;
			pre.clear();
			a[i] = 0;
			pre[0] = 1;
		} else {
			pre[a[i]] = 1;
		}
	}
	for (int i = n; i >= 1; i--) {
		b[i] ^= b[i + 1];
		if (suf[b[i]]) {
			suf.clear();
			suf[0] = 1;
			b[i] = 0;
			r--;
		} else {
			suf[b[i]] = 1;
		}
	}
	deb1(min(l, r))
}

int main() {
	GODSPEED;
	int test = 1;
	cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}