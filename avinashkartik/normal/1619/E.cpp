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

const ll   N     =  1e6 + 5;
const ll   mod   =  998244353;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const int  LEVEL =  log2(N) + 1;

int n, a[N];

void solve() {
	cin >> n;
	vector <int> ct(n + 1, 0), b(n, -1);
	multiset <int> s;
	for (int i = 0; i < n; i++) cin >> a[i], ct[a[i]]++, s.insert(a[i]);
	for (int i = 0, j = 0; i < n; i++) {
		auto it = s.upper_bound(i);
		if (it != s.begin()) it--;
		b[i] = *it;
		s.erase(it);
	}
	vector <ll> ans(n + 1, -1);
	ll res = 0, f = 1;
	for (int i = 0; i < n; i++) {
		ans[i] = res + ct[i];
		res += i - b[i];
		if (b[i] > i) {
			f = 0;
			break;
		}
	}
	if (f == 1) {
		ans[n] = res;
	}
	debv(ans)
}

int main() {
	GODSPEED;
	int test = 1;
	cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}