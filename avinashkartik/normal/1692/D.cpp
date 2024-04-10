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

const ll   N     =  1e5 + 5;
const ll   mod   =  1e9 + 7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

int t;
string s;

int is_pal(int h, int m) {
	string hh = h < 10? '0' + to_string(h) : to_string(h);
	string mm = m < 10? '0' + to_string(m) : to_string(m);
	if (hh[0] == mm[1] && hh[1] == mm[0]) return 1;
	return 0;
}

void solve() {
	cin >> s >> t;
	int h = stoi(s.substr(0, 2));
	int m = stoi(s.substr(3, 2));
	int th = h, tm = m, ans = 0;
	do {
		ans += is_pal(th, tm);
		th += t / 60;
		tm += t % 60;
		if (tm >= 60) {
			th++;
			tm %= 60;
		}
		th %= 24;
	} while (th != h || tm != m);
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