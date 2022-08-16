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

const ll   N     =  1e5 + 1;
const ll   mod   =  998244353;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const ll   LEVEL =  log2(N) + 1;

ll n, a[N], pre[N], dp[N][130];
vector <int> f[N];

ll mem(int i, int j) {
	if (i == 0) return 0;
	if (j == 1) return pre[i];
	if (a[i] % j == 0 && dp[i][f[j][a[i] / j]] != -1) return dp[i][f[j][a[i] / j]];
	ll no = (a[i] + j - 1) / j, newj;
	if (((a[i] + no - 1) / no) * no <= a[i]) newj = (a[i] + no - 1) / no;
	else newj = a[i] / no;
	ll ans = (mem(i - 1, newj) + (no - 1) * i) % mod;
	if (a[i] % j == 0) dp[i][f[j][a[i] / j]] = ans;
	return ans;
}

void solve() {

	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 130; j++) dp[i][j] = -1;
		cin >> a[i];
		pre[i] = (pre[i - 1] + (a[i] - 1) * i) % mod;
	}
	ll ans = 0;
	for (int st = n - 1; st >= 1; st--) {
		ans = (ans + mem(st, a[st + 1])) % mod;
	}
	deb1(ans)
}

int main() {
	GODSPEED;

	for (int i = 1; i <= N; i++) {
		f[i].assign(N / i + 3, 0);
	}

	for (int i = 1; i <= N; i++) {
		vector <int> v;
		for (int j = 1; j * j <= i; j++) {
			if (i % j == 0) {
				v.pb(j);
				if (j * j != i) v.pb(i / j);
			}
		}
		sort(all(v));
		for (int j = 0; j < v.size(); j++) {
			f[v[j]][i / v[j]] = j;
		}
	}

	int test = 1;
	cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}