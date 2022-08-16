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

const ll   N     =  1e3 + 5;
const ll   mod   =  1e9 + 7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

int n, m, a[N][N], vis[N][N], paint[N][N];

void solve() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
		}
	}
	
	queue <pair <int, int>> q;
	vector <tuple <int, int, int>> ans;
	
	auto check = [&](int i, int j) {
		if (i == 0 || i == n) return;
		if (j == 0 || j == m) return;
		int c = max({a[i][j], a[i + 1][j], a[i][j + 1], a[i + 1][j + 1]});
		if (!c) return;
		for (int ii = i; ii <= i + 1; ii++) {
			for (int jj = j; jj <= j + 1; jj++) {
				if (a[ii][jj] && a[ii][jj] != c) return;
			}
		}
		if (!paint[i][j]) {
			paint[i][j] = 1;
			q.push({i, j});
			ans.pb({i, j, c});
		}
	};
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			check(i, j);
		}
	}
	
	while (q.size()) {
		auto [i, j] = q.front();
		q.pop();
		for (int ii = i; ii <= i + 1; ii++) {
			for (int jj = j; jj <= j + 1; jj++) {
				vis[ii][jj] = 1;
				a[ii][jj] = 0;
			}
		}
		
		for (int ii = i - 1; ii <= i + 1; ii++) {
			for (int jj = j - 1; jj <= j + 1; jj++) {
				check(ii, jj);
			}
		}
	}
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (!vis[i][j]) {
				deb1(-1)
				return;
			}
		}
	}
	
	reverse(all(ans));
	deb1(ans.size())
	for (auto [i, j, c] : ans) deb3(i, j, c)
}

int main() {
	GODSPEED;
	int test = 1;
	// cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}