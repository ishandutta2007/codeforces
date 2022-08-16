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

const ll   N     =  2e5 + 5;
const ll   mod   =  1e9 + 7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const ll   LEVEL =  log2(N) + 1;

ll n, m;
string s;

void calc(int a, int b) {
	deb2(1 - b, 1 - a);
}

void solve() {
	cin >> n >> m;
	cin >> s;
	int mxh = 0, mxv = 0, mnh = 0, mnv = 0, h = 0, v = 0;
	for (auto it : s) {
		if (it == 'L') {
			h -= 1;
			mnh = min(mnh, h);
			if (mxh - mnh >= m) {
				mnh++;
				calc(mnh, mnv);
				return;
			}
		}
		if (it == 'R') {
			h += 1;
			mxh = max(mxh, h);
			if (mxh - mnh >= m) {
				mxh--;
				calc(mnh, mnv);
				return;
			}
		}
		if (it == 'U') {
			v -= 1;
			mnv = min(mnv, v);
			if (mxv - mnv >= n) {
				mnv++;
				calc(mnh, mnv);
				return;
			}
		}
		if (it == 'D') {
			v += 1;
			mxv = max(mxv, v);
			if (mxv - mnv >= n) {
				mxv--;
				calc(mnh, mnv);
				return;
			}
		}
		// deb2(mnv, mxv)
	}
	calc(mnh, mnv);
}

int main() {
	GODSPEED;
	int test = 1;
	cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}