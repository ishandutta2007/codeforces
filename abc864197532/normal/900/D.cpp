#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define printv(a) {\
    for (auto y : a) cout << y << ' ';\
    cout << '\n';\
}
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define mt make_tuple
#define pii pair<int,int> 
#define pll pair<lli,lli>
#define tiii tuple<int,int,int>
#define all(a) a.begin(), a.end()
#define X first
#define Y second
#define oset tree<pii,null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update>
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int mod = 1e9 + 7, x = 864197532, N = 500001, logN = 17, K = 350;

lli modpow(lli a, int b) {
	lli ans = 1;
	for (; b; b >>= 1, a = a * a % mod) {
		if (b & 1) ans = ans * a % mod;
	}
	return ans;
}

int mu(int x) {
	int cnt = 1;
	for (int i = 2; i * i <= x; ++i) if (x % i == 0) {
		cnt *= -1;
		while (x % i == 0) {
			x /= i;
			if (x % i == 0) cnt = 0;
		}
	}
	if (x > 1) cnt *= -1;
	return cnt;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int x, y;
    cin >> x >> y;
    if (y % x) {
    	cout << 0 << endl;
    	return 0;
	}
	y /= x;
	lli ans = 0;
	for (int i = 1; i * i <= y; ++i) if (y % i == 0) {
		ans = (ans + modpow(2, i - 1) * mu(y / i)) % mod;
		if (i * i != y) ans = (ans + modpow(2, y / i - 1) * mu(i)) % mod;
	}
	cout << (ans + mod) % mod << endl;
}