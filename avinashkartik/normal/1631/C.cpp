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

int n, k;

void solve() {
	cin >> n >> k;
	set <pair <int, int>> s;
	for (int i = 0; i < n / 2; i++) {
		s.insert({i, n - i - 1});
	}
	
	if (k != n - 1) {
		s.erase({0, n - 1});
		s.erase({min(k, n - k - 1), max(k, n - k - 1)});
		s.insert({0, n - k - 1});
		s.insert({k, n - 1});
		
		for (auto it : s) deb2(it.f, it.s)
	} else {
		if (n == 4) {
			deb1(-1)
			return;
		}
		s.erase({0, n - 1});
		s.erase({1, n - 2});
		s.erase({2, n - 3});
		s.insert({n - 2, n - 1});
		s.insert({1, n - 3});
		s.insert({0, 2});
		
		for (auto it : s) deb2(it.f, it.s)
	}
}

int main() {
	GODSPEED;
	int test = 1;
	cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}