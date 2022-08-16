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

const ll   N     =  605;
const ll   mod   =  1e9 + 7;
const ll   INF   =  1e16;
const int  INFi  =  0x7f7f7f7f;
const int  LEVEL =  log2(N) + 1;

ll n, c[N][N];

void solve() {
	cin >> n;
	int m = 2 * n;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			cin >> c[i][j];
		}
	}
	ll ans = 0;
	for (int i = m - n; i < m; i++) {
		for (int j = m - n; j < m; j++) {
			ans += c[i][j];
			c[i][j] = 0;
		}
	}

	ll res = min({c[n][0], c[m - 1][0], c[n][n - 1], c[m - 1][n - 1], c[0][n], c[0][m - 1], c[n - 1][n], c[n - 1][m - 1]});

	deb1(res + ans)
}

int main() {
	GODSPEED;
	int test = 1;
	cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}