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

const ll   N     =  2e5 + 5;
const ll   mod   =  998244353;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const int  LEVEL =  log2(N) + 1;

ll n, m, a[N];
string s[N];

void solve() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> s[i];
	ll ans = -INF;
	vector <int> best(m);
	for (int msk = 0; msk < (1 << n); msk++) {
		vector <pair <int, int>> v(m); 
		for (int i = 0; i < m; i++) {
			int cnt = 0;
			for (int j = 0; j < n; j++) {
				if (s[j][i] == '0') continue;
				if ((msk >> j)&1) cnt++;
				else cnt--;
			}
			v[i].f = cnt;
			v[i].s = i;
		}
		sort(all(v));
		ll res = 0;
		for (int i = 0; i < m; i++) {
			res += (i + 1) * v[i].f;
		}
		for (int i = 0; i < n; i++) {
			if ((msk >> i)&1) res -= a[i];
			else res += a[i];
		}
		if (res > ans) {
			ans = res;
			for (int i = 0; i < m; i++) {
				best[v[i].s] = i + 1;
			}
		}
	}
	debv(best)
}

int main() {
	GODSPEED;
	int test = 1;
	cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}