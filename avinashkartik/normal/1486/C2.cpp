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

const ll   N     =  1005;
const ll   mod   =  998244353;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const ll   LEVEL =  log2(N) + 1;

ll n, x[N], y[N];
map <pll, int> m;

int q(int l, int r){
	if(m[{l, r}]) return m[{l, r}];
	cout << "? " << l << " " << r << endl;
	int x;
	cin >> x;
	m[{l, r}] = x;
	return x;
}

void solve() {
	cin >> n;
	int l = 1, r = n, ans;
	int x = q(1, n);
	if(x == 1 || q(1, x) != x) {
		l = x + 1;
		while(l <= r) {
			int mid = (l + r) / 2;
			if(q(x, mid) != x) l = mid + 1;
			else {
				ans = mid;
				r = mid - 1;
			}
		}
	} else {
		r = x - 1;
		while(l <= r) {
			int mid = (l + r) / 2;
			if(q(mid, x) != x) r = mid - 1;
			else {
				ans = mid;
				l = mid + 1;
			}
		}
	}
	cout << "! " << ans << endl;
}

int main() {
	GODSPEED;
	int test = 1;
	//cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}