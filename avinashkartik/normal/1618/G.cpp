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

const ll   N     =  1e6 + 5;
const ll   mod   =  998244353;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const int  LEVEL =  log2(N) + 1;

ll n, m, q, a[N], pre[N], p[N], ct[N], ans = 0;
map <ll, int> cur;

void make(ll n){
	for(int i = 1; i <= n; i++){
		p[i] = i;
		ct[i] = 0;
	}
}

int find(ll x){
	return (p[x] == x)? x: p[x] = find(p[x]);
}

void merge(ll x, ll y){
	ll a = find(x);
	ll b = find(y);
	if(a != b){
		p[a] = b;
		ans -= pre[b] - pre[b - ct[b]];
		ans -= pre[a] - pre[a - ct[a]];
		ct[b] += ct[a];
		ans += pre[b] - pre[b - ct[b]];
	}
}

void solve() {
	cin >> n >> m >> q;
	for (int i = 1; i <= n + m; i++) {
		cin >> a[i];
		if (i <= n) cur[a[i]]++;
	}
	sort (a + 1, a + n + m + 1);
	make(n + m);
	for (int i = 1; i <= n + m; i++) {
		pre[i] = pre[i - 1] + a[i];
		if (cur[a[i]]) {
			ct[i]++;
			ans += a[i];
			cur[a[i]]--;
		}
	}
	set <pair <int, int>> s;
	for (int i = 2; i <= n + m; i++) {
		s.insert({a[i] - a[i - 1], i});
	}
	vector <pair <int, int>> v;
	vector <ll> res(q + 1);
	for (int i = 1; i <= q; i++) {
		int k; cin >> k;
		v.pb({k, i});
	}
	sort(all(v));
	for (auto &[k, i] : v) {
		while (s.size() && s.begin()->f <= k) {
			merge(s.begin()->s - 1, s.begin()->s);
			s.erase(s.begin());
		}
		res[i] = ans;
	}
	for (int i = 1; i <= q; i++) deb1(res[i])
}

int main() {
	GODSPEED;
	int test = 1;
	// cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}