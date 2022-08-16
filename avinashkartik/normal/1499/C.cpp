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
typedef  pair<ll, ll>          pll;
typedef  vector<ll>            vll;
typedef  vector<pll>           vpll;

const ll   N     =  1e5 + 5;
const ll   mod   =  998244353;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const ll   LEVEL =  log2(N) + 1;

ll n, a[N];

void solve() {
	cin >> n;
	ll ans = INF, sum1 = 0, sum2 = 0, mn1 = INFi, mn2 = INFi;
	vector <int> dp(n, 0);
	for (int i = 1, j = 0, k = 0; i <= n; i++) {
		cin >> a[i];
		if (i & 1) {
			ans = min(ans, sum2 + (n - k) * mn2 + sum1 + (n - j) * a[i]);
			sum1 += a[i];
			j++;
			mn1 = min(mn1, a[i]);
		} else {
			ans = min(ans, sum1 + (n - j) * mn1 + sum2 + (n - k) * a[i]);
			sum2 += a[i];
			k++;
			mn2 = min(mn2, a[i]);
		}
	}
	deb1(ans)
}

int main() {
	GODSPEED;
	int test = 1;
	cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}