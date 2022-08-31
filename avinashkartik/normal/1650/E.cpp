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

int n, d, a[N];

bool check(int ind, int x) {
	vector <int> v;
	for (int i = 1; i <= n; i++) {
		if (i == ind) continue;
		v.pb(a[i]);
	}
	
	if (v[0] - 1 < x) return 0;
	for (int i = 0; i < v.size() - 1; i++) {
		if (v[i + 1] - v[i] - 1 < x) return 0;
	}
	
	if (d - v.back() - 1 >= x) return 1;
	if (v[0] - 1 >= 2 * x + 1) return 1;
	for (int i = 0; i < v.size() - 1; i++) {
		if (v[i + 1] - v[i] - 1 >= 2 * x + 1) return 1;
	}
	
	return 0;
}

int f(int x) {
	set <int> s;
	for (int i = 0; i < n; i++) {
		if (a[i + 1] - a[i] - 1 < x) {
			s.insert(i);
			s.insert(i + 1);
		}
	}
	if (s.size() > 3) return 0;
	if (s.size() == 0) return 1;
	int f = 0;
	for (auto it : s) {
		if (it == 0 || it == n + 1) continue;
		f |= check(it, x);
	}
	return f;
}

void solve() {
	cin >> n >> d;
	for (int i = 1; i <= n; i++) cin >> a[i];
	a[0] = 0, a[n + 1] = d;
	int l = 1, r = 1e9, ans = 0;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (f(mid)) {
			ans = mid;
			l = mid + 1;
		} else r = mid - 1;
	}
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