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

const ll   N     =  3e5 + 5;
const ll   mod   =  1e9 + 7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll n, k;

void solve() {
	cin >> n >> k;
	map <int, int> m;
	vector <int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i], m[a[i]]++;
	sort(all(a));
	uniq(a);
	vector <pair <int, int>> ans;
	int prv = -1;
	for (auto it : a) {
		if (m[it] >= k) {
			if (prv == -1) {
				prv = it;
				ans.pb({it, prv});
			} else if (it == ans.back().f + 1) {
				ans.pb({it, prv});
			} else {
				prv = it;
				ans.pb({it, prv});
			}
		} else {
			prv = -1;
		}
	}
	pair <int, int> res = {-1, -1};
	for (auto it : ans) {
		if (it.f - it.s > res.f - res.s || res.f == -1) res = it;
	}
	if (res.f == - 1) deb1(-1)
	else deb2(res.s, res.f)
}

int main() {
	GODSPEED;
	int test = 1;
	cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}