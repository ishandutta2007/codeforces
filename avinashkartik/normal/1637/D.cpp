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

const ll   N     =  102;
const ll   mod   =  1e9 + 7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll n, a[N], b[N], dp[N][N * N], pre[N];

ll mem(int i, int j) {
	if (i == n + 1) return 0;
	if (dp[i][j] != -1) return dp[i][j];
	ll ai = j * a[i] + (pre[i - 1] - j) * b[i] + mem(i + 1, j + a[i]);
	ll bi = j * b[i] + (pre[i - 1] - j) * a[i] + mem(i + 1, j + b[i]);
	return dp[i][j] = min(ai, bi);
}

void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) cin >> b[i];
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		pre[i] = pre[i - 1] + a[i] + b[i];
		ans += (n - 1) * (a[i] * a[i] + b[i] * b[i]);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < N * N; j++) dp[i][j] = -1;
	}
	deb1(ans + 2 * mem(1, 0))
}

int main() {
	GODSPEED;
	int test = 1;
	cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}