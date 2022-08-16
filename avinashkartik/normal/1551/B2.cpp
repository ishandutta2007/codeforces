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
typedef  pair<ll, ll>           pll;
typedef  vector<ll>            vll;
typedef  vector<pll>           vpll;

const ll   N     =  3e5 + 5;
const ll   mod   =  1e9 + 7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const ll   LEVEL =  log2(N) + 1;

int n, k, a[N];
string s;

void solve() {
	cin >> n >> k;
	vector <vector<int>> ct(n + 1);
	vector <vector<int>> ans(n + 1);
	for (int i = 0; i < n; i++) cin >> a[i], ct[a[i]].pb(i);
	int st = 0, no = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < min((int)ct[i].size(), k); j++) {
			ans[no].pb(ct[i][j]);
			st = (st + 1) % k;
			if (st == 0) no++;
		}
	}
	vector <int> res(n, 0);
	for (int i = 0; i <= no; i++) {
		if (ans[i].size() < k) break;
		for (int j = 0; j < k; j++) {
			res[ans[i][j]] = j + 1;
		}
	}
	debv(res)
}

int main() {
	GODSPEED;
	int test = 1;
	cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}