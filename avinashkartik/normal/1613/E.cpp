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

ll n, m;
string s[N];

void solve() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> s[i];
		s[i] = '#' + s[i] + '#';
	}
	s[0] = s[n + 1] = string(m + 2, '#');
	queue <pll> q;
	for (int i = 1; i <= n;i++) {
		for (int j = 1; j <= m; j++ ){
			if (s[i][j] == 'L') q.push({i, j});
		}
	}

	auto check = [&](int i, int j) {
		if (s[i][j] != '.') return 0;
		int cnt = 0;
		cnt += (s[i - 1][j] == '.');
		cnt += (s[i + 1][j] == '.');
		cnt += (s[i][j - 1] == '.');
		cnt += (s[i][j + 1] == '.');
		if (cnt <= 1) return 1;
		return 0;
	};

	while (q.size()) {
		auto it = q.front(); q.pop();
		if (s[it.f][it.s] == '.') s[it.f][it.s] = '+';
		if (check(it.f - 1, it.s)) q.push({it.f - 1, it.s});
		if (check(it.f + 1, it.s)) q.push({it.f + 1, it.s});
		if (check(it.f, it.s - 1)) q.push({it.f, it.s - 1});
		if (check(it.f, it.s + 1)) q.push({it.f, it.s + 1});
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++ ){
			cout << s[i][j];
		}
		newl;
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