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

ll n, m1, m2;

class DSU{
	int n;
	vector <int> p, sz;

	public:
	DSU(int n) {
		this->n = n;
		p.assign(n + 2, 0);
		sz.assign(n + 2, 0);
	}

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
		}
	}
};

void solve() {
	cin >> n >> m1 >> m2;

	DSU d1(n), d2(n);
	d1.make(n);
	d2.make(n);

	for (int i = 1; i <= m1; i++) {
		int u, v; cin >> u >> v;
		d1.merge(u, v);
	}
	for (int i = 1; i <= m2; i++) {
		int u, v; cin >> u >> v;
		d2.merge(u, v);
	}

	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	vector<int> permutation(n);

    for (int i = 0; i < n; i++)
        permutation[i] = i + 1;

    shuffle(permutation.begin(), permutation.end(), rng);
    // debv(permutation)
	
	vpll res;
	for (int no = 0; no < min(n, 500ll); no++) {
		int i = permutation[no];
		for (int j = 1; j <= n; j++) {
			if (d1.find(i) != d1.find(j) && d2.find(i) != d2.find(j)) {
				d1.merge(i, j);
				d2.merge(i, j);
				res.pb({i, j});
			}
		}
	}
	deb1(res.size())
	for (auto it : res) deb2(it.f, it.s)
}

int main() {
	GODSPEED;
	int test = 1;
	// cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}