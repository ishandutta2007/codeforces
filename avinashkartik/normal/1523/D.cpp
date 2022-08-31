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

const ll   N     =  2e5 + 5;
const ll   mod   =  998244353;
const ll   INF   =  1e18;
const int  INFi  =  0x7f7f7f7f;
const ll   LEVEL =  log2(N) + 1;

int n, m, p;
ll val[N], ans = 0, ansno = 0;
vector <int> v[N];
string s[N];

void calc(int ind) {
	vector <int> M((1 << v[ind].size()), 0);
	for (int i = 0; i < n; i++) {
		int msk = 0;
		for (int j = 0; j < v[ind].size(); j++) {
			if (val[i]&(1ll << v[ind][j]))
				msk += (1 << j);
		}
		M[msk]++;
	}
	int msk = (1 << v[ind].size()) - 1;
	for (int i = v[ind].size() - 1; i >= 0; i--) {
		for (int j = 0; j <= msk; j++) {
			if (j & (1 << i)) {
				M[j - (1 << i)] += M[j];
			}
		}
	}
	for (int j = msk; j; j = (j - 1)&msk) {
		if (M[j] >= (n + 1) / 2) {
			if (__builtin_popcountll(j) > ansno) {
				ansno = __builtin_popcountll(j);
				ll msk = 0;
				for (int i = 0; i < v[ind].size(); i++) {
					if (j&(1 << i))
						msk += (1ll << v[ind][i]);
				}
				ans = msk;
			}
		}
	}
}

void solve() {
	cin >> n >> m >> p;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
		for (int j = 0; j < m; j++) {
			if (s[i][j] == '0') continue;
			val[i] += (1ll << j);
			v[i].pb(j);
		}
	}

	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	vector <int> ind(n);
	iota(all(ind), 0);
	shuffle(all(ind), rng);

	for (int i = 0; i < min(n, 20); i++) {
		calc(ind[i]);
	}
	for (int i = 0; i < m; i++) {
		cout << "01"[((ans >> i) & 1)];
	}
	newl;
}

int main() {
	GODSPEED;
	int test = 1;
	// cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}