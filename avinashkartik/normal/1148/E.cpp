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
const ll   mod   =  998244353;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const ll   LEVEL =  log2(N) + 1;

ll n, s[N], t[N];

void solve() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> s[i];
	for (int i = 0; i < n; i++) cin >> t[i];
	if (accumulate(s, s + n, 0ll) != accumulate(t, t + n, 0ll)) {
		deb1("NO")
		return;
	}
	sort(t, t + n);
	vpll v;
	for (int i = 0; i < n; i++) v.pb({s[i], i});
	sort(all(v));
	vpll l, r;
	for (int i = 0; i < n; i++) {
		if (v[i].f > t[i]) r.pb({i, v[i].s});
		else l.pb({i, v[i].s});
	}
	vector <tuple<int, int, ll>> ans;
	int i = 0, j = 0;
	for (; i < l.size() && j < r.size();) {
		if (s[l[i].s] >= s[r[j].s]) {
			deb1("NO")
			return;
		}
		if (s[r[j].s] - t[r[j].f] > t[l[i].f] - s[l[i].s]) {
			ans.pb({l[i].s, r[j].s, t[l[i].f] - s[l[i].s]});
			s[r[j].s] -= t[l[i].f] - s[l[i].s];
			i++;
			while (j < r.size() && s[r[j].s] == t[r[j].f]) j++;
		} else {
			ans.pb({l[i].s, r[j].s, s[r[j].s] - t[r[j].f]});
			s[l[i].s] += s[r[j].s] - t[r[j].f];
			j++;
			while (i < l.size() && s[l[i].s] == t[l[i].f]) i++;
		}
	}
	while (j < r.size() && s[r[j].s] == t[r[j].f]) j++;
	while (i < l.size() && s[l[i].s] == t[l[i].f]) i++;
	if (i != l.size() || j != r.size()) {
		deb1("NO")
		return;
	}
	deb1("YES")
	deb1(ans.size())
	for (auto [i, j, k] : ans) {
		deb3(i + 1, j + 1, k)
	}
}

int main() {
	GODSPEED;
	int test = 1;
	//cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}