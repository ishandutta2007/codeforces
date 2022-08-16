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

const int   N    =  5e5 + 5;
const ll   mod   =  1e9 + 7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll n, k;

int s(int a, int b) {
	int c = 0, p = 1;
	while (a || b) {
		int c1 = (a % k - b % k + k) % k;
		c += c1 * p;
		p *= k;
		a /= k;
		b /= k;
	}
	return c;
}

int a(int a, int b) {
	int c = 0, p = 1;
	while (a || b) {
		int c1 = (a % k + b % k + k) % k;
		c += c1 * p;
		p *= k;
		a /= k;
		b /= k;
	}
	return c;
}

void solve() {
	cin >> n >> k;
	int cur = 0, prv = 0, c = 0;
	for (int i = 0; i < n; i++) {
		if (i) {
			c = s(prv, cur);
			cur = c;
			if (i&1) c = s(c, i);
			else c = a(c, i);
		}
		cout << c << endl;
		int x; cin >> x;
		if (x == -1) exit(0);
		if (x == 1) return;
		prv = c;
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