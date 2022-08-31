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

const ll   N     =  2e5 + 5;
const ll   mod   =  998244353;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const ll   LEVEL =  log2(N) + 1;

int n, m, k, vis[20][20];
string s[N];

bool check(int i, int j, int k) {
	for (int ct = 0, x = i, y = j; ct <= k; ct++, x--, y--) {
		if (x == -1 || y == -1 || y == m) return 0;
		if (s[x][y] == '.') return 0;
	}
	for (int ct = 0, x = i, y = j; ct <= k; ct++, x--, y++) {
		if (x == -1 || y == -1 || y == m) return 0;
		if (s[x][y] == '.') return 0;
	}
	return 1;
}

void mark(int i, int j, int k) {
	for (int ct = 0, x = i, y = j; ct <= k; ct++, x--, y--) {
		vis[x][y] = 1;
	}
	for (int ct = 0, x = i, y = j; ct <= k; ct++, x--, y++) {
		vis[x][y] = 1;
	}
}

void solve() {
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) cin >> s[i];
	mset(vis, 0);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int kk = k; kk < 20; kk++) {
				if (check(i, j, kk)) {
					// deb3(i, j, kk)
					mark(i, j, kk);
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (s[i][j] == '*' && vis[i][j] == 0) {
				deb1("NO")
				return;
			}
		}
	}
	deb1("YES")
}

int main() {
	GODSPEED;
	int test = 1;
	cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}