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

const ll   N     =  1e3 + 2;
const ll   mod   =  998244353;
const ll   INF   =  1e18;
const int  INFi  =  0x7f7f7f7f;
const int  LEVEL =  log2(N) + 1;

int n, x, p = 0, res = 0;

int f(int c) {
	if (c == n) return 1;
	if (c > n) c -= n;
	cout << "+ " << c << endl;
	res += c;
	int x; cin >> x;
	if (x > p) {
		p++;
		return 1;
	}
	return 0;
}

void solve() {
	cin >> n;
	int l = 1, r = n - 1, add = 0, ans = 0;
	while (l <= r) {
		int mid = (l + r) / 2;
		int c = mid + (n - add) % n;
		add = (add + c) % n;
		if (f(c)) {
			ans = mid;
			r = mid - 1;
		} else l = mid + 1;
	}
	cout << "! " << n - ans + res << endl;
}

int main() {
	GODSPEED;
	int test = 1;
	// cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}