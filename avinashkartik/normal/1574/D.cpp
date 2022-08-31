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

ll n, m, c[11];
vector <vector <int>> a(11), v(N);
map <vector <int>, bool> b;

void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
		a[i].assign(c[i] + 1, 0);
		for (int j = 1; j <= c[i]; j++) cin >> a[i][j];
	}

	ll ans = 0;
	vector <int> res;
	cin >> m;
	for (int i = 0; i < m; i++) {
		v[i].assign(n, 0);
		for (int j = 0; j < n; j++) cin >> v[i][j];
		b[v[i]] = 1;
	}

	for (int i = 0; i < m; i++) {
		ll sum = 0;
		for (int j = 0; j < n; j++) sum += a[j + 1][v[i][j]];
		for (int j = 0; j < n; j++) {
			if (v[i][j] != 1) {
				sum -= a[j + 1][v[i][j]];
				sum += a[j + 1][v[i][j] - 1];
				v[i][j]--;
				if (sum > ans && b.find(v[i]) == b.end()) {
					ans = sum;
					res = v[i];
				}
				v[i][j]++;
				sum += a[j + 1][v[i][j]];
				sum -= a[j + 1][v[i][j] - 1];
			}
		}
	}

	vector <int> v;
	for (int i = 1; i <= n; i++) v.pb(c[i]);
	if (b.find(v) == b.end()) res = v;
	debv(res)
}

int main() {
	GODSPEED;
	int test = 1;
	// cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}