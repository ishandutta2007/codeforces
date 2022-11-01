#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <cstring>
#include <iomanip>
#include <numeric>
#include <set>
#include <map>
#include <queue>
#include <deque>

#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
#define pb push_back

using namespace std; using ll = long long; using pii = pair<int, int>; using vi = vector<int>; using ld = long double;

const int mod = (int)1e9 + 7;
const int N = (int)2e5;

ll pw(ll a, ll b) {
	if (!b) return 1;
	if (b & 1) return a * pw(a, b - 1) % mod;
	a = pw(a, b >> 1);
	return a * a % mod;
}

ll fac[N];

ll cnk(ll n, ll k) {
	if (n < k) return 0;
	return fac[n] * pw(fac[k] * fac[n - k] % mod, mod - 2) % mod;
}

ll sm[N];

int32_t main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//ifstream cin("in.txt");
	fac[0] = 1;
	for (int i = 1; i < N; i++) fac[i] = fac[i - 1] * i % mod;
	int n, k; string s; cin >> n >> k >> s;
	for (int d = 0; d < n - 1; d++) sm[d] = pw(10, d) * cnk(n - 2 - d, k - 1) % mod;
	for (int d = 1; d < n - 1; d++) sm[d] += sm[d - 1];
	ll ans = 0;
	//for (int i = 0; i < n; i++) ans = (ans + (s[i] - '0') * sm[n - 1 - i]) % mod, cout << "! "<<(s[i]-'0')*sm[n - 1 - i] << endl;
	for (int i = 0; i < n; i++) ans = (ans + (s[i] - '0') * ((n - 2 - i < 0 ? 0 : sm[n - 2 - i]) + pw(10, n - 1 - i) * cnk(i, k) % mod)) % mod;
	//for (int i = 0; i < n; i++) cout << ((s[i] - '0') * ((n - 2 - i < 0 ? 0 : sm[n - 2 - i]) + pw(10, n - 1 - i) * cnk(i, k) % mod)) % mod << endl;
	cout << ans;
}