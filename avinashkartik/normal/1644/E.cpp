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
const ll   mod   =  998244353;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll n;
string s;

void solve() {
	cin >> n >> s;
	ll d = count(all(s), 'D') + 1, r = count(all(s), 'R') + 1;
	if (d == 1 || r == 1) {
		deb1(n)
		return;
	}
	s = s + s.back();
	ll dd = 0, rr = 0, last = 0;
	ll ans = 0;
	for (int i = 0; i < s.size(); i++) {
		ans++;
		if (s[i] != s[i + 1]) break;
	}
	for (int i = s.size() - 2; i >= 0; i--) {
		if (s[i] != s[i + 1]) {
			if (s[i] == 'R') {
				if (last) ans += (last - i) * (n - rr - r + 1);
				else ans += (n - d + 1) * (n - r + 1);
			} else {
				if (last) ans += (last - i) * (n  - dd - d + 1);
				else ans += (n - d + 1) * (n - r + 1);
			}
			last = i;
		}
		if (s[i] == 'D') d--, dd++;
		else r--, rr++;
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