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

int n, k, x[N], y[N], p[N], sz[N], t[N];

void make(ll n){
	for(int i = 1; i <= n; i++){
		p[i] = i;
		sz[i] = 1;
	}
}

int find(ll x){
	return (p[x] == x)? x: p[x] = find(p[x]);
}

void merge(ll x, ll y){
	ll a = find(x);
	ll b = find(y);
	if(a != b){
		if(sz[a] >= sz[b]) swap(a,b);
		p[a] = b;
		sz[b] += sz[a];
		t[b] = min(t[b], t[a]);
	}
}

void solve() {
	cin >> n >> k;
	make(n);
	for (int i = 1; i <= n; i++) {
		cin >> x[i] >> y[i] >> t[i];
	}
	vector <int> ind(n);
	iota(all(ind), 1);

	sort(all(ind), [&](int i, int j){
		if (x[i] == x[j]) return y[i] < y[j];
		return x[i] < x[j];
	});
	for (int i = 1; i < n; i++) {
		if (x[ind[i - 1]] == x[ind[i]] && abs(y[ind[i]] - y[ind[i - 1]]) <= k) {
			merge(ind[i], ind[i - 1]);
		}
	}

	sort(all(ind), [&](int i, int j){
		if (y[i] == y[j]) return x[i] < x[j];
		return y[i] < y[j];
	});
	for (int i = 1; i < n; i++) {
		if (y[ind[i - 1]] == y[ind[i]] && abs(x[ind[i]] - x[ind[i - 1]]) <= k) {
			merge(ind[i], ind[i - 1]);
		}
	}

	vector <int> v;
	for (int i = 1; i <= n; i++) {
		if (find(i) == i) {
			v.pb(t[i]);
		}
	}
	sort(all(v), greater<>());
	
	int ans = 0;
	for (auto it : v) if (it >= ans) ans++;
	
	deb1(ans - 1)
}

int main() {
	GODSPEED;
	int test = 1;
	cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}