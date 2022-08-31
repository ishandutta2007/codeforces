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

const int   N    =  5e3 + 1;
const ll   mod   =  1e9 + 7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ld c, m, p, v;

ld recurse(ld c, ld m, ld p, ld mv) {
	ld ans = p * mv;
	for (int i = 0; i < 2; i++) {
		if (c - v > 1e-9) {
			if (!m) ans += recurse(c - v, 0, p + v, mv + 1) * c;
			else ans += recurse(c - v, m + v / 2, p + v / 2, mv + 1) * c;
		} else if (c > 1e-9) {
			if (!m) ans += recurse(0, 0, p + c, mv + 1) * c;
			else ans += recurse(0, m + c / 2, p + c / 2, mv + 1) * c;
		}
		swap(m, c);
	}
	return ans;
}

void solve() {
	cin >> c >> m >> p >> v;
	deb1(recurse(c, m, p, 1.0))
}

int main() {
	GODSPEED;
	int test = 1;
	cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}