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
typedef  pair<ll, ll>          pll;
typedef  vector<ll>            vll;
typedef  vector<pll>           vpll;

const ll   N     =  1e6 + 5;
const ll   mod   =  998244353;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const ll   LEVEL =  log2(N) + 1;

int n, a[N][5];

bool check(int x, int y) {
	vector <int> vis(n + 1);
	int ct1 = 0, ct2 = 0;
	for (int i = 1; i <= n; i++) {
		vis[i] |= a[i][x];
		ct1 += a[i][x];
	}
	for (int i = 1; i <= n; i++) {
		vis[i] |= a[i][y];
		ct2 += a[i][y];
	}
	int total = accumulate(all(vis), 0);
	return total == n && ct1 >= n / 2 && ct2 >= n / 2;
}

void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 5; j++) {
			cin >> a[i][j];
		}
	}
	bool f = 0;
	for (int i = 1; i <= 5; i++) {
		for (int j = i + 1; j <= 5; j++) {
			f |= check(i, j);
		}
	}
	if (f) deb1("YES")
	else deb1("NO")
}

int main() {
	GODSPEED;
	int test = 1;
	cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}