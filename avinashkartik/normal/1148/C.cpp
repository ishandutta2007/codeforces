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

ll n, a[N], ind[N];

void Swap(int i, int j) {
	swap(a[i], a[j]);
	ind[a[i]] = i;
	ind[a[j]] = j;
}

void solve() {
	cin >> n;
	vpll ans;
	for (int i = 1; i <= n; i++) cin >> a[i], ind[a[i]] = i;
	for (int i = 1; i <= n; i++) {
		if (i <= n / 2) {
			if (ind[i] <  i + n / 2) {
				if(ind[i] > n / 2) {
					ans.pb({ind[i], 1});
					Swap(ind[i], 1);
				}
				ans.pb({ind[i], n});
				Swap(ind[i], n);
			}
			if (ind[i] != i) {
				ans.pb({i, ind[i]});
				Swap(i, ind[i]);
			}
		} else {
			if (ind[i] > i - n / 2) {
				if(i <= n / 2) {
					ans.pb({ind[i], n});
					Swap(ind[i], n);
				}
				ans.pb({ind[i], 1});
				Swap(ind[i], 1);
			}
			if (ind[i] != i) {
				ans.pb({i, ind[i]});
				Swap(i, ind[i]);
			}
		}
	}
	assert(ans.size() <= 5 * n);
	deb1(ans.size())
	for (auto it : ans) deb2(it.f, it.s)
	}

int main() {
	GODSPEED;
	int test = 1;
	//cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}