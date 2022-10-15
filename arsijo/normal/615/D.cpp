#include <bits/stdc++.h>
using namespace std;
#define files(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout);
#define input freopen("input.txt", "r", stdin)
#define output freopen("output.txt", "w", stdout)
#define io input; output;
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ms(x, y) memset(x, y, sizeof(x))
#define sqr(a) ((a) * (a))
//#define endl "\n"
#define def(f) make(#f);
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
#ifdef LOCAL
typedef double ld;
#else
typedef double ld;
#endif
typedef pair<ll, ll> ii;
typedef pair<ii, ii> iii;
typedef vector<int>::iterator vit;
typedef set<ii>::iterator siit;
typedef pair<string, string> ss;
const ld E = 1e-9;
const ll MOD = 1e9 + 7;
#define mod % MOD

#ifdef LOCAL
//#define DEBUG
#endif

#ifdef LOCAL
const int MAX = 2e4;
#else
const int MAX = 2e4;
#endif
#ifdef DEBUG
#define dbg cout
#else
#define dbg if(0) cout
#endif

ll ans = 1;

void add(ll n){
	ans = ((ans) * (n mod)) mod;
}

ll pow_mod(ll n, ll m){
	if(m == 0)
		return 1;
	if(m == 1)
		return n;
	ll ans = pow_mod(n, m >> 1);
	ans = (ans * ans) mod;
	if(m & 1)
		ans = (ans * n) mod;
	return ans;
}

ll ml(ll n, ll m){
	return (n * m) % (MOD - 1);
}

ll sum(ll n){
	return ((n + 1) * n / 2) % (MOD - 1);
}

int main() {

	cout.precision(11);
	cout << fixed;
	sync;
#ifdef LOCAL
	input;
#else

#endif

	int n;
	cin >> n;

	map<int, int> m;
	for(int i = 0; i < n; i++){
		int a;
		cin >> a;
		m[a]++;
	}
	ll a[m.size()], b[m.size()];
	ms(a, 0);
	ms(b, 0);
	int sz = 0;
	for(map<int, int>::iterator it = m.begin(); it != m.end(); it++){
		a[sz] = it->first, b[sz] = it->second;
		sz++;
	}
	ll dp1[sz], dp2[sz];
	for(int i = 0; i < sz; i++)
		dp1[i] = (i == 0 ? 1 : dp1[i - 1]) * (b[i] + 1) % (MOD - 1);
	for(int i = sz - 1; i >= 0; i--)
		dp2[i] = (i == sz - 1 ? 1 : dp2[i + 1]) * (b[i] + 1) % (MOD - 1);

	for(int i = 0; i < sz; i++){
		ll c = (i == 0 ? 1 : dp1[i - 1]) * (i == sz - 1 ? 1 : dp2[i + 1]);
		c = c % (MOD - 1);
		add(pow_mod(a[i], ml(sum(b[i]), c)));
	}

	cout << ans;
}