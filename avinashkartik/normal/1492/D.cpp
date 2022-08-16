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

const ll   N     =  605;
const ll   mod   =  998244353;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const ll   LEVEL =  log2(N) + 1;

int a, b, k;

void solve() {
	cin >> a >> b >> k;
	if ((b < 2 || a == 0) && k) {
		deb1("NO")
		return;
	}
	string s, t;
	s += '1';
	t += '1';
	b--;
	if (k) {
		b--;
		a--;
		s += '1';
		t += '0';
		for (int i = 1; i < k; i++) {
			if (b) {
				s += '1';
				t += '1';
				b--;
			} else if (a) {
				s += '0';
				t += '0';
				a--;
			} else {
				deb1("NO")
				return;
			}
		}
		s += '0';
		t += '1';
	}
	while (a + b) {
		if (b) {
			s += '1';
			t += '1';
			b--;
		} else if (a) {
			s += '0';
			t += '0';
			a--;
		}
	}
	deb1("YES")
	deb1(s)
	deb1(t)
}

int main() {
	GODSPEED;
	int test = 1;
	//cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}