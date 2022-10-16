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
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) cin >> b[i];
	ll mx0 = -INF, mn0 = INF, mx1 = -INF, mn1 = INF;
	for (int i = 1; i <= n; i++) {
		if (a[i] < b[i]) {
			deb1("NO")
			return;
		}
		if (b[i] == 0) {
			mx0 = max(mx0, a[i] - b[i]);
			mn0 = min(mn0, a[i] - b[i]);
		} else {
			mx1 = max(mx1, a[i] - b[i]);
			mn1 = min(mn1, a[i] - b[i]);
		}
	}
	if (mx1 == -INF) mx1 = INF;
	if (mx0 > mx1 || mn1 != mx1) {
		deb1("NO")
	} else deb1("YES")
}

int main() {
	GODSPEED;
	int test = 1;
	cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}