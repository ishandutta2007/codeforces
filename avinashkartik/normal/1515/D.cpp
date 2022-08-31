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

int n, l, r;

void solve() {
	cin >> n >> l >> r;
	vector <int> v(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		int x; cin >> x;
		if (i <= l) {
			v[x]++;
		} else v[x]--;
	}
	vector <int> L, R;
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (v[i] < 0) {
			for (int j = 0; j > v[i]; j--) L.pb(i);
		} else {
			for (int j = 0; j < v[i]; j++) R.pb(i);
		}
	}
	sort(all(L));
	sort(all(R));
	if (L.size() == R.size()) {
		deb1(L.size())
	} else {
		if (L.size() < R.size()) swap(L, R);
		int ans = R.size(), prv = 0, no = 0;
		for (auto it : L) {
			if (prv == it) {
				prv = 0;
				no += 2;
			} else prv = it;
		}
		int left = L.size() - R.size();
		ans += max(0, left - no) + min(left, no) / 2;
		deb1(ans)
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