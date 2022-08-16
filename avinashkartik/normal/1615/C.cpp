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
const int  LEVEL =  log2(N) + 1;

int n;
string a, b;

void solve() {
	cin >> n >> a >> b;
	int s = 0, d = 0, fs = 0, fd = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] == b[i]) {
			s++;
			fs += (a[i] == '1');
		} else {
			d++;
			fd += (a[i] == '1');
		}
	}
	if (s < d) {
		if (s&1 && fs == (s + 1) / 2) deb1(s)
		else if(d % 2 == 0 && fd == (d + 1) / 2) deb1(d)
		else deb1(-1)
	} else {
		if (d % 2 == 0 && fd == (d + 1) / 2) deb1(d)
		else if(s&1 && fs == (s + 1) / 2) deb1(s)
		else deb1(-1)
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