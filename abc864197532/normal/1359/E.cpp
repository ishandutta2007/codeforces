#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define print(a) {\
    for (auto i : a) cout << i << ' ';\
    cout << '\n';\
}
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define mt make_tuple
#define pii pair<int,int> 
#define pdd pair<ld,ld> 
#define ld double
#define pll pair<lli,lli>
#define tiii tuple<int,int,int>
#define all(a) a.begin(), a.end()
#define X first
#define Y second
#define oset tree<pii,null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update>
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);

const int mod = 998244353, x = 864197532, N = 500087, logN = 17;
long long frac[N], fracp[N];

long long modpow(int a, int b) {
	long long ans = 1;
	for (long long aa = a; b; b >>= 1, aa = aa * aa % mod) {
		if (b & 1) ans = ans * aa % mod;
	}
	return ans;
}

long long modinv (int b) {
	return modpow(b, mod - 2);
}

long long C (int a, int b) {
	return frac[a] * fracp[b] % mod * fracp[a - b] % mod;
}

int main () {
	int n, k;
	cin >> n >> k;
	frac[0] = 1;
	fop (i,1,N) frac[i] = frac[i - 1] * i % mod;
	fop (i,0,N) fracp[i] = modinv(frac[i]);
	lli ans = 0;
	int now = 1;
	while (k <= n / now) {
		ans += C(n / now - 1, k - 1);
		ans %= mod;
		now++;
	}
	cout << ans << endl;
}