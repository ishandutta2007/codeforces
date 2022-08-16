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

ll n, a[N], ind[N];
string s[N];

void solve() {
	cin >> n;
	map <int, int> mx, my;
	for (int i = 1; i <= n; i++) cin >> s[i];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (s[i][j - 1] == '*') {
				mx[i]++;
				my[j]++;
			}
		}
	} 
	int x = 0, x2 = 0, y = 0, y2 = 0;
	if(mx.size() == 1) {
		if(mx[1] == 2) x = x2 = 2;
		else x = x2 = 1;
	} else {
		for(auto it : mx) {
			if(x == 0) x = it.f;
			else x2 = it.f;
		}
	}
	if(my.size() == 1) {
		if(my[1] == 2) y = y2 = 2;
		else y = y2 = 1;
	} else {
		for(auto it : my) {
			if(y == 0) y = it.f;
			else y2 = it.f;
		}
	}
	if(s[x][y - 1] == '*') swap(y, y2);
	s[x][y - 1] = '*';
	s[x2][y2 - 1] = '*';
	for (int i = 1; i <= n; i++) deb1(s[i])
}

int main() {
	GODSPEED;
	int test = 1;
	cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}