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
const int mod = 998244353, x = 864197532, N = 2000, logN = 18, K = 350, all = (1 << N) - 1;

lli frac[N], fracp[N];

lli modpow (lli a, int b) {
	lli ans = 1;
	for (; b; b >>= 1, a = a * a % mod) {
		if (b & 1) ans = ans * a % mod; 
	}
	return ans;
}

lli C(int n, int m) {
	return frac[n] * fracp[n - m] % mod * fracp[m] % mod; 
}

int main () {
	frac[0] = 1;
	fop (i,1,N) frac[i] = frac[i - 1] * i % mod;
	fop (i,0,N) fracp[i] = modpow(frac[i], mod - 2);
	int n;
	cin >> n;
	int a[n];
	fop (i,0,n) cin >> a[i];
	vector <lli> dp(n + 1, 0);
	dp[n] = 1;
	FOP (i,n,0) {
		if (a[i] <= 0) continue;
		fop (j,i + 1,n + 1) if (a[i] <= j - i - 1) {
			dp[i] = (dp[i] + C(j - i - 1, a[i]) * dp[j] % mod) % mod;
		}
	}
	dp.pop_back();
	cout << accumulate(all(dp), 0ll) % mod << endl;
}