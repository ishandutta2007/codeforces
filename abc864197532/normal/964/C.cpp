#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define lli long long int
#define ld long double
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
#define readfile freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout); 
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int mod = 1e9 + 9, x = 864197532, N = 100087, logN = 18, K = 350;

lli modpow(lli a, lli b) {
	lli ans = 1;
	for (; b; b >>= 1, a = a * a % mod) {
		if (b & 1) ans = ans * a % mod;
	}
	return ans;
}

int main () {
	int n, a, b, k;
	string s;
	cin >> n >> a >> b >> k >> s;
	lli block = 0;
	fop (i,0,k) {
		block = (block + mod + (modpow(a, k - 1 - i) * modpow(b, i) % mod * (s[i] == '+' ? 1 : -1))) % mod;
	}
	lli ans = (modpow(a, n + 1) + mod - modpow(b, n + 1)) % mod;
	lli cur = (modpow(a, k) + mod - modpow(b, k)) % mod;
	if (cur) cout << block * ans % mod * modpow(cur, mod - 2) % mod << endl;
	else {
		lli aa = modpow(a, k);
		cout << block * modpow(aa, (n + 1) / k - 1) % mod * ((n + 1) / k) % mod << endl;
	}
}