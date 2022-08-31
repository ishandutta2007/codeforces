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

const ll   N     =  1e5 + 5;
const ll   mod   =  998244353;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const ll   LEVEL =  log2(N) + 1;

ll a, b;
string s;

void solve() {
	cin >> a >> b >> s;
	int n = s.size();
	for(int i = 0; i < n; i++) {
		if(s[i] == '0') a--;
		if(s[i] == '1') b--;
	}
	for(int i = 0; i < n; i++) {
		if(s[i] == '0' && s[n - i - 1] == '?') {
			s[n - i - 1] = '0';
			a--;
		}
		if(s[i] == '1' && s[n - i - 1] == '?') {
			s[n - i - 1] = '1';
			b--;
		}
	}
	for(int i = 0; i < n; i++) {
		if(s[i] == '?' && s[n - i - 1] == '?') {
			if(a > b) {
				s[i] = s[n - i - 1] = '0';
				a -= 2;
				if(i == n - i - 1) a++;
			} else {
				s[i] = s[n - i - 1] = '1';
				b -= 2;
				if(i == n - i - 1) b++;
			}
		}
	}
	if(a or b) {
		deb1(-1)
		return;
	}
	for(int i = 0; i < n; i++) {
		if(s[i] != s[n - i - 1]) {
			deb1(-1)
			return;
		}
	}
	deb1(s)
}

int main() {
	GODSPEED;
	int test = 1;
	cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}