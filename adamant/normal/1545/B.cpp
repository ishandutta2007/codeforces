#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define int int64_t
#define all(x) begin(x), end(x)

const int mod = 998244353;

int add(int a, int b) {
	return (a + b) % mod;
}
int sub(int a, int b) {
	return (a + mod - b) % mod;
}
int mul(int a, int b) {
	return a * b % mod;
}
int bpow(int x, int n) {
	return n ? n % 2 ? mul(x, bpow(x, n - 1)) : bpow(mul(x, x), n / 2) : 1;
}
int inv(int x) {
	return bpow(x, mod - 2);
}

const int maxn = 1e5 + 42;
int F[maxn], RF[maxn];

int fact(int n) {
	return F[n] ? F[n] : F[n] = n ? mul(n, fact(n - 1)) : 1;
}
int rfact(int n) {
	return RF[n] ? RF[n] : RF[n] = inv(fact(n));
}
int nCr(int n, int r) {
	return mul(fact(n), mul(rfact(r), rfact(n - r)));
}

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	s += '#';
	int cnt = 0;
	int grp = 0, tot = 0;
	for(auto c: s) {
		if(c == '1') {
			cnt++;
			tot++;
		} else if(cnt > 0) {
			grp += cnt % 2;
			cnt = 0;
		}
	}
	tot = (tot - grp) / 2;
	int ans = nCr(n - tot - grp, tot);
	cout << ans << "\n";
	
}

signed main() {
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		solve();
	}
}