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

ll n, q, a[N];

void solve() {
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	
	vector <pair <int, int>> w(n + 1, {INFi, -INFi});
	for (int i = 1, j = 1, k = 2; i < n; i++) {
		if (a[j] > a[k]) {
			w[j].f = min(w[j].f, i);
			w[k].s = max(w[k].s, i - 1);
			k = i + 2;
		} else {
			w[k].f = min(w[k].f, i);
			w[j].s = max(w[j].s, i - 1);
			j = i + 2;
		}
	}
	
	for (int i = 1; i <= q; i++) {
		int idx, k; cin >> idx >> k;
		if (a[idx] == n) {
			deb1(max(0, k - w[idx].f + 1))
		} else {
			deb1(max(0, min(w[idx].s, k) - w[idx].f + 1))
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