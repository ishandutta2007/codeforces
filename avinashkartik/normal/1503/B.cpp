#include<bits/stdc++.h>

using namespace std;

#define  f              first                 
#define  s              second
#define  pb             push_back  
#define  mset(a,x)      memset(a,x,sizeof(a))
#define  debv(a)        for(auto it: a)cout<<it<<" ";cout<<endl;
#define  deb1(a)        cout<<a<<endl;
#define  deb2(a,b)      cout<<a<<" "<<b<<endl;
#define  deb3(a,b,c)    cout<<a<<" "<<b<<" "<<c<<endl;
#define  deb4(a,b,c,d)  cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;


typedef  long long             ll;
typedef  long double           ld;
typedef  pair<ll, ll>           pll;
typedef  vector<ll>            vll;
typedef  vector<pll>           vpll;

const ll   N     =  2e5 + 5;
const ll   mod   =  998244353;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const ll   LEVEL =  log2(N) + 1;

ll n;

void solve() {
	cin >> n;
	vector <pll> o, e;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			if((i + j) % 2 == 0) e.pb({i, j});
			else o.pb({i, j});
		}
	}
	for(int i = 1; i <= n * n; i++) {
		int c; cin >> c;
		if(c != 2 && o.size()) {
			deb3(2, o.back().f, o.back().s);
			o.pop_back();
		} else if(c != 1 && e.size()) {
			deb3(1, e.back().f, e.back().s);
			e.pop_back();
		} else if(o.size()) {
			if(c == 2) {
				deb3(3, o.back().f, o.back().s);
				o.pop_back();
			} else {
				deb3(3, o.back().f, o.back().s);
				o.pop_back();
			}
		} else {
			if(c == 1) {
				deb3(3, e.back().f, e.back().s);
				e.pop_back();
			} else {
				deb3(1, e.back().f, e.back().s);
				e.pop_back();
			}
		}
	}
}

int main() {
	int test = 1;
	//cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}