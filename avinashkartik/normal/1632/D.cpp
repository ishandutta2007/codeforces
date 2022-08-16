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

int n, a[N];

void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	map <int, set <int>> m;
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		vector <int> e;
		for (auto &[div, s] : m) {
			int ng = __gcd(div, a[i]);
			if (ng == div) continue;
			for (auto it : s) m[ng].insert(it);
			s.clear();
		}
		int f = 0;
		m[a[i]].insert(i);
		for (auto &[div, s] : m) {
			while (s.size() && i - *s.begin() + 1 > div) {
				s.erase(s.begin());
			}
			if (s.size()) {
				if (i - *s.begin() + 1 == div) f = 1;
			}
			if (s.size() == 0) e.pb(div);
		}
		for (auto it : e) m.erase(it);
		if (f == 1) {
			ans++;
			m.clear();
		}
		cout << ans << " ";
	}
	
}

int main() {
	GODSPEED;
	int test = 1;
	// cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}