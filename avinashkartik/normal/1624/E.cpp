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

const ll   N     =  1e3 + 2;
const ll   mod   =  998244353;
const ll   INF   =  1e18;
const int  INFi  =  0x7f7f7f7f;
const int  LEVEL =  log2(N) + 1;

int n, m, dp[N], wh[N];
string s[N];
map <string, pair <int, int>> ind;
vector <tuple <int, int, int>> ans;

int mem(int i) {
	if (i == m) return 1;
	if (dp[i] != -1) return dp[i];
	dp[i] = 0;
	if (i < m - 1) {
		string t = s[0].substr(i, 2);
		if (ind.find(t) != ind.end()) {
			dp[i] = mem(i + 2);
			if (dp[i] == 1) wh[i] = 1;
		}
	}
	if (i < m - 2 && !dp[i]) {
		string t = s[0].substr(i, 3);
		if (ind.find(t) != ind.end()) {
			dp[i] = mem(i + 3);
			if (dp[i] == 1) wh[i] = 2;
		}
	}
	return dp[i];
}

void bt(int i) {
	if (i == m) return;
	if (wh[i] == 1) {
		pair <int, int> p = ind[s[0].substr(i, 2)]; 
		ans.pb({p.s + 1, p.s + 2, p.f});
		bt(i + 2);
	} else if (wh[i] == 2) {
		pair <int, int> p = ind[s[0].substr(i, 3)]; 
		ans.pb({p.s + 1, p.s + 3, p.f});
		bt(i + 3);
	}
}

void solve() {

	mset(dp, -1);
	mset(wh, -1);
	ans.clear();
	ind.clear();

	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> s[i];
	cin >> s[0];
	vector <pair <int, int>> mx(m, {-1, -1});
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < m - 1; j++) {
			string t = s[i].substr(j, 2);
			ind[t] = {i, j};
			if (j != m - 2) {
				t = s[i].substr(j, 3);
				ind[t] = {i, j};
			}
		}
	}
	int x = mem(0);
	if (x == 0) {
		deb1(-1)
		return;
	}
	bt(0);
	deb1(ans.size())
	for (auto [x, y, z] : ans) deb3(x, y, z)
}

int main() {
	GODSPEED;
	int test = 1;
	cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}