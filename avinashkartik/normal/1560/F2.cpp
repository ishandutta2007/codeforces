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
const ll   mod   =  1e9 + 7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const ll   LEVEL =  log2(N) + 1;

ll k, flag = 0;
string n;

void mem(int i, int j, int f, ll ans) {
	if (i == n.size()) {
		if (!flag) deb1(ans)
		flag = 1;
		return;
	}
	int no = __builtin_popcount(j);
	for (int ii = 0; ii <= 9; ii++) {
		if (flag) return;
		char ch = ii + '0';
		if (f == 1 && ch < n[i]) continue;
		int is_set = (j >> ii)&1;
		if (is_set == 1) {
			mem(i + 1, j, f&(ch == n[i]), ans * 10 + ii);
		} else if (no < k) {
			mem(i + 1, j + (1 << ii), f&(ch == n[i]), ans * 10 + ii);
		}
	}
}

void solve() {
	cin >> n >> k;

	flag = 0;
	mem(0, 0, 1, 0);
}

int main() {
	GODSPEED;
	int test = 1;
	cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}