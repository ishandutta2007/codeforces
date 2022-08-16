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

const ll   N     =  5e5 + 5;
const ll   mod   =  998244353;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const int  LEVEL =  log2(N) + 1;

ll n, m, SS, a[N], b[N], c[N];

void solve() {
	cin >> n >> m >> SS;
	for (int i = 1; i <= m; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) cin >> b[i];
	for (int i = 1; i <= n; i++) cin >> c[i];
	vector <int> ia(m), ib(n);
	iota(all(ia), 1);
	sort(all(ia), [&](int i, int j){
		return a[i] > a[j];
	});
	iota(all(ib), 1);
	sort(all(ib), [&](int i, int j){
		return b[i] > b[j];
	});

	auto f = [&](int x, int flag = 0) -> bool {
		set <pair <int, int>> s;
		vector <int> ans, res(m);
		ll S = SS;
		for (int i = 0, j = 0; i < m; i += x) {
			while (j < n && b[ib[j]] >= a[ia[i]]) {
				s.insert({c[ib[j]], ib[j]});
				j++;
			}
			if (s.size() == 0) return 0;
			auto it = *s.begin();
			if (it.f > S) return 0;
			S -= it.f;
			for (int ct = 0; ct < x; ct++) ans.pb(it.s);
			s.erase(it);
		}
		if (flag == 1) {
			for (int i = 0; i < m; i++) {
				res[ia[i] - 1] = ans[i];
			}
			deb1("YES")
			debv(res)
		}
		return 1;
	};

	ll l = 1, r = m, ans = 0;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (f(mid)) {
			ans = mid;
			r = mid - 1;
		} else l = mid + 1;
	}
	if (ans == 0) deb1("NO")
	else f(ans, 1);
}

int main() {
	GODSPEED;
	int test = 1;
	// cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}