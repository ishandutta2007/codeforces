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

const ll   N     =  2e3 + 5;
const ll   mod   =  1e9 + 7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

int n, m, q;
string s[N];

void solve() {
	cin >> n >> m >> q;
	for (int i = 0; i < n; i++)  cin >> s[i];
	int ct = 0, f = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			ct += (s[i][j] == '*');
		}
	}
	
	int cnt = ct;
	for (int j = 0; j < m; j++) {
		for (int i = 0; i < n; i++) {
			if (cnt == 0) break;
			f += (s[i][j] == '.');
			cnt--;
		}
	}
	
	auto add = [&](int i, int j) {
		s[i][j] = '*';
		ct++;
		int r = (ct - 1) % n, c = (ct - 1) / n;
		f += (s[r][c] == '.');
		if (j < c || (j == c && i < r)) {
			f--;
		}
	};
	
	auto rem = [&](int i, int j) {
		s[i][j] = '.';
		int r = (ct - 1) % n, c = (ct - 1) / n;
		ct--;
		f -= (s[r][c] == '.');
		if (j < c || (j == c && i <= r)) {
			f++;
		}
	};
	
	for (int i = 1; i <= q; i++) {
		int x, y; cin >> x >> y;
		x--, y--;
		if (s[x][y] == '.') add(x, y);
		else rem(x, y);
		deb1(f)
	}
}

int main() {
	GODSPEED;
	int test = 1;
	// cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}