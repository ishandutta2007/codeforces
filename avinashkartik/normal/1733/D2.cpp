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

const ll   N     =  5e3 + 5;
const ll   mod   =  1e9 + 7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll n, x, y, dp[N][N];
string a, b;

ll mem(int i, int j) {
	if (i == n) return j == n? 0 : y;
	if (dp[i][j] != -1) return dp[i][j];
	dp[i][j] = INF;
	if (j == n) {
		if (a[i] == b[i]) dp[i][j] = mem(i + 1, j);
		else dp[i][j] = mem(i + 1, i);
	} else {
		if (a[i] == b[i]) dp[i][j] = min(mem(i + 1, i) + 2 * x, mem(i + 1, n) + y);
		else dp[i][j] = mem(i + 1, n) + 2 * x;;
	}
	return dp[i][j];
}

void solve() {
	cin >> n >> x >> y;
	cin >> a >> b;
	vector <int> v;
	for (int i = 0; i < n; i++) {
		if (a[i] != b[i]) v.pb(i);
	}
	if ((ll)v.size() % 2 == 1) {
		deb1(-1)
		return;
	}
	if (x >= y) {
		if (v.size() == 2) {
			if (v[0] + 1 == v[1]) deb1(min(2 * y, x))
			else deb1(y)
		} else deb1((ll)v.size() / 2 * y)
	} else {
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= n; j++) {
				dp[i][j] = -1;
			}
		}
		deb1(mem(0, n) / 2)
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