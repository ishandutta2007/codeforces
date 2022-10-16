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

const ll   N     =  105;
const ll   mod   =  1e9 + 7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

int n, a[N], dp[4][4][2][2];

int mem(int z, int o, int b = 0, int f = 0) {
	int &ans = dp[z][o][b][f];
	if (z + o == 0) return ans = b == 0;
	if (ans != -1) return ans;
	if (f == 0) {
		if (z && mem(z - 1, o, b, 1 - f) == 1) ans = 1;
		else if (o && mem(z, o - 1, 1 - b, 1 - f) == 1) ans = 1;
		else ans = 0; 
	} else {
		if (z && mem(z - 1, o, b, 1 - f) == 0) ans = 0;
		else if (o && mem(z, o - 1, b, 1 - f) == 0) ans = 0;
		else ans = 1;
	}
	return ans;
}

void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i], a[i] = abs(a[i]) % 2;
	int ones = accumulate(a + 1, a + n + 1, 0);
	if (dp[(n - ones) % 4][ones % 4][0][0] == 1) deb1("Alice")
	else deb1("Bob")
}

int main() {
	GODSPEED;
	
	mset(dp, -1);
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			mem(i, j);
		}
	}
	
	int test = 1;
	cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}