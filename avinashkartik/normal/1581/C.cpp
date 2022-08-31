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

const ll   N     =  405;
const ll   mod   =  1e9 + 7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const ll   LEVEL =  log2(N) + 1;

ll n, m, p[N][N];
string s[N];

void solve() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> s[i];
		s[i] = '#' + s[i] + '#';
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			p[i][j] = p[i - 1][j] + p[i][j - 1] - p[i - 1][j - 1];
			if (s[i][j] == '1') p[i][j]++;
		}
	}

	auto sum = [&](int i1, int j1, int i2, int j2) {
		return p[i2][j2] - p[i1 - 1][j2] - p[i2][j1 - 1] + p[i1 - 1][j1 - 1];
	};

	auto top = [&](int i, int j1, int j2) {
		return j2 - j1 - 1 - sum(i, j1 + 1, i, j2 - 1) - (sum(1, j1 + 1, i, j2 - 1) + 2 * i - sum(1, j1, i, j1) - sum(1, j2, i, j2));
	};

	auto bottom = [&](int i, int j1, int j2) {
		return sum(1, j1 + 1, i - 1, j2 - 1) + 2 * (i - 1) - sum(1, j1, i - 1, j1) - sum(1, j2, i - 1, j2) + j2 - j1 - 1 - sum(i, j1 + 1, i, j2 - 1);
	};

	ll ans = INF;
	for (int j1 = 1; j1 <= m; j1++) {
		for (int j2 = j1 + 3; j2 <= m; j2++) {
			ll mn = INF;
			for (int i = n - 4; i >= 1; i--) {
				mn = min(mn, bottom(i + 4, j1, j2));
				ans = min(ans, mn + top(i, j1, j2));
			}
		}
	}
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