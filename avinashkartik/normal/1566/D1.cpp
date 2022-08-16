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

const ll   N     =  4e5 + 5;
const ll   mod   =  1e9 + 7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const ll   LEVEL =  log2(N) + 1;

ll n, m, a[N];

void solve() {
	cin >> n >> m;
	vector <int> cc;
	for (int i = 0; i < n * m; i++) cin >> a[i], cc.pb(a[i]);
	sort(all(cc));
	uniq(cc);
	for (int i = 0; i < n * m; i++) a[i] = lower_bound(all(cc), a[i]) - cc.begin();
	
	vector <int> indd(n * m), ind(n * m);
	iota(all(indd), 0);
	sort(all(indd), [&](int i, int j){
		return a[i] < a[j];
	});
	for (int i = 0; i < n * m; i++) {
		ind[indd[i]] = i;
	}
	
	int l = cc.size();
	vector <vector <int>> wh(l), s(n, vector <int>(m, 0));
	for (int i = 0; i < n * m; i++) {
		// deb2(a[i], ind[i])
		wh[a[i]].pb(ind[i]);
	}
	for (int i = 0; i < l; i++) {
		sort(all(wh[i]), [&](int i, int j){
			int r1 = i / m, c1 = i % m;
			int r2 = j / m, c2 = j % m;
			if (r1 == r2) return c1 < c2;
			return r1 > r2;
		});
	}

	int ans = 0;
	for (int i = 0; i < n * m; i++) {
		int ii = wh[a[i]].back();
		wh[a[i]].pop_back();
		// deb1(ii)
		int r = ii / m, c = ii % m;
		for (int j = 0; j < c; j++) ans += s[r][j];
		s[r][c] = 1;
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