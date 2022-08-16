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

const ll   N     =  1e5 + 5;
const ll   mod   =  1e9 + 7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const ll   LEVEL =  log2(N) + 1;

int n, a[N];

bool check(int ind) {
	map <int, int> m;
	for (int j = 1; j <= 2 * n; j++) {
		if (ind == j) continue;
		m[a[j]]++;
	}
	vector <pll> ans;
	ans.pb({a[1], a[ind]});
	int tmp = a[ind];
	a[ind] = 0;
	sort (a + 1, a + 2 * n + 1, greater<>());
	int mx = a[1];
	for (int i = 2; i <= 2 * n; i++) {
		if (m[a[i]] == 0) continue;
		m[a[i]]--;
		if (m[mx - a[i]] == 0) {
			a[2 * n] = tmp;
			return 0;
		}
		m[mx - a[i]]--;
		ans.pb({a[i], mx - a[i]});
		mx = max(a[i], mx - a[i]);
	}
	deb1("YES")
	deb1(a[1] + tmp)
	for (auto it : ans) deb2(it.f, it.s)
	return 1;
}

void solve() {
	cin >> n;
	for (int i = 1; i <= 2 * n; i++) cin >> a[i];
	for (int i = 2; i <= 2 * n; i++) {
		sort (a + 1, a + 2 * n + 1, greater<>());
		if (check(i) == 1) return;
	}
	deb1("NO")
}

int main() {
	GODSPEED;
	int test = 1;
	cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}