#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <cstring>
#include <cmath>
#include <unordered_set>
#include <map>
#include <deque>
#include <unordered_map>
#include <fstream>
#include <set>
#include <algorithm>
#include <iomanip>
#define fin cin
#define fout cout
#define F first
#define S second
#define PB push_back
#define PF push_front
#define MP make_pair
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef unsigned long long ull;
const int maxn = 1e6 + 5;
const int mod = 1e9 + 7;
const int inf = (1 << 30);
const int block = 316;
const int del = 229939;
const ll Inf = 1e18;

ll n, f, a[30];

ll b[30];

ll power (ll a, ll b) {
	if (b == 1)
		return a;
	ll ret = power (a, b / 2);
	ret *= ret;
	ret %= mod;
	if (b % 2 == 1)
		ret *= a;
	return ret % mod;
}

ll C (ll r, ll n) {
	if (n < r)
		return 0;
	ull m = 1, tmp = 1;
	for (ll i = n - r + 1; i <= n; i++) {
		ll q = i % mod;
		m *= q;
		m %= mod;
	}
	ll q = 1;
	for (int i = 1; i <= r; i++)
		q = (q * i) % mod;
	
	return m * power (q, mod - 2) % mod;
}

ll ans = 0;

void check (string s) { // a[1] + a[2] + a[3] + ... + a[n] = f --> C (n - 1, f + n - 1)
	ll tot = 0, cnt = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == '1') {
			tot += a[i] + 1;
			cnt ++;
		}
	}
	if (cnt % 2 == 0)
		ans += C (n - 1, f - tot + n - 1);
	else
		ans -= C (n - 1, f - tot + n - 1);
	ans = (ans + mod) % mod;
}

void mask (string s) {
	if (s.size() == n) {
		check (s);
		return;
	}
	mask (s + '0');
	mask (s + '1');
}

int main () {
	ios_base::sync_with_stdio (false);
	cin >> n >> f;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	mask ("");
	cout << ans << endl;
}